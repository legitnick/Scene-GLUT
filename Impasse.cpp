#include "Impasse.h"
void maxToZero(double& a,double& b){
		  if(a>b){a = 0;return;}
		  b = 0;
}
void smallest(Point3& pt){
		  maxToZero(pt.x,pt.y);
		  if(pt.y){maxToZero(pt.x,pt.z);return;}
		  maxToZero(pt.y,pt.z);
}
Point3 Impasse::Cube::Has(const Point3& pt)const{
			Point3 deltaPt;
					 if(pts[0].x<pt.x&&pts[1].x>pt.x){deltaPt.x = (pts[1].x+pts[0].x)/2>pt.x?(pt.x-pts[0].x):(pt.x-pts[1].x);}
					 if(pts[0].y<pt.y&&pts[1].y>pt.y){deltaPt.y = (pts[1].y+pts[0].y)/2>pt.y?(pt.y-pts[0].y):(pt.y-pts[1].y);}
					 if(pts[0].z<pt.z&&pts[1].z>pt.z){deltaPt.z = (pts[1].z+pts[0].z)/2>pt.z?pt.z-pts[0].z:pt.z-pts[1].z;}
					 if(deltaPt.x&&deltaPt.y&&deltaPt.z){smallest(deltaPt);	 
					 //if(deltaPt.x+deltaPt.y+deltaPt.z>10)return Point3(INT_MAX,0,0);
					 return deltaPt;
					 }
					 return Point3();

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
			
		//	 Areas[j]->pts[i] = pt; 
	//		 i++;

	}
		  //if(i<1){
			 Areas[j].pts[i] = pt; 
			 i++;
	//}	
}
