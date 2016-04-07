#include "PixelBuffer.h"

using namespace math;

PixelBuffer::PixelBuffer(const int & w, const int & h) : width(w), height(h) {
	front	= new vec3[width * height];
	back	= new vec3[width * height];
}

PixelBuffer::~PixelBuffer(){
	if (front != nullptr) {
		delete[] front;
	}
	if (back != nullptr) {
		delete[] back;
	}
}

void PixelBuffer::swap_buffers() {
	write.lock();
	read.lock();
	vec3 * temp = back;
	back = front;
	front = temp;
	read.unlock();
	write.unlock();
}

void PixelBuffer::write_pixel(const int& x, const int& y, const vec3& c) {
	write.lock();
	back[y * width + x] = c;
	write.unlock();
}

math::vec3* PixelBuffer::get_front() {
	return front;
}

void PixelBuffer::start_read() {
	read.lock();
}

void PixelBuffer::end_read() {
	read.unlock();
}