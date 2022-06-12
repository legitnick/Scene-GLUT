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
		  glEnable(GL_TEXTURE_2D);
		  {
					 glBindTexture(GL_TEXTURE_2D,texID);
					 glPushMatrix();{
								glutSolidCube(a);
					 }glPopMatrix();

		  }glDisable(GL_TEXTURE_2D);
}
void Draw::drawCubeTexur(int a,int x, int y, int z,int texID){
glPushMatrix();	
		  glEnable(GL_TEXTURE_2D);{
		  int tr_x = 400, tr_y = -400, tr_z = -30;
             glPushMatrix(); {                                                                                                             
                 glBindTexture(GL_TEXTURE_2D, tex.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,0);  glVertex3f(-15, 0, 30);
                     glTexCoord2f(0,1);  glVertex3f(-20, 0, 60);
                     glTexCoord2f(0,1); glVertex3f(-5, 0, 90);
                     glTexCoord2f(1,1); glVertex3f(5, 0, 90);
                     glTexCoord2f(1,0); glVertex3f(20, 0, 60);
                     glTexCoord2f(1,1); glVertex3f(15, 0, 30);
                 }glEnd();
             } glPopMatrix();
			}glDisable(GL_TEXTURE_2D);
		  glPopMatrix();
}
