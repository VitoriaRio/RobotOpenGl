#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "plataform.h"
#include "camera.h"
#include "robot.h"
#include "runner.h"
#include "RgbImage.h"
using namespace std;

Runner::Runner(){
	Robot robot;
	Camera camera; 
	Plataform plataform;
	gokuhead = 0;
}


void Runner::run(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Robot");
	initLighting();
	initRendering();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(moving_mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}

void Runner::reshape(int width, int height){
	Width = width;
	Height = height;
	glutPostRedisplay();
}

void Runner::initLighting(void){
	GLfloat luzAmbiente[4] = { 0.2,0.2,0.2,1.0 };
	GLfloat luzDifusa[4] = { 0.7,0.7,0.7,1.0 }; // "cor"
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };// "brilho"
	GLfloat posicaoLuz[4] = { 0.0, 0.0, 0.0, 0.5 };

	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 60;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);

	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

}

// keyboard callback
void Runner::keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 27:
		exit(0); break;
	case 'a': 
		robot.setPositionX(-0.1);
		robot.setDirection(-90.0);
		break;
	case 's':
		robot.setPositionY(0.1);  
		robot.setDirection(0.0);
		break;
	case 'd':
		robot.setPositionX(0.1); 
		robot.setDirection(90.0);
		break;
	case 'w':
		robot.setPositionY(-0.1);  
		robot.setDirection(180.0);
		break;
	case '+':
		camera.setZoom(-1);
		break;
	case '-':
		camera.setZoom(1);
		break;
	case 'q': 
		robot.setAlpha(-1.0);
	break;	
	case 'e': 
		robot.setAlpha(1.0);
		break;
	case 'f': 
		robot.changeArm();
		break;
	case '1': 
		robot.setBeta(-2.0);
	break;
	case '2': 
		robot.setBeta(2.0);
	break;
	case '3': 
		robot.spinHands();
	break;
	case '4': 
		robot.pick();
	break;
	default:
		return; 
	}
	glutPostRedisplay();
}
void Runner::moving_mouse(int x, int y){

	if (x != pos_mouse_x || y != pos_mouse_y){

		if (x < pos_mouse_x){
			camera.setAlpha(0.1);	
		}else if (x > pos_mouse_x){
			camera.setAlpha(-0.1);
		}
		if (y < pos_mouse_y){
			camera.setBeta(1.0);
		}else if (y > pos_mouse_y){
			camera.setBeta(-1.0);
		}
		pos_mouse_x = x;
		pos_mouse_y = y;
	}
		
	glutPostRedisplay();
}
	
void Runner::mouse(int button, int state, int x, int y){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		if (x != pos_mouse_x || y != pos_mouse_y){

		
			if (x < pos_mouse_x){
				camera.setAlpha(0.1);	
			}else if (x > pos_mouse_x){
				camera.setAlpha(-0.1);
			}
			if (y < pos_mouse_y){
				camera.setBeta(1.0);
			}else if (y > pos_mouse_y){
				camera.setBeta(-1.0);
			}
			pos_mouse_x = x;
			pos_mouse_y = y;
		}
	}
	glutPostRedisplay();
}

//draw callback
void Runner::display(void){
	double x = robot.getPositionX();
	double y = robot.getPositionY();
	camera.view(x, y);
	plataform.draw(ring);
	robot.draw(gokuhead);

	glutSwapBuffers();
}

void Runner::initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	gokuhead = loadTextureFromFile("../img/goku.bmp");
	ring = loadTextureFromFile("../img/dragonballw.bmp");
}


GLuint Runner::loadTextureFromFile(char *filename) {
	GLuint textureId;
	RgbImage theTexMap(filename); //Image with texture
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Texture to be edited
											 //Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D, //Always GL_TEXTURE_2D
		0, //0 for now
		GL_RGB, //Format OpenGL uses for image
		theTexMap.GetNumCols(), //Width
		theTexMap.GetNumRows(), //Height
		0, //The border of the image
		GL_RGB, //GL_RGB: pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE:pixels are stored as
						  //unsigned numbers
		theTexMap.ImageData()); //The actual pixel data
	return textureId; //Returns the id of the texture
}