#include "catgame_intro.h"
#include "bn_log.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_regular_bg_items_cats_intro.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_builder.h"
#include "bn_vector.h"
#include "bn_sprite_ptr.h"

namespace catgame
{
    intro::intro(bn::sprite_text_generator &text_generator){
        BN_LOG("INTRO");
        current_game_phase = catgame::game_phases::INTRO;
        next_game_phase = catgame::game_phases::LVL1;

        // Show text
        text_generator.set_center_alignment();
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        text_generator.generate(0, 60, "PRESS START", text_sprites);

        bn::regular_bg_ptr cats_intro = bn::regular_bg_items::cats_intro.create_bg(0, 10);

        while (!bn::keypad::start_pressed())
        {
            bn::core::update();
        }
    }
}