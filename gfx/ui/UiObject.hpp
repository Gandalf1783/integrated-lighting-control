#include <iostream>
#include <string>
#include "../Framebuffer.hpp"

#ifndef UIOBJECT_H
#define UIOBJECT_H

typedef struct {
    int x,y;
    int width, height;
} uiObjectInfo;

class UiObject {
  private:
    int x,y;
    uiObjectInfo objectInfo;
  public:
    UiObject();
    uiObjectInfo getUiObjectInfo();
    virtual void render(Framebuffer fb) = 0;
    //virtual bool isHovering() = 0;
    virtual void mouseMoveEvent(int x, int y) = 0;
    virtual void mouseDownEvent() = 0;
    virtual void mouseReleasedEvent(int x, int y) = 0;
    virtual void freeMemory() = 0;
    virtual ~UiObject() = default;

};

#endif
