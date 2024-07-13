#include "catgame_scene.h"
#include "bn_camera_actions.h"

namespace catgame
{
    class logo : public scene
    {
    private:

    public:
        logo();
        catgame::game_phases execute(bn::camera_ptr &camera);
    };
}