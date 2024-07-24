#include "catgame_logo.h"
#include "bn_log.h"
#include "bn_core.h"
#include "bn_keypad.h"
#include "bn_camera_actions.h"
#include "bn_regular_bg_items_gbajam24_logo.h"
#include "bn_regular_bg_items_gbajam24_banner.h"
#include "bn_regular_bg_ptr.h"

namespace catgame
{
    logo::logo(){}

    catgame::game_phases logo::execute(bn::camera_ptr &camera)
    {
        BN_LOG("Logo scene");
        next_game_phase = catgame::game_phases::INTRO;

        bn::fixed amplitude = 60;
        camera.set_position(-amplitude, 0);
        bn::camera_move_loop_action camera_action(camera, 600, amplitude, 0);

        bn::regular_bg_ptr gbajam24_banner_bg = bn::regular_bg_items::gbajam24_banner.create_bg(0, 40);
        bn::regular_bg_ptr gbajam24_logo_bg = bn::regular_bg_items::gbajam24_logo.create_bg(0, 70);

        gbajam24_banner_bg.set_camera(camera);
        //gbajam24_logo_bg.set_camera(camera);

        int timer = 0;
        while (!bn::keypad::start_pressed() && timer < 600)
        {
            timer += 1;
            camera_action.update();
            bn::core::update();
        }
        camera.set_position(0, 0);
        return next_game_phase;
    }
}