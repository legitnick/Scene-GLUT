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
					 std::shared_ptr<Impasse> impasse;
					 TexManager tex;
void drawWall(int d,int a,int texID);
		  public:
Draw(TexManager& tex);
					 float white[4]={1,1,1,1};

void drawRoom(int w,int h, int l);
Draw();
std::shared_ptr<Impasse>  getImpasse();
void drawMouse(void);
void drawCubeTexur(int a,int x, int y, int z,int texID);
void drawCubeTexure(int a,int x, int y, int z,int texID);
};


#endif
