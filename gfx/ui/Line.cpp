#include "Line.hpp"

Line::Line() {
    this->x1 = 150;
    this->x2 = 100;
    this->y1 = 300;
    this->y2 = 100;
    int dY = y2-y1;
    int dX = x2-x1;
    m = dY/dX;
};

void Line::setFrom(int x, int y) {
    this->x1 = x;
    this->y1 = y;
    m = (y2-y1) / (x2-x1);
};

void Line::setTo(int x, int y) {
    this->x2 = x;
    this->y2 = y;
    m = (y2-y1) / (x2-x1);
};

void Line::render(char * imageBuffer, int lineLength) {
    u_int64_t location;
    int x,y;
    this->y2++;
    //printf("m: %u\n", m);
    if((y2-y1) >= 0) {
        for(int y = y1; y < y2-y1; y++) {
            x = y/m;
            location = ((x1+x) * 4) + ((y1+y) * lineLength);

            *(imageBuffer + location) = 0xFF; //b
            *(imageBuffer + location + 1 ) = 0xFF; //g
            *(imageBuffer + location + 2) = 0xFF; //r
            *(imageBuffer + location + 3) = 0x0;  //a
        }
    } else if((y2-y1) < 0) {
        for(int y = y2; y > 0; y--) {
            x = y/m;
            location = ((x1+x) * 4) + ((y1+y) * lineLength);

            *(imageBuffer + location) = 0xFF; //b
            *(imageBuffer + location + 1 ) = 0xFF; //g
            *(imageBuffer + location + 2) = 0xFF; //r
            *(imageBuffer + location + 3) = 0x0;  //a
        }
    }
};

void Line::mouseMoveEvent(int x, int y) {

};

void Line::freeMemory() {

};

void Line::mouseReleasedEvent(int x, int y) {

}