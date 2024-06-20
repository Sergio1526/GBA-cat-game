//SG stands for simple game
#ifndef SG_ENTITY_H
#define SG_ENTITY_H

#include "bn_fixed_point.h"
#include "bn_optional.h"
#include "bn_sprite_ptr.h"

namespace sg{
    enum anim_state{
        ANIM_IDLE,
        ANIM_WALK,
        ANIM_DEAD,
        ANIM_WIN,
        ANIM_LOSE,
    };

    class sg_entity{



        protected:
		bn::fixed_point _pos;
		bn::optional<bn::sprite_ptr> _spr;
		anim_state _anim_state;
    };
}

#endif