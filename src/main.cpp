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
#include "catgame_lvl2.h"
#include "catgame_minigame_1.h"
#include "catgame_lvl_gym.h"
#include "catgame_history.h"

int main()
{
    bn::core::init();

    int _stamina = 30;
    int _food = 0;
    int _times_played = 0;

    catgame::game_phases next_game_phase = catgame::game_phases::LOGO;

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);

    while (true)
    {
        switch (next_game_phase)
        {
        case (catgame::game_phases::LOGO):
        {
            catgame::logo logo = catgame::logo();
            bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
            next_game_phase = logo.execute(camera);
        }
        break;
        case (catgame::game_phases::INTRO):
        {
            catgame::intro intro = catgame::intro();
            next_game_phase = intro.execute(text_generator);
        }
        break;
        case (catgame::game_phases::HISTORY):
        {
            catgame::history intro = catgame::history();
            next_game_phase = intro.execute(text_generator);
        }
        break;
        case (catgame::game_phases::LVL1):
        {
            catgame::lvl1 lvl1 = catgame::lvl1();
            next_game_phase = lvl1.execute(text_generator, _times_played, _food, _stamina);
        }
        break;
        case (catgame::game_phases::MINIGAME1):
        {
            catgame::minigame_1 minigame_1 = catgame::minigame_1();
            next_game_phase = minigame_1.execute(text_generator, _times_played, _food, _stamina);
        }
        break;
        case (catgame::game_phases::GYM):
        {
            catgame::lvl_gym lvl_gym = catgame::lvl_gym();
            next_game_phase = lvl_gym.execute(text_generator, _times_played, _food, _stamina);
        }
        break;
        default:
            BN_ERROR("Invalid next scene: ");
            break;
        }
        bn::core::update();
    }
}