#pragma once

#include <string>

namespace ngl {
    struct NGLWindow;

    NGLWindow* createWindow(int __width, int __height, std::string __title);
    void initOpenGLContext(NGLWindow *__window);
    
    std::string getLastError();
}