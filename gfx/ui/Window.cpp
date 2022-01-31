#include "Window.hpp"


Window::Window(std::string title) {
    x = 100; //TODO: Issue when setting x and/or y > 0
    y = 100;
    width = 500;
    height = 500;

    screensizeInBytes = width*height*4/8; // *4 bytes / 8 bit pro pixel

    windowFramebuffer = (char *) malloc(screensizeInBytes); // Height * Width * 4 Bytes * 8 Bits => Calculates Size of window content in bytes!
    printf("WindowBuffer was created with %u bytes\n", screensizeInBytes);

    this->title = new Text();
    this->title->setText(title);
    this->title->setColor(0xFF, 0xFF, 0xFF);


    Text* t = new Text();
    t->setPos(10,10);
    t->setText("Hello, i'm a text!");
    t->setColor(255,0,0);
    this->uiObjects.push_back(t);
};


void Window::render(char * framebuffer) {
    if(this->x < 200) {
        this->x++;
    }
    if(this->y < 200) {
        this->y++;
    }
    
    u_int64_t location;
    
    windowFramebuffer = (char *) memset(windowFramebuffer, 0x0, screensizeInBytes);

    for(int i = x; i < x+width; i++) {
        for(int j = y; j < y+titleHeight; j++) {
            location =  i * 4 +
                        j * 4096;
            
            *(framebuffer + location) = 0xFF; //b
            *(framebuffer + location + 1) = 0x0; //g
            *(framebuffer + location + 2) = 0x0; //r
            *(framebuffer + location + 3) = 0x0; // a
        }
    }

    for(int i = x; i < x+width; i++) {
        for(int j = y+titleHeight; j < y+height; j++) {
            location =  i * 4 +
                        j * 4096;
            *(framebuffer + location) = 0xAE; //b
            *(framebuffer + location + 1) = 0xAE; //g
            *(framebuffer + location + 2) = 0xAE; //r
            *(framebuffer + location + 3) = 0x0; // a
        }
    }

    this->title->setPos(x+(width/2)-20,y+(titleHeight/2)-7); // Center the Text
    this->title->render(framebuffer);
    
    
    for(UiObject* uiObject : uiObjects) {
        uiObject->render(windowFramebuffer);
    }
    u_int64_t test = ((x*4)+((y+titleHeight)*4096));
    printf("Memcpy...\n");
    memcpy(framebuffer+test, windowFramebuffer, screensizeInBytes);
};

void Window::setPos(int x, int y) {
    this->x = x;
    this->y = y;
};

void Window::addUiObject(UiObject* object) {
    this->uiObjects.push_back(object);
}