#include "draw.h"
Draw::Draw(TexManager& tex){
	this->tex = tex;
	impasse = std::make_shared<Impasse>();
}
std::shared_ptr<Impasse> Draw::getImpasse(){return impasse;}
void Draw::drawMouse(){
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
glLoadIdentity();
gluOrtho2D(0.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_MODELVIEW);

glPushMatrix();
glLoadIdentity();


glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
	 float wpx = 5/(float)WIDTH;
	 float hpx = 5/(float)HEIGHT;
	 
    glVertex2f(0.5 - wpx, 0.5-hpx);
    glVertex2f(0.5 + wpx, 0.5-hpx);
    glVertex2f(0.5 + wpx, 0.5+hpx);
    glVertex2f(0.5 - wpx, 0.5+hpx);
glEnd();
// Making sure we can render 3d again
glMatrixMode(GL_PROJECTION);
glPopMatrix();
glMatrixMode(GL_MODELVIEW);
glPopMatrix();
//cam.setModelviewMatrix();
}
void Draw::drawCubeTexure(int a,int x, int y, int z,int texID){
             glPushMatrix(); {                                                       // middle wall                                                            
                 glNormal3f(0,0,1);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-100, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-100, 0, 100);
                     glTexCoord2f(1,1); glVertex3f(100, 0, 100);
                     glTexCoord2f(1,0); glVertex3f(100, 0, 0);
                 }glEnd();
             } glPopMatrix();
}
void Draw::drawWall(int d,int a,int texID){
			int x{},y{},z{};
			if(d == 0){
					  x = a;
					  z = a;
			}else if(d == 1){
					  y = a;
					  z = a;
			}else{
					  x = a;
					  y = a;
			}
							glPushMatrix(); {
							// middle wall     
					 glBindTexture(GL_TEXTURE_2D,texID);
                 glNormal3f(0,0,1);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(y?x:0, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(x, y, 0);
                     glTexCoord2f(1,1); glVertex3f(y?0:x, y, z);
                     glTexCoord2f(1,0); glVertex3f(0, 0, z);//this took all my creativity 
                 }glEnd();
             } glPopMatrix();
}
void Draw::drawRoom(int w,int h, int l){
		  int a = 40; 
	for(int i = 0;i<h;i++){
			  for(int j = 0;j<w;j++){
						 for(int k = 0;k<l;k++){
									if(!k||!j||!i||(i==h+1)||(j==w+1)||(k==l+1)){
											  drawCubeTexur(a,a*k,a*j,a*h,tex.texid1);
									}
						 }
			  }
	}
}
void Draw::drawCubeTexur(int a,int x, int y, int z,int texID){
         glPushMatrix();{
             glRotatef(0,0,0,0);
             glTranslatef(0,0,0);
             glEnable(GL_BLEND);
             glColor4f(1,1,1,1);
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
             glAlphaFunc(GL_GREATER,.1);
             glEnable( GL_ALPHA_TEST );

             glPushMatrix();
				 Point3 lBot,rTop;
				 lBot.set(x,y,z);
				 rTop.set(x+a,y+a,z+a);
				 impasse->Pushp(lBot);
				 impasse->Pushp(rTop);
			//	 std::cout<<x<<y<<z<<'\n'<<a<<'\n';
				 glTranslatef(x,y,z);
					  this->drawWall(0,a,texID);
					  glTranslatef(0,a,0);
					  this->drawWall(0,a,texID);
					  glTranslatef(0,-a,0);

					  this->drawWall(1,a,texID);
					  glTranslatef(a,0,0);
					  this->drawWall(1,a,texID);
					  glTranslatef(-a,0,0);

					  this->drawWall(2,a,texID);
					  glTranslatef(0,0,a);
					  this->drawWall(2,a,texID);
					  glTranslatef(0,0,-a);
							glTranslatef(-x,-y,-z);
			glPopMatrix();				glPopMatrix();
			}
}
