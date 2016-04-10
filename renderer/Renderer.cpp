#include "Renderer.h"
#include <iostream>
#include <vector>
#include "Solid.h"

using namespace math;
std::vector<Solid> solids;

Renderer::Renderer(PixelBuffer& pb) : pixel_buffer(pb) {
	
	solids.push_back(create_cube(vec3(2,2,2), 1));
	solids.push_back(create_sphere(vec3(0, 0, 0), 1));
	solids.push_back(create_plane(vec3(0, -2, 0), vec3(0,1,0)));
}

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


float proximity(const vec3& pos, Solid & solid) {
	float dist = 100000.0f;
	for (auto && s : solids) {
		float d = s.distance(pos);
		if (d < dist) {
			dist = d;
			solid = s;
		}
	}
	return dist;
}

vec3 shade(const vec3 & p, const Solid & closest) {
	vec3 n = closest.normal(p);
	vec3 l = normalize(vec3(0, 10, 0) - p);
	return (closest.color * 0.1f) + closest.color * dot(n, l);
}

vec3 background() {
	return vec3(0.3f, 0.4f, 0.95f);
}

vec3 ray_march(Ray r) {
	float distance = 0.0f;
	vec3 p = r.o;
	// March to find intersection
	Solid closest;
	while (distance < 10000) {
		float prox = proximity(p, closest);
		if (prox < 0.01f) return shade(p, closest);

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