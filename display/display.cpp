#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/kd.h>
#include <string.h>


char fbfd = 0; // Framebuffer (Number for the Monitor to be used)
char ttyfd = 0; // TTY File Descriptor.

struct fb_var_screeninfo vinfo; // Variable Info
struct fb_fix_screeninfo finfo; // Fixed Info

long int screensize = 0; // Screensize in bytes

char *fbp; // Framebuffer Pointer
char *imageBuffer; // Image Buffer, will be copied after each render.

// Function declarations:


void initDisplay();
void renderDisplay();
void stopDisplay();


void initDisplay() {
	 // Open the file for reading and writing
	 fbfd = open("/dev/fb0", O_RDWR);
	 if (fbfd == -1) {
			 perror("Error: cannot open framebuffer device");
			 exit(1);
	 }
	 printf("The framebuffer device was opened successfully.\n");

	 // Get fixed screen information
	 if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
			 perror("Error reading fixed information");
			 exit(2);
	 }

	 // Get variable screen information
	 if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
			 perror("Error reading variable information");
			 exit(3);
	 }

	 printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

	 // Figure out the size of the screen in bytes
	 screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

	 // Map the device to memory
	 fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
	 if ((int)fbp == -1) {
			 perror("Error: failed to map framebuffer device to memory");
			 exit(4);
	 }
	 printf("The framebuffer device was mapped to memory successfully.\n");




	 imageBuffer = malloc(screensize);
	 if(imageBuffer ==  NULL) {
		 perror("Failed to allocate %u bytes for the imageBuffer.\n");
		 exit(-1);
	 }
}


void renderDisplay() {
	// This just renders stuff to the display

	int x = 0, y = 0; // Used for iteration
	int location = 0; // Location of Pixel

    memset(imageBuffer, 0, screensize); // Clears the imageBuffer to a black image.

	for (y = 0; y < vinfo.yres; y++) {
        for (x = 0; x < vinfo.xres; x++) {

            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (y+vinfo.yoffset) * finfo.line_length;

            if (vinfo.bits_per_pixel == 32) {
                *(imageBuffer + location) = x;        // Some blue
                *(imageBuffer + location + 1) = x+80;     // A little green
                *(imageBuffer + location + 2) = x+170;    // A lot of red
                *(imageBuffer + location + 3) = 0;      // No transparency
        //location += 4;
            } else  { //assume 16bpp
                int b = 10;
                int g = (x-100)/6;     // A little green
                int r = 31-(y-100)/16;    // A lot of red
                unsigned short int t = r<<11 | g << 5 | b;
                *((unsigned short int*)(fbp + location)) = t;
            }

        }
	}

	memcpy(fbp, imageBuffer, screensize); // After each frame!
}


void stopDisplay() {
    //Free all the memory and unmap and close files:
	ioctl(ttyfd, KDSETMODE, KD_TEXT);
    munmap(fbp, screensize);
	free(imageBuffer);
    close(fbfd);
	close(ttyfd);
}
