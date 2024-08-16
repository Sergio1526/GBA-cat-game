#ifndef CATGAME_TRIGGER_H
#define CATGAME_TRIGGER_H

#include "bn_point.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

namespace catgame
{
    class trigger
    {
    private:
        bn::optional<bn::sprite_ptr> _sprite;
        bn::optional<bn::sprite_animate_action<4>> _action;
    public:
        trigger(bn::camera_ptr &camera, bn::point position, bool show);
        bool near_player(bn::fixed_point player_pos);
    };
}

#endif