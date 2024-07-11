#include "catgame_logo.h"
#include "bn_log.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_camera_actions.h"
#include "bn_regular_bg_items_jam2024.h"
#include "bn_regular_bg_ptr.h"

namespace catgame
{
    logo::logo(bn::camera_ptr &camera)
    {
        BN_LOG("Logo scene");
        current_game_phase = catgame::game_phases::LOGO;
        next_game_phase = catgame::game_phases::INTRO;

        bn::fixed amplitude = 10;
        camera.set_position(-amplitude, -amplitude);
        bn::camera_move_loop_action camera_action(camera, 120, amplitude, amplitude);

        bn::regular_bg_ptr jam2024_bg = bn::regular_bg_items::jam2024.create_bg(8, 48);

        jam2024_bg.set_camera(camera);

        while (!bn::keypad::start_pressed())
        {
            camera_action.update();
            bn::core::update();
        }
        
        camera.set_position(0, 0);
    }
}