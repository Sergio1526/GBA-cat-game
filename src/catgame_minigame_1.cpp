#include "catgame_minigame_1.h"
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
#include "bn_sprite_items_collider.h"

// Backgrounds
#include "bn_regular_bg_items_minigame1.h"
#include "bn_regular_bg_items_dialog.h"

// Sprites
#include "bn_sprite_items_cat_hand.h"
#include "bn_sprite_items_heart_icon.h"
#include "bn_sprite_items_empty_heart_icon.h"
#include "bn_sprite_items_cat_hand_icon.h"
#include "bn_sprite_items_time_icon.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

namespace catgame
{
    minigame_1::minigame_1() {}
    catgame::game_phases minigame_1::execute(bn::sprite_text_generator &text_generator, int &times_played, int &food, int &stamina)
    {
        bn::backdrop::set_color(bn::color(0, 0, 0));
        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
        // Set current scene
        current_game_phase = catgame::game_phases::LVL1;
        next_game_phase = catgame::game_phases::GYM;

        // Backgrounds
        bn::regular_bg_ptr ground = bn::regular_bg_items::minigame1.create_bg(256, 256); // Center
        ground.set_priority(3);

        // Sprites
        bn::sprite_ptr left_hand = bn::sprite_items::cat_hand.create_sprite(bn::point(-26, 30));
        left_hand.set_bg_priority(1);
        bn::sprite_ptr right_hand = bn::sprite_items::cat_hand.create_sprite(bn::point(35, 30));
        right_hand.set_bg_priority(1);
        right_hand.set_horizontal_flip(true);

        // Dialog
        bn::regular_bg_ptr dialog = bn::regular_bg_items::dialog.create_bg(264, 146);
        dialog.set_priority(0);
        // Show text
        text_generator.set_bg_priority(0);
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        bool end = false;
        bool scored = false;
        bn::fixed _stamina = stamina;
        bn::fixed time = 0;
        int counter = 0;
        int goal = 30;

        bool started = false;

        text_sprites.clear();
        text_generator.set_center_alignment();
        text_generator.generate(0, 37, "START PUSHING!", text_sprites);
        text_generator.set_left_alignment();
        text_generator.generate(-106, 47, "Try to get " + bn::to_string<32>(goal) + " push ups", text_sprites);
        text_generator.generate(-106, 57, "You must stop to recover stamina", text_sprites);

        // GUI
        bn::sprite_ptr empty_hearth_1 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(-87, -67));
        bn::sprite_ptr empty_hearth_2 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(-71, -67));
        bn::sprite_ptr empty_hearth_3 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(-55, -67));
        bn::sprite_ptr empty_hearth_4 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(-39, -67));
        bn::sprite_ptr empty_hearth_5 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(-23, -67));
        bn::sprite_ptr hearth_1 = bn::sprite_items::heart_icon.create_sprite(bn::point(-87, -67));
        bn::sprite_ptr hearth_2 = bn::sprite_items::heart_icon.create_sprite(bn::point(-71, -67));
        bn::sprite_ptr hearth_3 = bn::sprite_items::heart_icon.create_sprite(bn::point(-55, -67));
        bn::sprite_ptr hearth_4 = bn::sprite_items::heart_icon.create_sprite(bn::point(-39, -67));
        bn::sprite_ptr hearth_5 = bn::sprite_items::heart_icon.create_sprite(bn::point(-23, -67));
        bn::sprite_ptr start_hearth = bn::sprite_items::cat_hand_icon.create_sprite(bn::point(-103, -67));

        bn::sprite_ptr empty_time_1 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(79, -67));
        bn::sprite_ptr empty_time_2 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(63, -67));
        bn::sprite_ptr empty_time_3 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(47, -67));
        bn::sprite_ptr empty_time_4 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(31, -67));
        bn::sprite_ptr empty_time_5 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(15, -67));
        bn::sprite_ptr time_1 = bn::sprite_items::heart_icon.create_sprite(bn::point(79, -67));
        bn::sprite_ptr time_2 = bn::sprite_items::heart_icon.create_sprite(bn::point(63, -67));
        bn::sprite_ptr time_3 = bn::sprite_items::heart_icon.create_sprite(bn::point(47, -67));
        bn::sprite_ptr time_4 = bn::sprite_items::heart_icon.create_sprite(bn::point(31, -67));
        bn::sprite_ptr time_5 = bn::sprite_items::heart_icon.create_sprite(bn::point(15, -67));
        bn::sprite_ptr start_time = bn::sprite_items::time_icon.create_sprite(bn::point(103, -67));

        while (!end)
        {
            // Hearts
            hearth_1.set_visible(true);
            hearth_2.set_visible(true);
            hearth_3.set_visible(true);
            hearth_4.set_visible(true);
            hearth_5.set_visible(true);
            if (_stamina <= 0)
            {
                hearth_1.set_visible(false);
            }
            if (_stamina <= 20)
            {
                hearth_2.set_visible(false);
            }
            if (_stamina <= 40)
            {
                hearth_3.set_visible(false);
            }
            if (_stamina <= 60)
            {
                hearth_4.set_visible(false);
            }
            if (_stamina <= 80)
            {
                hearth_5.set_visible(false);
            }

            if (started)
            {
                time += 0.1f;
                dialog.set_visible(false);
                text_sprites.clear();
                text_generator.generate(-106, 60, "Time: " + bn::to_string<32>(time), text_sprites);
                text_generator.generate(-106, 70, "Stamina: " + bn::to_string<32>(_stamina), text_sprites);
                text_generator.generate(-106, -60, "Push ups: " + bn::to_string<32>(counter), text_sprites);
            }

            if (time > 60)
            {
                end = true;
            }

            if (_stamina > 0)
            {
                // Animate face
                if (bn::keypad::l_pressed())
                {
                    counter += 1;
                }
                if (bn::keypad::r_pressed())
                {
                    counter += 1;
                }

                if (bn::keypad::l_held())
                {
                    started = true;
                    _stamina -= 0.5f;
                    left_hand.set_position(left_hand.position().x(), 20);
                }
                else if (bn::keypad::l_released())
                {
                    left_hand.set_position(left_hand.position().x(), 30);
                }

                if (bn::keypad::r_held())
                {
                    started = true;
                    _stamina -= 0.5f;
                    right_hand.set_position(right_hand.position().x(), 20);
                }
                else if (bn::keypad::r_released())
                {
                    right_hand.set_position(right_hand.position().x(), 30);
                }
            }
            else
            {
                // Animate sweat/tired
                // Animate face
                left_hand.set_position(left_hand.position().x(), 30);
                right_hand.set_position(right_hand.position().x(), 30);
            }
            if (_stamina < stamina)
            {
                _stamina += 0.1f;
            }
            bn::core::update();
        }

        while (end && !bn::keypad::a_pressed())
        {
            text_sprites.clear();

            dialog.set_visible(true);
            text_generator.generate(-106, 47, "You did " + bn::to_string<32>(counter) + " push ups...", text_sprites);
            if (counter > 29)
            {
                if (!scored)
                {
                    scored = true;
                    stamina += 20;
                }
                text_generator.generate(-106, 57, "Your life has increased!", text_sprites);
            }
            else
            {
                text_generator.generate(-106, 57, "Try again later.", text_sprites);
            }

            bn::core::update();
        }

        food -= 1;
        times_played++;

        return next_game_phase;
    }
}