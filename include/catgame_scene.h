#ifndef CATGAME_SCENE_H
#define CATGAME_SCENE_H

#include "catgame_game_phases.h"

namespace catgame
{
    class scene
    {
    public:
        virtual ~scene() = default;
        catgame::game_phases current_game_phase;
        catgame::game_phases next_game_phase;

    protected:
        scene() = default;
    };
}

#endif