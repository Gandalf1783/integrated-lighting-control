#include "UiObject.hpp"

#ifndef MOUSE_HPP
#define MOUSE_HPP

class Mouse : public UiObject {
    private:
        int x,y;
        bool wasMouseReleased;
    public:
        Mouse();
        void render(char * imageBuffer, int lineLength);
        void setPos(int x, int y);
        void setDelta(int dX, int dY);
        int getX();
        int getY();
        void mouseMoveEvent(int x, int y);
        void freeMemory();
        void mouseRelease();
        void mouseReleasedEvent(int x, int y);
        bool getMouseReleased();
};

#endif