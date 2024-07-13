#include "catgame_scene.h"
#include "bn_sprite_text_generator.h"

namespace catgame
{
    class intro : public scene
    {
    public:
        intro();
        catgame::game_phases execute(bn::sprite_text_generator &text_generator);

    private:
    };
}
