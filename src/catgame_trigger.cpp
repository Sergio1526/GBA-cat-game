#include "catgame_trigger.h"

#include "bn_point.h"
#include "bn_math.h"
#include "bn_camera_ptr.h"
#include "bn_sprite_items_limit.h"
#include "bn_sprite_animate_actions.h"

namespace catgame
{
    trigger::trigger(bn::camera_ptr &camera, bn::point position, bool show)
    {
        _sprite = bn::sprite_items::limit.create_sprite(position);
        _sprite.value().set_camera(camera);
        _sprite.value().set_visible(show);
        _action = bn::create_sprite_animate_action_forever(
                _sprite.value(), 16, bn::sprite_items::limit.tiles_item(), 0, 1);
    }
    bool trigger::near_player(bn::fixed_point player_pos)
    {
        if (_action.has_value() && !_action.value().done())
        {
            _action.value().update();
        }
        bn::fixed dist_x = bn::abs(player_pos.x() - _sprite.value().position().x());
        bn::fixed dist_y = bn::abs(player_pos.y() - _sprite.value().position().y());
        if (dist_x < 10 && dist_y < 25)
        {
            return true;
        }
        return false;
    }
}