//
//  Viewport.cpp
//  TinyCS
//
#include "Viewport.hpp"

int Viewport::width = 0;
int Viewport::height = 0;

bool Viewport::grabbed = false;

void Viewport::init(){
	//����GLUT�ص�����
	glutReshapeFunc(Viewport::reshape);
	glutDisplayFunc(Viewport::display);
	glutIdleFunc(Viewport::display);
	//������Ȳ��ԣ����������Զ���Զ����ر���ס��ͼ��
	glEnable(GL_DEPTH_TEST);
	//���ö�ά����
	glEnable(GL_TEXTURE_20);

	//��������Ƿ�ֱ�ӱ� OpenGL ȫ�ֲ�����ʾ
	grabbed ? Viewport::setGrabbed(true) : Viewport::setGrabbed(false);
}

void Viewport::setGrabbed(bool value) {
	grabbed = value ? true : false;

	if (grabbed) {
		// ���õ�ǰ���ڵĹ����ʽ, ����Ϊ���ù��
		glutSetCursor(GLUT_CURSOR_NONE);
	} else {
		// �̳�ϵͳ���
		glutSetCursor(GLUT_CURSOR_INHERIT);
	}
}

void Viewport::reshape(int w, int h) {
	width = w;
	height = h;
	if (h <= 0) h = 1;
	// ���㳤���
	float ratio = (float)w / h;

	// ����ͼ���е���ʱ��Ҫ�л�����ģʽ
	glMatrixMode(GL_PROJECTION);
	// �� PROJECTION �������Ϊ��λ��
	glLoadIdentity();
	glViewport(0, 0, w, h);
	// �ʵ�����͸�ӽ�
	gluPerspective(45, ratio, 0.01, 1000);
	// �л�GL_MODELVIEW
	glMatrixMode(GL_MODELVIEW);
}
void Viewport::display() {

	// ��յ�ǰ Viewport �еĻ���
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// ����Ϊ��λ����
	glLoadIdentity();

	// ����һ��������
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-1, 0, -3);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 2, -3);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1, 0, -3);
	glEnd();

	// �󶨲���
	glBindTexture(GL_TEXTURE_2D, 0);

	// ����������ͼ�񽻻����Կ�������Ⱦ,
	// ������ main.cpp ��ע������ʾGLUT_DOUBLE˫�������ʾģʽ
	glutSwapBuffers();
}


