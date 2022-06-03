#include "UiManager.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

UiManager::UiManager() {
  std::cout<<"Acquiring "<<ANSI_COLOR_YELLOW<<"tty2"<<ANSI_COLOR_RESET<<" and changing to graphics mode...\n";
  ttyfd = open("/dev/tty2", O_RDWR);
  ioctl(ttyfd,VT_ACTIVATE,2);
  ioctl(ttyfd, VT_WAITACTIVE, 2);
  ioctl(ttyfd, KDSETMODE, KD_GRAPHICS);
  this->shouldStop = false;
  this->displayFPS = true;
  this->timeA = std::chrono::system_clock::now();
  this->timeB = std::chrono::system_clock::now();
  this->work_time = timeA-timeB;
};

void UiManager::stop() {
  for(Display* d : displayArray) {
    d->stopDisplay();
    delete d;
  }
  this->displayArray.clear();

  for(UiObject* o : uiArray) {
    o->freeMemory(); // Free all memory that is inside the objects
    delete o; // Delete the Object
  }
  this->uiArray.clear();
  ioctl(ttyfd, KDSETMODE, KD_TEXT);
  ioctl(ttyfd,VT_ACTIVATE,1);
  ioctl(ttyfd, VT_WAITACTIVE, 1);
  close(ttyfd);
  printf("Changing to text mode and acquiring tty1\n");
};

void UiManager::renderDisplays() {
  printf(ANSI_COLOR_RESET "[" ANSI_COLOR_GREEN "RENDER" ANSI_COLOR_RESET "]");
  printf(" Render thread has been started\n");
  printf(ANSI_COLOR_RESET "[" ANSI_COLOR_GREEN "RENDER" ANSI_COLOR_RESET "]");
  printf(" (%x)\n", this);
  while(!this->shouldStop) {
    // FPS LOOP
    timeA = std::chrono::system_clock::now(); // Begin of the measurement
    work_time = timeA-timeB;
    if(work_time.count() < 16) {
      std::chrono::duration<double, std::milli> delta_ms(16.0 - work_time.count());
      auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
      std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
    }
    timeB = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> sleep_time = timeB-timeA;
    // FPS LOOP END
    // (ca. 60 FPS)
    int mouseX, mouseY;
    mouseX = this->m->getDX();
    mouseY = this->m->getDY();
    this->mouseMoveEvent(mouseX, mouseY);
    if(this->m->getMouseLeftDown()) {
      printf("UI MANAGER MOUSE DOWN\n");
      this->mouseOnDownEvent(this->m->getX(), this->m->getY());
    }
    if(this->m->getMouseReleased() == true) {
//      printf("IMMA CALL MOUSE RELEASE!\n");
      this->mouseOnReleaseEvent(this->m->getX(), this->m->getY());
    }

    // RENDER CODE:
    for(Display* d: displayArray) {
      char * framebuffer = d->getFrameBuffer();
      int lineLength = d->getLineLength();
      Framebuffer fb;
      fb.createFramebuffer(d->getScreenInfo().xres, d->getScreenInfo().yres);

      // printf("uiArray: %x\n", uiArray);
      // printf("&uiArray: %x\n", &uiArray);
      
      for(UiObject* pObject : uiArray) {
        // printf("[RENDER] (%x) Rendering Object...", pObject);
        pObject->render(fb);
        
      } 

      this->m->render(fb);

      unsigned char * fbCopy = fb.copyFramebuffer();

      memcpy(d->getFrameBuffer(), fbCopy, (d->getScreenInfo().xres * d->getScreenInfo().yres * 4));

      d->renderDisplay();

      free(fbCopy);
      fb.destroyFramebuffer();
    }
    

    // printf("[RENDER] Loop-Time: %f \n", (work_time + sleep_time).count());
  }
};

void UiManager::addDisplay(Display* d) {
  displayArray.push_back(d);
  
  Window* w = new Window("Test!");
  //Window* w2 = new Window("Systemeinstellungen!");
  

  //w2->addUiObject(i);
  //printf("Image pointer: %x\n", &i);
  //uiArray.push_back(t);
  //w->addUiObject(i);
  //w->addUiObject(pBar);

  //uiArray.push_back(i);
  //uiArray.push_back(w2);
  uiArray.push_back(w);
  //uiArray.push_back(i);
}
void UiManager::addUiObject(UiObject* o) {
  this->uiArray.push_back(o);
};

void UiManager::startThread() {
  printf(ANSI_COLOR_RESET "[" ANSI_COLOR_GREEN "RENDER" ANSI_COLOR_RESET "] ");
    printf("Starting UiManager\n");
    uiManagerThread = std::thread(&UiManager::renderDisplays, this);
};

void UiManager::stopThread() {
  printf(ANSI_COLOR_RESET "[" ANSI_COLOR_GREEN "RENDER" ANSI_COLOR_RESET "] ");
  printf("Stopping Thread\n");
  this->shouldStop = true;
  uiManagerThread.join();
  printf(ANSI_COLOR_RESET "[" ANSI_COLOR_GREEN "RENDER" ANSI_COLOR_RESET "] ");
  printf("Thread has stopped.\n");
};


void UiManager::mouseMoveEvent(int x, int y) {
  for(UiObject* o : uiArray) {
      o->mouseMoveEvent(x,y);
  }
};

void UiManager::closeWindow(Window* window) {
  for(UiObject* o : uiArray) {
    if(o == window) {
      o->freeMemory();
    }
  }
};

void UiManager::mouseOnDownEvent(int x, int y) {
  for(UiObject* o : uiArray) {
      o->mouseDownEvent();
  }
};


void UiManager::mouseOnReleaseEvent(int x, int y) {
    for(UiObject* o : uiArray) {
      o->mouseReleasedEvent(x,y);
  }
};

void UiManager::mouseOnRightClickEvent(int x, int y) {

};

void UiManager::setMouse(Mouse* m) {
  this->m = m;
  printf("MOUSE HAS BEEN SET!\n");
}
