#include <GL/glut.h>
#include<Windows.h>
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<stdlib.h>

using namespace std;
#pragma region Preset
float vfColorlist[][3] = {
		{1,0,0},
		{0,1,0},
		{0,0,1},
		{1,1,0} };
#pragma endregion
#pragma region Mod
int mod = 0;

float defualtMaxtir[] = { 0,0,0     ,1,0,0,    0,1,0 };
float pos[] = { 0,0,0 };
float vf3Vectory[] = { 0,0,0 };
float rangle[] = { 1,0,0 };
float head[] = { 0,1,0 };
float vf2begin[] = { 0,0 };
float vf2end[] = { 0,0 };
float Vectory2D[] = { 0,1,0,0 };
float* temp = pos;
float step = 0.1f;
float glsize = 0.15;
float headstep = step;
int W_Window = 600;
int H_Window = 600;
char WindowTitle[] = "212303041黄可羽";
int WindowDisPlayMode = GLUT_SINGLE | GLUT_RGB;
void (*IdleFunc)();
void (*DisplayFunc)();
void (*KeyboardFunc)(unsigned char key, int x, int y);
void (*SpecilKeyboardFunc)(int key, int x, int y);
void (*InitFuncPoint)();
void (*ReshapeFunc)(int w, int h);
void (*MouseFunc)(int Btn, int state, int x, int y);
void (*MouseMotionFunc)(int, int);
void(*MousePassiveMotionFunc)(int, int);
void(*Preset)();
void (*Meanul)(int);
void (*SubMeanul1)(int);
#pragma endregion
#pragma region T2
void T2Firstone() {
	glPolygonMode(GL_BACK,GLU_FILL);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0.8, 0);
	glVertex3f(-0.8, 0, 0.8);
	glVertex3f(0.8, 0, 0.8);
	glEnd();
	glFlush();
	
}
void T2Firstsecond() {

	glClearColor(0, 0, 0, 0);
	glFlush();
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -2, 2);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 1, 0, 0, 0, 0, 0, 0, -1);
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 0.8, 0);
	glVertex3f(-0.8, 0, 0.8);
	glColor3f(1, 0, 0);
	glVertex3f(0.8, 0, 0.8);
	glColor3f(0, 0, 1);
	glVertex3f(0.8, 0, -0.8);
	glColor3f(0, 1, 0);
	glVertex3f(-0.8, 0, -0.8);
	glColor3f(1, 1, 0);
	glVertex3f(-0.8, 0, 0.8);
	glEnd();
	glFlush();
}
void T2SecondFirst() {

	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_BACK, GL_LINE);
	glLineWidth(5);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(6, 0XAAAA);
	glBegin(GL_POLYGON);
	glColor3f(0, 1, 0);
	glVertex3f(-0.5, 0.5, 0.5);//a
	glColor3f(1, 0, 0);
	glVertex3f(-0.5, -0.5, 0.5);//b
	glColor3f(0, 1, 1);
	glVertex3f(0.5, -0.5, 0.5);//c
	glColor3f(1, 0,1 );
	glVertex3f(0.5, 0.5, 0.5);//d
	glEnd();
	glFlush();
}
void T2SecondSecond() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-8, 8, -8, 8, -8, 8);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);
	//背面剔除
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glPolygonMode(GL_BACK, GL_LINE);
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 1, 1);//A
	glVertex3f(-1, -1, 1);//B
	glVertex3f(1, -1, 1);//C
	glVertex3f(1, 1, 1);//D
	glEnd();
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 1, 1);//A
	glVertex3f(-1, 1, -1);//G
	glVertex3f(-1, -1, -1);//H
	glVertex3f(-1, -1, 1);//B
	glEnd();
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 1, -1);//G
	glVertex3f(1, 1, -1);//E
	glVertex3f(1, -1, -1);//F
	glVertex3f(-1, -1, -1);//H
	glEnd();
	glColor3f(1, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(1, 1, -1);//E
	glVertex3f(1, 1, 1);//D
	glVertex3f(1, -1, 1);//C
	glVertex3f(1, -1, -1);//F
	glEnd();
	glColor3f(1, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 1, 1);//A
	glVertex3f(1, 1, 1);//D
	glVertex3f(1, 1, -1);//E
	glVertex3f(-1, 1, -1);//G
	glEnd();
	glColor3f(1, 0.5, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-1, -1, 1);//B
	glVertex3f(-1, -1, -1);//H
	glVertex3f(1, -1, -1);//F
	glVertex3f(1, -1, 1);//C
	glEnd();
	glFlush();
}
void T2Thirdone(){

		int n = 20;
		GLfloat R = 0.6f;
		GLfloat Pi = 3.1415926536f;
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POLYGON);
		for (int i = 0; i < n; i++)
		{
			glVertex2f(R * cos(i * (2 * Pi) / n), R * sin(i * (2 * Pi) / n));
		}
		glEnd();
		glFlush();
	
}
void T2Fourone() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-8, 8, -8, 8, -8, 8);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);
	//背面剔除
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glPolygonMode(GL_BACK, GL_LINE);
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 1, 1);//A
	glVertex3f(-1, -1, 1);//B
	glVertex3f(1, -1, 1);//C
	glVertex3f(1, 1, 1);//D
	glEnd();
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 1, 1);//A
	glVertex3f(-1, 1, -1);//G
	glVertex3f(-1, -1, -1);//H
	glVertex3f(-1, -1, 1);//B
	glEnd();
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 1, -1);//G
	glVertex3f(1, 1, -1);//E
	glVertex3f(1, -1, -1);//F
	glVertex3f(-1, -1, -1);//H
	glEnd();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(1, 1, -1);//E
	glVertex3f(1, 1, 1);//D
	glVertex3f(1, -1, 1);//C
	glVertex3f(1, -1, -1);//F
	glEnd();
	glColor3f(0.7, 0.7, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 1, 1);//A
	glVertex3f(1, 1, 1);//D
	glVertex3f(1, 2.5, 0);//K
	glVertex3f(-1, 2.5, 0);//J
	glEnd();
	glColor3f(0.7, 0.7, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 1, -1);//G
	glVertex3f(1, 1, -1);//E
	glVertex3f(1, 2.5, 0);//k
	glVertex3f(-1, 2.5, 0);//J
	glEnd();
	glColor3f(0.7, 0.5, 0);
	glBegin(GL_POLYGON);
	glVertex3f(1, 1, 1);//D
	glVertex3f(1, 1, -1);//E
	glVertex3f(1, 2.5, 0);//k
	glEnd();
	glColor3f(1, 0, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-1, -1, 1);//B
	glVertex3f(-1, -1, -1);//H
	glVertex3f(1, -1, -1);//F
	glVertex3f(1, -1, 1);//C
	glEnd();
	int n = 20;
	GLfloat R = 0.6f;
	GLfloat Pi = 3.1415926536f;
	glColor3f(1, 1,0 );
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++)
	{
		glVertex3f(R * cos(i * (2 * Pi) / n), R * sin(i * (2 * Pi) / n),1);
	}
	glEnd();
	//大门口
	glColor3f(0, 0.5, 1);
	glBegin(GL_POLYGON);
	glVertex3f(1, -0.1, -0.2);//a
	glVertex3f(1, -0.1, 0.2);//d
	glVertex3f(1, -1, 0.2);//c
	glVertex3f(1, -1, -0.2);//b
	glEnd();

	glFlush();

}
#pragma endregion
#pragma region T3
void T3Firstone() {
	glClearColor(0, 0, 0,1);
	//绘制点
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//视域体大小
	int size = 2;
	glOrtho(1*size,-1*size,-1*size,1*size,1,-1*size);
	glColor3f(1, 0, 0);
	glPointSize(13.0f);
	glBegin(GL_POINTS);
glVertex3f(0, 0, 2);
	glEnd();
	glFlush();

}
void T3Secondvone() {
	glClearColor(0, 0, 0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//进行视点变换
	gluLookAt(0,0,2,0,0,2,0,1,0);
	//进行模型变换
	//进行投影变换正交模式
	glOrtho(-1, 1, -1, 1, 1, -1);
	//进行视口变换
	glColor3f(1, 0, 0);
	glPointSize(12.0f);
	glBegin(GL_POINTS);
	glVertex3f(0,0,2);
	glEnd(); glFlush();
}
void T3Secondone() {
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
	//gluLookAt(0, 0, 0, 0, 0, 1, 0, 1, 0);// 正面
	//gluLookAt(0, 0, 0, 1, 0, 0, 0, 1, 0);//侧面
	gluLookAt(0, 0, 0, -0.5, 0.5, -0.5, 0, 1, 0);//斜切
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0);//p0
	glVertex3f(0.5, -0.5, 0);//p1
	glVertex3f(0.5, 0.5, 0);//P2
	glVertex3f(-0.5, 0.5, 0);//P3
	glEnd();
	glFlush();

}
void T3Secondtwo() {
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
	//进行视点变化
	//gluLookAt(0, 0, 0, 0, 0, -1, 1, 0, 0);//第一个图
    //gluLookAt(0, 0, 0, 0, 0.2, -1, 0, -1, 0);	//第二个图
// gluLookAt(0, 0, 0, 1, 0, -1, 0, 1, 0);	//第三个图 
 gluLookAt(0, 0, 0, -1, 1, -1, 0, 1, 0);	//第四个图 
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glutWireTeapot(0.4);
	glFlush();

}
void T3Secondthree() {
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -2, 2);
	//进行视点变化
   gluLookAt(0.5, 0.5, 0.5, 0, 0, 0, 0, 1, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glutWireCube(0.5);
	glFlush();
}
void T3Thirdone() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-0.25, 0.25, -0.25, 0.25, 0.1, 400);//	第一幅图片对应的是
	//glFrustum(-0.25, 0.25, -0.25, 0.25, 0.25, 400);//		第二幅图片对应的是
	//glFrustum(-0.25, 0.25, -0.25, 0.25, 0.5, 400);//		第三幅图片对应的是
	glFrustum(-0.25, 0.25, -0.25, 0.25, 0.8, 400);//		第四幅图片对应的是
	glTranslatef(0, 0, -1.0f);
	glutSolidSphere(0.25f, 20, 20);
	glTranslatef(1.0f, 0, -1.0f);
	glutSolidSphere(0.25f, 20, 20);
	glFlush();
}
void T3Thirdtwo() {
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//gluPerspective(135, 1, 0.1, 400);//第一幅图片对应的是
	//gluPerspective(68, 1, 0.1, 400);//第二幅图片对应的是
		gluPerspective(55, 1, 1, 400);//第三幅图片对应的是

		glTranslatef(0, 0, -1.0f);
		glutSolidSphere(0.25f, 20, 20);
		glTranslatef(1.0f, 0, -1.0f);
		glutSolidSphere(0.25f, 20, 20);
		glFlush();

}
#pragma endregion
#pragma region T4
void T4Firstone() {
	glClearColor(0, 0, 0, 1);
	//视点变换
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
	//模型变换
	//绘制一个菱形
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, 0);
	glColor3f(1, 1, 1);
	float rangle = 180 / 3;
	glRotatef(rangle, 0, 0, 1);
	for (int i = 0; i < 3; i++) {
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(0.1, 0.45, 0);
		glVertex3f(0, 0.9, 0);
		glVertex3f(-0.1, 0.45, 0);
		glEnd();
		glRotatef(-rangle, 0, 0, 1);
	}
	//投影变换
	glOrtho(1, -1, -1, 1, 1, 1);
	//视口变换
	glFlush();
}
void T4Firsttwo() {
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluLookAt(0, 0, 1, 0, 0.5, 0, 0, 1, 0);
	glOrtho(-0.5, 0.5, -0.5, 0.5, -0.5, 0.5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScaled(1, 0.4, 1);
	glTranslatef(0,0,0);
	glColor3f(1,0,0);
	glutSolidCube(0.3);
	glTranslatef(0, 0.35, 0);
	glColor3f(1, 1, 0);
	glutSolidCube(0.4);
	glTranslatef(0, 0.3, 0);
	glColor3f(1, 0, 1);
	glutSolidCube(0.5);
	glTranslatef(0, 0.3, 0);
	glScaled(1, 0.8, 1);
	glColor3f(0, 1, 0);
	glutSolidCube(0.6);
	glFlush();
}
void T4Firstthree() {
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//视点变换
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
	//投影变换
	int sizeofview = 8;
	glOrtho(-1 * sizeofview,1*sizeofview,-1*sizeofview,1*sizeofview,1*sizeofview,-1*sizeofview);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1, 1, 1);
	glTranslatef(9, -6.5, 0);
	for (int line = 0; line < 4; line++) 
	{
		glTranslatef(-18, 3, 0);
		for (int i = 0; i < 6; i++) {
			glTranslatef(3, 0, 0);
			glutSolidSphere(0.7, 50, 50);
		}	}
	glFlush();
}
void T4Firstfour() {
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//绘制花
	//绘制一个菱形
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, 0);
	glColor3f(1, 1, 1);
	float rangle = 180 / 3;
	glRotatef(rangle, 0, 0, 1);
	for (int i = 0; i < 3; i++) {
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(0.1, 0.45, 0);
		glVertex3f(0, 0.9, 0);
		glVertex3f(-0.1, 0.45, 0);
		glEnd();
		glRotatef(-rangle, 0, 0, 1);	}
	//绘制花盆模型
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, -0.4, 0);
	glScaled(1, 0.4, 1);
	glTranslatef(0, 0, 0);
	glColor3f(1, 0, 0);
	glutSolidCube(0.3);
	glTranslatef(0, 0.35, 0);
	glColor3f(1, 1, 0);
	glutSolidCube(0.4);
	glTranslatef(0, 0.3, 0);
	glColor3f(1, 0, 1);
	glutSolidCube(0.5);
	glTranslatef(0, 0.3, 0);
	glScaled(1, 0.8, 1);
	glColor3f(0, 1, 0);
	glutSolidCube(0.6);
	glFlush();
}
#pragma endregion
#pragma region T5
void T5Fristone() {
	float material[4][4][3] = {
			{{0.2125,0.1275,0.054},{0.714,0.4284,0.18144},{0.393548,0.271906,0.166721},{0.2,0.2,0.2}},
			{ {0.135,0.225,0.1575},   {0.54,0.89,0.63},{0.316228,0.316228,0.316228},{0.1,0.1,0.1}},
			{{0.0,0.1,0.06},		{0.0,0.50980392,0.50196078},{0.50196078,0.50196078,0.50196078},{0.25,0.25,0.25}},
			{ {0.8, 0.8, 0.8},{0.2, 0.2, 0.2},{0.0, 0.0, 0.0},{0,0,0}}
	};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glTranslatef(9, -6.5, 0);
	for (int line = 0; line < 4; line++)
	{
		if (line >= 0) {
			glMaterialfv(GL_FRONT, GL_AMBIENT, material[line][0]);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, material[line][1]);
			glMaterialfv(GL_FRONT, GL_SPECULAR, material[line][2]);
			glMaterialfv(GL_FRONT, GL_SHININESS, material[line][3]);
		}
		glTranslatef(-18, 3, 0);
		for (int i = 0; i < 6; i++) {
			glTranslatef(3, 0, 0);

			glutSolidSphere(0.7, 50, 50);
		}
	}
	glFlush();
}
void T5Secondone() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	//光源设置
	float materix[][3] = { {0,0,1},{1,1,0},{1,0,1} };
	float spos[] = { 1.75,1.5,-2.5,0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, materix[0]);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, materix[1]);
	glLightfv(GL_LIGHT0, GL_SPECULAR, materix[2]);
	glLightfv(GL_LIGHT0, GL_POSITION, spos);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutSolidSphere(0.5, 20, 20);
	glFlush();
}
void T5SecondThrid() {
	//材质属性
	GLfloat A2[] = { 0.2,0.5,0.2,1 };
	GLfloat D2[] = { 0.2,1,0.2,1 };
	GLfloat S2[] = { 0,0,0,1 };
	//光源属性
	GLfloat light_ambient[] = { 0.0,0.0,1.0,1.0 };
	GLfloat light_diffuse[] = { 0.8,0.8,0.8,1.0 };
	GLfloat light_specular[] = { 1.0,0.0,1.0,1 };
	GLfloat light_pos[] = { -2,0,0,1 };
	GLfloat light_cutoff[] = { 45.0,0 };
	GLfloat light_dir[] = { 1,0,0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
	glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, light_cutoff);
	glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,light_dir);

	glMaterialfv(GL_FRONT, GL_AMBIENT, A2);
	glMaterialfv(GL_FRONT,GL_DIFFUSE, D2);
	glMaterialfv(GL_FRONT,GL_SPECULAR,S2);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,1);

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int offset = 3;
	glOrtho(-1*offset,1*offset,-1*offset,1*offset,-1*offset,1*offset);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutSolidSphere(1, 20, 20);

	glFlush();


}
void T5SecondFour() {
	float material[4][4][3] = {
			{{0.2125,0.1275,0.054},{0.714,0.4284,0.18144},{0.393548,0.271906,0.166721},{0.2,0.2,0.2}},
			{ {0.135,0.225,0.1575},   {0.54,0.89,0.63},{0.316228,0.316228,0.316228},{0.1,0.1,0.1}},
			{{0.0,0.1,0.06},		{0.0,0.50980392,0.50196078},{0.50196078,0.50196078,0.50196078},{0.25,0.25,0.25}},
			{ {0.8, 0.8, 0.8},{0.2, 0.2, 0.2},{0.0, 0.0, 0.0},{0,0,0}}
	};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glColorMaterial(GL_FRONT,GL_DIFFUSE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glTranslatef(9, -6.5, 0);
	for (int line = 0; line < 4; line++)
	{
		if (line >= 0) {
			if (line == 2) {
				glEnable(GL_COLOR_MATERIAL);
				glColor4f(1, 1, 0, 1);
			}
			if (line == 0) {
				glEnable(GL_COLOR_MATERIAL);
				glColor4f(1, 0, 0, 1);
			}
			glMaterialfv(GL_FRONT, GL_AMBIENT, material[line][0]);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, material[line][1]);
			glMaterialfv(GL_FRONT, GL_SPECULAR, material[line][2]);
			glMaterialfv(GL_FRONT, GL_SHININESS, material[line][3]);
			glDisable(GL_COLOR_MATERIAL);
		}
		glTranslatef(-18, 3, 0);
		for (int i = 0; i < 6; i++) {
			glTranslatef(3, 0, 0);
			glutSolidSphere(0.7, 50, 50);
		}
	}
	glFlush();
}
#pragma endregion
#pragma region T6
void T6Firstone() {
	//窗口重绘函数
	ReshapeFunc = [](int w, int h) {
		if (!h)h = 1;
		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		cout << "w:" << w << "  h:" << h << endl;
		float min = w >= h ? h : w;
		glOrtho(-1 * w / min, 1 * w / min, -1 * h / min, 1 * h / min, -1, 1);
		glPopMatrix();
		glViewport(0, 0, w, h);
		//窗口绘制函数
		DisplayFunc();
	};
	DisplayFunc = []() {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 0, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glutSolidSphere(0.8, 20, 20);
		glFlush();

	};
}
void T6Firsttwo() {
	IdleFunc = []() {
		glRotatef(0.05,0,1,0);
		glutSwapBuffers();
		glutPostRedisplay();
	};
	DisplayFunc=[]()  {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 0, 0, 1);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glutSolidTeapot(0.5);
		glFlush();
	};
}
void T6FirstthreeOne() {

	//float pos[]  
	//float glsize
	KeyboardFunc = [](unsigned char k, int x, int y) {
		if (k == '0') { glsize += 0.25; }
		if (k == '9') { glsize -= 0.25; }
		if (k == 'r' || k == 'g' || k == 'b') {
			pos[0] = k == 'r';
			pos[1] = k == 'g';
			pos[2] = k == 'b';		}
		DisplayFunc();
	};
	DisplayFunc = []() {
		float materix[4][4] = { {0.1,0.1,0.1,1},			{pos[0],pos[1],pos[2],1},			{0.1,0.1,0.1,1}		,{0.2,0.2,0.2,1} };
		float lightCompont[4][4] = { {0.1,0.1,0.1,1},{1,1,1,1},{0.1,0.1,0.1,1},{-1,0,-1,0} };
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0,0,0,1);
		glLightfv(GL_LIGHT0, GL_AMBIENT, lightCompont[0]);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightCompont[1]);
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightCompont[2]);
		glLightfv(GL_LIGHT0, GL_POSITION, lightCompont[3]);
		glMaterialfv(GL_FRONT, GL_AMBIENT, materix[0]);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, materix[1]);
		glMaterialfv(GL_FRONT, GL_SPECULAR, materix[2]);
		glMaterialfv(GL_FRONT, GL_SHININESS, materix[3]);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glutSolidCube(glsize);
		glFlush();
	};

}
void T6FirstthreeTwo() {
	//float [4] Vectory
	SpecilKeyboardFunc = [](int k,int x,int y) {
		Vectory2D[0] = k == GLUT_KEY_UP;
		Vectory2D[1] = k == GLUT_KEY_DOWN;
		Vectory2D[2] = k == GLUT_KEY_LEFT;
		Vectory2D[3] = k == GLUT_KEY_RIGHT;
		for (int i = 0; i <= 4; i++) { cout << Vectory2D[i] << endl; 
		Vectory2D[i] *= 0.05;}
		glTranslatef(Vectory2D[3]-Vectory2D[2],Vectory2D[0]-Vectory2D[1],0);
		system("cls");
		DisplayFunc();
	};
	DisplayFunc = []() {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0,0,0,1);
		glMatrixMode(GL_MODELVIEW);
		glutSolidCube(0.1);
		glFlush();
	};



}
void T6Firstfourone() {
	MouseFunc = [](int btn,int state,int x,int y) {
		int laststate = step;
		if (btn == 0) {
			float w = x - W_Window / 2;
			w /= W_Window/2;
			float h = H_Window/2-y;
			h /= H_Window/2;
			if (laststate==1&& state == 0) {
				vf2begin[0] = w;
				vf2begin[1] =h;
			}
			if ((laststate + state) <= 1) {
				vf2end[0] = w;
				vf2end[1] = h;
			}
		}
		step = state;
		glutSwapBuffers();
		DisplayFunc();
	};
	DisplayFunc =[ ]() {
	glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0,0,0,1);
		glLoadIdentity();
		glColor3f(1, 1, 1);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glBegin(GL_LINES);
			glVertex2f(vf2begin[0], vf2begin[1]);
			glVertex2f(vf2end[0],vf2end[1]);
		glEnd();
		glFlush();
	};
}
void T6Firstfoutwo() {
	MouseMotionFunc = [](int x, int y) {   
		float w = x - W_Window / 2;
		w /= W_Window / 2;
		float h = H_Window / 2 - y;
		h /= H_Window / 2;
		Vectory2D[0] = w;
		Vectory2D[1] = h;
		DisplayFunc();

	};
	MousePassiveMotionFunc = [](int x,int y) {
		//空的
	};
	DisplayFunc = []() {   
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0,0,0,1);
		glColor3f(1, 0, 0);
		glPointSize(30);
		glBegin(GL_POINTS);
		glVertex3f(Vectory2D[0],Vectory2D[1],0);
		glEnd();
		glFlush();
	};


}
void T6Firstfiveone() {
	glsize = 3;pos[0] = 1;
	pos[1] = 0; pos[2] = 0;
	SubMeanul1 = [](int v) {
		//设置宽度
		glsize = v * 3;	};
	Meanul = [](int v) {
		pos[0] = v == 2;//设置红色
		pos[1] = v == 3;//设置绿色
		pos[2] = v == 4;//设置蓝色
	};
//创建菜单
	int mainMeanul = glutCreateMenu(SubMeanul1);
	glutAddMenuEntry("3px", 1);
	glutAddMenuEntry("6px", 2);
	glutAddMenuEntry("9px", 3);
	 glutCreateMenu(Meanul);
	 glutAddSubMenu("宽度", mainMeanul);
	glutAddMenuEntry("红", 2);
	glutAddMenuEntry("绿", 3);
	glutAddMenuEntry("蓝",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	MouseFunc = [](int btn, int state, int x, int y) {
		int laststate = step;
		if (btn == 0) {
			float w = x - W_Window / 2;
			w /= W_Window / 2;
			float h = H_Window / 2 - y;
			h /= H_Window / 2;
			if (laststate == 1 && state == 0) {
				vf2begin[0] = w;
				vf2begin[1] = h;
			}
			if ((laststate + state) <= 1) {
				vf2end[0] = w;
				vf2end[1] = h;
			}
		}
		step = state;
		glutSwapBuffers();
		DisplayFunc();
	};
	DisplayFunc = []() {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0, 0, 0, 1);
		glLoadIdentity();
		glColor3f(pos[0], pos[1], pos[2]);
		glLineWidth(glsize);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glBegin(GL_LINES);
		glVertex2f(vf2begin[0], vf2begin[1]);
		glVertex2f(vf2end[0], vf2end[1]);
		glEnd();
		glFlush();
	};


}
#pragma endregion
#pragma region T7
void T7Firstone() {
	DisplayFunc=[]() {
		glClearColor(0,0,0,1);
		float lent = 0.6;
		float Colorlist[][3] = {
			{1,0,0},
			{0,1,0},
			{0,0,1},
			{1,1,0}		};
		float VertexPointlist[][3] = {
			{lent,lent,0},/*A*/
			{-lent,lent,0},/*B*/
			{-lent,-lent,0},/*C*/
			{lent,-lent,0},/*D*/
			{0,0,lent}/*Center*/,
		};
		int list_ID=	glGenLists(4);
		int Point1 = 0, Point2 = 1;
		for (int i = 0; i < 4;i++) {
			glNewList(list_ID+i, GL_COMPILE);
			glColor3fv(Colorlist[i]);
			glBegin(GL_TRIANGLES);
			glVertex3fv(VertexPointlist[4]);
			glVertex3fv(VertexPointlist[Point1]);
			glVertex3fv(VertexPointlist[Point2]);
			glEnd();
			glEndList();
			Point1 = (Point1 + 1) % 4;
			Point2 = (Point2 + 1) % 4;
			glCallList(list_ID+i);
		}
		glFlush();
	};


}
void T7Firsttwo() {
   glClearColor(0, 0, 0, 1);
   float vfColorlist[][3] = {
   {1,0,0},		{0,1,0},
   {0,0,1},		{1,1,0} };
   pos[0] = glGenLists(1);
   glNewList(1, GL_COMPILE);
   glPushMatrix();
   glMatrixMode(GL_MODELVIEW);
   glPolygonMode(GL_BACK, GL_LINE);
   for (int i = 0; i < 4; i++) {
	   glColor3fv(vfColorlist[i]);
	   glBegin(GL_TRIANGLES);
	   glVertex3f(0, 0, 0.5);
	   glVertex3f(0.5, 0.5, 0);
	   glVertex3f(-0.5, 0.5, 0);
	   glEnd();
	   glRotatef(90, 0, 0, 1);   }
   glPopMatrix();
   glEndList();
	IdleFunc = []() {
		float angle = step;
		angle += 0.01;
		if (angle > 360) { angle = 0; }
		step = angle;
		glutPostRedisplay();	};
	DisplayFunc = []() {
		float angle = step;
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef(angle, 0, 1, 1);
		glCallList(pos[0]);
		glutSwapBuffers();	};

}
void T7Secondone() { 
	WindowDisPlayMode = GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH;
	DisplayFunc = []() {
		float LightPos []= {0,0,-0.8,0};
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(0, -1, 0);
		glBegin(GL_POLYGON);
		glVertex3f(1, 1, 0.5);
		glVertex3f(1, -1, 0.5);
		glVertex3f(-1, -1, 0.5);
		glVertex3f(-1, 1, 0.5);
		glEnd();
		glLoadIdentity();
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
		glEnable(GL_COLOR_MATERIAL);
     	glColorMaterial(GL_FRONT,GL_DIFFUSE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(1, 0, 0, 0.4);
		glMatrixMode(GL_MODELVIEW);
		glTranslatef(0,0.4,0);
		glutSolidTorus(0.1, 0.3, 80, 80);
		glDisable(GL_COLOR_MATERIAL);
		glEnable(GL_BLEND);
		glTranslatef(0, -0.8, 0);
		glutSolidTorus(0.1, 0.3, 80, 80);
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_BLEND);
		glFlush();
	};

}
void T7Thirdone() {

	float m_a[] = { 0.1745,0.012,0.012, 1 };
	float m_s[] = { 0.727811, 0.627, 0.627,1 };
	float m_d[] = { 0.61424, 0.04136, 0.04136, 1 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m_d);
	glMaterialfv(GL_FRONT, GL_AMBIENT, m_a);
	glMaterialfv(GL_FRONT, GL_SPECULAR, m_s);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.6*128);
	float fogColor[] = { 0.6,0.6,0.6,0.6 };
	glClearColor(0.6, 0.6, 0.6, 0.6);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_DENSITY, 0.9);
	glFogf(GL_FOG_START, 0.1);
	glFogf(GL_FOG_END,0.3 );
	glEnable(GL_FOG);
	glEnable(GL_DEPTH_TEST);
	float lightpos[] = {0.5,0.5,-0.5,0};
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
	glEnable(GL_LIGHT0);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	DisplayFunc = []() {
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(-0.8, 0, 0.1);
		for (int i = 0; i < 5;i++) {
			glutSolidSphere(0.1, 30, 30);
			glTranslatef(0.4, 0, 0.05);
		}
		glFlush();
	};


}
#pragma endregion
void WindowPreSet(){

	WindowDisPlayMode = WindowDisPlayMode;
	WindowDisPlayMode = GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH;

}
void MortalInit() {

	T7Thirdone();

}
#pragma region DeflautFunc
	void myDisplay(void)
	{
		


	}
void lookat() {
	float* temp = rangle;
	cout << "idle     pos   " << pos[0] << "   " << pos[1] << "   " << pos[2] << endl;
	cout << "idle     rangle" << rangle[0] << "   " << rangle[1] << "   " << rangle[2] << endl;
	cout << "idle     head  "<<head[0]<<"   " << head[1] << "   " << head[2] << endl;
	system("cls");

}
void keyboard(unsigned char key,int x,int y) {
	switch (key)
	{
	case 'q': { temp[0] += step;  break; }
	case 'a': {    temp[0] -= step;      break; }
	case 'w': {    temp[1] += step;      break; }
	case 's': {    temp[1] -= step;      break; }
	case 'e': {    temp[2] += step;      break; }
	case 'd': {    temp[2] -= step;      break; }
	case 'z': {   temp = pos;   step = 0.25;   break; }
	case 'x': {    temp = rangle;  step = 0.25;    break; }
	case 'c': {    temp = head; step = 0.1;      break; }
	case 'r': {   for (int i = 0; i < 3; i++) { 
		pos[i] = defualtMaxtir[i];
		rangle[i] = defualtMaxtir[i + 3];
		head[i] = defualtMaxtir[i + 6];
	
	}
			break; }
	default:
		break;
	}
	DisplayFunc();
}
void mouseMotionfunc(int x, int y) {};
void mousePassiveMotionfunc(int x, int y) {};
void mousefunc(int btn, int state, int x, int y) {};
void reshape(int w,int h) {};
void specilKeyboardFunc(int k, int x, int y) {};
void meanul(int v) {};
void submeanul1(int v) {};
#pragma endregion
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	WindowPreSet();
	glutInitWindowSize(W_Window, H_Window);
	glutInitDisplayMode(WindowDisPlayMode);
	glutCreateWindow(WindowTitle);
	IdleFunc = lookat;
	ReshapeFunc = reshape;
	KeyboardFunc = keyboard;
	DisplayFunc = myDisplay;
	MouseFunc = mousefunc;
	MouseMotionFunc = mouseMotionfunc;
	MousePassiveMotionFunc = mousePassiveMotionfunc;
	SpecilKeyboardFunc=specilKeyboardFunc;
	Meanul = meanul;
	SubMeanul1 = submeanul1;	
	MortalInit();
	glutIdleFunc(IdleFunc);
	glutSpecialFunc(SpecilKeyboardFunc);
	glutKeyboardFunc(KeyboardFunc);
	glutMouseFunc(MouseFunc);
	glutReshapeFunc(ReshapeFunc);
	glutMotionFunc(MouseMotionFunc);
	glutPassiveMotionFunc(MousePassiveMotionFunc);
	glutDisplayFunc(DisplayFunc);
	glutMainLoop();
}
