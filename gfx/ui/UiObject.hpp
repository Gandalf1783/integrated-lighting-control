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
    virtual ~UiObject() = default;
};

#endif
