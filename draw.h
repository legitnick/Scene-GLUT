#ifndef DRAW_H
#define DRAW_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>

#include "loader.h"
#include "Impasse.h"

#define GROUND 1, 1, 1
#define ANGLE 0.2
class Draw{
		  private:
					 int x= 0,y = 0;
					 std::shared_ptr<Impasse> impasse;
void begin2D();
void end2D();
void drawWall(int d,int a,int texID);
					 TexManager tex;
					 void drawObj();
		  public:
int objN = 0;
void drawLVL();
void MoveObj(int x,int y);
void showText(int x,int y, int z,const char* string);
void drawCoordWall(int x,int y,int z, int d,int a,int texID);
Draw(TexManager& tex);
					 float white[4]={1,1,1,1};

Draw();
std::shared_ptr<Impasse>  getImpasse();
void drawMouse(void);
void drawCubeTexur(int a,int x, int y, int z,int texID);
};


#endif
