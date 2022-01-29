#include <iostream>
#include <string>
#include "UiObject.hpp"
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
    int line_length;
    int x,y;
  public:
    Image();
    void loadImage(char * path, int line_length);
    void render(char * imageBuffer);
    void setPos(int x, int y);
};

#endif
