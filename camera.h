#ifndef CAMERA_H
#define CAMERA_H

#include "Impasse.h"


class Camera_class{
   
	private:

			  Vector3 u,v,n;
	   long double viewAngle,aspect,nearDist,farDist;
   public:
			  std::shared_ptr<Impasse> impasse;
      Point3 eye, look;
		Vector3 up;
		Point3 getCameraV();	
		void setModelviewMatrix();
		
		void cameraMove(int x, int y);
	   
		Camera_class(std::shared_ptr<Impasse> impasse);
		Camera_class();
	   void set(Point3 eye,Point3 look,Vector3 up);

	   bool slide(long double delU,long double delV,long double delN);

	   void roll(float angle);
      

	   void pitch(long double angle);

	   void yaw(long double angle);

};
void mouseHandler(int x,int y);

#endif
