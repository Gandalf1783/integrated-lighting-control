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
    this->isDragging = false;
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
            windowFb.setPixel(i,j,0x4A, 0x4A, 0x4A);
        }
    } 

    for(UiObject* uiObject : uiObjects) {
        uiObject->render(this->windowFb);
    }

    fb.integrateFramebuffer(this->windowFb, 0,0,this->width, this->height - this->titleHeight, this->x, this->y+titleHeight);
};

void Window::setPos(int x, int y) {
    if(this->stop) 
        return;
        
    this->x = x;
    this->y = y;
};

void Window::addUiObject(UiObject* object) {
     if(this->stop) 
        return;
    this->uiObjects.push_back(object);

};

void Window::mouseMoveEvent(MouseOnMoveEvent event) {
    if(this->stop) 
            return;
    
    int x,y;
    x = event.x;
    y = event.y;
    if(isDragging && event.left) {
        this->setPos(this->x+event.dX,this->y+event.dY);
        return;
    }
    //printf("%u, %u \n",x,y);
    if(event.left) {
        //printf("SETTING PIXELS\n");
        

        // If cursor is inside titleBar:
        if(x >= this->x && x < this->x+this->width) {
            // Then Drag the window around

            if(y >= this->y && y < this->y+this->titleHeight) {
                isDragging = true;
                this->setPos(this->x+event.dX,this->y+event.dY);
            }
        }
    }
};

void Window::mouseReleasedEvent(MouseOnReleaseEvent event) {
}

void Window::mouseDownEvent(MouseOnDownEvent event) {
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
