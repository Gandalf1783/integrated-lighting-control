#include "InputManager.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <thread>
#include <poll.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

InputManager::InputManager() {
    this->shouldStop = false;
    this->previousLeftClick = false;
};

void InputManager::inputThread() {
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_CYAN "INPUT" ANSI_COLOR_RESET "] ");
    printf("Opening device file /dev/input/mouse0\n");
    
    this->inputFd = open("/dev/input/mice", O_RDWR);

      if(inputFd == -1)
    {
        printf(ANSI_COLOR_RED "[INPUT] ("  ANSI_COLOR_BLUE "mouse0" ANSI_COLOR_RED ") Error: Cannot open " ANSI_COLOR_BLUE "mouse0" ANSI_COLOR_RED " device-file.");
        exit (-10);
    }

    int left, middle, right; // Buttons (= 1 when clicked)
    signed char x, y; // Delta X/Y (offset to last mouse input)
    int bytes; // Number of bytes
    char byte[3]; // Datastream (no longer than 3 bytes)


    pollfd pfd[1];
    pfd[0].fd = inputFd;
    pfd[0].events = POLLIN;
    while(!this->shouldStop)
    {
        // Read Mouse     
        if(poll(pfd, 1, 500) <= 0) {
            continue;
        } else {
            bytes = read(inputFd, byte, sizeof(byte));

            if(bytes > 0)
            {
                left = byte[0] & 0x1;
                right = byte[0] & 0x2;
                middle = byte[0] & 0x4;

                x = byte[1];
                y = byte[2];
            // printf("x=%d, y=%d, left=%d, middle=%d, right=%d\n", x, y, left, middle, right);
                this->m->setDelta(x,y);
                this->m->setMouseButtons(left, right, middle);
                if(this->previousLeftClick == true && left == false) {
    //                printf("Calling Mouse Release!\n\n");
                    this->m->mouseRelease();
                }
                this->previousLeftClick = left;
            } 
        }
    }
    close(inputFd);
}

void InputManager::startThread() {
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_CYAN "INPUT" ANSI_COLOR_RESET "] ");
    printf("Starting InputManager\n");
    inputManagerThread = std::thread(&InputManager::inputThread, this);
};


void InputManager::stopThread() {
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_CYAN "INPUT" ANSI_COLOR_RESET "] ");
    printf("Stopping InputManager...\n");
    this->shouldStop = true;
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_CYAN "INPUT" ANSI_COLOR_RESET "] ");
    printf("Joining Thread...");
    this->inputManagerThread.join();
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_CYAN "INPUT" ANSI_COLOR_RESET "] ");
    printf("Done.\n");
};

void InputManager::setMouse(Mouse* m) {
    this->m = m;
}
