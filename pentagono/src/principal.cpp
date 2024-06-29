/*
 * principal.cpp
 *
 *  Created on: 29 jun. 2024
 *      Author: luis2
 */


#include <iostream>
#include <GL/glut.h>
using namespace std;
#include "funciones.h"


int main(int argc, char **argv) {

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutCreateWindow("Grafico en #D");
Inicializar(16);
glutDisplayFunc(Dibujar);
glutKeyboardFunc(translado);
glutSpecialFunc(tecladoEspecial);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;

}

