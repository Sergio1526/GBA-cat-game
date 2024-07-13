#ifndef CATGAME_ENEMY_H
#define CATGAME_ENEMY_H

#include "bn_camera_ptr.h"
#include "bn_point.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"

namespace catgame
{
    class enemy
    {
    private:
        bn::optional<bn::sprite_ptr> _sprite;
        bn::optional<bn::sprite_animate_action<4>> _action;
        int _hp;
        int _velocity;
        bool _dead = false;

    public:
        int _mov_count = 0;
        enemy(bn::camera_ptr camera, bn::point pos);
        void spawn();
        void update();
    };
}

#endif