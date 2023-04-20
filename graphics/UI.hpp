#ifndef UI_HPP
#define UI_HPP

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

#include "Display.hpp"

#include "../config/Config.hpp"

#include "objects/Text.hpp"
#include "objects/DebugView.hpp"

#include <sys/types.h>
#include <sys/sysinfo.h>

#include "../dmx_engine/FrameLimit.hpp"
#include "../state/State.hpp"

class UI {
    public:
        UI();
        ~UI();
        void init();
        void start();
        void stop();
        void freeMemory();
        bool isUIRunning();
        void displayStopDialog();
    private:
        bool shouldThreadStop;
        std::vector<Display*> displays;
        
        std::thread eventThread;

        int x = 0, y = 0;
        int sizeMouse = currentConfig.get<int>("graphics.sizeMouse");

        float defaultWaittime = 16.666f;
        float proposedDelay = 0.0f;

        int numDisplays;

        void sdlEventLoop();
};

#endif