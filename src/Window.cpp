#include "Window.hpp"

#include <X11/Xutil.h>

#include <GL/gl.h>
#include <GL/glx.h>

#include "error.hpp"

#include <iostream>

namespace ngl {
    struct WndID {
        #if defined(__linux__)
        unsigned long id = 0;
        Display* pDisplay;
        #endif
    };

    MyWindow::MyWindow(int __width, int __height, std::string __title, bool __createFullscreen, WndID* __parentID)
        : _width(__width), _height(__height), _title(__title) {
        #if defined(__linux__)

        XSetWindowAttributes attrs;
        XSizeHints sizeHint;
        XClassHint classHint;

        char* propertyData;
        char* className = "NeuralEngine";
        char* resName = "NeuralEngine";
        char* iconName;

        _id = (WndID*)malloc(sizeof(WndID));
        if (_id == nullptr) {
            lastError = "can't init memory for WndID";
            return;
        }
        
        if (__parentID == nullptr) _id->pDisplay = XOpenDisplay(nullptr);
        else _id->pDisplay = __parentID->pDisplay;
        if (_id->pDisplay == nullptr) {
            lastError = "can't create X-11 device";
            return;
        }

        int screen =        DefaultScreen(_id->pDisplay);
        Window root =       RootWindow(_id->pDisplay, screen);
        int background =    WhitePixel(_id->pDisplay, screen);
        int depth =         DefaultDepth(_id->pDisplay, screen);
        Visual* visual =    DefaultVisual(_id->pDisplay, screen);

        attrs.background_pixel = background;

        if (__parentID == nullptr) {
            _id->id = XCreateWindow(
                _id->pDisplay,
                RootWindow(_id->pDisplay, screen),
                100, 100,
                __width, __height,
                0, depth, InputOutput, visual, CWBackPixel, &attrs
            );
        } else _id->id = __parentID->id;

        XStoreName(_id->pDisplay, _id->id, __title.c_str());
        XSetIconName(_id->pDisplay, _id->id, __title.c_str());

        sizeHint.flags = PMinSize | PMaxSize | PResizeInc;
        sizeHint.min_width = 0;
        sizeHint.min_height = 0;
        sizeHint.max_width = 1920;
        sizeHint.max_height = 1080;
        sizeHint.width_inc = 1;
        sizeHint.height_inc = 1;
        XSetWMNormalHints(_id->pDisplay, _id->id, &sizeHint);

        classHint.res_name = resName;
        classHint.res_class = className;
        XSetClassHint(_id->pDisplay, _id->id, &classHint);

        XMapWindow(_id->pDisplay, _id->id);

        XFlush(_id->pDisplay);
        #endif
    }

    MyWindow::~MyWindow() {
        #if defined(__linux__)
        XDestroyWindow(_id->pDisplay, _id->id);
        XCloseDisplay(_id->pDisplay);
        glXDestroyContext(_id->pDisplay, _glContext);
        #endif
        free(_id);
    }

    void MyWindow::initOpenGLContext() {
        int args[5] = {
            GLX_RGBA,
            GLX_DEPTH_SIZE, 24,
            GLX_DOUBLEBUFFER,
            None
        };
        XVisualInfo *visual = glXChooseVisual(_id->pDisplay, 0, args);
        _glContext = glXCreateContext(_id->pDisplay, visual, 0, True);
        glXMakeCurrent(_id->pDisplay, _id->id, _glContext);
    }

    void MyWindow::draw() {
        glClearColor(0.0, 0.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        #if defined(__linux__)
        glXSwapBuffers(_id->pDisplay, _id->id);
        #endif
    }

    Display* MyWindow::getDisplayPtr() {
        return _id->pDisplay;
    }
}