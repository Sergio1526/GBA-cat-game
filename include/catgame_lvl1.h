#include "catgame_scene.h"
#include "bn_camera_actions.h"
#include "bn_sprite_text_generator.h"

namespace catgame
{
    class lvl1 : public scene
    {
    public:
        lvl1(bn::camera_ptr &camera, bn::sprite_text_generator &text_generator);

    private:
    };
}