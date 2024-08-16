#include "catgame_lvl_gym.h"
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
#include "bn_regular_bg_items_gym_bg.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_items_dialog.h"

// Sprites
#include "bn_sprite_items_limit.h"
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
    lvl_gym::lvl_gym() {}
    catgame::game_phases lvl_gym::execute(bn::sprite_text_generator &text_generator, int &times_played, int &food, int &stamina)
    {
        bn::backdrop::set_color(bn::color(0, 0, 0));
        bn::camera_ptr camera = bn::camera_ptr::create(0, 0);
        // Set current scene
        current_game_phase = catgame::game_phases::LVL1;
        next_game_phase = catgame::game_phases::LVL1;

        // Show text
        text_generator.set_center_alignment();
        bn::vector<bn::sprite_ptr, 32> text_sprites;

        // Sprites

        // Backgrounds
        bn::regular_bg_ptr ground = bn::regular_bg_items::gym_bg.create_bg(256, 256); // Center
        // Generate map for collisions
        const bn::regular_bg_map_item &map_item = bn::regular_bg_items::gym_bg.map_item();

        // Set player at middle of the map
        int map_collider_index = 3;

        // Create player
        catgame::player _player = player(camera, bn::point(138, 250), map_collider_index);

        // Create enemies
        bn::vector<enemy, 5> enemies = {};
        enemies.push_back(enemy(camera, bn::point(100, 100), _player.sprite(), map_collider_index, "Hello my fellow cat"));
        enemies.push_back(enemy(camera, bn::point(150, 90), _player.sprite(), map_collider_index, "..."));
        enemies.push_back(enemy(camera, bn::point(240, 120), _player.sprite(), map_collider_index, "Don't forget to eat sometimes"));
        enemies.push_back(enemy(camera, bn::point(250, 120), _player.sprite(), map_collider_index, "It's a nicve day!"));
        enemies.push_back(enemy(camera, bn::point(230, 120), _player.sprite(), map_collider_index, "You look stronger >.<"));

        // Create triggers
        catgame::trigger gym_door = trigger(camera, bn::point(140, 188));
        catgame::trigger minigame_1 = trigger(camera, bn::point(204, 312));

        // Set camera
        ground.set_camera(camera);

        // GUI
        bn::sprite_ptr empty_hearth_1 = bn::sprite_items::empty_heart_icon.create_sprite(bn::point(-74, -67));
        bn::sprite_ptr hearth_1 = bn::sprite_items::heart_icon.create_sprite(bn::point(-72, -67));
        bn::fixed stamina_scale = 2;
        empty_hearth_1.set_horizontal_scale(stamina_scale);
        hearth_1.set_horizontal_scale(stamina_scale);
        bn::sprite_ptr start_hearth = bn::sprite_items::cat_hand_icon.create_sprite(bn::point(-103, -67));
        // Food
        bn::sprite_ptr fish = bn::sprite_items::fish_icon.create_sprite(bn::point(10 + 92, 30 - 94));
        bn::sprite_animate_action<2> action = bn::create_sprite_animate_action_forever(
            fish, 32, bn::sprite_items::fish_icon.tiles_item(), 2, 2);

        while (!_player.dead())
        {
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
            text_generator.generate(0, -70, bn::to_string<32>(_player.health()), text_sprites);
            text_generator.generate(0, -50, bn::to_string<32>(_player.map_cell(map_item)), text_sprites);

            for (enemy &enemy : enemies)
            {
                if (enemy.near_player(_player.position()))
                {
                    //_player.hurt(1);
                }
                enemy.update(map_item);
            }

            _player.update(map_item);
            _player.animate();

            if (gym_door.near_player(_player.position()))
            {
                next_game_phase = catgame::game_phases::MINIGAME1;
                break;
            }
            if (minigame_1.near_player(_player.position()))
            {
                next_game_phase = catgame::game_phases::LVL1;
                break;
            }

            // Update camera pos
            camera.set_position(_player.position());

            bn::core::update();
        }
        return next_game_phase;
    }
}