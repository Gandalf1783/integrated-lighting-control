#include "UiObject.hpp"
#include "../Framebuffer.hpp"

#ifndef Button_HPP
#define Button_HPP

class Button: public UiObject {
    private:
        int x,y;
        bool isPressed;
        char colorPressed = 0x30;
        char colorUnpressed = 0x80;
    public:
        Button();
        void render(Framebuffer fb);
        void mouseMoveEvent(MouseOnMoveEvent event);
        void freeMemory();
        void mouseReleasedEvent(MouseOnReleaseEvent event);
};


#endif