#include "ABBscreen.h"
#include "ABBtree.h"




void inicializaCola(struct cola &q)
{
	q.delante = nullptr;
	q.atras = nullptr;
}

void encola(struct cola &q, ABB n)
{
	struct nodoCola *p;
	p = new(struct nodoCola);
	p->ptr = n;
	p->sgte = nullptr;
	if (q.delante == nullptr)
		q.delante = p;
	else
		(q.atras)->sgte = p;
	q.atras = p;
}

ABB desencola(struct cola &q)
{
	struct nodoCola *p;
	p = q.delante;
	ABB n = p->ptr;
	q.delante = (q.delante)->sgte;
	delete(p);
	return n;
}


//-------Creacion de un nuevo nodo para el arbol ABB------------//
ABB crearNodo(int x)
{
	ABB nuevoNodo = new(struct ABBnodo);
	nuevoNodo->nro = x;
	nuevoNodo->izq = nullptr;
	nuevoNodo->der = nullptr;

	return nuevoNodo;
}


//------Metodo de insertar en el arbol ABB------------//

void insertar(ABB &arbol, int x)
{
	system("cls");
	if (arbol == nullptr)
	{
		arbol = crearNodo(x);
		
		cout << "\n\t  Insertado..!" << endl << endl;
		system("cls");
	}
	else if (x < arbol->nro)
		insertar(arbol->izq, x);
	else if (x > arbol->nro)
		insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
	if (arbol != nullptr)
	{
		cout << arbol->nro << " ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void enOrden(ABB arbol)
{
	if (arbol != nullptr)
	{
		enOrden(arbol->izq);
		cout << arbol->nro << " ";
		enOrden(arbol->der);
	}
}

void postOrden(ABB arbol)
{
	if (arbol != nullptr)
	{
		enOrden(arbol->izq);
		enOrden(arbol->der);
		cout << arbol->nro << " ";
	}
}

void verArbol(ABB arbol, int n)
{
	if (arbol == nullptr)
		return;
	verArbol(arbol->der, n + 1);

	for (int i = 0; i<n; i++)
		cout << "   ";

	numNodosABB++;
	cout << arbol->nro << endl;

	verArbol(arbol->izq, n + 1);
}

bool busquedaRec(ABB arbol, int dato)
{
	int r = 0;   // 0 indica que no lo encontre

	if (arbol == nullptr)
		return r;

	if (dato<arbol->nro)
		r = busquedaRec(arbol->izq, dato);

	else if (dato> arbol->nro)
		r = busquedaRec(arbol->der, dato);

	else
		r = 1;   // son iguales, lo encontre

	return r;
}

ABB unirABB(ABB izq, ABB der)
{
	if (izq == nullptr) return der;
	if (der == nullptr) return izq;

	ABB centro = unirABB(izq->der, der->izq);
	izq->der = centro;
	der->izq = izq;
	return der;
}

void elimina(ABB &arbol, int x)
{
	if (arbol == nullptr) return;

	if (x<arbol->nro)
		elimina(arbol->izq, x);
	else if (x>arbol->nro)
		elimina(arbol->der, x);

	else
	{
		ABB p = arbol;
		arbol = unirABB(arbol->izq, arbol->der);
		delete p;
	}
	system("PAUSE");
}



void recorrerxNivel(ABB arbol)
{
	struct cola q;
	inicializaCola(q);
	cout << "\t";

	if (arbol != nullptr)
	{
		encola(q, arbol);

		while (q.delante != nullptr)
		{
			arbol = desencola(q);
			cout << arbol->nro << ' ';

			if (arbol->izq != nullptr)
				encola(q, arbol->izq);
			if (arbol->der != nullptr)
				encola(q, arbol->der);
		}
	}
}


int contarHojas(ABB arbol)
{
	if (arbol == nullptr)
	{
		return 0;
	}
	if ((arbol->der == nullptr) && (arbol->izq == nullptr))
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

	if (arbol == nullptr)
		return;

	if (arbol->der != nullptr) {
		sumarNodosABB(arbol->der);
	}
	if (arbol->izq != nullptr) {
		sumarNodosABB(arbol->izq);
	}

	sumNodos += arbol->nro;

}