#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <string.h>

#include "../config/Config.hpp"

#include "objects/Text.hpp"
#include "objects/DebugView.hpp"
#include "objects/Texture.hpp"
#include "objects/Grid.hpp"
#include "objects/Textbox.hpp"

class UiObject;

class Display {

    public:
        Display(unsigned int displayNum);
        ~Display();
        void start();
        void stop();
        SDL_Rect* getDisplayDimensions();
        
    private:
        SDL_Rect* displayDimensions;
        SDL_Window* window;
        SDL_Renderer* renderer;

        bool shouldThreadStop;
        bool showDebug;
        unsigned int displayNum;

        float fps;
        float frameTime;
        unsigned int frameCount;

        std::thread renderThread;
        std::vector<UiObject*> uiObjects;

        void renderLoop();
};

#endif