#include "Image.hpp"
using std::string;

Image::Image()
{
  std::cout << "Image was created!" << '\n';
};

void Image::loadImage(char * path)
{
  img = stbi_load(path, &width, &height, &channels, 0);
  if (img == NULL)
  {
    printf("Error in loading the image\n");
    exit(1);
  }
  printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);
};

void Image::render(char * imageBuffer, int lineLength)
{
  //printf("Image is rendering: \n");
  // printf("Address of imageBuffer IMAGE: %x\n", imageBuffer);
  // printf("LineLength: %u\n",this->line_length);
  int posX = 0, posY = 0; // Used for iteration
  u_int64_t location = 0;       // Location of Pixel
  //printf("PosY = %d | y = %d | height: %d", posY, y, height);

  for (posY = y; posY < height; posY++)
  {
    //std::cout << "Yep. Height.";
    
    for (posX = x; posX < width; posX++)
    {
     // printf("PosX: %d | PosY: %d\n", posX, posY);
      location = posX * channels +
                 posY * line_length;

      unsigned char *pixelOffset = img + (posX + width * posY) * channels;
      
      char r = pixelOffset[0];
      char g = pixelOffset[1];
      char b = pixelOffset[2];

      *(imageBuffer + location) = r;        // Some blue
      *(imageBuffer + location + 1) = g;    // A little green
      *(imageBuffer + location + 2) = b;    // A lot of red
      *(imageBuffer + location + 3) = 0x0; // No transparency
    }
  }
};

void Image::setPos(int x, int y) {
    this->x = x;
    this->y = y;
};