#include "bn_core.h"
#include "bn_blending.h"
#include "bn_unique_ptr.h"
#include "bn_keypad.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_builder.h"           //Sprites tiled
#include "bn_sprite_animate_actions.h"   //Sprites animated
#include "bn_regular_bg_map_cell_info.h" //To create logical map
// #include "bn_display.h" //for windows
#include "bn_rect_window_boundaries_hbe_ptr.h"

#include "bn_log.h" //Remove on final version

// Assets
// Background
#include "bn_regular_bg_items_jam2024.h"
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

// My libraries

// Code
namespace
{
    bn::point cat_map_position(0, 0);

    void logo_scene()
    {
        BN_LOG("Logo scene");

        bn::regular_bg_ptr jam2024_bg = bn::regular_bg_items::jam2024.create_bg(8, 48);

        while (!bn::keypad::start_pressed())
        {
            bn::core::update();
        }
    }

    void first_scene()
    {
        BN_LOG("First scene");

        bn::regular_bg_ptr cats_intro = bn::regular_bg_items::cats_intro.create_bg(0, 10);

        while (!bn::keypad::start_pressed())
        {
            bn::core::update();
        }
    }

    void second_scene(bn::sprite_text_generator &text_generator)
    {
        BN_LOG("Second scene");

        // Show text
        constexpr bn::string_view info_text_lines[] = {
            "PAD: move",
            "",
            "START: go to next scene"};
        common::info info("Second Scene", info_text_lines, text_generator);
        info.update();

        //Sprites
        bn::sprite_ptr dino_sprite = bn::sprite_items::dino.create_sprite(20, 10);
        bn::sprite_ptr cat_sprite = bn::sprite_items::cat.create_sprite(0, 0);
        bn::sprite_ptr ninja_sprite = bn::sprite_items::ninja.create_sprite(0, 0);

        //Backgrounds
        bn::regular_bg_ptr simple_bg = bn::regular_bg_items::simple_bg.create_bg(0, 0);
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

        bn::rect_window internal_window = bn::rect_window::internal();
        internal_window.set_boundaries(-48, -96, 48, 96);

        BN_LOG("Window created");
        internal_window.set_visible(true);

        while (!bn::keypad::start_pressed())
        {
            // Handle animations
            /*if(bn::keypad::left_held())
            {
                ninja_sprite.set_tiles(bn::sprite_items::ninja.tiles_item().create_tiles(8));
            }
            else if(bn::keypad::right_held())
            {
                ninja_sprite.set_tiles(bn::sprite_items::ninja.tiles_item().create_tiles(12));
            }

            if(bn::keypad::up_held())
            {
                ninja_sprite.set_tiles(bn::sprite_items::ninja.tiles_item().create_tiles(4));
            }
            else if(bn::keypad::down_held())
            {
                ninja_sprite.set_tiles(bn::sprite_items::ninja.tiles_item().create_tiles(0));
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
            // if (bn::keypad::left_pressed())
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
                BN_LOG("Map pos: ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());
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
            if (cat_map_position.x() < -120)
            {
                cat_map_position.set_x(-120);
            }
            if (cat_map_position.x() > 120)
            {
                cat_map_position.set_x(120);
            }

            // Update position
            bn::fixed cat_sprite_x = cat_map_position.x();
            bn::fixed cat_sprite_y = cat_map_position.y();

            cat_sprite.set_position(cat_sprite_x, cat_sprite_y);

            if (bn::keypad::b_pressed())
            {
                BN_LOG("Map pos (Gravity): ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());
                BN_LOG("Cat pos: ", " X:", cat_sprite_x, " Y:", cat_sprite_y);
            }
            // For Backgrounds
            // cat_sprite.set_priority(1);
            // For sprites
            cat_sprite.set_z_order(1);

            if (bn::keypad::a_pressed())
            {
                BN_LOG("Should show window");
                internal_window.set_visible(!internal_window.visible());
            }

            // Animate cloud
            clouds_bg.set_position(clouds_bg.x() + 0.5, clouds_bg.y() + 0.5);

            bn::core::update();
        }
    }
}

int main()
{
    bn::core::init();

    // Initialize text generator
    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);

    // X (Left to Right), Y (Top to Bottom) Each tile 4x4

    while (true)
    {
        BN_LOG("Main cycle");

        logo_scene();
        bn::core::update();

        first_scene();
        bn::core::update();

        second_scene(text_generator);
        bn::core::update();
    }
}