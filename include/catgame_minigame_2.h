#include "catgame_scene.h"
#include "bn_sprite_text_generator.h"

namespace catgame
{
    class minigame_2 : public scene
    {
    public:
        minigame_2();
        catgame::game_phases execute(bn::sprite_text_generator &text_generator, int &times_played, int &food, int &stamina);

    private:
    };
}