#ifndef RENDERER_SOLID
#define RENDERER_SOLID
#include <math/vec3.h>

class Solid{
public:
    float distance(const math::vec3&) {
        return 0;
    }
};

class Union : public Solid {
public:
    float distance(const math::vec3& p) {
        return 0.0f;
    }
private:
    Solid a, b;
};


#endif



