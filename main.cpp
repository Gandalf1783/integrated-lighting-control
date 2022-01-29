#include <iostream>

#include "gfx/Display.hpp"
#include "gfx/UiManager.hpp"
#include <chrono>

using namespace std;


int main()
{
  cout<<"Starting...";

  UiManager uiManager;
  Display d(0);


  char * framebuffer = d.getFrameBuffer();
  printf("MAIN: %x framebuffer", framebuffer);
  
  uiManager.addDisplay(d);
  uiManager.startThread();
  sleep_for(15s);
  printf("Stopping the Thread and joining...\n\n");
  uiManager.stopThread();
  uiManager.stop();
  return 0;
}
