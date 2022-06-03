#include "UiObject.hpp"
#include "../Framebuffer.hpp"

#ifndef MOUSE_HPP
#define MOUSE_HPP

class Mouse : public UiObject {
    private:
        int x,y;
        bool left, right, middle;
        bool wasMouseReleased;
        int dX, dY;
    public:
        Mouse();
        void render(Framebuffer fb);
        void setPos(int x, int y);
        void setDelta(int dX, int dY);
        int getX();
        int getY();
        int getDX();
        int getDY();
        void mouseMoveEvent(int x, int y);
        void freeMemory();
        void mouseRelease();
        void mouseReleasedEvent(int x, int y);
        void mouseDownEvent();
        bool getMouseReleased();
        bool getMouseLeftDown();
        void setMouseButtons(bool left, bool right, bool middle);

};

#endif