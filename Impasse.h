#ifndef IMPASSE_H
#define IMPASSE_H

#include <climits>
#include "Vector.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <memory>
#include <iostream>
#include <array>
#include <vector>
#define HEIGHT 1080
#define WIDTH 1920
#define DELTA 1/5.0

class Impasse{
		  private:


struct Cube{
		  Point3 Has(const Point3 pt)const;
		  std::array<Point3,2> pts;
};
					 int i=0,j=0;
					 std::vector<Cube> Areas;
		  public:
		   
		  bool Sees(Point3 eye,Vector3 camDir,int j);
		  int Pushp(const Point3 pt);
					 Point3 Includes(const Point3& pt)const; 
};

#endif
