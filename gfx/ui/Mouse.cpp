#include "Mouse.hpp"


Mouse::Mouse() {
    this->lastX = 0;
    this->lastY = 0;
    this->x = 0;
    this->y = 0;
    this->wasMouseReleased = false;
    this->setMouseButtons(false, false, false);
};

void Mouse::render(Framebuffer fb) {
    u_int64_t location;
    //printf("this: 0x%x (render)\n", this);
    for(int i = this->x; i < this->x+4; i++) {
        for(int j = this->y; j < this->y+4; j++) {
            fb.setPixel(i,j,0xFF,0xFF,0xFF);
        };
    };
};

void Mouse::setPos(int x, int y) {
    this->lastX = this->x;
    this->lastY = this->y;
    this->x = x;
    this->y = y;

    //printf("X: %d Y: %d\n", this->x, this->y);
};

void Mouse::mouseMoveEvent(MouseOnMoveEvent event) {

};

int Mouse::getX() {
    return this->x;
};

int Mouse::getY() {
    return this->y;
};

void Mouse::freeMemory() {

};

void Mouse::mouseReleasedEvent(MouseOnReleaseEvent event) {

};

void Mouse::mouseDownEvent(MouseOnDownEvent event) {

};

bool Mouse::evaluateIfChanged() {
    return (lastX-x != 0) || (lastY-y != 0);
}

void Mouse::mouseRelease() {
    this->wasMouseReleased = true;
}

bool Mouse::getMouseReleased() {
    bool ret = this->wasMouseReleased;
    this->wasMouseReleased = false;
    return ret;
}
bool Mouse::getMouseLeftDown() {
    
    return this->left;
}

void Mouse::setMouseButtons(bool left, bool right, bool middle) {
    //printf(this->left ? "MOUSE SET: true\n" : "MOUSE SET: false\n");
    this->left = left;
    this->right = right;
    this->middle = middle;
}
