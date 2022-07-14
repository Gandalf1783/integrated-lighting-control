#include <iostream>
#include <string>
#include "UiObject.hpp"
#include "../Framebuffer.hpp"



#ifndef IMAGE_H
#define IMAGE_H

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include "stb_image.h"

using std::string;

class Image : public UiObject {
  private:
    unsigned char *img;
    int width, height, channels;
    int x,y;
  public:
    Image();
    void loadImage(char * path);
    void mouseMoveEvent(MouseOnMoveEvent event);
    void render(Framebuffer fb);
    void setPos(int x, int y);
    void freeMemory();
    void mouseReleasedEvent();
    void mouseReleasedEvent(MouseOnReleaseEvent event);
};

#endif
