#include <NeuralGL/ngl.hpp>

#include "Window.hpp"
#include "error.hpp"

#include <string>
#include <stdlib.h>

namespace ngl {
    struct NGLWindow {
        MyWindow windowObj;
        int width, height;
        std::string title;
    };

    NGLWindow* createWindow(int __width, int __height, std::string __title) {
        NGLWindow* window = (NGLWindow*)malloc(sizeof(NGLWindow));

        if (window == nullptr) lastError = "Can't create window: haven't memory";

        return window;
    }

    void initOpenGLContext(NGLWindow *__window) {
        __window->windowObj.initOpenGLContext();
    }

    std::string getLastError() {
        std::string error = lastError;
        lastError = "";
        
        return error;
    }
}