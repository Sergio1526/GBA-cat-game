#include "catgame_intro.h"
#include "bn_log.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_regular_bg_items_cats_intro.h"
#include "bn_regular_bg_ptr.h"

namespace catgame
{
    intro::intro(){
        BN_LOG("INTRO");
        current_game_phase = catgame::game_phases::INTRO;
        next_game_phase = catgame::game_phases::LVL1;

        bn::regular_bg_ptr cats_intro = bn::regular_bg_items::cats_intro.create_bg(0, 10);

        while (!bn::keypad::start_pressed())
        {
            bn::core::update();
        }
    }
}