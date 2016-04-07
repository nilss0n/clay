#ifndef CLAY_PIXELBUFFER
#define CLAY_PIXELBUFFER

#include "math/math.h"
#include <mutex>

class PixelBuffer
{
public:
	PixelBuffer(const int & w, const int & h);
	~PixelBuffer();

	void swap_buffers();

	void write_pixel(const int& x, const int& y, const math::vec3& c);
	
	void start_read();
	void end_read();
	math::vec3 * get_front();

	const int width;
	const int height;
private:
	std::mutex read, write;
	math::vec3* front;
	math::vec3* back;
};

#endif