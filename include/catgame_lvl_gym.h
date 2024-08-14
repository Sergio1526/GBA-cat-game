#include "catgame_scene.h"
#include "bn_sprite_text_generator.h"

namespace catgame
{
    class lvl_gym : public scene
    {
    public:
        lvl_gym();
        catgame::game_phases execute(bn::sprite_text_generator &text_generator, int &times_played, int &food, int &stamina);

    private:
    };
}