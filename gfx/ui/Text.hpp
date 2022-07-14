#include <iostream>
#include <string.h>
#include "UiObject.hpp"
#include "Rectangle.hpp"
#include "../bitmapfont/Font.cpp"
#include "../Framebuffer.hpp"


#ifndef TEXT_HPP
#define TEXT_HPP

#define STB_TRUETYPE_IMPLEMENTATION
#define STBTT_STATIC
#include "stb_truetype.hpp"


class Text : public UiObject {

    private:
        int x,y;
        int maxPixelWidth;
        std::string text;
        char r,g,b;
    public:
        Text();
        Text(std::string s);
        Text(char* s);
        void setColor(char r, char g, char b);
        void render(Framebuffer fb);
        void setText(std::string text);
        void setPos(int x, int y);
        int getCharCount();
        void mouseMoveEvent(MouseOnMoveEvent event);
        void mouseReleasedEvent(MouseOnReleaseEvent event);
        void mouseDownEvent(MouseOnDownEvent event);
        void freeMemory();
        
};

#endif