#ifndef CATGAME_FOOD_H
#define CATGAME_FOOD_H

#include "bn_camera_ptr.h"
#include "bn_point.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_string_view.h"

namespace catgame
{
    class food
    {
    private:
        bn::optional<bn::sprite_ptr> _sprite;
        bn::optional<bn::sprite_animate_action<4>> _action;
        bn::fixed _velocity = 0.5;
        bool _is_near_player = false;
        bn::point _position;
        bn::fixed _speed;

    public:
        food(bn::camera_ptr camera);
        bool near_player(bn::fixed_point player_pos);
        void update();
    };
}

#endif