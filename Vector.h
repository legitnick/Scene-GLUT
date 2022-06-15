#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
class Point3{
public:
	double x = 0,y = 0,z = 0;
   Point3(){
			  this->x  = 0;
			  this->y = 0;
			  this->z =  0;
	}	
	void set(double dx,double dy, double dz)
	{
	  x=dx;
	  y=dy;
	  z=dz;
	}

	void set(Point3& p)
	{
	  x=p.x;
	  y=p.y;
	  z=p.z;
	
	}
    
	Point3(double xx,double yy,double zz)
	{
	  x=xx;
	  y=yy;
	  z=zz;
	 
	}
    

};

class Vector3{
  public:
    double x,y,z;
    Vector3 static multiply(int k,Vector3 v){
				v.x*=k;
				v.y*=k;
				v.z*=k;
				return v;
	 }	  
    void set(double dx,double dy, double dz)
    {
          x=dx;
          y=dy;
          z=dz;
    }
	void set(Vector3 const  &v)
	{
    	  x=v.x;
    	  y=v.y;
    	  z=v.z;
	
	}
    void flip()
	{
    	  x=-x;
    	  y=-y;
    	  z=-z;
	
	}
	void setDiff(Point3& a,Point3& b)
    {
         x=a.x-b.x;
    	 y=a.y-b.y;
    	 z=a.z-b.z;
   
    }
    void normalize()
    {
        double sizeSq = x*x+y*y+z*z;
    	
    	double d=(double)sqrt(sizeSq);
    	x /= d;
    	y /= d;
    	z /= d;
   
    }

    Vector3(double xx,double yy,double zz)
	{
    	 x=xx;
    	 y=yy;
    	 z=zz;
	}

    Vector3(Vector3 const &v)
	{
    	  x=v.x;
    	  y=v.y;
    	  z=v.z;
	}
    Vector3()
	{
    	  x=0;
    	  y=0;
    	  z=0;
	}
	double dot(Vector3 b)
    {
          return x*b.x+y*b.y+z*b.z;
    }
  
    Vector3 cross(Vector3 b)
    {
          Vector3 to_ret= Vector3( double(y*b.z - z*b.y) , double(z*b.x - x*b.z) , double(x*b.y - y*b.x) );
          return to_ret;
    }
	 Point3 static move(Point3 in,Vector3 v){
				return Point3(v.x+in.x,v.y+in.y,v.z+in.z);
	 }
};
#endif
