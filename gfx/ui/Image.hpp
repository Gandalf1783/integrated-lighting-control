#include <iostream>
#include <string>
#include "UiObject.hpp"
#include "../Framebuffer.hpp"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include "stb_image.h"

#ifndef IMAGE_H
#define IMAGE_H

using std::string;

class Image : public UiObject {
  private:
    unsigned char *img;
    int width, height, channels;
    int x,y;
  public:
    Image();
    void loadImage(char * path);
    void mouseMoveEvent(int x, int y);
    void render(Framebuffer fb);
    void setPos(int x, int y);
    void freeMemory();
    void mouseReleasedEvent();
    void mouseReleasedEvent(int x, int y);
};

#endif
