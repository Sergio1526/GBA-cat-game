#include "catgame_lvl1.h"
#include "bn_core.h"
#include "bn_blending.h"
#include "bn_unique_ptr.h"
#include "bn_keypad.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_builder.h"           //Sprites tiled
#include "bn_sprite_animate_actions.h"   //Sprites animated
#include "bn_regular_bg_map_cell_info.h" //To create logical map
#include "bn_camera_actions.h"           //Add camera
#include "bn_rect_window_boundaries_hbe_ptr.h"
#include "bn_log.h" //Remove on final version
#include "bn_string.h"
#include "bn_vector.h"
#include "bn_backdrop.h"

// Backgrounds
#include "bn_regular_bg_items_simple_bg.h"
#include "bn_regular_bg_items_clouds.h"
#include "bn_regular_bg_map_ptr.h"

// Sprites
#include "bn_sprite_items_limit.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "catgame_enemy.h"
#include "catgame_player.h"
#include "bn_sprite_items_collider.h"

namespace catgame
{
    lvl1::lvl1() {}
    catgame::game_phases lvl1::execute(bn::sprite_text_generator &text_generator)
    {
        bn::backdrop::set_color(bn::color(0, 0, 0));
        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
        // Set current scene
        current_game_phase = catgame::game_phases::LVL1;
        next_game_phase = catgame::game_phases::INTRO;

        // Show text
        text_generator.set_center_alignment();
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        // Sprites
        

        // Backgrounds
        bn::regular_bg_ptr ground = bn::regular_bg_items::simple_bg.create_bg(256, 256);    //Center
        // Generate map for collisions
        const bn::regular_bg_map_item &map_item = bn::regular_bg_items::simple_bg.map_item();

        bn::regular_bg_ptr clouds_bg = bn::regular_bg_items::clouds.create_bg(0, 0);
        bn::blending::set_transparency_alpha(0.1);
        clouds_bg.set_blending_enabled(true);

        // Set player at middle of the map
        bn::point start_position(128, 128);

        // Create player
        catgame::player _player = player(camera, start_position);

        // Create enemies
        bn::vector<enemy, 16> enemies = {};
        enemies.push_back(enemy(camera, bn::point(100, 80), _player.sprite()));
        enemies.push_back(enemy(camera, bn::point(150, 90), _player.sprite()));
        enemies.push_back(enemy(camera, bn::point(250, 120), _player.sprite()));

        // Set camera
        ground.set_camera(camera);
        clouds_bg.set_camera(camera);

        // For Backgrounds
        clouds_bg.set_priority(0);

        while (!_player.dead())
        {
            text_sprites.clear();
            text_generator.generate(0, -70, "GUI", text_sprites);
            bn::string val = bn::to_string<32>(_player.health());
            text_generator.generate(0, -60, val, text_sprites);
            
            int pos = _player.map_cell(map_item);
            val = bn::to_string<32>(pos);
            text_generator.generate(0, -50, val, text_sprites);

            for (enemy &enemy : enemies)
            {
                if(enemy.near_player(_player.position())){
                    _player.hurt(1);
                }
                enemy.update(map_item);
            }

            _player.update(map_item);
            _player.animate();

            // Animate cloud
            clouds_bg.set_position(clouds_bg.x() + 0.1, clouds_bg.y() + 0.1);

            // Update camera pos
            camera.set_position(_player.position());

            bn::core::update();
        }
        return next_game_phase;
    }
}