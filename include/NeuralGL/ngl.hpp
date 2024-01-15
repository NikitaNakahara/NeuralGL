#pragma once

#include <string>

#include "../../src/Window.hpp"

namespace ngl {
    using Wnd = MyWindow;

    Wnd *createWindow(int __width, int __height, std::string __title) {
        return new Wnd(__width, __height, __title);
    }

    Wnd *createOpenGLWindow(int __width, int __height, std::string __title) {
        Wnd *window = createWindow(__width, __height, __title);
        window->initOpenGLContext();

        return window;
    }

    Display* getDisplayPtr(Wnd __window) {
        __window.getDisplayPtr();
    }
}