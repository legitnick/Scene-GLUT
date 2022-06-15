#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define HEIGHT 1080
#define WIDTH 1920
#define GROUND 1, 1, 1
#define ANGLE 0.2

class Game{
bool pointed = false;
bool selected = false;
		  public:
void Logic();
void mouseListener(int button, int state, int x, int y);
void keyboardListener(unsigned char key,int x,int y); 
}game;
GLUquadricObj *quadric, *minercylinder;
double D = 50 * 50;
GLfloat ctrlpoints[4][3] = {
	{ 62.0, 0, 75.0}, { 4.0, 0, 103.0}, 
	{16.0, 0, 103.0}, {-41.0, 0, 75.0},};
float ctrlpoints2[4][3] = 
{{ 50.0, 0, 40.0}, { 4.0, 0, 60.0}, 
	{16.0, 0, 60.0}, {-30.0, 0, 40.0}};

#include "loader.h"
#include "camera.h"
#include "draw.h"

int frustum = 70;

std::shared_ptr<Draw> drw;
std::shared_ptr<Camera_class> cam;
TexManager tx;
void mouseHandler(int x,int y) {cam->cameraMove(x,y);}
void specialMouseHandler(int button, int state, int x, int y) {game.mouseListener(button,state, x, y);}
void keyboardHandler(unsigned char key,int x, int y){game.keyboardListener(key,x,y);}
#endif
