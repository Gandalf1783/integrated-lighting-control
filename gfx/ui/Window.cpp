#include "Window.hpp"

Window::Window(std::string title) {
    x = 0; //TODO: Issue when setting x and/or y > 0
    y = 0;
    width = 600;
    height = 600;

    windowFb.createFramebuffer(width, height-titleHeight);

    this->title = new Text();
    this->title->setText(title);
    this->title->setColor(0xFF, 0xFF, 0xFF);

    Text* t = new Text();
    t->setPos(5,3);
    t->setText("Hello, i'm a text!");
    t->setColor(255,0,0);
    
    this->uiObjects.push_back(t);
    this->stop = false;
    this->isMouseDown = false;
};


void Window::render(Framebuffer fb) {
    if(this->stop) 
        return;
    
    for(int i = x; i < x+width; i++) {
        for(int j = y; j < y+height; j++) {
            fb.setPixel(i,j,0,0,0xFF);
        }
    }

    this->title->setPos(x+(width/2)-(this->title->getCharCount()*8/2),y+(titleHeight/2)-7); // Center the Text
    this->title->render(fb);

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            windowFb.setPixel(i,j,0xA0,0xA0,0xA0);
        }
    }
    
    for(UiObject* uiObject : uiObjects) {
        uiObject->render(this->windowFb);
    }

    fb.integrateFramebuffer(this->windowFb, 0,0,this->width, this->height-this->titleHeight, this->x, this->y+titleHeight);

};

void Window::setPos(int x, int y) {
    if(this->stop) 
        return;

    printf("(%d|%d)\n", x,y);
    /*
    if(x+width>1920 || x < 0)
        return;
    if(y+height+titleHeight>1080 || y < 0)
        return;
      */  
    printf("y+height: %d\n ", (y+height));
    this->x = x;
    this->y = y;
};

void Window::addUiObject(UiObject* object) {
     if(this->stop) 
        return;
    this->uiObjects.push_back(object);

};

void Window::mouseMoveEvent(int x, int y) {
    if(this->stop) 
            return;
            
    if(this->isMouseDown) {
        printf("SETTING PIXELS\n");
        this->setPos(x,y);
        /*
        // If cursor is inside titleBar:
        if(x >= this->x && x < this->x+this->width) {
            // Then Drag the window around

            if(y >= this->y && y < this->y+this->titleHeight) {

            }
        }
        */
        
    }
};

void Window::mouseReleasedEvent(int x, int y) {
    //this->stop = true;
    this->isMouseDown = false;
}

void Window::mouseDownEvent() {
    printf("MOUSE DOWN\n");
    this->isMouseDown = true;
}

void Window::freeMemory() {
    for(UiObject* o : this->uiObjects) {
        o->freeMemory();
        delete o;
    }
    this->uiObjects.clear();
    this->title->freeMemory();
    this->windowFb.destroyFramebuffer();
    delete this->title;
};
