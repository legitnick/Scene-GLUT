#ifndef CAMERA_H
#define CAMERA_H

#include "Vector.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

#define DELTA 1.0/2.9
#define HEIGHT 1080
#define WIDTH 1920
#define zoom  350







class Impasse{
		  private:
					 std::vector<Point3> pts;
		  public:
					 void includes(Point3& pt); 
};
class Camera_class{
   
	private:
   public:
      Point3 eye, look;
		Vector3 up;
	   Vector3 u,v,n;
	   long double viewAngle,aspect,nearDist,farDist;

		void setModelviewMatrix();
		
		void cameraMove(int x, int y);
	   
		Camera_class();
	   void set(Point3 eye,Point3 look,Vector3 up);

	   void slide(long double delU,long double delV,long double delN);

	   void roll(float angle);
      

	   void pitch(long double angle);

	   void yaw(long double angle);

};
void mouseHandler(int x,int y);

#endif
