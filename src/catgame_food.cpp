#include "catgame_food.h"
#include "bn_camera_ptr.h"
#include "bn_point.h"
#include "bn_keypad.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_items_fish.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_log.h" //Remove on final version
#include "bn_math.h"
#include "bn_size.h"
#include "bn_string_view.h"
#include "bn_random.h"

namespace catgame
{
    bn::random random_food = bn::random();
    bn::fixed speed;
    food::food(bn::camera_ptr camera)
    {
        bn::point new_position = bn::point(random_food.get_int(-100, 100), -85);
        _sprite = bn::sprite_items::fish.create_sprite(new_position);
        speed = random_food.get_fixed(0, 2);
        _sprite.value().set_camera(camera);
        _sprite.value().set_z_order(2);
        _action = bn::create_sprite_animate_action_forever(
            _sprite.value(), 32, bn::sprite_items::fish.tiles_item(), 2, 2);
    }
    bool food::near_player(bn::fixed_point player_pos)
    {
        bn::fixed dist_x = bn::abs(player_pos.x() - _sprite.value().position().x());
        bn::fixed dist_y = bn::abs(player_pos.y() - _sprite.value().position().y());
        if (dist_x < 32 && dist_y < 16)
        {
            _is_near_player = true;
            return _is_near_player;
        }
        _is_near_player = false;
        return _is_near_player;
    }
    void food::update()
    {
        if (_is_near_player)
        {
            bn::point new_position = bn::point(random_food.get_int(-100, 100), -85);
            _sprite.value().set_position(new_position);
        }
        // AI
        else
        {
            _sprite.value().set_position(_sprite.value().position().x(), _sprite.value().position().y() + (speed));
            if (_sprite.value().position().y() > 85)
            {
                speed = random_food.get_fixed(0, 2);
                bn::point new_position = bn::point(random_food.get_int(-100, 100), -85);
                _sprite.value().set_position(new_position);
            }
        }

        if (_action.has_value())
        {
            _action.value().update();
        }
    }
}