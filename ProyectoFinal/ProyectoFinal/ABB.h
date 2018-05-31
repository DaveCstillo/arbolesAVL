#pragma once 
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glaux.lib")
#define MARKER // declarations #endif 
#endif   CSPIRTEMANAGER
#define CSPRITEMANAGER

/*---------  Estructura del arbol ABB  -------*/
typedef struct ABBnodo {
	int nro;
	struct ABBnodo *izq, *der;
}*ABB;


static int numNodosABB = 0; // nummero de nodos del arbol ABB
static int sumNodos = 0;
static int numK = 0, k;     //  nodos menores que un numero k ingresado


							/* ---------- Estructura de la cola ---------*/
struct nodoCola {
	ABB ptr;
	struct nodoCola *sgte;
};
struct cola {
	struct nodoCola *delante;
	struct nodoCola *atras;
};
