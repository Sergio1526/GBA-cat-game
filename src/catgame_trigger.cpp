#include "catgame_trigger.h"

#include "bn_point.h"
#include "bn_math.h"
#include "bn_camera_ptr.h"
#include "bn_sprite_items_limit.h"

namespace catgame
{
    trigger::trigger(bn::camera_ptr &camera, bn::point position)
    {
        _sprite = bn::sprite_items::limit.create_sprite(position);
        _sprite.value().set_camera(camera);
    }
    bool trigger::near_player(bn::fixed_point player_pos)
    {
        bn::fixed dist_x = bn::abs(player_pos.x() - _sprite.value().position().x());
        bn::fixed dist_y = bn::abs(player_pos.y() - _sprite.value().position().y());
        if (dist_x < 5)
        {
            if (dist_y < 5)
            {
                return true;
            }
        }
        return false;
    }
}