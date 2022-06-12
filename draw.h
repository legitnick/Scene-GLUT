#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

#include "loader.h"


#define HEIGHT 1080
#define WIDTH 1920
#define GROUND 1, 1, 1
#define ANGLE 0.2
class Draw{
		  private:
					 TexManager tex;
void drawWall(int d,int a,int texID);
		  public:
Draw(TexManager& tex);
					 float white[4]={1,1,1,1};


void drawMouse(void);
void drawCubeTexur(int a,int x, int y, int z,int texID);
void drawCubeTexure(int a,int x, int y, int z,int texID);
};


#endif
