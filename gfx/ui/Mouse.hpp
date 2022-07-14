#include "UiObject.hpp"
#include "../Framebuffer.hpp"

#ifndef MOUSE_HPP
#define MOUSE_HPP

class Mouse : public UiObject {
    private:
        int x,y;
        bool left, right, middle;
        bool wasMouseReleased;
        int lastX, lastY;
    public:
        Mouse();
        void render(Framebuffer fb);
        void setPos(int x, int y);
        int getX();
        int getY();
        void mouseMoveEvent(MouseOnMoveEvent event);
        void freeMemory();
        void mouseRelease();
        void mouseReleasedEvent(MouseOnReleaseEvent event);
        void mouseDownEvent(MouseOnDownEvent event);
        bool getMouseReleased();
        bool getMouseLeftDown();
        void setMouseButtons(bool left, bool right, bool middle);
        bool evaluateIfChanged();

};

#endif