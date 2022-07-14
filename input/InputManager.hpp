#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <thread>
#include "../gfx/ui/Mouse.hpp"


#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include "../gfx/UiManager.hpp"

class UiManager;

class InputManager {
    private:
        char inputFd;
        std::thread inputManagerThread;
        bool shouldStop;
        bool left, middle, right; // Buttons (= 1 when clicked)
        int x, y, mouseScroll;
        signed char dX, dY; // Delta X/Y (offset to last mouse input)
        UiManager* uiM;
    public:
        InputManager();
        void startThread();
        void stopThread();
        void inputThread();
        void registerEventHandler();
        void resetDelta();
        signed char getDX();
        signed char getDY();
        int getX();
        int getY();
        bool getLeft();
        void setUiM(UiManager* uiM);
};

#endif
