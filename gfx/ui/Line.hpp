#include "UiObject.hpp"
#include "../Framebuffer.hpp"

#ifndef LINE_HPP
#define LINE_HPP

class Line : public UiObject {
    private:
        int x1,y1;
        int x2,y2;
        float m;
    public:
        Line();
        void setFrom(int x, int y);
        void setTo(int x, int y);
        void render(Framebuffer fb);
        void mouseMoveEvent(MouseOnMoveEvent event);
        void freeMemory();
        void mouseReleasedEvent();
        void mouseReleasedEvent(MouseOnReleaseEvent event);
};

#endif