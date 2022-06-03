#include "UiObject.hpp"
#include "../Framebuffer.hpp"

#ifndef CONTEXTMENU_HPP
#define CONTEXTMENU_HPP

class ContextMenu : public UiObject {
    private:
        int x,y;
    public:
        ContextMenu();
        void render(Framebuffer fb);
        void mouseMoveEvent(int x, int y);
        void freeMemory();
        void mouseReleasedEvent(int x, int y);
};


#endif