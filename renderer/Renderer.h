#ifndef CLAY_RENDERER_RENDERER
#define CLAY_RENDERER_RENDERER
#include <PixelBuffer.h>

class Renderer {
public:
	Renderer(PixelBuffer& pb);
	~Renderer();

	void run();
	void exit();
private:
	PixelBuffer& pixel_buffer;
	bool should_exit;


};
#endif //CLAY_RENDERER_H
