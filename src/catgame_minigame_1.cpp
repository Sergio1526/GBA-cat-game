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
#include "bn_regular_bg_items_cat_body.h"

#include "bn_sprite_items_cat_hand.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

namespace catgame
{
    minigame_1::minigame_1() {}
    catgame::game_phases minigame_1::execute(bn::sprite_text_generator &text_generator)
    {
        bn::backdrop::set_color(bn::color(0, 0, 0));
        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
        // Set current scene
        current_game_phase = catgame::game_phases::LVL1;
        next_game_phase = catgame::game_phases::GYM;

        // Show text
        text_generator.set_center_alignment();
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        // Backgrounds
        bn::regular_bg_ptr ground = bn::regular_bg_items::minigame1.create_bg(256, 256); // Center
        bn::regular_bg_ptr cat = bn::regular_bg_items::cat_body.create_bg(256, 256);

        // Sprites
        bn::sprite_ptr left_hand = bn::sprite_items::cat_hand.create_sprite(bn::point(-26, 30));
        bn::sprite_ptr right_hand = bn::sprite_items::cat_hand.create_sprite(bn::point(35, 30));
        right_hand.set_horizontal_flip(true);

        bool end = false;
        bn::fixed stamina = 100;
        int strenght = 0;
        bn::fixed time = 0;
        int counter = 0;

        bool started = false;

        while (!end)
        {
            if(started){
                time += 0.1f;
            }

            if(time > 60 || stamina <= 0){
                end = true;
            }

            text_sprites.clear();
            text_generator.generate(0, -70, "START PUSHING!", text_sprites);
            text_generator.generate(0, -60, "Try to get 10 push ups", text_sprites);

            bn::string val = bn::to_string<32>(time);
            text_generator.generate(0, 60, "Time: " + val, text_sprites);

            bn::string val2 = bn::to_string<32>(stamina);
            text_generator.generate(0, 70, "Stamina: " + val2, text_sprites);

            if (bn::keypad::l_pressed())
            {
                counter += 1;
            }
            if (bn::keypad::r_pressed())
            {
                counter += 1;
            }
            BN_LOG("Count ", counter);

            if (bn::keypad::l_held())
            {
                started = true;
                stamina -= 0.3f;
                left_hand.set_position(left_hand.position().x(), 10);
            }
            else if (bn::keypad::l_released())
            {
                stamina += 0.1f;
                left_hand.set_position(left_hand.position().x(), 30);
            }

            if (bn::keypad::r_held())
            {
                started = true;
                stamina -= 0.3f;
                right_hand.set_position(right_hand.position().x(), 10);
            }
            else if (bn::keypad::r_released())
            {
                stamina += 0.1f;
                right_hand.set_position(right_hand.position().x(), 30);
            }

            bn::core::update();
        }
        return next_game_phase;
    }
}