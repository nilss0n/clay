#ifndef CLAY_WINDOW_H
#define CLAY_WINDOW_H
#include <GLFW/glfw3.h>
#include "PixelBuffer.h"

class Window {
public:
    Window(PixelBuffer& pb);
    ~Window();

    void run();

private:
    void init();
	PixelBuffer& pixels;
    GLFWwindow * window;
};


#endif //CLAY_WINDOW_H
