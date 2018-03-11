#include <GL/glut.h>
#include "camera.h"
#include <math.h>
Camera::Camera(){
	width = 800;
	height = 800;
	alpha = 0.0;
	raio = 15.0;
	beta = 5.0;
	max_beta = 15.0;
	min_beta = 5.0;
}

void Camera::view(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(width/8, height/8, width / 1.5, height / 1.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-3.0, 3.0, -3.0, 3.0, 3.0, 70.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt( raio*sin(alpha) ,beta, raio*cos(alpha), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

}
void Camera::setAlpha(double delta){
	alpha+=delta;
}
void Camera::setBeta(double delta){
	if (beta + delta < max_beta && beta + delta > min_beta){
		beta += delta;
	}
}
