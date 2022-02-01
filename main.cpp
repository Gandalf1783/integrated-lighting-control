#include <iostream>
#include "gfx/Display.hpp"
#include "gfx/UiManager.hpp"
#include "input/InputManager.hpp"
#include "gfx/ui/Mouse.hpp"
#include <chrono>

using namespace std;



int main()
{
  cout<<"Starting...";
  Mouse* m = new Mouse();
  UiManager uiManager;
  InputManager im;
  Display d(0);

  char * framebuffer = d.getFrameBuffer();
  uiManager.addUiObject(m);
  uiManager.addDisplay(d);
  uiManager.startThread();
  im.setMouse(m);
  im.startThread();
  sleep_for(15s);

  printf("[MAIN] STOPPING\n\n");
  
  uiManager.stopThread();
  uiManager.stop();

  im.stopThread();

  printf("\n ### EXIT ### \n");
  return 0;
}
