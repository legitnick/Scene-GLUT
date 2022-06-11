#ifndef CAMERA_H
#define CAMERA_H

#define DELTA 1.0/2.9
#define HEIGHT 1080
#define WIDTH 1920
#define zoom  350
#include <GL/glut.h>
#include <math.h>

#define TO_RADIANS 3.14/180.0

//width and height of the window ( Aspect ratio 16:9 )
struct Motion
{
    bool Forward,Backward,Left,Right;
};
class Camera {
		  private:

int width ;
int height;

float pitch = 0.0, yaw= 0.0;
float camX=0.0,camZ=0.0;

		  public:
					 
Motion motion;
void passive_motion(int x,int y);
   Camera(int w,int h);
	void camera();
};


void mouseHandler(int x,int y);

#endif
