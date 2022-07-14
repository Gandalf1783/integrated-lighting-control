#include "UiManager.hpp"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

/*
  #############
  # This is the UI Manager. It manages (obviously) everything UI related.
  # It aquires the tty and gives it back as soon as the stop methods are called. 
  #############
*/

UiManager::UiManager() {
  std::cout << "Acquiring " << ANSI_COLOR_YELLOW << "tty2" << ANSI_COLOR_RESET << " and changing to graphics mode...\n";
  ttyfd = open("/dev/tty2", O_RDWR);
  ioctl(ttyfd, VT_ACTIVATE, 2);
  ioctl(ttyfd, VT_WAITACTIVE, 2);
  ioctl(ttyfd, KDSETMODE, KD_GRAPHICS);
  this -> shouldStop = false;
  this -> displayFPS = true;
  this -> timeA = std::chrono::system_clock::now();
  this -> timeB = std::chrono::system_clock::now();
  this -> work_time = timeA - timeB;
};

void UiManager::addDisplay(Display * d) {
  displayArray.push_back(d);

  Window* w = new Window("Test!");
  //Window * w2 = new Window("Systemeinstellungen!");

  uiArray.push_back(w);
  //uiArray.push_back(w);
}

void UiManager::renderDisplays() {
  printf(ANSI_COLOR_RESET "["
    ANSI_COLOR_GREEN "RENDER"
    ANSI_COLOR_RESET "]");
  printf(" Render thread has been started\n");
  printf(ANSI_COLOR_RESET "["
    ANSI_COLOR_GREEN "RENDER"
    ANSI_COLOR_RESET "]");
  printf(" (%x)\n", this);
  while (!this -> shouldStop) {
    // FPS LOOP
    timeA = std::chrono::system_clock::now(); // Begin of the measurement
    work_time = timeA - timeB;
    if (work_time.count() < 16) {
      std::chrono::duration < double, std::milli > delta_ms(16.0 - work_time.count());
      auto delta_ms_duration = std::chrono::duration_cast < std::chrono::milliseconds > (delta_ms);
      std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
    }
    timeB = std::chrono::system_clock::now();
    std::chrono::duration < double, std::milli > sleep_time = timeB - timeA;
    // FPS LOOP END
    // (ca. 60 FPS)

    // RENDER CODE:
    for (Display * d: displayArray) {
      char * framebuffer = d -> getFrameBuffer(); //Get Display FB
      int lineLength = d -> getLineLength();

      Framebuffer fb;
      
      fb.createFramebuffer(d -> getScreenInfo().xres, d -> getScreenInfo().yres); // Create a new FB.

      for (UiObject * pObject: uiArray) {
        pObject -> render(fb); // Render all Elements which are in the pObject Array!
      }

      this -> m -> render(fb); // Render the Mouse
      
      unsigned char * fbCopy = fb.copyFramebuffer(); // Create a copy of the Framebuffer

      memcpy(framebuffer, fbCopy, (d -> getScreenInfo().xres * d -> getScreenInfo().yres * 4)); // Copy the contents into the Display Framebuffer

      d -> renderDisplay(); // Copy the contents of the Display FB onto the actual Linux Framebuffer
      free(fbCopy); // Destroy the copy
      fb.destroyFramebuffer(); // Destroy the temp copy
    }

    //printf("[RENDER] Loop-Time: %f \n", (work_time + sleep_time).count());
  }
};

void UiManager::addUiObject(UiObject * o) {
  this -> uiArray.push_back(o);
};

void UiManager::startThread() {
  printf(ANSI_COLOR_RESET "["
    ANSI_COLOR_GREEN "RENDER"
    ANSI_COLOR_RESET "] ");
  printf("Starting UiManager\n");
  uiManagerThread = std::thread( & UiManager::renderDisplays, this);
};

void UiManager::closeWindow(Window * window) {
  for (UiObject * o: uiArray) {
    if (o == window) {
      o -> freeMemory();
    }
  }
};

/*
  ################
  # MOUSE EVENTS #
  ################
*/

void UiManager::mouseInput() {
    int mouseX = 0, mouseY = 0;
    signed char mouseDX = 0, mouseDY = 0;
    bool left = false, middle = false, right = false;

    mouseX = this->im->getX();
    mouseY = this->im->getY();
 
    mouseDX = this->im->getDX();
    mouseDY = - this->im->getDY();

    left = this->im->getLeft();

    this->m->setPos(mouseX, mouseY);

    if((mouseDX != 0 || mouseDY != 0)) {
      printf("dX: %u dY: %u\n", mouseDX, mouseDY);
      MouseOnMoveEvent event;
      event.dX = mouseDX;
      event.dY = mouseDY;
      event.x = mouseX;
      event.y = mouseY;
      event.left = left;
      this -> mouseMoveEvent(event);
    }

    if (left) {
      printf("OnDown!\n");
      MouseOnDownEvent event;
      event.dX = mouseDX;
      event.dY = mouseDY;
      event.x = mouseX;
      event.y = mouseY;
      event.left = left;
      this -> mouseOnDownEvent(event);
    }

    // if (this -> m -> getMouseReleased() == true) {
    //   MouseOnReleaseEvent event;
    //   event.dX = mouseDX;
    //   event.dY = mouseDY;
    //   event.x = mouseX;
    //   event.y = mouseY;
    //   event.left = left;
    //   this -> mouseOnReleaseEvent(event);
    // }
}

void UiManager::setInputManager(InputManager* im) {
  this->im = im;  
}

void UiManager::setMouse(Mouse * m) {
  this -> m = m;
}

void UiManager::mouseMoveEvent(MouseOnMoveEvent event) {
  for (UiObject * o: uiArray) {
    o -> mouseMoveEvent(event);
  }
};

void UiManager::mouseOnDownEvent(MouseOnDownEvent event) {
  for (UiObject * o: uiArray) {
    o -> mouseDownEvent(event);
  }
};

void UiManager::mouseOnReleaseEvent(MouseOnReleaseEvent event) {
  for (UiObject * o: uiArray) {
    o -> mouseReleasedEvent(event);
  }
};

/*
  ##################
  # STOP FUNCTIONS #
  ##################
*/

void UiManager::stopThread() {
  printf(ANSI_COLOR_RESET "["
    ANSI_COLOR_GREEN "RENDER"
    ANSI_COLOR_RESET "] ");
  printf("Stopping Thread\n");
  this -> shouldStop = true;
  uiManagerThread.join();
  printf(ANSI_COLOR_RESET "["
    ANSI_COLOR_GREEN "RENDER"
    ANSI_COLOR_RESET "] ");
  printf("Thread has stopped.\n");
};

void UiManager::stop() {
  printf(ANSI_COLOR_RESET "["
    ANSI_COLOR_GREEN "UIMANAGER"
    ANSI_COLOR_RESET "] ");
  printf("Cleaning Up...\n");

  for (Display * d: displayArray) {
    printf(ANSI_COLOR_RESET "["
      ANSI_COLOR_GREEN "UIMANAGER"
      ANSI_COLOR_RESET "] ");
    printf("Deleting Display...\n");
    d -> stopDisplay();
    delete d;
  }
  this -> displayArray.clear();

  for (UiObject * o: uiArray) {
    printf(ANSI_COLOR_RESET "["
      ANSI_COLOR_GREEN "UIMANAGER"
      ANSI_COLOR_RESET "] ");
    printf("Deleting UiObject...\n");
    o -> freeMemory(); // Free all memory that is inside the objects
    delete o; // Delete the Object
  }

  this -> uiArray.clear();

  printf(ANSI_COLOR_RESET "["
    ANSI_COLOR_GREEN "UIMANAGER"
    ANSI_COLOR_RESET "] ");
  printf("Changing to text mode & returning tty1\n");

  ioctl(ttyfd, KDSETMODE, KD_TEXT);
  ioctl(ttyfd, VT_ACTIVATE, 1);
  ioctl(ttyfd, VT_WAITACTIVE, 1);
  close(ttyfd);

  printf(ANSI_COLOR_RESET "["
    ANSI_COLOR_GREEN "UIMANAGER"
    ANSI_COLOR_RESET "] ");
  printf("Cleanup "
    ANSI_COLOR_GREEN "done"
    ANSI_COLOR_RESET "\n");
};