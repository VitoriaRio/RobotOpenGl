#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "camera.h"
#include "robot.h"
#include "runner.h"
using namespace std;

int Runner::Width = 800;
int Runner::Height = 800;
int Runner::pos_mouse_x;
int Runner::pos_mouse_y;
Robot Runner::robot;
Camera Runner::camera;
// prototipos
void moving_mouse(int x, int y);
void mouse(int button, int state, int x, int y);
void initLighting(void);
void reshape(int width, int height);
void display(void);
void keyboard(unsigned char key, int x, int y);


int main(int argc, char** argv){
	Runner::run(argc, argv);
}

