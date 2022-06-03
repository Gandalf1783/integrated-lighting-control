#include "Mouse.hpp"


Mouse::Mouse() {
    this->x = 1024/2;
    this->y = 768/2;
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
    this->x = x;
    this->y = y;
};

void Mouse::setDelta(int dX, int dY) {
    this->x = this->x+dX;
    this->y = this->y-dY;
}

void Mouse::mouseMoveEvent(int x, int y) {

};

int Mouse::getX() {
    return this->x;
};

int Mouse::getY() {
    return this->y;
};

int Mouse::getDX() {
    return this->x;
};

int Mouse::getDY() {
    return this->y;
};

void Mouse::freeMemory() {

};

void Mouse::mouseReleasedEvent(int x, int y) {

};

void Mouse::mouseDownEvent() {

};

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
