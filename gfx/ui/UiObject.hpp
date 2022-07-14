#include <iostream>
#include <string>
#include "../Framebuffer.hpp"
#include "MouseEventStructs.hpp"

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
    virtual void mouseMoveEvent(MouseOnMoveEvent event) = 0;
    virtual void mouseDownEvent(MouseOnDownEvent event) = 0;
    virtual void mouseReleasedEvent(MouseOnReleaseEvent event) = 0;
    virtual void freeMemory() = 0;
    virtual ~UiObject() = default;

};

#endif
