#include "ContextMenu.hpp"


void ContextMenu::render(Framebuffer fb) {

    u_int64_t location;

    for(int i = x; i < x+100; i++) {
        for(int j = y; j < y+100; j++) {
            fb.setPixel(i,j,0x70,0x70,0x70);
        }
    }
};

void ContextMenu::mouseMoveEvent(MouseOnMoveEvent event) {

};


void ContextMenu::freeMemory() {

};

void ContextMenu::mouseReleasedEvent(MouseOnReleaseEvent event) {

}
