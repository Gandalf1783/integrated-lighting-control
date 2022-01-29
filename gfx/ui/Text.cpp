#include "Text.hpp"


Text::Text() {

};

Text::Text(std::string s) {

};

Text::Text(char* s) {

};

void Text::setColor(char r, char g, char b) {
    this->r = r;
    this->g = g;
    this->b = b;
};

void Text::setText(std::string text) {
    this->text = text;
}

void Text::render(char * imageBuffer) {
    u_int64_t location;
    for(int i = 0; i < text.size(); i++) {
        char c = text[i];
        if(c > 31 && c < 127) {
            c = c-32;
        }
        for(int j = 12; j > 0; j--) {
            char d = font[c][j];
            
            for(int k = 0; k < 8; k++) {
                location =  (i*8+abs(k-8)) * 4 + abs(j-12) * 4096;
                if(((d>>k) & 0x1) == true) {
                    *(imageBuffer + location) = b;
                    *(imageBuffer + location +1) = g;
                    *(imageBuffer + location +2) = r;
                    *(imageBuffer + location +3) = 0x0;
                }
            }
        }
    }
/*
    for(int i = 0; i < 95; i++) {
        for(int j = 12; j > 0; j--) {
            char c = font[i][j];
            
            for(int k = 0; k < 8; k++) {
                location =  (i*8+abs(k-8)) * 4 + abs(j-12) * 4096;
                if(((c>>k) & 0x1) == true) {
                    *(imageBuffer + location) = b;
                    *(imageBuffer + location +1) = g;
                    *(imageBuffer + location +2) = r;
                    *(imageBuffer + location +3) = 0x0;
                }
            }
        }
    }*/
};

void Text::setPos(int x, int y) {
    this->x = x;
    this->y = y;
};

