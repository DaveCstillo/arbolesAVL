#ifndef _ABB
#define _ABB
#include <iostream>

using namespace std;

#pragma once

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



int contarHojas(ABB arbol)
{
	if (arbol == NULL)
	{
		return 0;
	}
	if ((arbol->der == NULL) && (arbol->izq == NULL))
	{
		return 1;
	}
	else
	{
		return contarHojas(arbol->izq) + contarHojas(arbol->der);
	}
}



void sumarNodosABB(ABB arbol)
{
	int suma;

	if (arbol == NULL)
		return;

	if (arbol->der != NULL) {
		sumarNodosABB(arbol->der);
	}
	if (arbol->izq != NULL) {
		sumarNodosABB(arbol->izq);
	}

	sumNodos += arbol->nro;

}

void inicializaCola(struct cola &q)
{
	q.delante = NULL;
	q.atras = NULL;
}

void encola(struct cola &q, ABB n)
{
	struct nodoCola *p;
	p = new(struct nodoCola);
	p->ptr = n;
	p->sgte = NULL;
	if (q.delante == NULL)
		q.delante = p;
	else
		(q.atras)->sgte = p;
	q.atras = p;
}



void preOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		cout << arbol->nro << " ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void enOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		enOrden(arbol->izq);
		cout << arbol->nro << " ";
		enOrden(arbol->der);
	}
}

void postOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		enOrden(arbol->izq);
		enOrden(arbol->der);
		cout << arbol->nro << " ";
	}
}

void verArbol(ABB arbol, int n)
{
	if (arbol == NULL)
		return;
	verArbol(arbol->der, n + 1);

	for (int i = 0; i<n; i++)
		cout << "   ";

	numNodosABB++;
	cout << arbol->nro << endl;

	verArbol(arbol->izq, n + 1);
}

int busquedaRec(ABB arbol, int dato)
{
	int r = 0;   // 0 indica que no lo encontre

	if (arbol == NULL)
		return r;

	if (dato<arbol->nro)
		r = busquedaRec(arbol->izq, dato);

	else if (dato> arbol->nro)
		r = busquedaRec(arbol->der, dato);

	else
		r = 1;   // son iguales, lo encontre

	return r;
}



#endif // !ABB
