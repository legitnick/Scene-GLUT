#ifndef MAIN_H
#define MAIN_H

#include "loader.h"
#include "camera.h"
#include "draw.h"

class Game{
bool pointed = false;
bool selected = false;
		  public:
void Logic();
void mouseListener(int button, int state, int x, int y);
void keyboardListener(unsigned char key,int x,int y); 
}game;

GLUquadricObj *quadric, *minercylinder;
GLfloat ctrlpoints[4][3] = {
	{ 62.0, 0, 75.0}, { 4.0, 0, 103.0}, 
	{16.0, 0, 103.0}, {-41.0, 0, 75.0},};



std::shared_ptr<Draw> drw;
std::shared_ptr<Camera_class> cam;
TexManager tx;
void mouseHandler(int x,int y) {cam->cameraMove(x,y);}
void specialMouseHandler(int button, int state, int x, int y) {game.mouseListener(button,state, x, y);}
void keyboardHandler(unsigned char key,int x, int y){game.keyboardListener(key,x,y);}
#endif
