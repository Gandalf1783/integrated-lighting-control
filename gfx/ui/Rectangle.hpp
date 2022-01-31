#include "UiObject.hpp"

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle : public UiObject {
    private:
        int x,y;
        int width,height;
        int r,g,b;
    public:
        Rectangle();
        void render(char * imageBuffer, int lineLength);
        void setPos(int x, int y);
        void setDimensions(int width, int height);
        void setColor(char r, char g, char b);
};

#endif