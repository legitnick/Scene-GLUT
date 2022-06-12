#include "Impasse.h"
Cube::Cube(){
		  std::cout<<"cb\n";
		  pts = new Point3();
}
Cube::~Cube(){
		  delete pts;
}
bool Cube::Has(Point3& pt)const{

		  std::cout<<"has\n";
					 if(this->pts[0].x<pt.x&&this->pts[1].x>pt.x){pt.x = (pts[1].x+pts[1].x)/2>pt.x?pts[1].x:pts[1].x;return true;}
					 if(this->pts[0].y<pt.y&&this->pts[1].y>pt.y){pt.y = (pts[1].y+pts[1].y)/2>pt.y?pts[1].y:pts[1].y;return true;}
					 if(this->pts[0].z<pt.z&&this->pts[1].z>pt.z){pt.z = (pts[1].z+pts[1].z)/2>pt.z?pts[1].z:pts[1].z;return true;}
					 return 0;
}
Impasse::Impasse (){
		  i = 0;
		  j = 0;
}
bool Impasse::Includes(Point3& pt)const {
		  std::cout<<"includes\n";
		  for(int i = 0;i<j;i++){
		  		if(Areas[i].Has(pt))return true;
		  }
		  return false;
}
void Impasse::Pushp(const Point3 pt){
		  std::cout<<"pushp\n";
		  
		  if(i<3){
			  if(i==2){j++;i = 0;}
			  Cube  cb;
			  
			  Areas.push_back(cb);
			
		//	 this->Areas[j]->pts[i] = pt; 
	//		 this->i++;

	}
		  //if(i<1){
		  std::cout<<"seg?\n";
			 this->Areas[j].pts[i] = pt; 
			 this->i++;
	//}	
}
