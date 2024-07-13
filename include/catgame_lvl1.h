#include "catgame_scene.h"
#include "bn_sprite_text_generator.h"

namespace catgame
{
    class lvl1 : public scene
    {
    public:
        lvl1();
        catgame::game_phases execute(bn::sprite_text_generator &text_generator);

    private:
    };
}