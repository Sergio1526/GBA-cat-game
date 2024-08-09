#include "catgame_scene.h"
#include "bn_sprite_text_generator.h"

namespace catgame
{
    class lvl2 : public scene
    {
    public:
        lvl2();
        catgame::game_phases execute(bn::sprite_text_generator &text_generator);

    private:
    };
}