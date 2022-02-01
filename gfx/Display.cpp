#include <iostream>
#include "Display.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

using std::string;

void Display::beginDisplay() {
  // Open the file for reading and writing
  string fbPath = "/dev/fb"+std::to_string(displayNumber);
  printf(ANSI_COLOR_RESET "[" ANSI_COLOR_GREEN "DISPLAY" ANSI_COLOR_RESET "] ");
  printf("Opening %s...\n", fbPath.c_str());
  fbfd = open(fbPath.c_str(), O_RDWR);

  if (fbfd == -1) {
      printf(ANSI_COLOR_RED "[DISPLAY] ("  ANSI_COLOR_BLUE "%d" ANSI_COLOR_RED ") Error: cannot open framebuffer device", displayNumber);
      exit(1);
  }
  printf(ANSI_COLOR_RESET "[" ANSI_COLOR_GREEN "DISPLAY" ANSI_COLOR_RESET "] ");
  printf("The framebuffer device was opened successfully.\n");

  // Get fixed screen information
  if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
     printf(ANSI_COLOR_RED "[DISPLAY] ("  ANSI_COLOR_BLUE "%d" ANSI_COLOR_RED ") Error: cannot read fixed information", displayNumber);
      exit(2);
  }

  // Get variable screen information
  if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
      printf(ANSI_COLOR_RED "[DISPLAY] ("  ANSI_COLOR_BLUE "%d" ANSI_COLOR_RED ") Error: cannot read variable information", displayNumber);
      exit(3);
  }
  printf(ANSI_COLOR_RESET "[" ANSI_COLOR_GREEN "DISPLAY" ANSI_COLOR_RESET "] ");
  printf("Screen-Res: %dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

  // Figure out the size of the screen in bytes
  screensize = vinfo.xres_virtual * vinfo.yres_virtual * vinfo.bits_per_pixel / 8;

  // Map the device to memory
  fbp = (char *) mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
  if (fbp == NULL) {
      printf(ANSI_COLOR_RED "[DISPLAY] ("  ANSI_COLOR_BLUE "%d" ANSI_COLOR_RED ") Error: cannot map framebuffer to memory", displayNumber);
      exit(4);
  }
  printf(ANSI_COLOR_RESET "[" ANSI_COLOR_GREEN "DISPLAY" ANSI_COLOR_RESET "] ");
  printf("The framebuffer device was mapped to memory successfully.\n");

  imageBuffer = (char *) malloc(screensize);
  if(imageBuffer ==  NULL) {
    printf(ANSI_COLOR_RED "[DISPLAY] ("  ANSI_COLOR_BLUE "%d" ANSI_COLOR_RED ") Error: cannot allocate " ANSI_COLOR_BLUE "%u" ANSI_COLOR_RED " bytes for imageBuffer", displayNumber);
    exit(5);
  }
  printf(ANSI_COLOR_CYAN);
  printf("#### DISPLAY DEBUG ####\n");
  printf("Instance: %u (0x%x)\n", this->displayNumber, this);
  printf("Screensize: %dx%d (%d bytes)\n", vinfo.xres, vinfo.yres, screensize);
  printf("DisplayBuffer Addr: %x\n", fbp);
  printf("ImageBuffer Addr: %x\n", imageBuffer);
  printf("LineLength: %u\n", finfo.line_length);
  printf("##############\n\n\n" ANSI_COLOR_RESET);
}

Display::Display() {

};

Display::Display(int displayNumber) {
  printf(ANSI_COLOR_RESET "[" ANSI_COLOR_GREEN "DISPLAY" ANSI_COLOR_RESET "] ");
  printf("(%u) : INFO : Initialising Display (%u) \n", displayNumber, displayNumber);
  this->displayNumber = displayNumber;
  beginDisplay();
};

int Display::getLineLength() {
  return finfo.line_length;
};

char* Display::getFrameBuffer() {
  return imageBuffer;
};

void Display::renderDisplay() {
  memcpy(fbp, imageBuffer, screensize); // After each frame!
  memset(imageBuffer,0,screensize);
};

void Display::testRender() {
  int location;
  for(int x = 0; x < 300; x++) {
    for(int y = 0; y < 300; y++) {
      location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
            (y+vinfo.yoffset) * finfo.line_length;
      *(fbp + location) = 100;        // Some blue
      *(fbp + location + 1) = 15+(x-100)/2;     // A little green
      *(fbp + location + 2) = 200-(y-100)/5;    // A lot of red
      *(fbp + location + 3) = 0;      // No transparency

    }
  }
};

void Display::stopDisplay() {
  //Free all the memory and unmap and close files:
  munmap(fbp, screensize);
  free(imageBuffer);
  close(fbfd);
};


//TODO: FREE MEMORY!