#include "UiObject.hpp"

#ifndef MOUSE_HPP
#define MOUSE_HPP

class Mouse : public UiObject {
    private:
        int x,y;
    public:
        Mouse();
        void render(char * imageBuffer, int lineLength);
        void setPos(int x, int y);
        void setDelta(int dX, int dY);
        void mouseMoveEvent(int x, int y);
        void freeMemory();
};

#endif