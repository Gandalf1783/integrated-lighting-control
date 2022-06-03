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

void Text::render(Framebuffer fb) {
    for(int i = 0; i < text.size(); i++) {
        char c = text[i];
        if(c > 31 && c < 127) {
            c = c-32;
        }
        for(int j = 12; j > 0; j--) {
            char d = font[c][j];
            for(int k = 0; k < 8; k++) {
                if(((d>>k) & 0x1) == true) {
                    fb.setPixel((x+(i*9+abs(k-8))) ,(y+abs(j-12)),r,g,b);
                }
            }
        }
    }
};

int Text::getCharCount() {
    return this->text.length();
};

void Text::setPos(int x, int y) {
    this->x = x;
    this->y = y;
};

void Text::mouseMoveEvent(int x, int y) {

};

void Text::freeMemory() {

};

void Text::mouseReleasedEvent(int x, int y) {

}

void Text::mouseDownEvent() {
    
}