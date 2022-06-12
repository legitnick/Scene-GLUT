#include "camera.h"


void Camera_class::cameraMove(int x,int y){
 
	long double dx = x - WIDTH/2.0;
	

	long double dy = y  - HEIGHT/2.0;
	long double pitch_v = dy*DELTA;
	long double yaw_v = dx*DELTA;
	if (pitch_v>M_PI/2){
        pitch_v = M_PI/2 - 0.0001f;
    }
    else if (pitch_v<-1*M_PI/2) {
        pitch_v =-1*M_PI/2 + 0.0001f;
    }
	this->pitch(pitch_v);
	this->yaw(yaw_v);
	if(dx&&dy)glutWarpPointer(WIDTH/2,HEIGHT/2);
	return;

}

void Camera_class::setModelviewMatrix(void)
{

        float m[16];
		Vector3 eVec(eye.x,eye.y,eye.z);
		m[0]=u.x; m[4]=u.y;  m[8]=u.z; m[12]=-eVec.dot(u);

		m[1]=v.x; m[5]=v.y;  m[9]=v.z; m[13]=-eVec.dot(v);

		m[2]=n.x; m[6]=n.y;  m[10]=n.z; m[14]=-eVec.dot(n);

		m[3]=0;  m[7]=0;  m[11]=0; m[15]=1;

		glMatrixMode(GL_MODELVIEW);

		glLoadMatrixf(m);
}

Camera_class::Camera_class(Impasse* impasse):impasse(impasse){
     
eye = Point3(0,zoom,200);
	
look = Point3 (0,0,100);

up = Vector3(0,0,1);
}
void Camera_class::set(Point3 Eye,Point3 look,Vector3 up)
{
       eye.set(Eye);
	   n.set(eye.x-look.x,eye.y-look.y,eye.z-look.z);
	   u.set(up.cross(n));
	   n.normalize();
	   u.normalize();
	   v.set(n.cross(u));
	   //printf("\n%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t",eye.x,eye.y,eye.z,	cam.look.x,cam.look.y,cam.look.z,	cam.up.x,cam.up.y,cam.up.z);
	   //printf("\n%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",eye.x,eye.y,eye.z,u.x,u.y,u.z,v.x,v.y,v.z,n.x,n.y,n.z);
       setModelviewMatrix();

}


void Camera_class::slide(long double delU,long double delV,long double delN)
{
		eye.x += delU*u.x+ delV*v.x + delN*n.x;
		eye.y += delU*u.y+ delV*v.y + delN*n.y;
		eye.z += delU*u.z+ delV*v.z + delN*n.z;
		if(impasse->Includes(eye))std::cout<<"Bump";
		setModelviewMatrix();



}


void Camera_class::roll(float angle)
{

		float cs=cos(M_PI/180*angle);
		float sn=sin(M_PI/180*angle);

		Vector3 t(u);

		u.set(cs*t.x-sn*v.x,cs*t.y-sn*v.y,cs*t.z-sn*v.z);
		v.set(sn*t.x+cs*v.x,sn*t.y+cs*v.y,sn*t.z+cs*v.z);
		
        setModelviewMatrix();


}


void Camera_class::pitch(long double angle)
{


	 long double cs = cos( M_PI/180 * angle ) ;
    long double  sn = sin( M_PI/180 * angle ) ;
    
    Vector3 t( v ) ;

    v.set( cs*t.x - sn*n.x, cs*t.y - sn*n.y, cs*t.z - sn*n.z ) ;
    n.set( sn*t.x + cs*n.x, sn*t.y + cs*n.y, sn*t.z + cs*n.z ) ;

	setModelviewMatrix() ;


}



void Camera_class::yaw(long double angle)
{



	 long double  cs = cos( M_PI/180 * angle ) ;
    long double  sn = sin( M_PI/180 * angle ) ;

    Vector3 t( n ) ;

    n.set( cs*t.x - sn*u.x, cs*t.y - sn*u.y, cs*t.z - sn*u.z ) ;
    u.set( sn*t.x + cs*u.x, sn*t.y + cs*u.y, sn*t.z + cs*u.z ) ;

	setModelviewMatrix() ;


}
////////////////////////////////////////////////

