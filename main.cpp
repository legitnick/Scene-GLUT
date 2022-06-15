#include "main.h"
bool Game::Sees(Camera_class& cam)const{
		  for(int i =0;i<100;i++){
					 std::cout<<"cam.xyz:"<<cam.eye.x<<' '<<cam.eye.y<<' '<<cam.eye.z<<'\n';
					 Point3 currCamPos = cam.impasse->getObjCube(drw->objN).Has(cam.eye);
								cam.slide(0,0,2);
					 if(!i)
					 std::cout<<"cam.impasse->getObjCube(drw->objN).xyz:"<<cam.impasse->getObjCube(drw->objN).pts[1].x<<' '<<cam.impasse->getObjCube(drw->objN).pts[1].y<<' '<<cam.impasse->getObjCube(drw->objN).pts[1].z<<'\n';
					 if(currCamPos.x||currCamPos.y||currCamPos.z){std::cout<<'T'<<'\n';
								return true;
					 }
		  }
		  return false;
}
void Game::Logic(){
		  Camera_class tmp(cam->impasse);
		  tmp.set(cam->eye,cam->look,cam->up);
		  if(Sees(tmp)){
					 std::cout<<"T\n";
					 pointed = true;
		  }
		  game.selected = false;
		  cam->slide(0,0,0);
}
void Game::keyboardListener(unsigned char key, int x,int y){
		  if(!(selected&&pointed)){
		  switch(key){
			
		case 'w':	//reverse the rotation of camera
			cam->slide(0,0,-3);
			break;
			
		case 's':	//reverse the rotation of camera
			cam->slide(0,0,3);
			break;
			
		case 'd':	//toggle grids
			cam->slide(3,0,0);
			break;
			
		case 'a':	//toggle grids
			cam->slide(-3,0,0);
			break;
		case '-':
			break;
		case '+':
			break;
		case 27:	//ESCAPE KEY -- simply exit
			exit(0);
			break;

		default:
			break;
	}
		  return;
		  }
		switch(key){
		  case 'w':	//reverse the rotation of camera
			drw->MoveObj(0,5);
			break;
			
		case 's':	//reverse the rotation of camera
			drw->MoveObj(0,-5);
			break;
			
		case 'd':	//toggle grids
			drw->MoveObj(5,0);
			break;
			
		case 'a':	//toggle grids
			drw->MoveObj(-5,0);
			break;

		}
}

void specialKeyListener(int key, int x,int y){
}
void Blink()
{
					 cam->slide(0,0,-160) ;
}
void Game::mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){
				Blink();
			}
			break;

		case GLUT_RIGHT_BUTTON:
			if(state == GLUT_DOWN){
					  std::cout<<"ms5\n";
					  selected = true;
			}if(state == GLUT_UP){
					  selected = false;
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

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing
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





    float lightPosition[4] = {500, 500, 500.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	drw->drawLVL();
	drw->drawMouse();

		  game.Logic();
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


	glutDisplayFunc(display);	//display callback loadBMPstion
	//glutIdleFunc(idle);		//what you want to do in the idle time (when no drawing is occuring)
	glutTimerFunc(0, Timer, 0); 
	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardHandler);
	glutSpecialFunc(specialKeyListener);
	//glutKeyboardUpFunc(keyUp);

	//ADD mouse listeners:
	glutMouseFunc(specialMouseHandler);
	
	glutPassiveMotionFunc(mouseHandler);
	glutMotionFunc(mouseHandler);
	glutFullScreen();
	glutMainLoop();		//The main loop of OpenGL
	
	return 0;
}
