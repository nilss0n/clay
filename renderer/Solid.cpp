#include "Solid.h"
#include <math/math.h>
using namespace math;

Solid create_sphere(math::vec3 pos, float radius) {
	Solid s;
	s.distance = [pos, radius](const vec3& p) {
		return length(p - pos) - radius;
	};
	s.normal = [pos](const vec3& p) {
		return normalize(p - pos);
	};
	s.color = vec3(0, 0, 1);
	return s;
}
Solid create_cube(math::vec3 pos, float radius) {
	Solid s;
	vec3 b = vec3(radius, radius, radius);
	s.distance = [pos, b](const vec3& p) {
		vec3 d = abs(pos - p) - b;
		return length(max(d, 0.0));
	};

	s.normal = [pos](const vec3& p) {
		vec3 d = (p - pos);
		vec3 l = abs(d);
		d.x = (l.x < l.y || l.x < l.z ? 0 : d.x);
		d.y = (l.y < l.x || l.y < l.z ? 0 : d.y);
		d.z = (l.z < l.x || l.z < l.y ? 0 : d.z);
		return d;
	};
	s.color = vec3(1, 0, 0);
	return s;
}

Solid create_plane(math::vec3 pos, math::vec3 dir) {
	Solid s;
	s.distance = [pos, dir](const vec3& p) {
		vec3 d = p - pos;
		return dot(d, dir);
	};
	s.normal = [dir](const vec3& p) {
		return dir;
	};
	s.color = vec3(0, 1, 0);
	return s;
}