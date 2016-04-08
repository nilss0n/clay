#ifndef RENDERER_SCENE
#define RENDERER_SCENE

#include "solid/Solid.h"
#include <vector>

class Scene
{
public:
    Scene();
    ~Scene();

private:
    std::vector<Solid> solids;
};



#endif
