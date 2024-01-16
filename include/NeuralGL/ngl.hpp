#pragma once

#include <string>

namespace ngl {
    struct NGLWindow;

    NGLWindow* createWindow(int __width, int __height, std::string __title);
    void initOpenGLContext(NGLWindow* __window);
    void swapBuffers(NGLWindow* __window);
    
    std::string getLastError();

    void clearWindow(NGLWindow* __window);
}