#include "draw.h"
Draw::Draw(TexManager& tex){
	this->tex = tex;
}
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
void Draw::drawCubeTexur(int a,int x, int y, int z,int texID){
             glPushMatrix();
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
							glPopMatrix();
}
