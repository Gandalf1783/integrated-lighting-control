#include <iostream>
#include <string>

#ifndef UIOBJECT_H
#define UIOBJECT_H

class UiObject {
  private:
    int x,y;
  public:
    UiObject();
    virtual void render(char * imageBuffer, int lineLength) = 0;
    //virtual bool isHovering() = 0;
    virtual void mouseMoveEvent(int x, int y) = 0;
    //virtual void mouseDownEvent() = 0;
    //virtual void mouseReleasedEvent() = 0;
    virtual void freeMemory() = 0;
    virtual ~UiObject() = default;
};

#endif
