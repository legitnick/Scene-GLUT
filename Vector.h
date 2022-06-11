#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
class Point3{
public:
	float x,y,z;
	
	void set(float dx,float dy, float dz)
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
    
	Point3(float xx,float yy,float zz)
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
    float x,y,z;
	  
    void set(float dx,float dy, float dz)
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
    	
    	float d=(float)sqrt(sizeSq);
    	x /= d;
    	y /= d;
    	z /= d;
   
    }

    Vector3(float xx,float yy,float zz)
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
	float dot(Vector3 b)
    {
          return x*b.x+y*b.y+z*b.z;
    }
  
    Vector3 cross(Vector3 b)
    {
          Vector3 to_ret= Vector3( float(y*b.z - z*b.y) , float(z*b.x - x*b.z) , float(x*b.y - y*b.x) );
          return to_ret;
    }
};
#endif
