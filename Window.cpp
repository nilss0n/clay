#include "Window.h"
#include <stdexcept>
#include <iostream>

Window::Window(PixelBuffer& pb) : pixels(pb){}

Window::~Window() {}

void Window::init(){
    /* Initialize the library */
    if (!glfwInit()) {
        throw std::runtime_error("GLFW Initialization failed.");
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 720, "Clay", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Window creation failed.");
    }

    glfwMakeContextCurrent(window);

}

void Window::run(){
    init();

    glClearColor(0.f, 0.5f, 0.f, 1.0f);

    glViewport(0, 0, pixels.width, pixels.height);

    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		pixels.start_read();
        glDrawPixels(pixels.width,pixels.height,GL_RGB, GL_FLOAT, pixels.get_front());
		pixels.end_read();

        glfwSwapBuffers(window);
        glfwPollEvents();
        glfwSwapInterval(1);
    }
    glfwTerminate();
}
