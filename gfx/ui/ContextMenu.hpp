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
        void mouseMoveEvent(MouseOnMoveEvent event);
        void freeMemory();
        void mouseReleasedEvent(MouseOnReleaseEvent event);
};


#endif