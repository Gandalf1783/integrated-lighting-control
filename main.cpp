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
  UiManager* uiManager = new UiManager();
  InputManager* im = new InputManager();
  Display* d = new Display(0);

  uiManager->setMouse(m);
  uiManager->addDisplay(d);
  uiManager->startThread();
  im->setMouse(m);
  im->startThread();
  sleep_for(5s);

  printf("[MAIN] STOPPING\n\n");
  
  uiManager->stopThread();
  uiManager->stop();
  
  im->stopThread();


  printf("Deleting last references...\n");
  delete uiManager;
  delete im;
  delete m;

  printf("\n### EXIT ###\n");
  return 0;
}
