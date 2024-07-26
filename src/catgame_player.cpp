#include "catgame_player.h"
#include "bn_camera_ptr.h"
#include "bn_point.h"
#include "bn_sprite_items_cat.h"

namespace catgame
{

    player::player(bn::camera_ptr camera, bn::point pos)
    {
        _sprite = bn::sprite_items::cat.create_sprite(pos);
        _sprite.value().set_camera(camera);
        _sprite.value().set_z_order(1);
        _action = bn::create_sprite_animate_action_forever(
            _sprite.value(), 16, bn::sprite_items::cat.tiles_item(), 0, 1);
    }

    void player::update()
    {
        if (_action.has_value() && !_action.value().done())
        {
            _action.value().update();
        }
    }

}