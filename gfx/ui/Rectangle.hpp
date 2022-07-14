#include "UiObject.hpp"

#include "../Framebuffer.hpp"
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle : public UiObject {
    private:
        int x,y;
        int width,height;
        int r,g,b;
    public:
        Rectangle();
        void render(Framebuffer fb);
        void setPos(int x, int y);
        void setDimensions(int width, int height);
        void setColor(char r, char g, char b);
        void mouseMoveEvent(MouseOnMoveEvent event);
        void mouseReleasedEvent(MouseOnReleaseEvent event);
        void freeMemory();
};

#endif