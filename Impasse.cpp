#include "Impasse.h"
void maxToZero(double& a,double& b){
		  if(a>b){a = 0;return;}
		  b = 0;
}
void smallest(Point3& pt){
		  maxToZero(pt.x,pt.y);
		  if(pt.y){maxToZero(pt.y,pt.z);return;}
		  maxToZero(pt.x,pt.z);
		  //there is a slight increment to keep you from seeing through the walls
}
//a function which returns whether your camera is pointed towards a game object
//rotate and uplift it a little bit in this case(also condition - mouse 5 pressed)
//when pressing keys now just move the object
bool Impasse::Sees(Point3 eye, Vector3 camDir,int j){
		  for(int i = 0;i<1000;i+=5){
					Point3 pt = Areas[j].Has(Vector3::move(eye,Vector3::multiply(j,camDir)));
							  if(pt.x||pt.y||pt.z){std::cout<<"Sees!\n";
										 return true;}
		  }
		  return false;

}
Point3 Impasse::Cube::Has(const Point3 pt)const{
			Point3 deltaPt;
					 if((pts[0].x<pt.x+1)&&(pts[1].x>pt.x-1)){deltaPt.x = (pts[1].x+pts[0].x)/2>pt.x?(pt.x-pts[0].x+DELTA):(pt.x-pts[1].x+DELTA);}
					 if((pts[0].y<pt.y+1)&&(pts[1].y>pt.y-1)){deltaPt.y = (pts[1].y+pts[0].y)/2>pt.y?(pt.y-pts[0].y+DELTA):(pt.y-pts[1].y+DELTA);}
					 if((pts[0].z<pt.z+1)&&(pts[1].z>pt.z-1)){deltaPt.z = (pts[1].z+pts[0].z)/2>pt.z?(pt.z-pts[0].z+DELTA):(pt.z-pts[1].z+DELTA);}
					 if(deltaPt.x&&deltaPt.y&&deltaPt.z){
								smallest(deltaPt);	 
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
int Impasse::Pushp(const Point3 pt){

		  Point3 isAlready = Includes(pt);
		  if(!(isAlready.x||isAlready.y||isAlready.z)){
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
		  return j;
}
