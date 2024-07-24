#ifndef CATGAME_HITBOX_H
#define CATGAME_HITBOX_H

#include "bn_fixed.h"
#include "bn_fixed_point.h"

namespace catgame
{
    class hitbox
    {
        private:
            bn::fixed_point _pos;
            bn::fixed width, height;
        public:
            hitbox(bn::fixed x, bn::fixed y, bn::fixed width, bn::fixed height);
            bn::fixed_point pos();
    };
}
#endif