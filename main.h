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
#include <iostream>

#define HEIGHT 1080
#define WIDTH 1920
#define GROUND 1, 1, 1
#define ANGLE 0.2


GLUquadricObj *quadric, *minercylinder;
double D = 50 * 50;
GLfloat ctrlpoints[4][3] = {
	{ 62.0, 0, 75.0}, { 4.0, 0, 103.0}, 
	{16.0, 0, 103.0}, {-41.0, 0, 75.0},};
float ctrlpoints2[4][3] = 
{{ 50.0, 0, 40.0}, { 4.0, 0, 60.0}, 
	{16.0, 0, 60.0}, {-30.0, 0, 40.0}};

#include "loader.h"
#include "Vector.h"
#include "camera.h"
#include "draw.h"

Draw* drw;
Camera_class* cam;
TexManager tx;
void mouseHandler(int x,int y) {cam->cameraMove(x,y);}
#endif
