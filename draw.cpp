#include "draw.h"
Draw::Draw(TexManager& tex){
	this->tex = tex;
	impasse = std::make_shared<Impasse>();
}
std::shared_ptr<Impasse> Draw::getImpasse(){return impasse;}
void Draw::begin2D(){

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
glLoadIdentity();
gluOrtho2D(0.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_MODELVIEW);

glPushMatrix();
glLoadIdentity();
}
void Draw::end2D(){

glEnd();
// Making sure we can render 3d again
glMatrixMode(GL_PROJECTION);
glPopMatrix();
glMatrixMode(GL_MODELVIEW);
glPopMatrix();
}

void Draw::showText(int x,int y, int z,const char* string){
begin2D();
		 glRasterPos3f(x,y,z);
		 for(const char* c = string;*c!=0;c++)
		 	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c[0]);
		 end2D();

}
void Draw::drawMouse(){
begin2D();

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
	 float wpx = 5/(float)WIDTH;
	 float hpx = 5/(float)HEIGHT;
	 
    glVertex2f(0.5 - wpx, 0.5-hpx);
    glVertex2f(0.5 + wpx, 0.5-hpx);
    glVertex2f(0.5 + wpx, 0.5+hpx);
    glVertex2f(0.5 - wpx, 0.5+hpx);
//cam.setModelviewMatrix();
    end2D();
}
void Draw::drawCoordWall(int x,int y,int z, int d,int a,int texID){
		  int xx{},yy{},zz{};
			if(d == 0){
					  xx = a;
					  zz = a;
			}else if(d == 1){
					  yy = a;
					  zz = a;
			}else{
					  xx = a;
					  yy = a;
			}
							glPushMatrix(); {
			glTranslatef(x,y,z);	
					 glBindTexture(GL_TEXTURE_2D,texID);
                 glNormal3f(0,0,1);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(yy?xx:0, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(xx, yy, 0);
                     glTexCoord2f(1,1); glVertex3f(yy?0:xx, yy, zz);
                     glTexCoord2f(1,0); glVertex3f(0, 0, zz);//this took all myy creativityy 
                 }glEnd();
			glTranslatef(-x,-y,-z);	
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
				 Point3 lBot(x,y,z),rTop(x+a,y+a,z+a);
				 impasse->Pushp(lBot);
				 impasse->Pushp(rTop);
         glPushMatrix();{
             glRotatef(0,0,0,0);
             glTranslatef(0,0,0);
             glEnable(GL_BLEND);
             glColor4f(1,1,1,1);
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
             glAlphaFunc(GL_GREATER,.1);
             glEnable( GL_ALPHA_TEST );

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
			glPopMatrix();				glPopMatrix();
			}
}
void Draw::MoveObj(int x,int y){this->x = x;this->y =y;}
void Draw::drawObj(){
drawCubeTexur(35,-120,190,0,tex.texid2);
}
void Draw::drawLoseScreen(){

         glPushMatrix();{
             glEnable(GL_BLEND);
             glColor4f(1,1,1,1);
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
             glAlphaFunc(GL_GREATER,.1);
             glEnable( GL_ALPHA_TEST );

             glPushMatrix();
		  drawCoordWall(250,100,-150,0,600,tex.texid3);
glPopMatrix();glPopMatrix();
			}}

void Draw::drawWinScreen(){
         glPushMatrix();{
             glRotatef(0,0,0,0);
             glTranslatef(0,0,0);
             glEnable(GL_BLEND);
             glColor4f(1,1,1,1);
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
             glAlphaFunc(GL_GREATER,.1);
             glEnable( GL_ALPHA_TEST );

             glPushMatrix();
		  drawCoordWall(250,100,-150,0,600,tex.texid3);
glPopMatrix();glPopMatrix();
			}}

void Draw::drawLVL(bool gg,bool wp){
		  if(!gg){
		  drawObj();
		  drawCubeTexur(300,-150,150,80,tex.texid2);
		  drawCubeTexur(300,-150,150,-300,tex.texid2);
		  drawCubeTexur(310,-460,150,-200,tex.texid12);
		  drawCubeTexur(310,150,150,-200,tex.texid12);
		  drawCubeTexur(310,-150,-150,-200,tex.texid12);
		  drawCubeTexur(310,-150,450,-200,tex.texid12);
		  drawCoordWall(151,251,30,0,20,tex.texid1);
		  return;
		  }
		  if(!wp){
				drawLoseScreen();return;
		  }
		  drawWinScreen();
}
