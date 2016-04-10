#include "vec3.h"
#include "math.h"

using namespace math;


vec3::vec3(){
    x = y = z = 0.0f;
}
vec3::vec3(float a, float b, float c){
    x = a;
    y = b;
    z = c;
}

vec3::~vec3(){}

/** Add vectors. */
vec3 vec3::operator+(const vec3& rhs) const {
    return vec3(x + rhs.x, y + rhs.y, z + rhs.z);
}

/** Subtract vectors. */
vec3 vec3::operator-(const vec3& rhs) const {
    return vec3(x - rhs.x, y - rhs.y, z - rhs.z);
}

/** Multiply vectors. */
vec3 vec3::operator*(const vec3& rhs) const {
    return vec3(x * rhs.x, y * rhs.y, z * rhs.z);
}

/** Divide vectors. */
vec3 vec3::operator/(const vec3& rhs) const {
    return vec3(x / rhs.x, y / rhs.y, z / rhs.z);
}

/** Multiply by scalar. */
vec3 vec3::operator*(const float& rhs) const {
    return vec3(x * rhs, y * rhs, z * rhs);
}

/** Divide by scalar. */
vec3 vec3::operator/(const float& rhs) const {
    return vec3(x / rhs, y / rhs, z / rhs);
}

float vec3::length() const {
    return sqrt((x*x) + (y*y) + (z*z));
}

float math::length(const vec3& v) {
	return v.length();
}

/** Dot product*/
float math::dot(const vec3& a, const vec3& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

/** Cross product*/
vec3 math::cross(const vec3& a, const vec3& b) {
	return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

vec3 math::normalize(const vec3& v) {
	return v / length(v);
}


vec3 math::abs(const vec3& v) {
	return vec3(abs(v.x), abs(v.y), abs(v.z));
}