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
#include "bn_camera_actions.h"           //Add camera

namespace catgame
{
    history::history() {}
    catgame::game_phases history::execute(bn::sprite_text_generator &text_generator)
    {
        bn::backdrop::set_color(bn::color(0, 0, 0));

        current_game_phase = catgame::game_phases::INTRO;
        next_game_phase = catgame::game_phases::LVL1;

        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);

        // Show text
        text_generator.set_center_alignment();
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        bn::fixed history_timer = 0;
        constexpr bn::string_view story_lines[] = {
            "...",
            "One day",
            "Mr Skitty felt courius",
            "and decides to go out",
            "to explore the town!",
        };
        int counter = 0;
        text_generator.generate(0, -40 + (counter * 10), story_lines[counter], text_sprites);
        counter++;

        while (!bn::keypad::start_pressed())
        {
            // Update camera pos
            camera.set_position(camera.position().x(), camera.position().y() + 0.2f);
            if (history_timer > 10)
            {
                text_generator.generate(0, -40 + (counter * 10), story_lines[counter], text_sprites);
                history_timer = 0;
                if (counter < 5)
                {
                    counter += 1;
                }
                else{
                    break;
                }
            }
            else{
                history_timer += 0.1f;
            }
            bn::core::update();
        }
        return next_game_phase;
    }
}