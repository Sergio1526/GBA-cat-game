#ifndef CATGAME_PLAYER_H
#define CATGAME_PLAYER_H

#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_camera_ptr.h"
#include "bn_point.h"
#include "bn_regular_bg_map_item.h"

namespace catgame
{

    class player
    {
    private:
        bn::optional<bn::sprite_ptr> _sprite;
        bn::optional<bn::sprite_animate_action<4>> _action;
        int _health = 100;
        bn::fixed _velocity = 0.5;
        int _view_distance = 10;
        bool _idle = true;
        bool _dead = false;
        bn::point _position;
        bn::point _map_position;
        int _wait_time = 30;

    public:
        player(bn::camera_ptr &camera, bn::point &position);
        void update(const bn::regular_bg_map_item &map);
        void animate();
        [[nodiscard]] bn::fixed_point position();
        [[nodiscard]] bn::sprite_ptr sprite();
        int map_cell(const bn::regular_bg_map_item &map);
        int health();
        void hurt(int amount);
        void die();
        bool dead();
    };

}

#endif