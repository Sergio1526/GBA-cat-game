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
        int _hp = 100;
        bn::fixed _velocity = 0.5;
        int _view_distance = 10;
        bool _dead = false;
        bool _is_near_player = false;

    public:
        enemy(bn::camera_ptr camera, bn::point pos, bn::sprite_ptr player_sprite);
        void spawn();
        void set_view_distance(bn::sprite_ptr player_pos);
        bool near_player(bn::fixed_point player_pos);
        void update();
    };
}

#endif