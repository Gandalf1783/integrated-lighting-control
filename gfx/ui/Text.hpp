#include <iostream>
#include <string.h>
#include "UiObject.hpp"
#include "Rectangle.hpp"
#include "../bitmapfont/Font.cpp"



#ifndef TEXT_HPP
#define TEXT_HPP

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
        void render(char * imageBuffer, int lineLength);
        void setText(std::string text);
        void setPos(int x, int y);
        int getCharCount();
        void mouseMoveEvent(int x, int y);
        void mouseReleasedEvent(int x, int y);
        void freeMemory();
        
};

#endif