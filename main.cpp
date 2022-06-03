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
  printf("Starting\n\n");

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
  printf("[MAIN] FREERUN >>ACTIVE<<\n");

  sleep_for(25s);

  printf("[MAIN] STOPPING\n");
  
  uiManager->stopThread();
  uiManager->stop();
  
  im->stopThread();
  
  serial->stop();


  printf("[MAIN] Deleting last references...\n");
  delete uiManager;
  delete im;
  delete m;
  delete serial;


  printf("\n### EXIT ###\n");
  return 0;
}
