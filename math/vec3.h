#ifndef CLAY_VEC3
#define CLAY_VEC3

namespace math{

    class vec3 {
    public:
        vec3();
        vec3(float, float, float);
        ~vec3();

        /** Add vector. */
        vec3 operator+(const vec3& rhs) const;

        /** Subtract vector. */
        vec3 operator-(const vec3& rhs) const;

        /** Multiply by vector. */
        vec3 operator*(const vec3& rhs) const;

        /** Divide by vector. */
        vec3 operator/(const vec3& rhs) const;

        /** Multiply by scalar. */
		vec3 operator*(const float& rhs) const;

        /** Divide by scalar. */
		vec3 operator/(const float& rhs) const;

		/** Vector length. */
		float length() const;

		float x,y,z;
    };
	float length(const vec3& v);

	/** Dot product*/
	float dot(const vec3& a, const vec3& b);

	/** Cross product*/
	vec3 cross(const vec3& a, const vec3& b);

	vec3 normalize(const vec3& v);
	
	vec3 abs(const vec3& v);
}

#endif //CLAY_VEC3
