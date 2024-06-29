/*
 * inicio.cpp
 *
 *  Created on: 29 jun. 2024
 *      Author: luis2
 */


#include "funciones.h"
#include <iostream>
#include <GL/glut.h>
using namespace std;


double rotar_x=25, rotar_y=-25;
int mover_x;
int mover_y;

void planoCartesiano(float valor){

glBegin(GL_LINES);
glVertex2f(-valor,0.0);
glVertex2f(valor,0.0);
glVertex2f(0.0,-valor);
glVertex2f(0.0,valor);
glEnd();

}

void pentagono(){
	//Abajo
	glBegin(GL_POLYGON);
	glColor3f( 1.0, 1.0, 1.0 ); // BLANCO
	glVertex3d(-0.5, 0.75, -0.5);
	glVertex3d(0.5, 0.75, -0.5);
	glVertex3d(1.0, 0.0, -0.5);
	glVertex3d(0.5, -0.75, -0.5);
	glVertex3d(-0.45, -0.75, -0.5);
	glVertex3d(-1.0, 0.0, -0.5);
	glEnd();

	//Arrriba
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0); // ROJO
	glVertex3d(-0.5, 0.75, 0.5);
	glVertex3d(0.5, 0.75, 0.5);
	glVertex3d(1.0, 0.0, 0.5);
	glVertex3d(0.5, -0.75, 0.5);
	glVertex3d(-0.45, -0.75, 0.5);
	glVertex3d(-1.0, 0.0, 0.5);
	glEnd();

	// Lado L1
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0); // VERDE
	glVertex3d(-0.5, 0.75, -0.5);
	glVertex3d(-0.5, 0.75, 0.5);
	glVertex3d(0.5, 0.75, 0.5);
	glVertex3d(0.5, 0.75, -0.5);
	glEnd();

	// Lado L2
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0); // AZUL
	glVertex3d(0.5, 0.75, -0.5);
	glVertex3d(0.5, 0.75, 0.5);
	glVertex3d(1.0, 0.0, 0.5);
	glVertex3d(1.0, 0.0, -0.5);
	glEnd();

	// Lado L3
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0); // AMARILLO
	glVertex3d(1.0, 0.0, -0.5);
	glVertex3d(1.0, 0.0, 0.5);
	glVertex3d(0.5, -0.75, 0.5);
	glVertex3d(0.5, -0.75, -0.5);
	glEnd();

	// Lado L4
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0); // MAGENTA
	glVertex3d(0.5, -0.75, -0.5);
	glVertex3d(0.5, -0.75, 0.5);
	glVertex3d(-0.45, -0.75, 0.5);
	glVertex3d(-0.45, -0.75, -0.5);
	glEnd();

	// Lado L5
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0); // CIAN
	glVertex3d(-0.45, -0.75, -0.5);
	glVertex3d(-0.45, -0.75, 0.5);
	glVertex3d(-1.0, 0.0, 0.5);
	glVertex3d(-1.0, 0.0, -0.5);
	glEnd();

	// Lado L6
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0); // NARANJA
	glVertex3d(-1.0, 0.0, -0.5);
	glVertex3d(-1.0, 0.0, 0.5);
	glVertex3d(-0.5, 0.75, 0.5);
	glVertex3d(-0.5, 0.75, -0.5);
	glEnd();

}

void Inicializar(double unidad){

glClearColor(0.0,0.0,0.0,1.0);//negro
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);

}

void Dibujar(){

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3f(1.0,1.0,1.0);//blanco
planoCartesiano(16);
glPushMatrix();
glTranslatef(mover_x , mover_y , 0.0);
glRotatef(rotar_x,1.0,0.0,0.0);
glRotatef(rotar_y,0.0,1.0,0.0);
pentagono();
glPopMatrix();
glFlush();

}

void tecladoEspecial(int key, int x, int y){
switch(key){
case GLUT_KEY_RIGHT: rotar_y++;break;
case GLUT_KEY_LEFT:  rotar_y--;break;
case GLUT_KEY_UP:    rotar_x--;break;
case GLUT_KEY_DOWN:  rotar_x++;break;
}

glutPostRedisplay();

}

void translado(unsigned char k, int x, int y){
switch(k){
case '4':mover_x--;break;
case '6':mover_x++;break;
case '8':mover_y++;break;
case '2':mover_y--;break;

case 27:exit(0);
}
glutPostRedisplay();
}


