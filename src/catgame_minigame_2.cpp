#include "catgame_minigame_2.h"
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
#include "bn_sprites_actions.h"
#include "bn_sprite_actions.h"
#include "catgame_food.h"

// Backgrounds
#include "bn_regular_bg_items_minigame2.h"
#include "bn_regular_bg_items_dialog.h"

// Sprites
#include "bn_sprite_items_cat.h"
#include "bn_sprite_items_heart_icon.h"
#include "bn_sprite_items_empty_heart_icon.h"
#include "bn_sprite_items_fish.h"
#include "bn_sprite_items_cat_hand_icon.h"
#include "bn_sprite_items_time_icon.h"
#include "bn_sprite_items_a_icon.h"
#include "bn_sprite_items_time_hands_icon.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

namespace catgame
{
    minigame_2::minigame_2() {}
    catgame::game_phases minigame_2::execute(bn::sprite_text_generator &text_generator, int &times_played, int &cur_food, int &stamina)
    {
        bn::backdrop::set_color(bn::color(0, 0, 0));
        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
        // Set current scene
        current_game_phase = catgame::game_phases::LVL1;
        next_game_phase = catgame::game_phases::LVL1;

        // Backgrounds
        bn::regular_bg_ptr ground = bn::regular_bg_items::minigame2.create_bg(256, 256+27); // Center
        ground.set_priority(3);

        // Sprites
        bn::sprite_ptr cat_sprite = bn::sprite_items::cat.create_sprite(bn::point(0, 40));
        bn::sprite_animate_action<2> player_action = bn::create_sprite_animate_action_forever(
            cat_sprite, 16, bn::sprite_items::cat.tiles_item(), 0, 1);
        cat_sprite.set_bg_priority(1);

        // Dialog
        bn::regular_bg_ptr dialog = bn::regular_bg_items::dialog.create_bg(264, 146);
        dialog.set_priority(0);
        bn::sprite_ptr a_button = bn::sprite_items::a_icon.create_sprite(bn::point(45 + 53, 60));
        bn::sprite_animate_action<2> a_button_action = bn::create_sprite_animate_action_forever(
            a_button, 32, bn::sprite_items::a_icon.tiles_item(), 0, 1);
        a_button.set_bg_priority(0);
        bn::sprite_ptr energy_icon = bn::sprite_items::fish.create_sprite(bn::point(0, 0));
        bn::sprite_scale_loop_action energy_action(energy_icon, 60, 2);
        energy_icon.set_bg_priority(0);
        energy_icon.set_visible(false);
        // Show text
        text_generator.set_bg_priority(0);
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        bool end = false;
        bool scored = false;
        bn::fixed _stamina = stamina;
        bn::fixed time = 0;
        int counter = 0;
        int goal = 5;
        int instructions = 0;

        bool started = false;

        // GUI
        bn::sprite_ptr empty_hearth_1 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(-74, -67));
        bn::sprite_ptr hearth_1 = bn::sprite_items::heart_icon.create_sprite(bn::point(-72, -67));
        bn::fixed stamina_scale = 2;
        empty_hearth_1.set_horizontal_scale(stamina_scale);
        hearth_1.set_horizontal_scale(stamina_scale);
        bn::sprite_ptr start_hearth = bn::sprite_items::cat_hand_icon.create_sprite(bn::point(-103, -67));

        bn::sprite_ptr empty_time_1 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(79 - 16, -67));
        bn::sprite_ptr time_1 = bn::sprite_items::heart_icon.create_sprite(bn::point(79 - 15, -67));
        bn::fixed scale = 2;
        time_1.set_horizontal_scale(scale);
        empty_time_1.set_horizontal_scale(scale);
        bn::sprite_ptr start_time = bn::sprite_items::time_icon.create_sprite(bn::point(103, -67));
        bn::sprite_ptr start_time_hands = bn::sprite_items::time_hands_icon.create_sprite(bn::point(103, -67));
        bn::sprite_rotate_loop_action rotate_action(start_time_hands, 60, 360);

        // Create enemies
        bn::vector<food, 3> foods = {};
        foods.push_back(food(camera));
        foods.push_back(food(camera));
        foods.push_back(food(camera));

        while (!end)
        {
            if (instructions < 3)
            {
                if (instructions == 0)
                {
                    text_sprites.clear();
                    text_generator.set_center_alignment();
                    text_generator.generate(0, 35, "INSTRUCTIONS!", text_sprites);
                    text_generator.set_left_alignment();
                    text_generator.generate(-106, 45, "Use arrows to move and catch", text_sprites);
                    text_generator.generate(-106, 55, "fish.", text_sprites);
                }
                else if (instructions == 1)
                {
                    text_sprites.clear();
                    text_generator.set_left_alignment();
                    text_generator.generate(-106, 35, "Don't let fish fall to ground", text_sprites);
                    text_generator.generate(-106, 45, "or you'll lose.", text_sprites);
                    text_generator.generate(-106, 55, "Try to get at least " + bn::to_string<32>(goal) + ".", text_sprites);
                }
                else if (instructions == 2)
                {
                    a_button.set_visible(false);
                    text_sprites.clear();
                    text_generator.set_center_alignment();
                    text_generator.generate(0, 35, "Press arrows to start", text_sprites);
                    text_generator.generate(0, 50, "START CATCHING!", text_sprites);
                }
                if (bn::keypad::a_pressed())
                {
                    instructions++;
                }
            }
            else
            {
                if (bn::keypad::left_pressed() || bn::keypad::right_pressed())
                {
                    started = true;
                    a_button.set_visible(false);
                }
            }
            // Hearts
            if (_stamina >= 0)
            {
                stamina_scale = (2 * _stamina) / 100;
                if (stamina_scale <= 0)
                {
                    stamina_scale = 0.001;
                }
                if (_stamina <= 0)
                {
                    _stamina = 0.001;
                }
                hearth_1.set_horizontal_scale(stamina_scale);
                hearth_1.set_x((0.14 * (_stamina - 100)) - 77);
            }

            if (started)
            {
                rotate_action.update();
                time += 0.1;
                dialog.set_visible(false);
                text_sprites.clear();
                text_generator.set_left_alignment();
                text_generator.generate(-106, -50, "Lost: " + bn::to_string<32>(counter), text_sprites);

                if (scale > 0.05)
                {
                    scale -= 0.003;
                }
                time_1.set_horizontal_scale(scale);
                time_1.set_x(time_1.position().x() + 0.05);

                if (time > 60)
                {
                    end = true;
                }

                if (_stamina > 0)
                {
                    // Animate face
                    if (bn::keypad::left_pressed())
                    {
                        cat_sprite.set_horizontal_flip(true);
                    }
                    if (bn::keypad::right_pressed())
                    {
                        cat_sprite.set_horizontal_flip(false);
                    }

                    if (bn::keypad::left_held())
                    {
                        if(cat_sprite.x() > -110){
                            _stamina -= 0.2f;
                            cat_sprite.set_x(cat_sprite.x() - 1);
                        }
                    }

                    if (bn::keypad::right_held())
                    {
                        if(cat_sprite.x() < 110){
                            _stamina -= 0.2f;
                            cat_sprite.set_x(cat_sprite.x() + 1);
                        }
                    }
                }
                else
                {
                    // Animate sweat/tired
                    // Animate face
                }
                if (_stamina < stamina)
                {
                    _stamina += 0.1f;
                }

                for (food &f : foods)
                {
                    if (f.near_player(cat_sprite.position()))
                    {
                        counter++;
                    }
                    f.update();
                }
            }

            if (a_button.visible())
            {
                a_button_action.update();
            }
            player_action.update();
            bn::core::update();
        }

        while (end && !bn::keypad::a_pressed())
        {
            a_button.set_visible(true);

            text_sprites.clear();

            dialog.set_visible(true);
            text_generator.set_left_alignment();
            text_generator.generate(-106, 35, "You catch " + bn::to_string<32>(counter) + " fish...", text_sprites);
            if (counter > goal)
            {
                if (!scored)
                {
                    scored = true;
                    cur_food = 4;
                    if (stamina > 100)
                    {
                        stamina = 100;
                    }
                }
                energy_icon.set_visible(true);
                energy_action.update();
                text_generator.generate(-106, 45, "You are full of food.", text_sprites);
                bn::sprite_animate_action<2> _action = bn::create_sprite_animate_action_forever(
                    energy_icon, 32, bn::sprite_items::fish.tiles_item(), 2, 2);
                _action.update();
            }
            else
            {
                text_generator.generate(-106, 45, "Try again later.", text_sprites);
                energy_action.update();
                energy_icon.set_visible(true);
                bn::sprite_animate_action<2> _action = bn::create_sprite_animate_action_forever(
                    energy_icon, 32, bn::sprite_items::fish.tiles_item(), 0, 0);
                _action.update();
            }

            bn::core::update();
        }
        cur_food--;
        times_played++;

        return next_game_phase;
    }
}