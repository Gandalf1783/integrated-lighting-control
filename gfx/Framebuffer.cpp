#include "Framebuffer.hpp"

int minInt(int a, int b) {
    return ( a < b ? a : b);
};

void Framebuffer::createFramebuffer(int sizeX, int sizeY) {

    this->sizeX = sizeX;
    this->sizeY = sizeY;

    this->framebuffer = (unsigned char *) malloc(sizeX * sizeY * 4); // Assume Format: BGRA (4 channels á 1 Byte)
    
    this->canBeUsed = true;
};


void Framebuffer::setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    
    if(x >= this->sizeX || x < 0)
        return;
    if(y >= this->sizeY || y < 0)
        return;

    if(!this->canBeUsed)
        return;

    this->isBeingAccessed = true;
    
    int location =  x * 4 + 
                    y * (this->sizeX*4);

    *(this->framebuffer + location   ) = b;
    *(this->framebuffer + location +1) = g;
    *(this->framebuffer + location +2) = r;
    *(this->framebuffer + location +3) = 0x0;

    this->isBeingAccessed = false;
};


unsigned char * Framebuffer::getFramebuffer() {
    return this->framebuffer;
};

void Framebuffer::destroyFramebuffer() {

    while(this->isBeingAccessed) {}
    this->canBeUsed = false;
    while(this->isBeingAccessed) {}
    
    free(this->framebuffer);
};

int Framebuffer::getSizeX() {
    return this->sizeX;
};

int Framebuffer::getSizeY() {
    return this->sizeY;
};

unsigned char * Framebuffer::copyFramebuffer() {
    unsigned char * array;
    array = (unsigned char *) malloc(this->sizeX * this->sizeY * 4);

    memcpy(array, this->framebuffer, (this->sizeX * this->sizeY * 4));
    return array;
};

/*
    Copies the content of the foreign Framebuffer into the local one. Specify from where to where!
*/
void Framebuffer::integrateFramebuffer(Framebuffer foreignFb, int foreignX, int foreignY, int foreignWidth, int foreignHeight, int localX, int localY) {    
    int boundsX, boundsY;

    

    if(foreignX < 0 || foreignY < 0)
        return;
    if(foreignWidth < 0 || foreignHeight < 0)
        return;

    boundsX = minInt(minInt(foreignWidth,  foreignFb.getSizeX()), this->sizeX);
    boundsY = minInt(minInt(foreignHeight, foreignFb.getSizeY()), this->sizeY);

    unsigned char * foreignFramebuffer;
    foreignFramebuffer = foreignFb.getFramebuffer();

    char r,g,b;
    
    for(int y = foreignY; y < boundsY; y++) {
        
        for(int x = foreignX; x < boundsX; x++) {
            
            int location = x*4 + y * foreignFb.getSizeX() * 4;
            


            b = *(foreignFramebuffer + location);
            g = *(foreignFramebuffer + location+1);
            r = *(foreignFramebuffer + location+2);

            this->setPixel(localX+x, localY+y, r,g,b);

        }
    }

    /*
    for(int y = foreignY; y < boundsY; y++) {
        int locationForeign = foreignX *4 + y * foreignFb.getSizeX() * 4;
        memcpy(this->getFramebuffer()+(localX * 4 + (localY+y) * 4 * this->getSizeX()), foreignFb.getFramebuffer()+(locationForeign), boundsX*4);
    }
    */
}
