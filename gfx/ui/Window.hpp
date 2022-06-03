#include "../Framebuffer.hpp"
#include "UiObject.hpp"
#include <string.h>
#include <vector>
#include "Text.hpp"
#include "Rectangle.hpp"
#include "ProgressBar.hpp"
#include "Image.hpp"



#ifndef WINDOW_HPP
#define WINDOW_HPP


class Window : public UiObject {
    private:
        int x,y;
        int width,height;
        const int titleHeight = 40;
        Text *title;
        std::vector<UiObject*> uiObjects;
        u_int64_t screensizeInBytes;
        
        Framebuffer windowFb;
        bool stop;
        bool isMouseDown;
    public:
        Window(std::string title);
        void render(Framebuffer fb);
        void setPos(int x, int y);
        void addUiObject(UiObject* object);
        void mouseMoveEvent(int x, int y);
        void mouseReleasedEvent(int x, int y);
        void mouseDownEvent();
        void freeMemory();
};

#endif