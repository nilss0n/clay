#ifndef CLAY_MATH
#define CLAY_MATH
#include <cmath>
#include "vec3.h"

namespace math{

    inline float sqrt(const float& f){
        return std::sqrtf(f);
    }

	inline float abs(const float& x) {
		return x > 0 ? x : -x;
	}

	inline float min(const float& a, const float& b) {
		return (a < b ? a : b);
	}

	inline float max(const float& a, const float& b) {
		return (a > b ? a : b);
	}

	inline vec3 min(const vec3& a, const float& b) {
		return vec3(min(a.x, b), min(a.y, b), min(a.z, b));
	}
	inline vec3 max(const vec3& a, const float& b) {
		return vec3(max(a.x, b), max(a.y, b), max(a.z, b));
	}


}

#endif //CLAY_MATH_H
