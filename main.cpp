#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "camera.h"
#include "robot.h"
using namespace std;
GLint Width = 800;
GLint Height = 800;
int pos_mouse_x = 0;
int pos_mouse_y = 0;
Robot robot;
Camera camera; 

// prototipos
void moving_mouse(int x, int y);
void mouse(int button, int state, int x, int y);
void initLighting(void);
void reshape(int width, int height);
void display(void);
void keyboard(unsigned char key, int x, int y);


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Robot");
	initLighting();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(moving_mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

void reshape(int width, int height){
	Width = width;
	Height = height;
	//glViewport(0, 0, width, height);
	glutPostRedisplay();
}

void initLighting(void){
	GLfloat lightposition[] = { 3.0, -3.0, 3.0, 0.0 };
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.5, 0.0, 0.0, 0.0);
}

// keyboard callback
void keyboard(unsigned char key, int x, int y){
	cout << key;
	switch (key) {
	case 27:
		exit(0); break;
	case 'a':
		robot.setPositionX(-0.1); break;
	case 's':
		robot.setPositionY(-0.1);  break;
	case 'd':
		robot.setPositionX(0.1); break;
	case 'w':
		robot.setPositionY(0.1);  break;
	default:
		return; 
	}
	glutPostRedisplay();
}
void moving_mouse(int x, int y){

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
	
void mouse(int button, int state, int x, int y){

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
void display(void){
  	camera.view();
	robot.draw();
	glutSwapBuffers();
}
