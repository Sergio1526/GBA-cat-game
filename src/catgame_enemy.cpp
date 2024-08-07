#include "catgame_enemy.h"
#include "bn_camera_ptr.h"
#include "bn_point.h"
#include "bn_keypad.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_items_ninja.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_cell_info.h"
#include "bn_random.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_log.h" //Remove on final version
#include "bn_math.h"
#include "bn_size.h"

namespace catgame
{
    enemy::enemy(bn::camera_ptr camera, bn::point position, bn::sprite_ptr player_sprite)
    {
        _position = position;
        _map_position.set_x(_position.x() / 8); // Pos divide by 8 (tiles size)
        _map_position.set_y(_position.y() / 8);
        _sprite = bn::sprite_items::ninja.create_sprite(_position);
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
                return _is_near_player;
            }
        }
        _is_near_player = false;
        return _is_near_player;
    }
    void enemy::set_view_distance(bn::sprite_ptr player_sprite)
    {
        _view_distance = _sprite.value().dimensions().width() + _view_distance;
    }
    int enemy::map_cell(const bn::regular_bg_map_item &map)
    {
        bn::regular_bg_map_cell map_cell = map.cell(_map_position);
        int tile_index = bn::regular_bg_map_cell_info(map_cell).tile_index();
        return tile_index;
    }
    bn::random random = bn::random();
    void enemy::update(const bn::regular_bg_map_item &map)
    {
        if (_is_near_player)
        {
            //
        }
        // AI
        else
        {
            bn::point _new_position = _position;
            // Calculate position in map
            if (_direction == 0)
            {
                _new_position.set_x(_new_position.x() + 1);
            }
            else if (_direction == 1)
            {
                _new_position.set_x(_new_position.x() - 1);
            }
            else if (_direction == 2)
            {
                _new_position.set_y(_new_position.y() - 1);
            }
            else if (_direction == 3)
            {
                _new_position.set_y(_new_position.y() + 1);
            }
            _map_position.set_x(_new_position.x() / 8);
            _map_position.set_y(_new_position.y() / 8);
            // Update position
            if (map_cell(map) < 5)
            {
                _position = _new_position;
            }
            else
            {
                _direction = random.get_int(4);
            }
            _sprite.value().set_position(_position.x(), _position.y());
        }

        if (_action.has_value() && !_action.value().done())
        {
            _action.value().update();
        }
    }
}