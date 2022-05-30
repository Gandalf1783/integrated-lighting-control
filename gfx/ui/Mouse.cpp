#include "Mouse.hpp"


Mouse::Mouse() {
    this->x = 1024/2;
    this->y = 768/2;
    this->wasMouseReleased = false;
};

void Mouse::render(char * imageBuffer, int lineLength) {
    u_int64_t location;
    //printf("this: 0x%x (render)\n", this);
    for(int i = this->x; i < this->x+4; i++) {
        for(int j = this->y; j < this->y+4; j++) {
            location = (i*4) + j * lineLength;
            //printf("x: %u | y: %u\n", this->x,this->y);
            *(imageBuffer + location) = 0xFF;
            *(imageBuffer + location +1) = 0xFF;
            *(imageBuffer + location +2) = 0xFF;
            *(imageBuffer + location +3) = 0x0;
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
    this->left = left;
    this->right = right;
    this->middle = middle;
}
