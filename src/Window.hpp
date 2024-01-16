#pragma once

#include <string>

#include <X11/Xlib.h>
#include <GL/glx.h>

namespace ngl {
    struct WndID;

    class MyWindow {
    public:
        MyWindow(int __width, int __height, std::string __title, bool __createFullscreen = false, WndID* __parentID = nullptr);
        ~MyWindow();

        void initOpenGLContext();

        WndID* getWindowID() { return _id; }

        Display* getDisplayPtr();

        void swapBuffers();

    private:
        WndID* _id;
        GLXContext _glContext;
        int _width, _height;
        std::string _title;
    };
}