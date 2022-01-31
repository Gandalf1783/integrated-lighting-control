#include "UiObject.hpp"
#include <string.h>
#include <vector>
#include "Text.hpp"
#include "Rectangle.hpp"
#include "ProgressBar.hpp"
#include "Image.hpp"

#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window : public UiObject {

    private:
        int x,y;
        int width,height;
        const int titleHeight = 40;
        Text *title;
        std::vector<UiObject*> uiObjects;
        u_int64_t screensizeInBytes;
        char * windowFramebuffer;
    public:
        Window(std::string title);
        void render(char * imageBuffer, int lineLength);
        void setPos(int x, int y);
        void addUiObject(UiObject* object);

};


#endif