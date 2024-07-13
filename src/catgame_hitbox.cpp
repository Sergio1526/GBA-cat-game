#include "catgame_hitbox.h"

namespace catgame
{
    hitbox::hitbox(bn::fixed x, bn::fixed y, bn::fixed width, bn::fixed height)
    {
    }
    bn::fixed_point hitbox::pos()
    {
        return _pos;
    }
}