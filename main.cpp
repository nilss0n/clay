#include <iostream>
#include <thread>
#include "Window.h"
#include "PixelBuffer.h"
#include "renderer/Renderer.h"

using namespace std;

int main() {
	PixelBuffer * pb = new PixelBuffer(1280, 720);
    Window * window = new Window(*pb);
	Renderer * render = new Renderer(*pb);

    //thread wt(&Window::run, window);
	thread rt(&Renderer::run, render);
    window->run();

    //wt.join();
	render->exit();
	rt.join();
    delete window;
	delete pb;
    return 0;
}