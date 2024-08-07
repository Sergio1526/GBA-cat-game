#include "catgame_player.h"
#include "bn_camera_ptr.h"
#include "bn_point.h"
#include "bn_sprite_items_cat.h"
#include "bn_keypad.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_cell_info.h"
#include "bn_log.h" //Remove on final version

namespace catgame
{

    player::player(bn::camera_ptr &camera, bn::point &position)
    {
        _position = position;
        _map_position.set_x(_position.x() / 8); // Pos divide by 8 (tiles size)
        _map_position.set_y(_position.y() / 8);
        _sprite = bn::sprite_items::cat.create_sprite(_position);
        _sprite.value().set_camera(camera);
        _sprite.value().set_z_order(1);
    }

    int player::health()
    {
        return _health;
    }

    void player::hurt(int amount)
    {
        if (_health > 0)
        {
            _health -= amount;
        }
        else
        {
            _health = 0;
        }
    }

    int player::map_cell(const bn::regular_bg_map_item &map)
    {
        bn::regular_bg_map_cell map_cell = map.cell(_map_position);
        int tile_index = bn::regular_bg_map_cell_info(map_cell).tile_index();
        return tile_index;
    }

    bn::sprite_ptr player::sprite()
    {
        return _sprite.value();
    }

    bn::fixed_point player::position()
    {
        return _position;
    }

    void player::animate()
    {
        if (_idle)
        {
            _action = bn::create_sprite_animate_action_forever(
                _sprite.value(), 16, bn::sprite_items::cat.tiles_item(), 0, 1);
        }
        if (_action.has_value() && !_action.value().done())
        {
            _action.value().update();
        }
    }

    bool player::dead()
    {
        return _dead;
    }

    void player::die()
    {
        _wait_time -= 1;
        if (_wait_time <= 0)
        {
            _dead = true;
        }
    }

    void player::update(const bn::regular_bg_map_item &map)
    {
        if (_health <= 0)
        {
            die();
        }
        else
        {
            bn::point _new_position = _position;

            // Handle movement
            _idle = true;
            if (bn::keypad::left_held())
            {
                _new_position.set_x(_new_position.x() - 1);
                _sprite.value().set_horizontal_flip(true);
                _idle = false;
            }
            else if (bn::keypad::right_held())
            {
                _new_position.set_x(_new_position.x() + 1);
                _sprite.value().set_horizontal_flip(false);
                _idle = false;
            }
            if (bn::keypad::up_held())
            {
                _new_position.set_y(_new_position.y() - 1);
                _idle = false;
            }
            else if (bn::keypad::down_held())
            {
                _new_position.set_y(_new_position.y() + 1);
                _idle = false;
            }
            // Calculate position in map
            _map_position.set_x(_new_position.x() / 8);
            _map_position.set_y(_new_position.y() / 8);
            // Update position
            if (map_cell(map) < 5)
            {
                _position = _new_position;
            }
            _sprite.value().set_position(_position.x(), _position.y());

            if (bn::keypad::a_pressed())
            {
            }

            if (bn::keypad::b_pressed())
            {
            }
        }
    }

}