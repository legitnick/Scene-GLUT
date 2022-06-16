#include "main.h"
bool Game::Sees(Camera_class& cam)const{
		  for(int i =0;i<200;i++){
					 Point3 currCamPos = cam.impasse->getObjCube().Has(cam.eye);
								cam.slide(0,0,-3);
					 if(!i)
								return true;
					 }
		  
		  return false;
}
void Game::Logic(){
		  if(!gg){
		  Camera_class tmp(cam->impasse);
		  tmp.set(cam->eye,cam->look,cam->up);
		  if(Sees(tmp)){
					 //std::cout<<"T\n";
					 pointed = true;
		  }
		  
		  game.selected = false;
		  cam->slide(0,0,0);
}
}
void Game::WriteStats(){
		  std::fstream myfile;
		  myfile.open("statistics.txt");
		  std::string line;
  if (myfile.is_open())
  {
			 int i = 0;
    while ( getline (myfile,line) )
    {
				long int num  = stoi(line);
				if(i==0)num=gameCount;
				if(i==1)num += ms;
				i++;
				std::string newline = std::to_string(num);
				line.replace(0,line.size(),newline);
    }
    myfile.close();
  }

  else std::cout << "Unable to open file";
		  myfile<<gameCount<<'\n'<<ms;
		  myfile.close();
}
void Game::ShowStats(){
		  std::string line;
		  std::ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
				std::cout << line << '\n';
    }
    myfile.close();
  }

  else std::cout << "Unable to open file";

}
void Game::Quit(){
		  gameCount++;
		  WriteStats();
		  ShowStats();
			exit(0);
}
void Game::keyboardListener(unsigned char key, int x,int y){
		  if(!gg){
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
		game.quit();
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

		}}
}

void Game::Blink()
{
					 cam->slide(0,0,-160); this->gg = true;;
					 std::cout<<cam->eye.x<<'\n';
					 if(cam->eye.x==INT_MIN)this->wp = false;
}
void Game::mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
if(!gg){
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
	
	drw->drawLVL(game.gg,game.wp);
	drw->drawMouse();

		  game.Logic();
	glutSwapBuffers();
   glDisable (GL_BLEND);
}
void Timer(int ms){
		  game.ms +=15;
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
	//glutKeyboardUpFunc(keyUp);

	//ADD mouse listeners:
	glutMouseFunc(specialMouseHandler);
	
	glutPassiveMotionFunc(mouseHandler);
	glutMotionFunc(mouseHandler);
	glutMainLoop();		//The main loop of OpenGL
	
	return 0;
}
