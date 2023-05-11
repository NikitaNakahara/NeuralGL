#include <NGL/ngl.hpp>

#include "framebuffer.hpp"

#include <iostream>

struct NGLWindow {
    const char* pFramebuffer;
    int width;
    int height;
    const char* title;
};

NGLWindow* nglCreateWindow(int width, int height, const char* title) {
    std::cout << "Neural GL\n";

    NGLWindow* window;
    window->pFramebuffer = getFramebufferPointer();
    window->width = width;
    window->height = height;
    window->title = title;

    return window;
 }