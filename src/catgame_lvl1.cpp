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

// Backgrounds
#include "bn_regular_bg_items_simple_bg.h"
#include "bn_regular_bg_items_clouds.h"

// Sprites
#include "bn_sprite_items_cat.h"
#include "bn_sprite_items_limit.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "catgame_enemy.h"
#include "bn_sprite_items_collider.h"

namespace catgame
{
    lvl1::lvl1() {}
    catgame::game_phases lvl1::execute(bn::sprite_text_generator &text_generator)
    {
        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
        // Set current scene
        current_game_phase = catgame::game_phases::LVL1;
        next_game_phase = catgame::game_phases::INTRO;

        BN_LOG("Second scene");

        // Show text
        text_generator.set_center_alignment();
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        // Sprites
        bn::sprite_ptr cat_sprite = bn::sprite_items::cat.create_sprite(0, 0);

        // Create enemies
        bn::vector<enemy, 16> enemies = {};
        enemies.push_back(enemy(camera, bn::point(10, 10)));
        enemies.push_back(enemy(camera, bn::point(20, 20)));
        enemies.push_back(enemy(camera, bn::point(30, 30)));

        bn::sprite_ptr limit_TL = bn::sprite_items::limit.create_sprite(0, 0);
        bn::sprite_ptr limit_TR = bn::sprite_items::limit.create_sprite(0, 255);
        bn::sprite_ptr limit_BL = bn::sprite_items::limit.create_sprite(255, 0);
        bn::sprite_ptr limit_BR = bn::sprite_items::limit.create_sprite(255, 255);

        // Backgrounds
        bn::regular_bg_ptr ground = bn::regular_bg_items::simple_bg.create_bg(128, 128);
        // Generate map for collisions
        const bn::regular_bg_map_item &map_item = bn::regular_bg_items::simple_bg.map_item();
        bn::regular_bg_map_cell valid_map_cell = map_item.cell(0, 0); // Set valid cell
        int valid_tile_index = bn::regular_bg_map_cell_info(valid_map_cell).tile_index();
        BN_LOG("Valid: ", valid_tile_index);

        // Set player at middle of the map
        bn::point cat_position(128, 128);
        bn::point cat_map_position(16, 16);

        bn::regular_bg_ptr clouds_bg = bn::regular_bg_items::clouds.create_bg(0, 0);
        bn::blending::set_transparency_alpha(0.1);
        clouds_bg.set_blending_enabled(true);

        // Animations
        bn::sprite_animate_action<2> cat_anim = bn::create_sprite_animate_action_forever(
            cat_sprite, 16, bn::sprite_items::cat.tiles_item(), 0, 1);

        // Set camera
        cat_sprite.set_camera(camera);
        ground.set_camera(camera);
        clouds_bg.set_camera(camera);
        limit_TL.set_camera(camera);
        limit_TR.set_camera(camera);
        limit_BL.set_camera(camera);
        limit_BR.set_camera(camera);

        // For Backgrounds
        clouds_bg.set_priority(0);
        // For sprites
        cat_sprite.set_z_order(0);

        while (!bn::keypad::start_pressed())
        {
            text_sprites.clear();
            text_generator.generate(0, -40, "GUI", text_sprites);

            bn::point cat_new_position = cat_position;

            // Handle movement
            bool idle = true;
            if (bn::keypad::left_held())
            {
                cat_new_position.set_x(cat_new_position.x() - 1);
                cat_sprite.set_horizontal_flip(true);
                idle = false;
            }
            else if (bn::keypad::right_held())
            {
                cat_new_position.set_x(cat_new_position.x() + 1);
                cat_sprite.set_horizontal_flip(false);
                idle = false;
            }

            if (bn::keypad::up_held())
            {
                cat_new_position.set_y(cat_new_position.y() - 1);
                idle = false;
            }
            else if (bn::keypad::down_held())
            {
                cat_new_position.set_y(cat_new_position.y() + 1);
                idle = false;
            }

            cat_anim.update();

            // Limits
            if (cat_new_position.x() < 0)
            {
                cat_new_position.set_x(0);
            }
            if (cat_new_position.x() > ground.dimensions().width())
            {
                cat_new_position.set_x(ground.dimensions().width());
            }
            if (cat_new_position.y() < 0)
            {
                cat_new_position.set_y(0);
            }
            if (cat_new_position.y() > ground.dimensions().height())
            {
                cat_new_position.set_y(ground.dimensions().height());
            }

            // Calculate map position
            cat_map_position.set_x(cat_new_position.x() / 8);
            cat_map_position.set_y(cat_new_position.y() / 8);

            // Update position
            bn::regular_bg_map_cell map_cell = map_item.cell(cat_map_position);
            int tile_index = bn::regular_bg_map_cell_info(map_cell).tile_index();
            bn::string val = bn::to_string<32>(tile_index);
            text_generator.generate(0, -60, val, text_sprites);
            if (tile_index < 5)
            {
                cat_position = cat_new_position;
            }
            cat_sprite.set_position(cat_position.x(), cat_position.y());

            if (bn::keypad::b_pressed())
            {
                BN_LOG("Cat pos: ", " X:", cat_position.x(), " Y:", cat_position.y());
                BN_LOG("Map pos: ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());

                map_cell = map_item.cell(cat_map_position);
                tile_index = bn::regular_bg_map_cell_info(map_cell).tile_index();
                BN_LOG(tile_index);
            }

            if (bn::keypad::a_pressed())
            {
                for (enemy &enemy : enemies)
                {
                    enemy.spawn();
                }
            }

            for (enemy &enemy : enemies)
            {
                enemy.update();
            }

            // Animate cloud
            clouds_bg.set_position(clouds_bg.x() + 0.1, clouds_bg.y() + 0.1);

            // Update camera pos
            camera.set_position(cat_position.x(), cat_position.y());

            bn::core::update();
        }
        return next_game_phase;
    }
}