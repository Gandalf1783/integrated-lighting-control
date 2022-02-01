#include <iostream>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <thread>
#include "../gfx/ui/Mouse.hpp"


#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

class InputManager {
    private:
        bool mouseLeft, mouseRight;
        int mouseScroll;
        char inputFd;
        std::thread inputManagerThread;
        bool shouldStop;
        Mouse* m;
    public:
        InputManager();
        void startThread();
        void stopThread();
        void inputThread();
        void registerEventHandler();
        void setMouse(Mouse* m);
};

#endif
