#include "catgame_history.h"
#include "bn_log.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_builder.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_backdrop.h"
#include "bn_string_view.h"

namespace catgame
{
    history::history() {}
    catgame::game_phases history::execute(bn::sprite_text_generator &text_generator)
    {
        bn::backdrop::set_color(bn::color(0, 0, 0));

        current_game_phase = catgame::game_phases::INTRO;
        next_game_phase = catgame::game_phases::LVL1;

        // Show text
        text_generator.set_center_alignment();
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        text_generator.generate(0, 60, "PRESS START", text_sprites);

        bn::fixed timer = 0;
        constexpr bn::string_view story_lines[] = {
            "...",
            "One day",
            "our friendly cat",
            "decides to go to",
            "THE GYM!",
        };
        int counter = 0;

        while (!bn::keypad::start_pressed())
        {
            timer += 0.1;
            if (timer > 1000)
            {
                BN_LOG("Here");
                text_generator.generate(0, 60, story_lines[counter], text_sprites);
                timer = 0;
                counter += 1;
                if (counter > 4)
                {
                    break;
                }
                bn::core::update();
            }
        }
        return next_game_phase;
    }
}