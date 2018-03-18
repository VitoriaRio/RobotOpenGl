#include "robot.h"
#include <GL/glut.h>
#include "RgbImage.h"
#include <iostream>
using namespace std;

Robot::Robot(){
	alphaR = 15;
	betaR = 60.0;
	alphaL = 15;
	betaL = 60.0;
	pos_x = 0;
	pos_y = 0;
	current_direction = 0.0;
	minAlpha = -30;
	maxAlpha = 15;
	arm = 1;
	theta = 0;
	delta = 60;
	minBeta = 0;
	maxBeta = 360;
}


void Robot::draw(){
	cout<<" -> "<<minAlpha<<" "<<maxAlpha<<" "<<arm<<" "<<endl;
	glTranslatef(pos_x,4.0, pos_y);

	glRotatef(current_direction, 0.0, 1.0, 0.0);
	//cout << current_direction;
	glPushMatrix();
		glPushMatrix();
			glPushMatrix();
				drawbody();
			glPopMatrix();
			//desenha braco
			drawarm(1, alphaL, betaL);
		glPopMatrix();
		drawarm(-1,alphaR, betaR);
	glPopMatrix();
	//desenha cabeca
	drawhead();

}
void Robot::drawplataform(){
	glColor3f(0, 1, 1);
        glScalef(25,3.0,25);
        glTranslatef(0, 0, 0);
        glutSolidCube(1);
}

void Robot::drawbody(){
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(1.0);

	//desenha esfera
	glTranslatef(0.0,-1.5, 0.0);
	glutSolidSphere(1.0,50.0, 50.0);
}
void Robot::drawhead(){
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0,0.0,1.1);
	glutSolidSphere(0.6, 30.0,30.0);
}
void Robot::drawarm(int arm, double alpha, double beta){
	glRotatef(arm*90.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, 0.5);
	glutSolidSphere(0.2, 30.0,30.0);
	glTranslatef(0.0, 0.0, 0.1);
	glRotatef(alpha, 1.0, 0.0, 0.0);
	gluCylinder(gluNewQuadric(), 0.1, 0.1, 1.0, 30.0, 30.0);
	glTranslatef(0.0, 0.0, 0.9);
	glutSolidSphere(0.2, 30.0,30.0);
	glRotatef(-60.0*arm, 0.0, 1.0, 0.0);
	glRotatef(beta, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.1);
	gluCylinder(gluNewQuadric(), 0.1, 0.1, 0.7, 30.0, 30.0);
	glTranslatef(0.0, 0.0, 0.6);
	glRotatef(arm*theta, 0.0, 0.0, 1.0);
	glutSolidSphere(0.2, 30.0,30.0);
	glPushMatrix();
		glRotatef(delta, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, 0.1);
		gluCylinder(gluNewQuadric(), 0.05, 0.05, 0.3, 30.0, 30.0);
		glTranslatef(0.0, 0.0, 0.3);
		glutSolidSphere(0.1, 30.0,30.0);
		glRotatef(-90.0, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, 0.1);
		glutWireCone(0.05, 0.3,50, 50);
	glPopMatrix();

	glPushMatrix();
		glRotatef(-delta, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, 0.1);
		gluCylinder(gluNewQuadric(), 0.05, 0.05, 0.3, 30.0, 30.0);
		glTranslatef(0.0, 0.0, 0.3);
		glutSolidSphere(0.1, 30.0,30.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, 0.05);
		glutWireCone(0.05, 0.3,50, 50);
	glPopMatrix();

}
void Robot::setPositionX(double x){
	if (pos_x + x <13 && pos_x + x > -13){
		pos_x += x;
	}
}
void Robot::setPositionY(double y){
	if (pos_y + y <13 && pos_y + y > -13){
		pos_y += y;
	}
}

void Robot::setDirection(int direction){
	current_direction = direction;
}

void Robot::changeArm(){
	if (arm == 1){
		arm = 2;
	}else{
		arm = 1;
	}
}
void Robot::setAlpha(double angle){
	if (arm == 1){
		if (alphaR + angle <= maxAlpha && alphaR + angle >=minAlpha){
			alphaR = alphaR+angle ;
		}
	}else{
		if (alphaL + angle <= maxAlpha && alphaL + angle >=minAlpha){
			alphaL = alphaL+angle ;
		}
	}
	
}

void Robot::setBeta(double angle){
	if (arm == 1){
		if (betaR+angle > maxBeta){
			betaR = minBeta+angle;
		}else if (betaR-angle < minBeta){
			betaR = maxBeta + angle;
		}else{
			betaR = betaR+angle ;
		}
		// if (betaR + angle <= maxBeta && betaR + angle >=minBeta){
		// 	betaR = betaR+angle ;
		// }
	}else{
		if (betaL+angle > maxBeta){
			betaL = minBeta+angle;
		}else if (betaL-angle < minBeta){
			betaL = maxBeta + angle;
		}else{
			betaL = betaL+angle ;
		}
		// if (betaL + angle <= maxBeta && betaL + angle >=minBeta){
		// 	betaL = betaL+angle ;
		// }
	}
}

void Robot::spinHands(){
	if (theta == 360){
		theta = 20;
	}else{
		theta += 20;
	}
}

void Robot::pick(){
	if (delta == 60){
		delta = 45;
	}else{
		delta = 60;
	}
}
double Robot::getPositionX(){
	return pos_x;
}

double Robot::getPositionY(){
	return pos_y;
}