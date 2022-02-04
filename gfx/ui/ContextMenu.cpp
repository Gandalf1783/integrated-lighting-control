#include "ContextMenu.hpp"


void ContextMenu::render(char * imageBuffer, int lineLength) {

    u_int64_t location;

    for(int i = x; i < x+100; i++) {
        for(int j = y; j < y+100; j++) {

            location = (i*4) + (j * 4096);

            *(imageBuffer + location) = 0x70; //B
            *(imageBuffer + location +1) = 0x70; //G
            *(imageBuffer + location +2) = 0x70; //R
            *(imageBuffer + location +3) = 0x0; //A
        }
    }
};

void ContextMenu::mouseMoveEvent(int x, int y) {

};


void ContextMenu::freeMemory() {

};

