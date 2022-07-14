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
    this->x = 1024/2;
    this->y = 768/2;
    this->left = false;
    this->right = false;
    this->middle = false;
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

    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_CYAN "INPUT" ANSI_COLOR_RESET "] ");
    printf("/dev/input/mouse0 has been opened!\n");

 
    int bytes; // Number of bytes
    char byte[3]; // Datastream (no longer than 3 bytes)


    pollfd pfd[1];
    pfd[0].fd = inputFd;
    pfd[0].events = POLLIN;

    while(!this->shouldStop)
    {
        // Read Mouse     
        if(poll(pfd, 1, 500) <= 0) { // Sees if any data has been received in 500ms. If not, just continue.
            continue;
        } else {
            bytes = read(inputFd, byte, sizeof(byte)); // Read the received bytes.

            if(bytes > 0)
            { // Now just pass them around into their variables
                left = byte[0] & 0x1;
                right = (byte[0] & 0x2);
                middle = (byte[0] & 0x4);

                dX = byte[1];
                dY = byte[2];

                x += dX;
                y -= dY;

                this->uiM->mouseInput();
                //printf("dx=%d, dy=%d, left=%d, middle=%d, right=%d\n", dX, dY, left, middle, right);
                
                dX = 0;
                dY = 0;
            } 
        }
    }
    close(inputFd);
}

void InputManager::startThread() {
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_CYAN "INPUT" ANSI_COLOR_RESET "] ");
    printf("Starting InputManager\n");
    inputManagerThread = std::thread(&InputManager::inputThread, this); // Starts a new thread for the input mechanism
};


void InputManager::stopThread() { // Just stops the input manager.
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_CYAN "INPUT" ANSI_COLOR_RESET "] ");
    printf("Stopping InputManager...\n");
    this->shouldStop = true;
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_CYAN "INPUT" ANSI_COLOR_RESET "] ");
    printf("Joining Thread...");
    this->inputManagerThread.join(); // Wait until Thread has exited. 
    printf(ANSI_COLOR_RESET "[" ANSI_COLOR_CYAN "INPUT" ANSI_COLOR_RESET "] ");
    printf("Done.\n");
};

void InputManager::resetDelta() {
    this->dX = 0;
    this->dY = 0;
}

signed char InputManager::getDX() {
    return this->dX;
}
signed char InputManager::getDY() {
    return this->dY;
}

int InputManager::getX() {
    return this->x;
}
int InputManager::getY() {
    return this->y;
}
bool InputManager::getLeft() {
    return this->left;
}


void InputManager::setUiM(UiManager* uiM) {
    this->uiM = uiM;
}