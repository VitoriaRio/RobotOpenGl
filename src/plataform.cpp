#include "plataform.h"
#include <GL/glut.h>


Plataform::Plataform(){}


void Plataform::draw(){
	//Plataforma
	glPushMatrix();
		drawplataform();
	glPopMatrix();

}
void Plataform::drawplataform(){
	glColor3f(0, 1, 1);
    glScalef(30,3.0,30);
    glTranslatef(0, 0, 0);
    glutSolidCube(1);
}

