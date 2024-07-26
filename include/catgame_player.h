#ifndef CATGAME_PLAYER_H
#define CATGAME_PLAYER_H

#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_camera_ptr.h"
#include "bn_point.h"

namespace catgame
{

    class player
    {
    private:
        bn::optional<bn::sprite_ptr> _sprite;
        bn::optional<bn::sprite_animate_action<4>> _action;
        int _hp = 100;
        bn::fixed _velocity = 0.5;
        int _view_distance = 10;
        bool _dead = false;
        bool _is_near_player = false;

    public:
        player(bn::camera_ptr camera, bn::point pos);
        void update();
    };

}

#endif