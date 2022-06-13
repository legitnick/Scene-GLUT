#include "Impasse.h"
Point3 Impasse::Cube::Has(const Point3& pt)const{
			Point3 deltaPt;
					 if(this->pts[0].x<pt.x&&this->pts[1].x>pt.x){deltaPt.x = (pts[1].x+pts[0].x)/2>pt.x?pts[0].x:pts[1].x;}
					 if(this->pts[0].y<pt.y&&this->pts[1].y>pt.y){deltaPt.y = (pts[1].y+pts[0].y)/2>pt.y?pts[0].y:pts[1].y;}
					 if(this->pts[0].z<pt.z&&this->pts[1].z>pt.z){deltaPt.z = (pts[1].z+pts[0].z)/2>pt.z?pts[0].z:pts[1].z;}
					 //if(deltaPt.x+deltaPt.y+deltaPt.z>20)return Point3(INT_MAX,0,0);
					 return deltaPt;

}
Impasse::Impasse (){
		  i = 0;
		  j = 0;
}
Point3 Impasse::Includes(const Point3& pt)const {
		  Point3 currPt;
		  for(int i = 0;i<j;i++){
		  		currPt = Areas[i].Has(pt);
				if(currPt.x||currPt.y||currPt.z)return currPt;
		  }
		  return currPt;
}
void Impasse::Pushp(const Point3 pt){
		  if(i<3){
			  if(i==2){j++;i = 0;}
			  Cube  cb;
			  
			  Areas.push_back(cb);
			
		//	 this->Areas[j]->pts[i] = pt; 
	//		 this->i++;

	}
		  //if(i<1){
			 this->Areas[j].pts[i] = pt; 
			 this->i++;
	//}	
}
