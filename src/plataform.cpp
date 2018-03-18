#include "plataform.h"
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
using namespace std;


Plataform::Plataform(){}


void Plataform::draw(GLuint texture){
	//Plataforma
	glPushMatrix();
		drawplataform(texture);
	glPopMatrix();
	glPushMatrix();
		drawring();	
	glPopMatrix();
}

void Plataform::drawplataform(GLuint texture){
	glPushMatrix();
		glColor3f(1, 1, 1);
	    glScalef(30,3.0,30);
	    glTranslatef(0, 0, 0);
	    glutSolidCube(1);
    glPopMatrix();
       glTranslatef(0, 1.55, 0);

    glRotatef(-180.0, 1.0, 0.0, 0.0);
    	glEnable(GL_TEXTURE_2D);
    	glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		GLUquadric *quad = gluNewQuadric();
		gluQuadricTexture(quad, 1);
    	
    	glBegin(GL_QUADS);

   			glTexCoord2f(1.0f, 1.0f); glVertex3f(15.0f, 0.0f, 15.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(-15.0f, 0.0f, 15.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-15.0f, 0.0f, -15.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(15.0f, 0.0f, -15.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
}

void Plataform::drawring(){
	glColor3f(1, 0, 0);
	glPushMatrix();
		glTranslatef(15, 0, 15);
		glTranslatef(0.0, 0.0, 0.1);
		glPushMatrix();
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 5.0, 30.0, 30.0);
			glTranslatef(0.0, 0.0, 5.0);
			glutSolidSphere(0.2, 30.0,30.0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 4, 0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 2, 0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(15, 0, -15);
		glTranslatef(0.0, 0.0, 0.1);
		glPushMatrix();
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 5.0, 30.0, 30.0);
			glTranslatef(0.0, 0.0, 5.0);
			glutSolidSphere(0.2, 30.0,30.0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 4, 0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 2, 0);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-15, 0, -15);
		glTranslatef(0.0, 0.0, 0.1);
		glPushMatrix();
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 5.0, 30.0, 30.0);
			glTranslatef(0.0, 0.0, 5.0);
			glutSolidSphere(0.2, 30.0,30.0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0, 4, 0);
			glRotatef(0.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 2, 0);
			glRotatef(0.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-15, 0, 15);
		glTranslatef(0.0, 0.0, 0.1);
		glPushMatrix();
			glRotatef(-90.0, 1.0, 0.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 5.0, 30.0, 30.0);
			glTranslatef(0.0, 0.0, 5.0);
			glutSolidSphere(0.2, 30.0,30.0);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(15, 0, 15);
		glTranslatef(0.0, 0.0, 0.1);

		glPushMatrix();
			glTranslatef(0, 4, 0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0, 2, 0);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			gluCylinder(gluNewQuadric(), 0.1, 0.1, 30.0, 30.0, 30.0);
		glPopMatrix();
	glPopMatrix();
}

