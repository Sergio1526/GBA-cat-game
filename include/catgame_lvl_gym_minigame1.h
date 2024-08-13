#include "catgame_scene.h"
#include "bn_sprite_text_generator.h"

namespace catgame
{
    class lvl_gym_minigame1 : public scene
    {
    public:
        lvl_gym_minigame1();
        catgame::game_phases execute(bn::sprite_text_generator &text_generator);

    private:
    };
}