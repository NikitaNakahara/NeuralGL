#include <NeuralGL/ngl.hpp>

#include "Window.hpp"
#include "error.hpp"

#include <string>
#include <stdlib.h>
#include <iostream>

namespace ngl {
    struct NGLWindow {
        MyWindow* window;
        int width, height;
        std::string title;
    };

    NGLWindow* createWindow(int __width, int __height, std::string __title) {
        NGLWindow* window = (NGLWindow*)malloc(sizeof(NGLWindow));

        if (window == nullptr) {
            lastError = "Can't create window: haven't memory";
            return nullptr;
        }

        window->window = new MyWindow(__width, __height, __title);

        return window;
    }

    void initOpenGLContext(NGLWindow *__window) {
        __window->window->initOpenGLContext();
    }

    std::string getLastError() {
        std::string error = lastError;
        lastError = "";
        
        return error;
    }

    void clearWindow(NGLWindow* __window) {
        free(__window->window);
        free(__window);
    }
}