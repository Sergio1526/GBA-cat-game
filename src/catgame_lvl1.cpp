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
#include "bn_sprite_items_collider.h"

// Backgrounds
#include "bn_regular_bg_items_simple_bg.h"
#include "bn_regular_bg_items_clouds.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_items_dialog.h"

// Sprites
#include "bn_sprite_items_gym.h"
#include "bn_sprite_items_construction.h"
#include "bn_sprite_items_fish_icon.h"
#include "bn_sprite_items_heart_icon.h"
#include "bn_sprite_items_empty_heart_icon.h"
#include "bn_sprite_items_cat_hand_icon.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "catgame_enemy.h"
#include "catgame_player.h"
#include "catgame_trigger.h"

namespace catgame
{
    lvl1::lvl1() {}
    catgame::game_phases lvl1::execute(bn::sprite_text_generator &text_generator, int &times_played, int &food, int &stamina)
    {
        bn::backdrop::set_color(bn::color(0, 0, 0));
        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
        // Set current scene
        current_game_phase = catgame::game_phases::LVL1;
        next_game_phase = catgame::game_phases::INTRO;

        // Backgrounds
        bn::regular_bg_ptr ground = bn::regular_bg_items::simple_bg.create_bg(256, 256); // Center
        // Generate map for collisions
        const bn::regular_bg_map_item &map_item = bn::regular_bg_items::simple_bg.map_item();

        // Set sprites
        bn::sprite_ptr gym_sprite = bn::sprite_items::gym.create_sprite(bn::point(192, 97));
        bn::sprite_ptr house_sprite = bn::sprite_items::gym.create_sprite(bn::point(150 - 28 - 19 + 1, 200));
        bn::sprite_ptr house_sprite2 = bn::sprite_items::gym.create_sprite(bn::point(150 - 28 - 19 + 40 + 1, 250 + 32));
        bn::sprite_ptr restaurant_sprite = bn::sprite_items::gym.create_sprite(bn::point(300 - 4 - 6 - 2, 280 + 2));
        gym_sprite.set_z_order(0);
        house_sprite.set_z_order(0);
        house_sprite2.set_z_order(0);
        restaurant_sprite.set_z_order(0);
        // bn::sprite_ptr under_construction_sprite = bn::sprite_items::construction.create_sprite(bn::point(100, 100));

        // Dialog
        bn::regular_bg_ptr dialog = bn::regular_bg_items::dialog.create_bg(264, 146);
        dialog.set_priority(0);
        // Show text
        text_generator.set_bg_priority(0);
        text_generator.set_center_alignment();
        bn::vector<bn::sprite_ptr, 32> text_sprites;

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
        // Food
        bn::sprite_ptr fish = bn::sprite_items::fish_icon.create_sprite(bn::point(10 + 92, 30 - 94));
        bn::sprite_animate_action<2> action = bn::create_sprite_animate_action_forever(
            fish, 32, bn::sprite_items::fish_icon.tiles_item(), 2, 2);

        bn::regular_bg_ptr clouds_bg = bn::regular_bg_items::clouds.create_bg(0, 0);
        bn::blending::set_transparency_alpha(0.1);
        clouds_bg.set_blending_enabled(true);

        int map_collider_index = 8;

        // Create player
        catgame::player _player = player(camera, bn::point(128, 128), map_collider_index);

        // Create enemies
        bn::vector<enemy, 3> enemies = {};
        enemies.push_back(enemy(camera, bn::point(100, 80), _player.sprite(), map_collider_index));
        enemies.push_back(enemy(camera, bn::point(150, 90), _player.sprite(), map_collider_index));
        enemies.push_back(enemy(camera, bn::point(250, 120), _player.sprite(), map_collider_index));

        // Create triggers
        catgame::trigger gym_door = trigger(camera, bn::point(192, 126));
        catgame::trigger restaurant_door = trigger(camera, bn::point(200 + 97, 200 + 115));

        // Set camera
        ground.set_camera(camera);
        clouds_bg.set_camera(camera);
        gym_sprite.set_camera(camera);
        restaurant_sprite.set_camera(camera);
        house_sprite.set_camera(camera);
        house_sprite2.set_camera(camera);
        // under_construction_sprite.set_camera(camera);

        // For Backgrounds
        clouds_bg.set_priority(0);

        while (!_player.dead())
        {
            action.update();
            // Hearts
            hearth_1.set_visible(true);
            hearth_2.set_visible(true);
            hearth_3.set_visible(true);
            hearth_4.set_visible(true);
            hearth_5.set_visible(true);
            if (stamina <= 0)
            {
                hearth_1.set_visible(false);
            }
            if (stamina <= 20)
            {
                hearth_2.set_visible(false);
            }
            if (stamina <= 40)
            {
                hearth_3.set_visible(false);
            }
            if (stamina <= 60)
            {
                hearth_4.set_visible(false);
            }
            if (stamina <= 80)
            {
                hearth_5.set_visible(false);
            }
            // Food
            if (food <= 1)
            {
                action = bn::create_sprite_animate_action_forever(
                    fish, 32, bn::sprite_items::fish_icon.tiles_item(), 0, 0);
            }
            else if (food <= 2)
            {
                action = bn::create_sprite_animate_action_forever(
                    fish, 32, bn::sprite_items::fish_icon.tiles_item(), 1, 1);
            }
            else if (food <= 3)
            {
                action = bn::create_sprite_animate_action_forever(
                    fish, 32, bn::sprite_items::fish_icon.tiles_item(), 2, 2);
            }

            text_sprites.clear();
            //text_generator.set_center_alignment();
            //text_generator.generate(0, -70, bn::to_string<32>(_player.health()), text_sprites);
            //text_generator.generate(0, -60, bn::to_string<32>(_player.map_cell(map_item)), text_sprites);

            dialog.set_visible(false);
            for (enemy &enemy : enemies)
            {
                if (enemy.near_player(_player.position()))
                {
                    //_player.hurt(1);
                    text_sprites.clear();
                    text_generator.set_left_alignment();
                    text_generator.generate(-106, 47, "Hello my friend.", text_sprites);
                    dialog.set_visible(true);
                }
                enemy.update(map_item);
            }

            _player.update(map_item);
            _player.animate();

            if (gym_door.near_player(_player.position()))
            {
                next_game_phase = catgame::game_phases::GYM;
                break;
            }

            // Animate cloud
            clouds_bg.set_position(clouds_bg.x() + 0.1, clouds_bg.y() + 0.1);

            // Update camera pos
            camera.set_position(_player.position());

            if (bn::keypad::b_pressed())
            {
                if (food > 1)
                {
                    food--;
                }
            }

            bn::core::update();
        }
        return next_game_phase;
    }
}