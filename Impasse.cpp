#include "Impasse.h"

bool Cube::Has(Point3& pt)const{

					 if(this->pts[0].x<pt.x&&this->pts[1].x>pt.x){pt.x = (pts[1].x+pts[1].x)/2>pt.x?pts[1].x:pts[1].x;return true;}
					 if(this->pts[0].y<pt.y&&this->pts[1].y>pt.y){pt.y = (pts[1].y+pts[1].y)/2>pt.y?pts[1].y:pts[1].y;return true;}
					 if(this->pts[0].z<pt.z&&this->pts[1].z>pt.z){pt.z = (pts[1].z+pts[1].z)/2>pt.z?pts[1].z:pts[1].z;return true;}
					 return 0;
}
bool Impasse::Includes(Point3& pt)const {
		  for(int i = 0;i<j;i++){
		  		if(Areas[i]->Has(pt))return true;
		  }
		  return false;
}
void Impasse::Pushp(const Point3 pt){
	if(i==0||i==6){
			  if(i)j++;
			  i = 0;
			  this->Areas[j] = new Cube;

		//	 this->Areas[j]->pts[i] = pt; 
	//		 this->i++;

	}
		  //if(i<1){
			 this->Areas[j]->pts[i] = pt; 
			 this->i++;
	//}	
}
