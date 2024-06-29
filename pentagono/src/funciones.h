/*
 * funciones.h
 *
 *  Created on: 29 jun. 2024
 *      Author: luis2
 */

#ifndef SRC_FUNCIONES_H_
#define SRC_FUNCIONES_H_

#include <iostream>
#include <GL/glut.h>
using namespace std;

void Inicializar(double);
void pentagono();
void planoCartesiano(float);
void Dibujar();

void translado(unsigned char, int, int);
void tecladoEspecial(int ,int, int);
#endif /* SRC_FUNCIONES_H_ */
