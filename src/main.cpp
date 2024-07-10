#include "bn_core.h"
#include "bn_camera_actions.h"

#include "bn_log.h"
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

// Catgame libraries
#include "catgame_game_phases.h"
#include "catgame_intro.h"
#include "catgame_logo.h"
#include "catgame_scene.h"
#include "catgame_lvl1.h"

// Code
bn::optional<catgame::game_phases> current_game_phase = catgame::game_phases::LOGO;
catgame::game_phases next_game_phase;

int main()
{
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    bn::camera_ptr camera = bn::camera_ptr::create(0, 0);

    while (true)
    {
        switch (next_game_phase)
        {
        case (catgame::game_phases::LOGO):
            new catgame::logo(camera);
            next_game_phase = catgame::game_phases::INTRO;
            bn::core::update();
            break;
        case (catgame::game_phases::INTRO):
            new catgame::intro();
            next_game_phase = catgame::game_phases::LVL1;
            bn::core::update();
            break;
        case (catgame::game_phases::LVL1):
            new catgame::lvl1(camera, text_generator);
            next_game_phase = catgame::game_phases::INTRO;
            bn::core::update();
            break;
        default:
            BN_ERROR("Invalid next scene: ");
            break;
        }
    }
}