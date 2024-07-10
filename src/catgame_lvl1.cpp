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
#include "bn_regular_bg_items_simple_bg.h"
#include "bn_regular_bg_items_clouds.h"
#include "bn_regular_bg_items_cats_intro.h"

// Sprites
#include "bn_sprite_items_dino.h"
#include "bn_sprite_items_cat.h"
#include "bn_sprite_items_ninja.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

namespace catgame
{
    bn::point cat_map_position(128, 128);
    
    lvl1::lvl1(bn::camera_ptr &camera, bn::sprite_text_generator &text_generator)
    {
        // Set current scene
        current_game_phase = catgame::game_phases::LVL1;
        next_game_phase = catgame::game_phases::INTRO;

        BN_LOG("Second scene");

        // Show text
        constexpr bn::string_view info_text_lines[] = {
            "PAD: move",
            "",
            "START: go to next scene"};
        common::info info("Second Scene", info_text_lines, text_generator);
        info.update();

        // Sprites
        bn::sprite_ptr dino_sprite = bn::sprite_items::dino.create_sprite(20, 10);
        bn::sprite_ptr cat_sprite = bn::sprite_items::cat.create_sprite(0, 0);
        bn::sprite_ptr ninja_sprite = bn::sprite_items::ninja.create_sprite(0, 0);

        // Backgrounds
        bn::regular_bg_ptr simple_bg = bn::regular_bg_items::simple_bg.create_bg(0, 0);
        // Generate map for collisions
        const bn::regular_bg_map_item &map_item = bn::regular_bg_items::simple_bg.map_item();
        bn::size s = map_item.dimensions();
        BN_LOG("Dimension: ", s.height(), "x", s.width());
        for (int i = 0; i < s.width(); i++)
        {
            for (int j = 0; j < s.height(); j++)
            {
                bn::point p(i, j);
                bn::regular_bg_map_cell map_cell = map_item.cell(p);
                int tile_index = bn::regular_bg_map_cell_info(map_cell).tile_index();
                BN_LOG(tile_index);
            }
        }

        bn::regular_bg_ptr clouds_bg = bn::regular_bg_items::clouds.create_bg(0, 0);
        bn::blending::set_transparency_alpha(0.1);
        clouds_bg.set_blending_enabled(true);

        // Animations
        bn::sprite_animate_action<4> action = bn::create_sprite_animate_action_forever(
            ninja_sprite, 16, bn::sprite_items::ninja.tiles_item(), 0, 1, 2, 3);

        // Create outside window
        bn::regular_bg_ptr cats_intro = bn::regular_bg_items::cats_intro.create_bg(8, 48);
        bn::window outside_window = bn::window::outside();
        outside_window.set_show_bg(cats_intro, false);

        // Create window
        bn::rect_window internal_window = bn::rect_window::internal();
        internal_window.set_boundaries(-48, -96, 48, 96);
        internal_window.set_visible(false);
        BN_LOG("Window created");

        // Set camera
        cat_sprite.set_camera(camera);
        dino_sprite.set_camera(camera);
        ninja_sprite.set_camera(camera);
        simple_bg.set_camera(camera);
        clouds_bg.set_camera(camera);

        while (!bn::keypad::start_pressed())
        {
            // Handle animations
            /*if(bn::keypad::left_held())
            {
                ninja_sprite.set_tiles(bn::sprite_items::ninja.tiles_item().create_tiles(8));
            }*/
            if (bn::keypad::left_pressed())
            {
                action = bn::create_sprite_animate_action_forever(
                    ninja_sprite, 16, bn::sprite_items::ninja.tiles_item(), 8, 9, 10, 11);
            }
            else if (bn::keypad::right_pressed())
            {
                action = bn::create_sprite_animate_action_forever(
                    ninja_sprite, 16, bn::sprite_items::ninja.tiles_item(), 12, 13, 14, 15);
            }

            if (bn::keypad::up_pressed())
            {
                action = bn::create_sprite_animate_action_forever(
                    ninja_sprite, 16, bn::sprite_items::ninja.tiles_item(), 4, 5, 6, 7);
            }
            else if (bn::keypad::down_pressed())
            {
                action = bn::create_sprite_animate_action_forever(
                    ninja_sprite, 16, bn::sprite_items::ninja.tiles_item(), 0, 1, 2, 3);
            }

            action.update();

            // Handle movement
            if (bn::keypad::left_held())
            {
                cat_map_position.set_x(cat_map_position.x() - 1);
                cat_sprite.set_horizontal_flip(true);
                BN_LOG("Map pos: ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());
            }
            else if (bn::keypad::right_held())
            {
                cat_map_position.set_x(cat_map_position.x() + 1);
                cat_sprite.set_horizontal_flip(false);
                BN_LOG("Pos: ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());
                // Check collider map 256x256 pixels, 32x32 tiles
                bn::point p(cat_map_position.x() / 8, cat_map_position.y() / 8);
                BN_LOG("Map pos: ", " X:", p.x(), " Y:", p.y());
                bn::regular_bg_map_cell map_cell = map_item.cell(p);
                int tile_index = bn::regular_bg_map_cell_info(map_cell).tile_index();
                BN_LOG(tile_index);
            }

            if (bn::keypad::up_held())
            {
                cat_map_position.set_y(cat_map_position.y() - 1);
                BN_LOG("Map pos: ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());
            }
            else if (bn::keypad::down_held())
            {
                cat_map_position.set_y(cat_map_position.y() + 1);
                BN_LOG("Map pos: ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());
            }

            // Limits
            if (cat_map_position.x() < 0)
            {
                cat_map_position.set_x(0);
            }
            if (cat_map_position.x() > simple_bg.dimensions().width())
            {
                cat_map_position.set_x(simple_bg.dimensions().width());
            }

            // Update position
            cat_sprite.set_position(cat_map_position.x(), cat_map_position.y());

            if (bn::keypad::b_pressed())
            {
                BN_LOG("Map pos (Gravity): ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());
                BN_LOG("Cat pos: ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());
            }
            // For Backgrounds
            // simple_bg.set_priority(2);
            clouds_bg.set_priority(0);
            // For sprites
            cat_sprite.set_z_order(0);
            dino_sprite.set_z_order(1);
            ninja_sprite.set_z_order(1);

            if (bn::keypad::a_pressed())
            {
                BN_LOG("Toogle window");
                internal_window.set_visible(!internal_window.visible());
            }

            // Animate cloud
            clouds_bg.set_position(clouds_bg.x() + 0.1, clouds_bg.y() + 0.1);

            // Update camera pos
            camera.set_position(cat_map_position.x(), cat_map_position.y());

            bn::core::update();
        }
        camera.set_position(0, 0);
    }
}