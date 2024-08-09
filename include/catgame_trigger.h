#ifndef CATGAME_TRIGGER_H
#define CATGAME_TRIGGER_H

#include "bn_point.h"
#include "bn_sprite_ptr.h"

namespace catgame
{
    class trigger
    {
    private:
        bn::optional<bn::sprite_ptr> _sprite;
    public:
        trigger(bn::camera_ptr &camera, bn::point position);
        bool near_player(bn::fixed_point player_pos);
    };
}

#endif