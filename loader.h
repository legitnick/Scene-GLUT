#ifndef LOADER_H
#define LOADER_H

#include <IL/il.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

int LoadPicture(char* filename);

int LoadBitmap(char *filename, int width, int height);
typedef struct tagBITMAPFILEHEADER {
  uint16_t  bfType;
  uint32_t bfSize;
  uint16_t  bfReserved1;
  uint16_t  bfReserved2;
  uint32_t bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagRGBTRIPLE {
  uint8_t rgbtBlue;
  uint8_t rgbtGreen;
  uint8_t rgbtRed;
} RGBTRIPLE;

typedef struct tagBITMAPINFOHEADER {
  uint32_t biSize;
  unsigned int  biWidth;
  unsigned int  biHeight;
  uint16_t  biPlanes;
  uint16_t  biBitCount;
  uint32_t biCompression;
  uint32_t biSizeImage;
  unsigned int  biXPelsPerMeter;
  unsigned int  biYPelsPerMeter;
  uint32_t biClrUsed;
  uint32_t biClrImportant;
} BITMAPINFOHEADER, *PBITMAM_PINFOHEADER;

struct TexManager{
GLuint texid1,texid2,texid3,texid4,texid5,texid6,texid7,texid8,texid9,texid10;
GLuint texid11,texid12,texid13,texid14,texid15,texid16,texid17,texid18,texid19,texid20;
int* skybox;

void loadBMPs(void);
};


#define SKY_FRONT 0
#define SKY_RIGHT 1
#define SKY_LEFT 2
#define SKY_BACK 3
#define SKY_UP 4
#define SKY_DOWN 5

#endif
