#include "bn_core.h"
#include "bn_blending.h"
#include "bn_unique_ptr.h"
#include "bn_keypad.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_builder.h"
#include "bn_regular_bg_map_cell_info.h" //To create logical map

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
    void logo_scene(bn::sprite_text_generator &text_generator)
    {
        BN_LOG("Logo scene");
        // Show text
        constexpr bn::string_view info_text_lines[] = {
            "START: go to next scene"};
        common::info info("First Scene", info_text_lines, text_generator);

        bn::regular_bg_ptr cats_intro = bn::regular_bg_items::cats_intro.create_bg(8, 48);

        while (!bn::keypad::start_pressed())
        {
            info.update();
            bn::core::update();
        }
    }

    void first_scene(bn::sprite_text_generator &text_generator)
    {
        BN_LOG("First scene");
        // Show text
        constexpr bn::string_view info_text_lines[] = {
            "START: go to next scene"};
        common::info info("First Scene", info_text_lines, text_generator);

        bn::regular_bg_ptr jam2024_bg = bn::regular_bg_items::jam2024.create_bg(8, 48);

        while (!bn::keypad::start_pressed())
        {
            info.update();
            bn::core::update();
        }
    }

    bn::point cat_map_position(0, 0);

    void second_scene(bn::sprite_text_generator &text_generator)
    {
        BN_LOG("Second scene");

        // Show text
        constexpr bn::string_view info_text_lines[] = {
            "PAD: move",
            "",
            "START: go to next scene"};
        common::info info("Second Scene", info_text_lines, text_generator);

        bn::sprite_ptr dino_sprite = bn::sprite_items::dino.create_sprite(20, 10);
        bn::sprite_ptr cat_sprite = bn::sprite_items::cat.create_sprite(0, 0);
        bn::sprite_ptr ninja_sprite = bn::sprite_items::ninja.create_sprite(0, 0);

        bn::regular_bg_ptr clouds_bg = bn::regular_bg_items::clouds.create_bg(0, 0);
        bn::blending::set_transparency_alpha(0.3);
        clouds_bg.set_blending_enabled(true);
        bn::regular_bg_ptr simple_bg = bn::regular_bg_items::simple_bg.create_bg(0, 0);

        while (!bn::keypad::start_pressed())
        {
            // Handle animations
            if(bn::keypad::left_held())
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
            }
            // Handle movement
            if (bn::keypad::left_pressed())
            {
                cat_map_position.set_x(cat_map_position.x() - 1);
                cat_sprite.set_horizontal_flip(true);
            }
            else if (bn::keypad::right_pressed())
            {
                cat_map_position.set_x(cat_map_position.x() + 1);
                cat_sprite.set_horizontal_flip(false);
            }

            if (bn::keypad::up_pressed())
            {
                cat_map_position.set_y(cat_map_position.y() - 1);
            }
            else if (bn::keypad::down_pressed())
            {
                cat_map_position.set_y(cat_map_position.y() + 1);
            }

            BN_LOG("Map pos: ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());

            // Limits
            if (cat_map_position.x() < -12)
            {
                cat_map_position.set_x(-12);
            }
            if (cat_map_position.x() > 12)
            {
                cat_map_position.set_x(12);
            }

            // Update position
            bn::fixed cat_sprite_x = (cat_map_position.x() * 8) + 4;
            bn::fixed cat_sprite_y = (cat_map_position.y() * 8) + 4;

            cat_sprite.set_position(cat_sprite_x, cat_sprite_y);

            BN_LOG("Map pos (Gravity): ", " X:", cat_map_position.x(), " Y:", cat_map_position.y());
            BN_LOG("Cat pos: ", " X:", cat_sprite_x, " Y:", cat_sprite_y);

            info.update();
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

        logo_scene(text_generator);
        bn::core::update();

        first_scene(text_generator);
        bn::core::update();

        second_scene(text_generator);
        bn::core::update();
    }
}