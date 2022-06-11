#ifndef CAMERA_H
#define CAMERA_H

#include "Vector.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define DELTA 1.0/2.9
#define HEIGHT 1080
#define WIDTH 1920
#define zoom  350








class Camera_class{
   
	private:
   public:
      Point3 eye, look;
		Vector3 up;
	   Vector3 u,v,n;
	   double viewAngle,aspect,nearDist,farDist;

		void setModelviewMatrix();
		
		void cameraMove(int x, int y);
	   
		Camera_class();
	   void set(Point3 eye,Point3 look,Vector3 up);

	   void slide(double delU,double delV,double delN);

	   void roll(float angle);
      

	   void pitch(double angle);

	   void yaw(double angle);

};
void mouseHandler(int x,int y);

#endif
