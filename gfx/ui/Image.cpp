#include "Image.hpp"
using std::string;

Image::Image()
{
  std::cout << "Image was created!" << '\n';
};

void Image::loadImage(char *path)
{
  img = stbi_load(path, &width, &height, &channels, 3);
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
  u_int64_t location = 0; // Location of Pixel

  for (posY = y; posY < height; posY++)
  {

    for (posX = x; posX < width; posX++)
    {
      location = posX * channels +
                 posY * lineLength;
      
      unsigned char* pixelOffset = img + (x + y * width) * channels;
      unsigned char r = pixelOffset[0];
      unsigned char g = pixelOffset[1];
      unsigned char b = pixelOffset[2];

      if (channels == 2)
      {
        *(imageBuffer + location) = pixelOffset[1];
        *(imageBuffer + location +1) = pixelOffset[1];
        *(imageBuffer + location +2) = pixelOffset[1];
        *(imageBuffer + location +3) = pixelOffset[0];
      }
      else if(channels == 3)
      {
        *(imageBuffer + location) = pixelOffset[2]; //B
        *(imageBuffer + location +1) = pixelOffset[1]; //G
        *(imageBuffer + location +2) = pixelOffset[0]; //R
        *(imageBuffer + location +3) = 0xFF; //A
      } else {
        printf("Channels larger than 3\n");
        for (int i = 0; i < channels; i++)
        {
          char c = pixelOffset[i];
          *(imageBuffer + location + i) = c;
        }
      }
    }
  }
};

void Image::setPos(int x, int y)
{
  this->x = x;
  this->y = y;
};

void Image::mouseMoveEvent(int x, int y) {

};


void Image::freeMemory() {
  stbi_image_free(this->img);
};