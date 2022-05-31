#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "log/Log.hpp"
#include "gfx/Display.hpp"
#include "gfx/UiManager.hpp"
#include "input/InputManager.hpp"
#include "gfx/ui/Mouse.hpp"
#include "serial/Serial.hpp"
#include <chrono>

using namespace std;

// Global Variable:
Log* logger = new Log();


int main()
{

  cout<<"Starting...";

  Mouse* m = new Mouse();
  UiManager* uiManager = new UiManager();
  InputManager* im = new InputManager();
  Display* d = new Display(0); 
  Serial* serial = new Serial();


  //std::vector<Display> displays;

  serial->start();
  
  uiManager->setMouse(m);
  uiManager->addDisplay(d);
  uiManager->startThread();
  im->setMouse(m);
  im->startThread();
  sleep_for(20s);

  printf("[MAIN] STOPPING\n\n");
  
  uiManager->stopThread();
  uiManager->stop();
  
  im->stopThread();
  
  serial->stop();


  printf("Deleting last references...\n");
  delete uiManager;
  delete im;
  delete m;
  delete serial;



  printf("\n### EXIT ###\n");
  return 0;
}
