#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
class Point3{
public:
	double x,y,z;
	
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
    
	Point3()
	{
	  x=0;
	  y=0;
	  z=0;
	}

};

class Vector3{
  public:
    double x,y,z;
    void multiply(int k){
				x*=k;
				y*=k;
				z*=k;
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
	 Point3 move(Point3 in){
				return Point3(x+in.x,y+in.y,z+in.z);
	 }
};
#endif
