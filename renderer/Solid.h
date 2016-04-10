#ifndef RENDERER_SOLID
#define RENDERER_SOLID
#include <math/vec3.h>
#include <functional>

struct Solid {
	std::function<float(const math::vec3&)> distance;
	std::function<math::vec3(const math::vec3&)> normal;
	math::vec3 color;
};

Solid create_sphere( math::vec3 pos,  float radius);
Solid create_cube(math::vec3 pos, float radius);
Solid create_plane(math::vec3 pos, math::vec3 dir);

#endif



