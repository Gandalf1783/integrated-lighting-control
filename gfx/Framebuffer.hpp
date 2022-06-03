#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP

class Framebuffer {
    	private:
            int sizeX; // Size of the encapsuled framebuffer
            int sizeY;
            unsigned char *framebuffer;
            char canBeUsed;
            char isBeingAccessed;
        public:
            void createFramebuffer(int sizeX, int sizeY);
            unsigned char * getFramebuffer();
            void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
            void destroyFramebuffer();
            int getSizeX();
            int getSizeY();
            unsigned char * copyFramebuffer();
            unsigned char * getRowOfFramebuffer(int y);
            void integrateFramebuffer(Framebuffer foreignFb, int foreignX, int foreignY, int foreignWidth, int foreignHeight, int localX, int localY);
};

#endif