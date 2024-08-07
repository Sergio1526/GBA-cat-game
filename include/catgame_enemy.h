#ifndef CATGAME_ENEMY_H
#define CATGAME_ENEMY_H

#include "bn_camera_ptr.h"
#include "bn_point.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_regular_bg_map_item.h"

namespace catgame
{
    class enemy
    {
    private:
        bn::optional<bn::sprite_ptr> _sprite;
        bn::optional<bn::sprite_animate_action<4>> _action;
        int _health = 100;
        int _direction = 0; //0 left, 1 right, 2 top, 3 down
        bn::fixed _velocity = 0.5;
        int _view_distance = 10;
        bool _dead = false;
        bool _is_near_player = false;
        bn::point _position;
        bn::point _map_position;

    public:
        enemy(bn::camera_ptr camera, bn::point position, bn::sprite_ptr player_sprite);
        void set_view_distance(bn::sprite_ptr player_pos);
        bool near_player(bn::fixed_point player_pos);
        void update(const bn::regular_bg_map_item &map);
        int map_cell(const bn::regular_bg_map_item &map);
    };
}

#endif