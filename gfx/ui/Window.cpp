#include "Window.hpp"

Window::Window(std::string title) {
    x = 0; //TODO: Issue when setting x and/or y > 0
    y = 0;
    width = 200;
    height = 200;

    screensizeInBytes = 4096*height*4; // *4 bytes (contains the rgba values)

    windowFramebuffer = (char *) malloc(screensizeInBytes);
    printf("WindowBuffer was created with %u bytes\n", screensizeInBytes);

    this->title = new Text();
    this->title->setText(title);
    this->title->setColor(0xFF, 0xFF, 0xFF);

    Text* t = new Text();
    t->setPos(5,3);
    t->setText("Hello, i'm a text!");
    t->setColor(255,0,0);
    
    this->uiObjects.push_back(t);

    

};


void Window::render(char * imageBuffer, int lineLength) {
    u_int64_t location;
    
    windowFramebuffer = (char *) memset(windowFramebuffer, 0x0, screensizeInBytes);

    for(int i = x; i < x+width; i++) {
        for(int j = y; j < y+height; j++) {
            location =  i * 4 +
                        j * lineLength;
            
            *(imageBuffer + location) = 0xFF; //b
            *(imageBuffer + location + 1) = 0x0; //g
            *(imageBuffer + location + 2) = 0x0; //r
            *(imageBuffer + location + 3) = 0x0; // a
        }
    }

    this->title->setPos(x+(width/2)-(this->title->getCharCount()*8/2),y+(titleHeight/2)-7); // Center the Text
    this->title->render(imageBuffer,lineLength);

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            location =  i * 4 +
                        j * lineLength;
            
            *(windowFramebuffer + location) = 0xA0; //b
            *(windowFramebuffer + location + 1) = 0xA0; //g
            *(windowFramebuffer + location + 2) = 0xA0; //r
            *(windowFramebuffer + location + 3) = 0x0; // a
        }
    }


    //printf("Try this\n");
    // for(int i = 0; i < 100; i++) {
    //     for(int j = 0; j < 50; j++) {
    //             location =  i * 4 +
    //                     j * width*4;
            
    //         *(windowFramebuffer + location) = 0x00; //b
    //         *(windowFramebuffer + location + 1) = 0xFF; //g
    //         *(windowFramebuffer + location + 2) = 0x00; //r
    //         *(windowFramebuffer + location + 3) = 0x0; // a
    //     }
    // }
    
    for(UiObject* uiObject : uiObjects) {
        uiObject->render(windowFramebuffer,lineLength);
    }
    
    if(y<500)
        y++;
    if(x<500) 
        x++;

    for(int j = 0; j < height; j++) {
        u_int64_t test = (j)*lineLength;
        u_int64_t test2 = x*4+(y+j+titleHeight)*lineLength;
        memcpy(imageBuffer+(test2), windowFramebuffer+(test), width*4);
    }

    // u_int64_t test = (y)*lineLength;
    // printf("Memcpy with %u bytes..\n", screensizeInBytes);
    // memcpy(imageBuffer+test, windowFramebuffer, screensizeInBytes/height);
};

void Window::setPos(int x, int y) {
    this->x = x;
    this->y = y;
};

void Window::addUiObject(UiObject* object) {
    this->uiObjects.push_back(object);
}