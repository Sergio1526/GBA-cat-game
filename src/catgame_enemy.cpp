#include "catgame_enemy.h"
#include "bn_camera_ptr.h"
#include "bn_point.h"
#include "bn_keypad.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_items_dino.h"
#include "bn_sprite_items_ninja.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_log.h" //Remove on final version
#include "bn_math.h"
#include "bn_size.h"

namespace catgame
{
    enemy::enemy(bn::camera_ptr camera, bn::point pos, bn::sprite_ptr player_sprite)
    {
        _sprite = bn::sprite_items::ninja.create_sprite(pos);
        _sprite.value().set_camera(camera);
        _sprite.value().set_z_order(1);
        _action = bn::create_sprite_animate_action_forever(
            _sprite.value(), 16, bn::sprite_items::ninja.tiles_item(), 0, 1, 2, 3);
        enemy::set_view_distance(player_sprite);
    }
    bool enemy::near_player(bn::fixed_point player_pos)
    {
        bn::fixed dist_x = bn::abs(player_pos.x() - _sprite.value().position().x());
        bn::fixed dist_y = bn::abs(player_pos.y() - _sprite.value().position().y());
        if (dist_x < _view_distance)
        {
            if (dist_y < _view_distance)
            {
                _is_near_player = true;
                return true;
            }
        }
        _is_near_player = false;
        return false;
    }
    void enemy::set_view_distance(bn::sprite_ptr player_sprite)
    {
        _view_distance = _sprite.value().dimensions().width() + _view_distance;
    }
    void enemy::update()
    {
        if (_is_near_player)
        {
            _sprite.value().set_position(_sprite.value().position().x(), _sprite.value().position().y() + _velocity);
        }
        /*if (bn::keypad::a_pressed())
        {
            BN_LOG("Im an enemy! ", _mov_count);
        }*/
        if (_action.has_value() && !_action.value().done())
        {
            _action.value().update();
        }
    }
}