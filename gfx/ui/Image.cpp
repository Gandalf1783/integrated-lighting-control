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
  int posX = 0, posY = 0; // Used for iteration
  u_int64_t location = 0;       // Location of Pixel

  for (posY = y; posY < height; posY++)
  {
    
    for (posX = x; posX < width; posX++)
    {
      location = posX * channels +
                 posY * lineLength;

      unsigned char *pixelOffset = img + (posX + width * posY) * channels;
      
      for(int i = 0; i < channels; i++) {
        char c = pixelOffset[i];
        *(imageBuffer + location + i) = c;
      }

    }
  }
};

void Image::setPos(int x, int y) {
    this->x = x;
    this->y = y;
};