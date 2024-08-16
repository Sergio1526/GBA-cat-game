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
#include "bn_regular_bg_items_simple_1_bg.h"
#include "bn_regular_bg_items_clouds.h"
#include "bn_regular_bg_items_dialog.h"
#include "bn_regular_bg_map_ptr.h"

// Sprites
#include "bn_sprite_items_gym.h"
#include "bn_sprite_items_construction.h"
#include "bn_sprite_items_fish_icon.h"
#include "bn_sprite_items_heart_icon.h"
#include "bn_sprite_items_empty_heart_icon.h"
#include "bn_sprite_items_cat_hand_icon.h"
#include "bn_sprite_items_flower.h"
#include "bn_sprite_items_fish_icon.h"
#include "bn_sprite_items_gym_sign.h"
#include "bn_sprite_items_restaurant_sign.h"

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
        bn::regular_bg_ptr fog = bn::regular_bg_items::simple_1_bg.create_bg(256, 256); // Center
        // Generate map for collisions
        const bn::regular_bg_map_item &map_item = bn::regular_bg_items::simple_bg.map_item();

        // Set sprites
        bn::sprite_ptr gym_sprite = bn::sprite_items::gym.create_sprite(bn::point(192, 97));
        bn::sprite_ptr gym_sprite_sign = bn::sprite_items::gym_sign.create_sprite(bn::point(192, 87));
        bn::sprite_ptr house_sprite = bn::sprite_items::gym.create_sprite(bn::point(150 - 28 - 19 + 2, 200 + 2));
        bn::sprite_ptr house_sprite2 = bn::sprite_items::gym.create_sprite(bn::point(150 - 28 - 19 + 42 - 1, 282));
        bn::sprite_ptr restaurant_sprite = bn::sprite_items::gym.create_sprite(bn::point(288, 282));
        bn::sprite_ptr restaurant_sprite_sign = bn::sprite_items::restaurant_sign.create_sprite(bn::point(288, 272));
        gym_sprite.set_z_order(0);
        gym_sprite_sign.set_z_order(0);
        house_sprite.set_z_order(0);
        house_sprite2.set_z_order(0);
        restaurant_sprite.set_z_order(0);
        restaurant_sprite_sign.set_z_order(0);
        bn::sprite_ptr under_construction_sprite = bn::sprite_items::construction.create_sprite(bn::point(100, 227));
        under_construction_sprite.set_z_order(1);
        bn::sprite_ptr under_construction_sprite2 = bn::sprite_items::construction.create_sprite(bn::point(142, 240 + 67));
        under_construction_sprite2.set_z_order(1);

        bn::sprite_ptr flower_sprite = bn::sprite_items::flower.create_sprite(bn::point(192+69, 132));
        bn::sprite_animate_action<4> flower_action = bn::create_sprite_animate_action_forever(
            flower_sprite, 8, bn::sprite_items::flower.tiles_item(), 0, 0, 1, 0);
        flower_sprite.set_z_order(1);
        flower_sprite.set_camera(camera);

        // Dialog
        bn::regular_bg_ptr dialog = bn::regular_bg_items::dialog.create_bg(264, 146);
        dialog.set_priority(0);
        // Show text
        text_generator.set_bg_priority(0);
        text_generator.set_center_alignment();
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        // GUI
        bn::sprite_ptr empty_hearth_1 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(-74, -67));
        bn::sprite_ptr hearth_1 = bn::sprite_items::heart_icon.create_sprite(bn::point(-72, -67));
        empty_hearth_1.set_horizontal_scale(2);
        hearth_1.set_horizontal_scale(2);
        empty_hearth_1.set_z_order(0);
        hearth_1.set_z_order(0);
        empty_hearth_1.set_bg_priority(0);
        hearth_1.set_bg_priority(0);

        bn::sprite_ptr start_hearth = bn::sprite_items::cat_hand_icon.create_sprite(bn::point(-103, -67));
        // Food
        bn::sprite_ptr fish = bn::sprite_items::fish_icon.create_sprite(bn::point(10 + 92, 30 - 94));
        bn::sprite_animate_action<2> action = bn::create_sprite_animate_action_forever(
            fish, 32, bn::sprite_items::fish_icon.tiles_item(), 2, 2);
        start_hearth.set_z_order(0);
        fish.set_z_order(0);
        start_hearth.set_bg_priority(0);
        fish.set_bg_priority(0);

        bn::regular_bg_ptr clouds_bg = bn::regular_bg_items::clouds.create_bg(0, 0);

        int map_collider_index = 11;

        // Create player
        catgame::player _player = player(camera, bn::point(320, 115), map_collider_index);

        // Create enemies
        bn::vector<enemy, 3> enemies = {};
        enemies.push_back(enemy(camera, bn::point(100, 80), _player.sprite(), map_collider_index, "Meow?"));
        enemies.push_back(enemy(camera, bn::point(150, 250), _player.sprite(), map_collider_index, "Where is the restaurant?"));
        enemies.push_back(enemy(camera, bn::point(230, 120), _player.sprite(), map_collider_index, "Nice to meet you"));

        // Create triggers
        catgame::trigger gym_door = trigger(camera, bn::point(196, 97 + 16), true);
        catgame::trigger restaurant_door = trigger(camera, bn::point(293, 296), true);

        // Set camera
        ground.set_camera(camera);
        fog.set_camera(camera);
        clouds_bg.set_camera(camera);
        gym_sprite.set_camera(camera);
        gym_sprite_sign.set_camera(camera);
        restaurant_sprite.set_camera(camera);
        restaurant_sprite_sign.set_camera(camera);
        house_sprite.set_camera(camera);
        house_sprite2.set_camera(camera);
        under_construction_sprite.set_camera(camera);
        under_construction_sprite2.set_camera(camera);

        // For Backgrounds
        fog.set_priority(2);
        //bn::blending::set_transparency_alpha(0.1);
        //fog.set_blending_enabled(true);
        clouds_bg.set_priority(0);
        bn::blending::set_transparency_alpha(0.1);
        clouds_bg.set_blending_enabled(true);

        while (!_player.dead())
        {
            // Flowers
            if (flower_sprite.visible())
            {
                flower_action.update();
            }

            action.update();
            // Stamina
            if (stamina <= 0)
            {
                stamina = 0.001;
            }
            hearth_1.set_horizontal_scale((bn::fixed)(stamina * 2) / 100);
            hearth_1.set_x((0.14 * (stamina - 100)) - 77);
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
            // text_generator.set_center_alignment();
            // text_generator.generate(0, -70, bn::to_string<32>(_player.health()), text_sprites);
            // text_generator.generate(0, -60, bn::to_string<32>(_player.map_cell(map_item)), text_sprites);

            dialog.set_visible(false);
            for (enemy &enemy : enemies)
            {
                if (enemy.near_player(_player.position()))
                {
                    text_sprites.clear();
                    text_generator.set_left_alignment();
                    text_generator.generate(-106, 47, enemy.get_dialog(), text_sprites);
                    dialog.set_visible(true);
                }
                enemy.update(map_item);
            }

            _player.update(map_item);
            //_player.animate();

            if (gym_door.near_player(_player.position()))
            {
                next_game_phase = catgame::game_phases::GYM;
                break;
            }
            if (restaurant_door.near_player(_player.position()))
            {
                next_game_phase = catgame::game_phases::MINIGAME2;
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