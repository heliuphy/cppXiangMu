//
//main.cpp
//TinyCS
//

#include<iostream>
#include "common.hpp"
#include "Viewport.hpp"

using namespace std;

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
const char *WINDOW_TITLE = "Shiyanlou Tiny CS";

int main( int argc,char *argv[] ){
	//初始化GLUT OpenGL
	glutInit(&argc, argv);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	//创建OPENGL

	glutCreateWindow(WINDOW_TITLE);

	//初始化视窗

	Viewport::init();

	//Enter Main Loop
	glutMainLoop();

	return 0;
}

