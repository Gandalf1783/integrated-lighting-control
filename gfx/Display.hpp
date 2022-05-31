#include <iostream>
#include <cstring>

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
  private:
    char fbfd; // Framebuffer (Number for the Monitor to be used)
    char ttyfd; // TTY File Descriptor.

    struct fb_var_screeninfo vinfo; // Variable Info
    struct fb_fix_screeninfo finfo; // Fixed Info

    long int screensize; // Screensize in bytes

    char *fbp; // Framebuffer Pointer
    char *imageBuffer; // Image Buffer, will be copied after each render.
    int displayNumber;


    void beginDisplay();

  public:
    Display();
    Display(int displayNumber);
    int getLineLength();
    char* getFrameBuffer();
    void renderDisplay();
    void testRender();
    void stopDisplay();
};

#endif
