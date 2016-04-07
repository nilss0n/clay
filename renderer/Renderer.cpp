#include "Renderer.h"
#include <iostream>

using namespace math;

Renderer::Renderer(PixelBuffer& pb) : pixel_buffer(pb) {}

Renderer::~Renderer() {}

struct Ray {
	vec3 o;
	vec3 d;
};

Ray create_ray(int u, int v) {
	Ray r;
	r.o = vec3(0,0, -5.0f);
	r.d = normalize(vec3(1.78f *(-640.0f + u) / 640.0f,  (-360.0f + v) / 360.0f, 1));
	//r.d = vec3(0, 0, 1.0f);
	//std::cout << "<" << r.d.x << ", " << r.d.y << ", " << r.d.z << ">" << std::endl;
	return r;
}


float proximity(const vec3& pos, vec3 & color) {
	float dist = 100000.0f;
	{
		float d = length(pos - vec3(0, 0, 0)) - 1.0f;
		if (d < dist) {
			dist = d;
			color = vec3(1, 0, 0);
		}
	}
	{
		float d = dot(vec3(0, 1, 0), pos - vec3(0, -2, 0));
		if (d < dist) {
			dist = d;
			color = vec3(0, 1, 0);
		}
	}
	return dist;
}

vec3 shade(const vec3 & p, const vec3 & col) {
	//if (fmod(abs(p.x), 4.0f) < 0.1f) return vec3(1, 1, 1);
	//if (fmod(abs(p.z), 4.0f) < 0.1f) return vec3(1, 1, 1);
	//return vec3(0.5f, 0.5f, 0.5f);
	return col;
}

vec3 background() {
	return vec3(0.3f, 0.4f, 0.95f);
}

vec3 ray_march(Ray r) {
	float distance = 0.0f;
	vec3 p = r.o;
	// March to find intersection
	vec3 col = vec3(1, 1, 1);
	while (distance < 10000) {
		float prox = proximity(p, col);
		if (prox < 0.01f) return shade(p, col);

		distance += prox;
		p = r.o + (r.d * distance);

	}
	return background();
}

void Renderer::run() {
	while (!should_exit) {
		for (int u = 0; u < pixel_buffer.width; u++) {
			for (int v = 0; v < pixel_buffer.height; v++) {
				float l = (float)u / pixel_buffer.width;
				Ray r = create_ray(u, v);
				pixel_buffer.write_pixel(u, v,ray_march(r));
			}
		}
		pixel_buffer.swap_buffers();
        std::cout << "Frame finished." << std::endl;
		//break;
	}
}

void Renderer::exit() {
	should_exit = true;
	std::cout << "EXIT" << std::endl;
}