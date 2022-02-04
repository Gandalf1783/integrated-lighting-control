#include "UiObject.hpp"

#ifndef CONTEXTMENU_HPP
#define CONTEXTMENU_HPP

class ContextMenu : public UiObject {
    private:
        int x,y;
    public:
        ContextMenu();
        void render(char * imageBuffer, int lineLength) = 0;
        void mouseMoveEvent(int x, int y);
        void freeMemory();
};


#endif