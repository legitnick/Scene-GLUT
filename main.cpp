#include "main.h"

void draw()
{
     glEnable(GL_TEXTURE_2D);{
         glPushMatrix();{
         glRotatef(90,1,0,0);
         glTranslatef(0,300,0);                     
         glPushMatrix();{
             glColor3fv(drw->white);
             glBindTexture(GL_TEXTURE_2D,tx.skybox[SKY_RIGHT]);
             glBegin(GL_QUADS);
                 glTexCoord2f(0,0); glVertex3f(-D,-D,-D);
                 glTexCoord2f(1,0); glVertex3f(+D,-D,-D);
                 glTexCoord2f(1,1); glVertex3f(+D,+D,-D);
                 glTexCoord2f(0,1); glVertex3f(-D,+D,-D);
             glEnd();
  
             glBindTexture(GL_TEXTURE_2D,tx.skybox[SKY_FRONT]);
             glBegin(GL_QUADS);
                 glTexCoord2f(0,0); glVertex3f(+D,-D,-D);
                 glTexCoord2f(1,0); glVertex3f(+D,-D,+D);
                 glTexCoord2f(1,1); glVertex3f(+D,+D,+D);
                 glTexCoord2f(0,1); glVertex3f(+D,+D,-D);
             glEnd();
  
             glBindTexture(GL_TEXTURE_2D,tx.skybox[SKY_LEFT]);
             glBegin(GL_QUADS);
                 glTexCoord2f(0,0); glVertex3f(+D,-D,+D);
                 glTexCoord2f(1,0); glVertex3f(-D,-D,+D);
                 glTexCoord2f(1,1); glVertex3f(-D,+D,+D);
                 glTexCoord2f(0,1); glVertex3f(+D,+D,+D);
             glEnd();
             
             glBindTexture(GL_TEXTURE_2D,tx.skybox[SKY_BACK]);
             glBegin(GL_QUADS);
                 glTexCoord2f(0,0); glVertex3f(-D,-D,+D);
                 glTexCoord2f(1,0); glVertex3f(-D,-D,-D);
                 glTexCoord2f(1,1); glVertex3f(-D,+D,-D);
                 glTexCoord2f(0,1); glVertex3f(-D,+D,+D);
             glEnd();

             /* Top and Bottom */
             glBindTexture(GL_TEXTURE_2D,tx.skybox[SKY_UP]);
             glBegin(GL_QUADS);
                 glTexCoord2f(0,0); glVertex3f(-D,+D,-D);
                 glTexCoord2f(1,0); glVertex3f(+D,+D,-D);
                 glTexCoord2f(1,1); glVertex3f(+D,+D,+D);
                 glTexCoord2f(0,1); glVertex3f(-D,+D,+D);
             glEnd();
             
             glBindTexture(GL_TEXTURE_2D,tx.skybox[SKY_DOWN]);
             glBegin(GL_QUADS);
                 glTexCoord2f(1,1); glVertex3f(+D,-D,-D);
                 glTexCoord2f(0,1); glVertex3f(-D,-D,-D);
                 glTexCoord2f(0,0); glVertex3f(-D,-D,+D);
                 glTexCoord2f(1,0); glVertex3f(+D,-D,+D);
             glEnd();
             
         }glPopMatrix();
         }glPopMatrix();
         
         // Wall 1
         glPushMatrix();{
             glRotatef(0,0,0,0);
             glTranslatef(0,0,0);
             
             //////////////////////////////////////////////////////////////////////////////////////////////////////
             /////////////////////////////////Design of the Wall //////////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glEnable(GL_BLEND);
             glColor4f(1,1,1,1);
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
             glAlphaFunc(GL_GREATER,.1);
             glEnable( GL_ALPHA_TEST );

				 drw->drawCubeTexur(200,500,20,10,tx.texid13);
//             glPushMatrix(); {                                                       // middle wall                                                            
//                 glNormal3f(0,0,1);
//                 glBegin(GL_POLYGON);{
//                     glTexCoord2f(0,0);  glVertex3f(-100, 0, 0);
//                     glTexCoord2f(0,1);  glVertex3f(-100, 0, 100);
//                     glTexCoord2f(1,1); glVertex3f(100, 0, 100);
//                     glTexCoord2f(1,0); glVertex3f(100, 0, 0);
//                 }glEnd();
//             } glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glPushMatrix(); {                                                       // left wall
                 glNormal3f(0,0,1);
                 glTranslatef(250,0,0);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-150, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-150, 0, 90);
                     glTexCoord2f(1,1); glVertex3f(-100, 0, 90);
                     glTexCoord2f(1,0); glVertex3f(-100, 0, 0);
                 }glEnd();
             } glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glPushMatrix(); {                                                       // right wall                                                         
                 glNormal3f(0,0,1);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0); glVertex3f(-150, 0, 0);
                     glTexCoord2f(0,1); glVertex3f(-150, 0, 90);
                     glTexCoord2f(1,1); glVertex3f(-100, 0, 90);
                     glTexCoord2f(1,0); glVertex3f(-100, 0, 0);
                 }glEnd();
             } glPopMatrix();
             
         }glPopMatrix();
         
         // Wall 2
         glPushMatrix();{
             glRotatef(90,0,0,1);
             glTranslatef(-167,170,0);
             
             //////////////////////////////////////////////////////////////////////////////////////////////////////
             /////////////////////////////////Design of the Wall //////////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glEnable(GL_BLEND);
             glColor4f(1,1,1,1);
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
             glAlphaFunc(GL_GREATER,.1);
             glEnable( GL_ALPHA_TEST );
         
             glPushMatrix(); {                                                       // middle wall                                                            
                 glNormal3f(0,0,1);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-100, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-100, 0, 100);
                     glTexCoord2f(1,1); glVertex3f(100, 0, 100);
                     glTexCoord2f(1,0); glVertex3f(100, 0, 0);
                 }glEnd();
             } glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glPushMatrix(); {                                                       // left wall
                 glNormal3f(0,0,1);
                 glTranslatef(250,0,0);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-150, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-150, 0, 90);
                     glTexCoord2f(1,1); glVertex3f(-100, 0, 90);
                     glTexCoord2f(1,0); glVertex3f(-100, 0, 0);
                 }glEnd();
             } glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glPushMatrix(); {                                                       // right wall                                                         
                 glNormal3f(0,0,1);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-150, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-150, 0, 90);
                     glTexCoord2f(1,1); glVertex3f(-100, 0, 90);
                     glTexCoord2f(1,0); glVertex3f(-100, 0, 0);
                 }glEnd();
             } glPopMatrix();
             
         }glPopMatrix();
         
         // Wall 3
         glPushMatrix();{
             glRotatef(90,0,0,1);
             glTranslatef(-167,-170,0);
             
             //////////////////////////////////////////////////////////////////////////////////////////////////////
             /////////////////////////////////Design of the Wall //////////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glEnable(GL_BLEND);
             glColor4f(1,1,1,1);
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
             glAlphaFunc(GL_GREATER,.1);
             glEnable( GL_ALPHA_TEST );
         
             glPushMatrix(); {                                                       // middle wall                                                            
                 glNormal3f(0,0,1);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-100, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-100, 0, 100);
                     glTexCoord2f(1,1); glVertex3f(100, 0, 100);
                     glTexCoord2f(1,0); glVertex3f(100, 0, 0);
                 }glEnd();
             } glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glPushMatrix(); {                                                       // left wall
                 glNormal3f(0,0,1);
                 glTranslatef(250,0,0);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-150, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-150, 0, 90);
                     glTexCoord2f(1,1); glVertex3f(-100, 0, 90);
                     glTexCoord2f(1,0); glVertex3f(-100, 0, 0);
                 }glEnd();
             } glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glPushMatrix(); {                                                       // right wall                                                         
                 glNormal3f(0,0,1);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-150, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-150, 0, 90);
                     glTexCoord2f(1,1); glVertex3f(-100, 0, 90);
                     glTexCoord2f(1,0); glVertex3f(-100, 0, 0);
                 }glEnd();
             } glPopMatrix();
             
         }glPopMatrix();
         
         // Wall 4
         glPushMatrix();{
             glRotatef(0,0,0,0);
             glTranslatef(0,-330,0);
             
             //////////////////////////////////////////////////////////////////////////////////////////////////////
             /////////////////////////////////Design of the Wall //////////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glEnable(GL_BLEND);
             glColor4f(1,1,1,1);
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
             glAlphaFunc(GL_GREATER,.1);
             glEnable( GL_ALPHA_TEST );
         
             glPushMatrix(); {                                                       // middle wall                                                            
                 glNormal3f(0,0,1);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-100, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-100, 0, 100);
                     glTexCoord2f(1,1); glVertex3f(100, 0, 100);
                     glTexCoord2f(1,0); glVertex3f(100, 0, 0);
                 }glEnd();
             } glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glPushMatrix(); {                                                       // left wall
                 glNormal3f(0,0,1);
                 glTranslatef(250,0,0);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-150, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-150, 0, 90);
                     glTexCoord2f(1,1); glVertex3f(-100, 0, 90);
                     glTexCoord2f(1,0); glVertex3f(-100, 0, 0);
                 }glEnd();
             } glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D,tx.texid1);
             glPushMatrix(); {                                                       // right wall                                                         
                 glNormal3f(0,0,1);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-150, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(-150, 0, 90);
                     glTexCoord2f(1,1); glVertex3f(-100, 0, 90);
                     glTexCoord2f(1,0); glVertex3f(-100, 0, 0);
                 }glEnd();
             } glPopMatrix();
             
         }glPopMatrix();
         
         
         
         // Ceiling
         glPushMatrix();{
             glBindTexture(GL_TEXTURE_2D,tx.texid15);
             glTranslatef(0,0,90);
             glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-170, 0, 0);
                     glTexCoord2f(0,10);  glVertex3f(-170, -330, 0);
                     glTexCoord2f(10,10); glVertex3f(170, -330, 0);
                     glTexCoord2f(10,0); glVertex3f(170, 0, 0);
             }glEnd();
             
             glPushMatrix();{
                 glPushMatrix();{
                     glTranslatef(90,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(70,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(50,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(30,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(10,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(-10,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(-30,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(-50,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(-70,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(-90,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
             }glPopMatrix();
             
             glPushMatrix();{
                 glPushMatrix();{
                     glTranslatef(0,-308,0);
                     glTranslatef(90,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(0,-308,0);
                     glTranslatef(70,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(0,-308,0);            
                     glTranslatef(50,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(0,-308,0);            
                     glTranslatef(30,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(0,-308,0);            
                     glTranslatef(10,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(0,-308,0);
                     glTranslatef(-10,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(0,-308,0);            
                     glTranslatef(-30,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(0,-308,0);            
                     glTranslatef(-50,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(0,-308,0);            
                     glTranslatef(-70,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glTranslatef(0,-308,0);            
                     glTranslatef(-90,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
             }glPopMatrix();
             
             glPushMatrix();{
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,-148,0);
                     glTranslatef(90,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,-148,0);
                     glTranslatef(70,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,-148,0);            
                     glTranslatef(50,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,-148,0);            
                     glTranslatef(30,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,-148,0);           
                     glTranslatef(10,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,-148,0);
                     glTranslatef(-10,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,-148,0);            
                     glTranslatef(-30,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,-148,0);            
                     glTranslatef(-50,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,-148,0);            
                     glTranslatef(-70,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,-148,0);            
                     glTranslatef(-90,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
             }glPopMatrix();
             
             glPushMatrix();{
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,170,0);
                     glTranslatef(90,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,170,0);
                     glTranslatef(70,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,170,0);           
                     glTranslatef(50,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,170,0);           
                     glTranslatef(30,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,170,0);           
                     glTranslatef(10,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,170,0);
                     glTranslatef(-10,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,170,0);            
                     glTranslatef(-30,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,170,0);            
                     glTranslatef(-50,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,170,0);            
                     glTranslatef(-70,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
                 glPushMatrix();{
                     glRotatef(90,0,0,1);
                     glTranslatef(-167,170,0);           
                     glTranslatef(-90,-11,0);
                     glutSolidCube(20);
                 }glPopMatrix();
             }glPopMatrix();
             
         }glPopMatrix();
         
         
         
         
         // Minar 1
         glPushMatrix();{
                         
             glTranslatef(170,0,0);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             ////////////////////////////////Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // lower part of the minar
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,0);
                 gluCylinder(quadric, 20, 20, 100, 6, 20);
             }glPopMatrix();
             
             glBindTexture(GL_TEXTURE_2D, tx.texid5);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 20, 20, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                           // minar carnish
                 glColor3f(0.99,0.62,0.55);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(20, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
             glBindTexture(GL_TEXTURE_2D, tx.texid14);
             glPushMatrix();{                                                        // lower part of the dome
                 glTranslatef(0,0,150);
                 gluCylinder(quadric, 20, 20, 15, 6, 20);
             }glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.99,0.62,0.55);
                 glTranslatef(0,0,172);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 10, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,186);
		         glutSolidCone(10,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,190);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,204);
                 glScalef(2, 2, 2);
		         glutSolidSphere(2, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         
         // Minar 2
         glPushMatrix();{
                         
             glTranslatef(-170,0,0);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             ////////////////////////////////Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // lower part of the minar
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,0);
                 gluCylinder(quadric, 20, 20, 100, 6, 20);
             }glPopMatrix();
             
             glBindTexture(GL_TEXTURE_2D, tx.texid5);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 20, 20, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // minar carnish
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(20, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
             glBindTexture(GL_TEXTURE_2D, tx.texid5);
             glPushMatrix();{                                                        // lower part of the dome
                 glTranslatef(0,0,150);
                 gluCylinder(quadric, 20, 20, 15, 6, 20);
             }glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,172);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 10, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,186);
		         glutSolidCone(10,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,190);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,204);
                 glScalef(2, 2, 2);
		         glutSolidSphere(2, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Minar 3
         glPushMatrix();{
                         
             glTranslatef(170,-330,0);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             ////////////////////////////////Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // lower part of the minar
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,0);
                 gluCylinder(quadric, 20, 20, 100, 6, 20);
             }glPopMatrix();
             
             glBindTexture(GL_TEXTURE_2D, tx.texid5);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 20, 20, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // minar carnish
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(20, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
             glBindTexture(GL_TEXTURE_2D, tx.texid5);
             glPushMatrix();{                                                        // lower part of the dome
                 glTranslatef(0,0,150);
                 gluCylinder(quadric, 20, 20, 15, 6, 20);
             }glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,172);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 10, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,186);
		         glutSolidCone(10,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,190);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,204);
                 glScalef(2, 2, 2);
		         glutSolidSphere(2, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Minar 4
         glPushMatrix();{
                         
             glTranslatef(-170,-330,0);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             ////////////////////////////////Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // lower part of the minar
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,0);
                 gluCylinder(quadric, 20, 20, 100, 6, 20);
             }glPopMatrix();
             
             glBindTexture(GL_TEXTURE_2D, tx.texid5);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 20, 20, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // minar carnish
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(20, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
             glBindTexture(GL_TEXTURE_2D, tx.texid5);
             glPushMatrix();{                                                        // lower part of the dome
                 glTranslatef(0,0,150);
                 gluCylinder(quadric, 20, 20, 15, 6, 20);
             }glPopMatrix();
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,172);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 10, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,186);
		         glutSolidCone(10,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,190);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,204);
                 glScalef(2, 2, 2);
		         glutSolidSphere(2, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         
         
         
         // Small Minar 1
         glPushMatrix();{
                         
             glTranslatef(90,-8,-10);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             //////////////////////////////// Small Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 10, 10, 50, 6, 20);
             }glPopMatrix();
             
             
             glPushMatrix();{                                                     // minar carnish
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(8, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Small Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,156);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 5.2, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,161);
		         glutSolidCone(5,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,155);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,174);
                 glScalef(2, 2, 2);
		         glutSolidSphere(1.5, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Small Minar 2
         glPushMatrix();{
                         
             glTranslatef(-90,-8,-10);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             //////////////////////////////// Small Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 10, 10, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // minar carnish
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(8, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Small Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,156);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 5.2, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,161);
		         glutSolidCone(5,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,155);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,174);
                 glScalef(2, 2, 2);
		         glutSolidSphere(1.5, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Small Minar 3
         glPushMatrix();{
                         
             glTranslatef(-90,-321,-10);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             //////////////////////////////// Small Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 10, 10, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // minar carnish
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(8, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Small Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,156);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 5.2, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,161);
		         glutSolidCone(5,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,155);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,174);
                 glScalef(2, 2, 2);
		         glutSolidSphere(1.5, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Small Minar 4
         glPushMatrix();{
                         
             glTranslatef(90,-321,-10);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             //////////////////////////////// Small Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 10, 10, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // minar carnish
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(8, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Small Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,156);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 5.2, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,161);
		         glutSolidCone(5,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,155);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,174);
                 glScalef(2, 2, 2);
		         glutSolidSphere(1.5, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Small Minar 5
         glPushMatrix();{
             glRotatef(90,0,0,1);            
             glTranslatef(-80,-162,-10);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             //////////////////////////////// Small Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 10, 10, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // minar carnish
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(8, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Small Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,156);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 5.2, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,161);
		         glutSolidCone(5,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,155);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,174);
                 glScalef(2, 2, 2);
		         glutSolidSphere(1.5, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Small Minar 6
         glPushMatrix();{
             glRotatef(90,0,0,1);            
             glTranslatef(-257,-162,-10);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             //////////////////////////////// Small Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 10, 10, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // minar carnish
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(8, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Small Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,156);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 5.2, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,161);
		         glutSolidCone(5,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,155);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,174);
                 glScalef(2, 2, 2);
		         glutSolidSphere(1.5, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Small Minar 7
         glPushMatrix();{
             glRotatef(90,0,0,1);            
             glTranslatef(-257,162,-10);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             //////////////////////////////// Small Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 10, 10, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // minar carnish
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(8, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Small Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,156);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 5.2, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,161);
		         glutSolidCone(5,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,155);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,174);
                 glScalef(2, 2, 2);
		         glutSolidSphere(1.5, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Small Minar 8
         glPushMatrix();{
             glRotatef(90,0,0,1);            
             glTranslatef(-80,+162,-10);
             
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             //////////////////////////////// Small Minar Body Design//////////////////////////////////////////////////////////////
             ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
             
             glBindTexture(GL_TEXTURE_2D, tx.texid4);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // minar gliphs
                 glRotatef(90,0,0,1);
                 glTranslatef(0,0,100);
                 gluCylinder(quadric, 10, 10, 50, 6, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // minar carnish
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,0,150);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(8, 6, 3);
             }glPopMatrix();
             
             //////////////////////////////////////////////////////////////////////////////////////////////////
             ///////////////////////////////// Small Minar Dome Design///////////////////////////////////////////////
             //////////////////////////////////////////////////////////////////////////////////////////////////
         
             glBindTexture(GL_TEXTURE_2D, tx.texid6);
             glPushMatrix();{                                                        // main dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,156);
                 glScalef(2, 2, 1.8);
		         gluSphere(quadric, 5.2, 20, 20);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,161);
		         glutSolidCone(5,10,20,20);
             }glPopMatrix();
         
             gluQuadricTexture(quadric, GLU_FALSE);
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,0,155);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 25, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,0,174);
                 glScalef(2, 2, 2);
		         glutSolidSphere(1.5, 20, 20);
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Big Dome
         glPushMatrix();{
             glTranslatef(0,0,-10);
             glBindTexture(GL_TEXTURE_2D, tx.texid16);
             gluQuadricNormals(quadric,GLU_SMOOTH);
             gluQuadricTexture(quadric, GLU_TRUE);
             glPushMatrix();{                                                        // octagon 1
                 glTranslatef(0,-170,100);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 80, 80, 10, 8, 2);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // octagon 1 cover
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,-170,110);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(46, 8, 3);
             }glPopMatrix();
             
             glPushMatrix();{                                                        //  octagon 2
                 glTranslatef(0,-170,110);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 70, 70, 10, 8, 2);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // octagon 2 cover
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,-170,120);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(40, 8, 3);
             }glPopMatrix();
             
             glPushMatrix();{                                                        //  octagon 3
                 glTranslatef(0,-170,120);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 60, 60, 10, 8, 2);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // octagon 3 cover
                 glColor3f(0.62,0.21,0.17);
                 glTranslatef(0,-170,130);
                 glScalef(2, 2, 0.1);
		         glutSolidSphere(35, 8, 3);
             }glPopMatrix();
             
             glPushMatrix();{                                                        //  octagon 4
                 glTranslatef(0,-170,130);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 50, 50, 30, 8, 2);
             }glPopMatrix();
             
             glBindTexture(GL_TEXTURE_2D, tx.texid8);
             glPushMatrix();{                                                        // big dome sphere
                 glTranslatef(0,-170,170);
                 glColor3f(0.34,0.91,0.74);
                 gluSphere(quadric, 50, 8, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // cone above the dome
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,-170,215);
		         glutSolidCone(20,20,20,20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // solid stick above the cone
                 glTranslatef(0,-170,230);
                 glColor3f(0.34,0.91,0.74);
                 gluCylinder(quadric, 1, 1, 40, 4, 2);
             }glPopMatrix();
         
             glPushMatrix();{                                                        // sphere in the middle of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,-170,250);
                 glScalef(2, 2, 2);
		         glutSolidSphere(3, 20, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // sphere in the bottom of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,-170,240);
                 glScalef(2, 2, 2);
		         glutSolidSphere(1.5, 20, 20);
             }glPopMatrix();
             
             glPushMatrix();{                                                        // sphere in the top of the stick
                 glColor3f(0.34,0.91,0.74);
                 glTranslatef(0,-170,260);
                 glScalef(2, 2, 2);
		         glutSolidSphere(1.5, 20, 20);
             }glPopMatrix();
         }glPopMatrix();
         
         // extra environment
         glPushMatrix();{
             //Kella Floor            
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid7);
                 glTranslatef(0,-175,0);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-248, -248, 0);
                     glTexCoord2f(0,20);  glVertex3f(-248, 248, 0);
                     glTexCoord2f(20,20);  glVertex3f(248, 248, 0);
                     glTexCoord2f(20,0); glVertex3f(248, -248, 0);
                 }glEnd();
             }glPopMatrix();
             glPushMatrix();{
                 glBindTexture(GL_TEXTURE_2D, tx.texid7);
                 glTranslatef(0,-175,-10);
                 glRotatef(45,0,0,1);
                 gluCylinder(quadric, 350, 350, 10, 4, 1);
             }glPopMatrix();
             
             // red brick boundary
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid12);
                 glTranslatef(0,-175,-10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-348, -348, 0);
                     glTexCoord2f(0,20);  glVertex3f(-348, 348, 0);
                     glTexCoord2f(20,20);  glVertex3f(348, 348, 0);
                     glTexCoord2f(20,0); glVertex3f(348, -348, 0);
                 }glEnd();
             }glPopMatrix();
             
             //red brick 1
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid12);
                 glTranslatef(97,572,-10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-60, -400, 0);
                     glTexCoord2f(0,20);  glVertex3f(-60, 400, 0);
                     glTexCoord2f(4,20);  glVertex3f(60, 400, 0);
                     glTexCoord2f(4,0); glVertex3f(60, -400, 0);
                 }glEnd();
             }glPopMatrix();
             
             //red brick 2
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid12);
                 glTranslatef(-97,572,-10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-60, -400, 0);
                     glTexCoord2f(0,20);  glVertex3f(-60, 400, 0);
                     glTexCoord2f(4,20);  glVertex3f(60, 400, 0);
                     glTexCoord2f(4,0); glVertex3f(60, -400, 0);
                 }glEnd();
             }glPopMatrix();
             
             //red brick 3
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glRotatef(90,0,0,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid12);
                 glTranslatef(-160,748,-10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-60, -400, 0);
                     glTexCoord2f(0,20);  glVertex3f(-60, 400, 0);
                     glTexCoord2f(4,20);  glVertex3f(60, 400, 0);
                     glTexCoord2f(4,0); glVertex3f(60, -400, 0);
                 }glEnd();
             }glPopMatrix();
             
             //red brick 4
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glRotatef(-90,0,0,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid12);
                 glTranslatef(160,748,-10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-60, -400, 0);
                     glTexCoord2f(0,20);  glVertex3f(-60, 400, 0);
                     glTexCoord2f(4,20);  glVertex3f(60, 400, 0);
                     glTexCoord2f(4,0); glVertex3f(60, -400, 0);
                 }glEnd();
             }glPopMatrix();
             
             //red brick 4
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glRotatef(180,0,0,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid12);
                 glTranslatef(0,923,-10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(-60, -400, 0);
                     glTexCoord2f(0,20);  glVertex3f(-60, 400, 0);
                     glTexCoord2f(4,20);  glVertex3f(60, 400, 0);
                     glTexCoord2f(4,0); glVertex3f(60, -400, 0);
                 }glEnd();
             }glPopMatrix();
             
             // grass field 1
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glRotatef(180,0,0,1);
                 glTranslatef(147,-1000,-11);
                 glBindTexture(GL_TEXTURE_2D, tx.texid10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,10);  glVertex3f(0, 1200, 0);
                     glTexCoord2f(10,10);  glVertex3f(1100, 1200, 0);
                     glTexCoord2f(10,0); glVertex3f(1100, 0, 0);
                 }glEnd();
             }glPopMatrix();
             
             // grass field 2
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glRotatef(180,0,0,1);
                 glTranslatef(-1255,-1000,-11);
                 glBindTexture(GL_TEXTURE_2D, tx.texid10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,10);  glVertex3f(0, 1200, 0);
                     glTexCoord2f(10,10);  glVertex3f(1100, 1200, 0);
                     glTexCoord2f(10,0); glVertex3f(1100, 0, 0);
                 }glEnd();
             }glPopMatrix();
             
             // grass field 3
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glRotatef(180,0,0,1);
                 glTranslatef(-53,150,-11);
                 glBindTexture(GL_TEXTURE_2D, tx.texid10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,10);  glVertex3f(0, 1200, 0);
                     glTexCoord2f(10,10);  glVertex3f(1300, 1200, 0);
                     glTexCoord2f(10,0); glVertex3f(1300, 0, 0);
                 }glEnd();
             }glPopMatrix();
             
             // grass field 4
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glRotatef(180,0,0,1);
                 glTranslatef(-1255,150,-11);
                 glBindTexture(GL_TEXTURE_2D, tx.texid10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,10);  glVertex3f(0, 1200, 0);
                     glTexCoord2f(10,10);  glVertex3f(1300, 1200, 0);
                     glTexCoord2f(10,0); glVertex3f(1300, 0, 0);
                 }glEnd();
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Pool 1
         glPushMatrix();{
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid13);
                 glTranslatef(37,170,-30);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(0, 300, 0);
                     glTexCoord2f(1,1);  glVertex3f(0, 300, 20);
                     glTexCoord2f(1,0); glVertex3f(0, 0, 20);
                 }glEnd();
             }glPopMatrix();
             
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid13);
                 glTranslatef(-37,170,-30);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(74, 0, 0);
                     glTexCoord2f(1,1);  glVertex3f(74, 0, 20);
                     glTexCoord2f(1,0); glVertex3f(0, 0, 20);
                 }glEnd();
             }glPopMatrix();
             
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid13);
                 glTranslatef(-37,470,-30);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(74, 0, 0);
                     glTexCoord2f(1,1);  glVertex3f(74, 0, 20);
                     glTexCoord2f(1,0); glVertex3f(0, 0, 20);
                 }glEnd();
             }glPopMatrix();
             
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid13);
                 glTranslatef(-37,170,-30);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(0, 300, 0);
                     glTexCoord2f(1,1);  glVertex3f(0, 300, 20);
                     glTexCoord2f(1,0); glVertex3f(0, 0, 20);
                 }glEnd();
             }glPopMatrix();
             
             //water
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid11);
                 glTranslatef(-37,170,-30);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,4);  glVertex3f(0, 300, 0);
                     glTexCoord2f(1,4);  glVertex3f(74, 300, 0);
                     glTexCoord2f(1,0); glVertex3f(74, 0, 0);
                 }glEnd();
             }glPopMatrix();
             
             //cylinders
             glPushMatrix();{
                 glTranslatef(0,25,0);
                 //pull cylinder 1
                 glPushMatrix();{
                     glPushMatrix();{
                         glColor4f(1,1,1,1);
                         glBindTexture(GL_TEXTURE_2D, tx.texid5);
                         glTranslatef(0,200,-30);
                         gluCylinder(quadric, 5, 5, 20, 10, 10);
                     }glPopMatrix();
                     glPushMatrix();{
                         glTranslatef(0,200,-10);
                         gluSphere(quadric, 6, 6, 6);
                     }glPopMatrix();
                 }glPopMatrix();
             
                 //pull cylinder 2
                 glPushMatrix();{
                     glPushMatrix();{
                         glColor4f(1,1,1,1);
                         glBindTexture(GL_TEXTURE_2D, tx.texid5);
                         glTranslatef(0,250,-30);
                         gluCylinder(quadric, 5, 5, 20, 10, 10);
                     }glPopMatrix();
                     glPushMatrix();{
                         glTranslatef(0,250,-10);
                         gluSphere(quadric, 6, 6, 6);
                     }glPopMatrix();
                 }glPopMatrix();
             
                 //pull cylinder 3
                 glPushMatrix();{
                     glPushMatrix();{
                         glColor4f(1,1,1,1);
                         glBindTexture(GL_TEXTURE_2D, tx.texid5);
                         glTranslatef(0,300,-30);
                         gluCylinder(quadric, 5, 5, 20, 10, 10);
                     }glPopMatrix();
                     glPushMatrix();{
                         glTranslatef(0,300,-10);
                         gluSphere(quadric, 6, 6, 6);
                     }glPopMatrix();
                 }glPopMatrix();
             
                 //pull cylinder 4
                 glPushMatrix();{
                     glPushMatrix();{
                         glColor4f(1,1,1,1);
                         glBindTexture(GL_TEXTURE_2D, tx.texid5);
                         glTranslatef(0,350,-30);
                         gluCylinder(quadric, 5, 5, 20, 10, 10);
                     }glPopMatrix();
                     glPushMatrix();{
                         glTranslatef(0,350,-10);
                         gluSphere(quadric, 6, 6, 6);
                     }glPopMatrix();
                 }glPopMatrix();
             
                 //pull cylinder 5
                 glPushMatrix();{
                     glPushMatrix();{
                         glColor4f(1,1,1,1);
                         glBindTexture(GL_TEXTURE_2D, tx.texid5);
                         glTranslatef(0,400,-30);
                         gluCylinder(quadric, 5, 5, 20, 10, 10);
                     }glPopMatrix();
                     glPushMatrix();{
                         glTranslatef(0,400,-10);
                         gluSphere(quadric, 6, 6, 6);
                     }glPopMatrix();
                 }glPopMatrix();
                 
             }glPopMatrix();
             
             //road after pool
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid12);
                 glTranslatef(-37,470,-10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,2);  glVertex3f(0, 70, 0);
                     glTexCoord2f(2,2);  glVertex3f(74, 70, 0);
                     glTexCoord2f(2,0); glVertex3f(74, 0, 0);
                 }glEnd();
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Pool 2
         glPushMatrix();{
             glTranslatef(0,370,0);
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid13);
                 glTranslatef(37,170,-30);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(0, 300, 0);
                     glTexCoord2f(1,1);  glVertex3f(0, 300, 20);
                     glTexCoord2f(1,0); glVertex3f(0, 0, 20);
                 }glEnd();
             }glPopMatrix();
             
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid13);
                 glTranslatef(-37,170,-30);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(74, 0, 0);
                     glTexCoord2f(1,1);  glVertex3f(74, 0, 20);
                     glTexCoord2f(1,0); glVertex3f(0, 0, 20);
                 }glEnd();
             }glPopMatrix();
             
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid13);
                 glTranslatef(-37,470,-30);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(74, 0, 0);
                     glTexCoord2f(1,1);  glVertex3f(74, 0, 20);
                     glTexCoord2f(1,0); glVertex3f(0, 0, 20);
                 }glEnd();
             }glPopMatrix();
             
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid13);
                 glTranslatef(-37,170,-30);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,1);  glVertex3f(0, 300, 0);
                     glTexCoord2f(1,1);  glVertex3f(0, 300, 20);
                     glTexCoord2f(1,0); glVertex3f(0, 0, 20);
                 }glEnd();
             }glPopMatrix();
             
             //water
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid11);
                 glTranslatef(-37,170,-30);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,4);  glVertex3f(0, 300, 0);
                     glTexCoord2f(1,4);  glVertex3f(74, 300, 0);
                     glTexCoord2f(1,0); glVertex3f(74, 0, 0);
                 }glEnd();
             }glPopMatrix();
             
             //cylinders
             glPushMatrix();{
                 glTranslatef(0,25,0);
                 //pull cylinder 1
                 glPushMatrix();{
                     glPushMatrix();{
                         glColor4f(1,1,1,1);
                         glBindTexture(GL_TEXTURE_2D, tx.texid5);
                         glTranslatef(0,200,-30);
                         gluCylinder(quadric, 5, 5, 20, 10, 10);
                     }glPopMatrix();
                     glPushMatrix();{
                         glTranslatef(0,200,-10);
                         gluSphere(quadric, 6, 6, 6);
                     }glPopMatrix();
                 }glPopMatrix();
             
                 //pull cylinder 2
                 glPushMatrix();{
                     glPushMatrix();{
                         glColor4f(1,1,1,1);
                         glBindTexture(GL_TEXTURE_2D, tx.texid5);
                         glTranslatef(0,250,-30);
                         gluCylinder(quadric, 5, 5, 20, 10, 10);
                     }glPopMatrix();
                     glPushMatrix();{
                         glTranslatef(0,250,-10);
                         gluSphere(quadric, 6, 6, 6);
                     }glPopMatrix();
                 }glPopMatrix();
             
                 //pull cylinder 3
                 glPushMatrix();{
                     glPushMatrix();{
                         glColor4f(1,1,1,1);
                         glBindTexture(GL_TEXTURE_2D, tx.texid5);
                         glTranslatef(0,300,-30);
                         gluCylinder(quadric, 5, 5, 20, 10, 10);
                     }glPopMatrix();
                     glPushMatrix();{
                         glTranslatef(0,300,-10);
                         gluSphere(quadric, 6, 6, 6);
                     }glPopMatrix();
                 }glPopMatrix();
             
                 //pull cylinder 4
                 glPushMatrix();{
                     glPushMatrix();{
                         glColor4f(1,1,1,1);
                         glBindTexture(GL_TEXTURE_2D, tx.texid5);
                         glTranslatef(0,350,-30);
                         gluCylinder(quadric, 5, 5, 20, 10, 10);
                     }glPopMatrix();
                     glPushMatrix();{
                         glTranslatef(0,350,-10);
                         gluSphere(quadric, 6, 6, 6);
                     }glPopMatrix();
                 }glPopMatrix();
             
                 //pull cylinder 5
                 glPushMatrix();{
                     glPushMatrix();{
                         glColor4f(1,1,1,1);
                         glBindTexture(GL_TEXTURE_2D, tx.texid5);
                         glTranslatef(0,400,-30);
                         gluCylinder(quadric, 5, 5, 20, 10, 10);
                     }glPopMatrix();
                     glPushMatrix();{
                         glTranslatef(0,400,-10);
                         gluSphere(quadric, 6, 6, 6);
                     }glPopMatrix();
                 }glPopMatrix();
                 
             }glPopMatrix();
             
             //road after pool
             glPushMatrix();{
                 glColor4f(1,1,1,1);
                 glBindTexture(GL_TEXTURE_2D, tx.texid12);
                 glTranslatef(-37,470,-10);
                 glBegin(GL_POLYGON);{
                     glTexCoord2f(0,0);  glVertex3f(0, 0, 0);
                     glTexCoord2f(0,4);  glVertex3f(0, 132, 0);
                     glTexCoord2f(2,4);  glVertex3f(74, 132, 0);
                     glTexCoord2f(2,0); glVertex3f(74, 0, 0);
                 }glEnd();
             }glPopMatrix();
             
         }glPopMatrix();
         
         // Trees
         glPushMatrix();{
             // tree 1
             int tr_x = 200, tr_y = 200, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                    
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 2
             tr_x = 300, tr_y = 200, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                    
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 3
             tr_x = 200, tr_y = 400, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                     
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 4
             tr_x = 200, tr_y = 600, tr_z = -30;
             glPushMatrix(); {                                                                                                             
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                   
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 5
             tr_x = 200, tr_y = 800, tr_z = -30;
             glPushMatrix(); {                                                                                                           
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                 
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 6
             tr_x = 400, tr_y = 100, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                   
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 7
             tr_x = 400, tr_y = 0, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                   
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 8
             tr_x = 400, tr_y = -300, tr_z = -30;
             glPushMatrix(); {                                                                                                             
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                   
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 9
             tr_x = 400, tr_y = -400, tr_z = -30;
             glPushMatrix(); {                                                                                                             
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                    
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 10
             tr_x = 250, tr_y = -600, tr_z = -30;
             glPushMatrix(); {                                                                                                            
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                   
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 11
             tr_x = 150, tr_y = -600, tr_z = -30;
             glPushMatrix(); {                                                                                                           
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                    
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 12
             tr_x = 150, tr_y = -800, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                    
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 13
             tr_x = 150, tr_y = -1000, tr_z = -30;
             glPushMatrix(); {                                                                                                             
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                     
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 14
             tr_x = 150, tr_y = -1200, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                   
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 15
             tr_x = -150, tr_y = -1200, tr_z = -30;
             glPushMatrix(); {                                                                                                            
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                     
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 16
             tr_x = -150, tr_y = -1000, tr_z = -30;
             glPushMatrix(); {                                                                                                            
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                  
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 17
             tr_x = -150, tr_y = -800, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                   
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 18
             tr_x = -150, tr_y = -600, tr_z = -30;
             glPushMatrix(); {                                                                                                          
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 19
             tr_x = -250, tr_y = -600, tr_z = -30;
             glPushMatrix(); {                                                                                                           
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                   
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 20
             tr_x = -400, tr_y = -400, tr_z = -30;
             glPushMatrix(); {                                                                                                           
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                     
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 21
             tr_x = -400, tr_y = -300, tr_z = -30;
             glPushMatrix(); {                                                                                                            
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                    
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 22
             tr_x = -400, tr_y = 0, tr_z = -30;
             glPushMatrix(); {                                                                                                             
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                  
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 23
             tr_x = -400, tr_y = 100, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                    
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 24
             tr_x = -300, tr_y = 200, tr_z = -30;
             glPushMatrix(); {                                                                                                            
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                     
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 25
             tr_x = -200, tr_y = 200, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                    
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 26
             tr_x = -200, tr_y = 400, tr_z = -30;
             glPushMatrix(); {                                                                                                             
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                    
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 27
             tr_x = -200, tr_y = 600, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                    
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
             
             // tree 28
             tr_x = -200, tr_y = 800, tr_z = -30;
             glPushMatrix(); {                                                                                                              
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
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
             glPushMatrix(); {                                                                                                  
                 glBindTexture(GL_TEXTURE_2D, tx.texid9);
                 glTranslatef(tr_x,tr_y,tr_z);
                 glRotatef(90,0,0,1);
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
               
         }glPopMatrix();
         
     } glDisable(GL_TEXTURE_2D);
	
	
	



	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)

}

void idle(){
	glutPostRedisplay();	
}
void keyboardListener(unsigned char key, int x,int y){
		  switch(key){
			
		case 'w':	//reverse the rotation of camera
			cam->slide(0,0,-5);
			break;
			
		case 's':	//reverse the rotation of camera
			cam->slide(0,0,5);
			break;
			
		case 'd':	//toggle grids
			cam->slide(5,0,0);
			break;
			
		case 'a':	//toggle grids
			cam->slide(-5,0,0);
			break;
		case 27:	//ESCAPE KEY -- simply exit
			exit(0);
			break;

		default:
			break;
	}
}

void specialKeyListener(int key, int x,int y){
}
void Blink()
{
					 cam->slide(0,0,-160) ;
}
void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){
				Blink();
			}
			break;

		case GLUT_RIGHT_BUTTON:
			if(state == GLUT_DOWN){		
			}
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}

void init(){

	glutSetCursor(GLUT_CURSOR_NONE);	
	glutWarpPointer(WIDTH/2,HEIGHT/2);
	
    quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
	glEnable(GL_NORMALIZE);
	glClearColor(GROUND, 0);
	

	glClearDepth(1);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_LIGHT1);


  	glEnable(GL_COLOR_MATERIAL);
    
	glShadeModel(GL_FLAT);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	
    glEnable(GL_MAP1_VERTEX_3);
	
	glEnable(GL_AUTO_NORMAL);
    glEnable(GL_TEXTURE_2D);
	glEnable (GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glBlendFunc (GL_SRC_ALPHA_SATURATE, GL_ONE);
    glEnable(GL_NORMALIZE);


   tx.loadBMPs();
	drw=  std::make_shared<Draw>(tx);
   cam = std::make_shared<Camera_class>(drw->getImpasse());	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(70,	1,	0.1,	10000.0);

}

void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(GROUND, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  	
	GLfloat qaAmbientLight[]	= {0.9, 0.9, 0.9, 1.0};
	GLfloat qaDiffuseLight[]	= {0.9, 0.9, 0.9, 1.0};
	GLfloat qaSpecularLight[]	= {1.0, 1.0, 1.0, 1.0};

   /////////////////////////////////////////////////////////////////////////////////
   	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);


	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);



    float lightPosition[4] = {500, 500, 500.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);


	float lightPosition1[4] = {-500, 500, 500.0, 1.0};
	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);

	//draw();
	//drw->drawCubeTexure(200,500,100,50,tx.texid1);
	//drw->drawRoom(5,4,5);
				// drw->drawRoom(10,6,8);
				 //drw->drawCoordWall(5*40,9*40-1,4*40,0,20,tx.texid1);
	drw->drawLVL();
	drw->drawMouse();

	glutSwapBuffers();
   glDisable (GL_BLEND);
}
void Timer(int ms){
		  glutPostRedisplay();
		  glutTimerFunc(15,Timer,0);
}
int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("Game");

    init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback loadBMPstion
	//glutIdleFunc(idle);		//what you want to do in the idle time (when no drawing is occuring)
	glutTimerFunc(0, Timer, 0); 
	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	//glutKeyboardUpFunc(keyUp);

	//ADD mouse listeners:
	glutMouseFunc(mouseListener);
	
	glutPassiveMotionFunc(mouseHandler);
	glutMotionFunc(mouseHandler);
	glutFullScreen();
	glutMainLoop();		//The main loop of OpenGL
	
	return 0;
}
