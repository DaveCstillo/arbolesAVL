
#pragma once


/*---------  Estructura del arbol ABB  -------*/
typedef struct ABBnodo {
	int nro;
	struct ABBnodo *izq, *der;
}*ABB;

int numNodosABB = 0; // nummero de nodos del arbol ABB
int sumNodos = 0;
int numK = 0, k;     //  nodos menores que un numero k ingresado


					 /* ---------- Estructura de la cola ---------*/
struct nodoCola {
	ABB ptr;
	struct nodoCola *sgte;
};
struct cola {
	struct nodoCola *delante;
	struct nodoCola *atras;
};


