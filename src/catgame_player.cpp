#include "catgame_player.h"
#include "bn_camera_ptr.h"
#include "bn_point.h"
#include "bn_sprite_items_cat.h"
#include "bn_keypad.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_map_item.h"
#include "bn_regular_bg_item.h"
#include "bn_regular_bg_ptr.h"

namespace catgame
{

    player::player(bn::camera_ptr &camera, bn::point &position, bn::point &map_position)
    {
        _position = position;
        _map_position = map_position;
        _sprite = bn::sprite_items::cat.create_sprite(_position);
        _sprite.value().set_camera(camera);
        _sprite.value().set_z_order(1);
        _action = bn::create_sprite_animate_action_forever(
            _sprite.value(), 16, bn::sprite_items::cat.tiles_item(), 0, 1);
        // Generate map for collisions
        //const bn::regular_bg_map_item &map_item = bg;
    }

    void player::update()
    {

        bn::point _new_position = _position;

        // Handle movement
        bool idle = true;
        if (bn::keypad::left_held())
        {
            _new_position.set_x(_new_position.x() - 1);
            _sprite.value().set_horizontal_flip(true);
            idle = false;
        }
        else if (bn::keypad::right_held())
        {
            _new_position.set_x(_new_position.x() + 1);
            _sprite.value().set_horizontal_flip(false);
            idle = false;
        }
        if (bn::keypad::up_held())
        {
            _new_position.set_y(_new_position.y() - 1);
            idle = false;
        }
        else if (bn::keypad::down_held())
        {
            _new_position.set_y(_new_position.y() + 1);
            idle = false;
        }
        // Calculate position in map
        _map_position.set_x(_new_position.x() / 8);
        _map_position.set_y(_new_position.y() / 8);
        // Update position
        // bn::regular_bg_map_cell map_cell = _map_item.cell(_map_position);
        // int tile_index = bn::regular_bg_map_cell_info(map_cell).tile_index();
        // if (tile_index < 5)
        //{
        _position = _new_position;
        //}
        _sprite.value().set_position(_position.x(), _position.y());
        // Animate
        if (_action.has_value() && !_action.value().done())
        {
            _action.value().update();
        }
    }

}