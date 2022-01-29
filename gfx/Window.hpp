#include <iostream>
#include <vector>
#include "Image.hpp"

#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {

  private:
    int x,y;
    int width,height;
    std::vector<Image> images;
    //std::vector<Button> buttons;
    //std::vector<Text> texts;

  public:

    void render(char * imageBuffer);

};

#endif
