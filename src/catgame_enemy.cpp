#include "catgame_enemy.h"
#include "bn_camera_ptr.h"
#include "bn_point.h"

#include "bn_sprite_animate_actions.h"
#include "bn_sprite_items_dino.h"
#include "bn_sprite_items_ninja.h"

// Common libraries
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_log.h" //Remove on final version

namespace catgame
{
    enemy::enemy(bn::camera_ptr camera, bn::point pos)
    {
        BN_LOG("Create an enemy: ", pos.x(), pos.y());
        _sprite = bn::sprite_items::ninja.create_sprite(pos);
        _sprite.value().set_camera(camera);
        _sprite.value().set_z_order(1);
        _action = bn::create_sprite_animate_action_forever(
            _sprite.value(), 16, bn::sprite_items::ninja.tiles_item(), 0, 1, 2, 3);
    }
    void enemy::spawn()
    {
        BN_LOG("Span called!");
    }
    void enemy::update()
    {
        if (_mov_count < 20)
        {
            _mov_count = _mov_count + 0.3;
            _sprite.value().set_position(_sprite.value().position().x(), _sprite.value().position().y() - _mov_count);
        }
        if (_action.has_value() && !_action.value().done())
        {
            _action.value().update();
        }
    }
}