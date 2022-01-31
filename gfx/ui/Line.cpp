#include "Line.hpp"

Line::Line() {
    printf("Construct!\n");
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
    int y = 0;
    //printf("m: %u\n", m);
    if((x2-x1) >= 0) {
        for(int x = 0; x < (x2-x1); x++) {
            y = x*m;
            location = ((x1+x) * 4) + ((y1+y) * lineLength);

            *(imageBuffer + location) = 0xFF; //b
            *(imageBuffer + location + 1 ) = 0xFF; //g
            *(imageBuffer + location + 2) = 0xFF; //r
            *(imageBuffer + location + 3) = 0x0;  //a
        }
    } else if((x2-x1) < 0) {
        for(int x = 0; x > (x2-x1); x--) {
            y = x*m;
            location = ((x1+x) * 4) + ((y1-y) * lineLength);

            *(imageBuffer + location) = 0xFF; //b
            *(imageBuffer + location + 1 ) = 0xFF; //g
            *(imageBuffer + location + 2) = 0xFF; //r
            *(imageBuffer + location + 3) = 0x0;  //a
        }
    }
};