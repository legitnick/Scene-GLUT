#ifndef IMPASSE_H
#define IMPASSE_H

#include "Vector.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#define HEIGHT 1080
#define WIDTH 1920


struct Cube{
		  bool Has(Point3& pt)const;
		  Point3 pts[2];
};
class Impasse{
		  private:
					 int i=0,j = 0;
					 std::vector<Cube*> Areas;
		  public:
					 void Pushp(const Point3 pt);

					 bool Includes(Point3& pt)const; 
};

#endif
