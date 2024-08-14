#include "catgame_scene.h"
#include "bn_sprite_text_generator.h"

namespace catgame
{
    class minigame_1 : public scene
    {
    public:
        minigame_1();
        catgame::game_phases execute(bn::sprite_text_generator &text_generator, int &times_played, int &food, int &stamina);

    private:
    };
}