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
    // Only god knows what I did here. 

    for(int i = 0; i < text.size(); i++) {
        char c = text[i];
        if(c > 31 && c < 127) { //Checks if the character is in range to be ascii valid.
            c = c-32; // Subtracts 32 to be at start of character array
        }

        for(int j = 12; j > 0; j--) { //For every 12 lines of vertical pixels of a single char
            char d = font[c][j]; // Chacter array. First is character selection, 2nd is row selection of the pixels.
            for(int k = 0; k < 8; k++) { // For every col of the character pixels
                if(((d>>k) & 0x1) == true) { // Check if the bit is set
                    fb.setPixel((x+(i*9+abs(k-8))) ,(y+abs(j-12)),r,g,b);  //Sets the pixel with this weird calculation. Dont even think about asking.
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