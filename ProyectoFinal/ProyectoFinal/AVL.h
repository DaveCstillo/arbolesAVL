#pragma once

#include <iostream>


using namespace std;



/*---------  Estructura del arbol AVL  -------*/

typedef struct AVLnodo {
	int nro;
	int hDer, hIzq;
	int FE;
	struct AVLnodo *izq, *der;
}*AVL;

int numNodosAVL = 0; // nummero de nodos del arbol AVL


					 //-------Creacion de un nuevo nodo para el arbol AVL------------//

AVL crearNodoAVL(int x)
{
	AVL Nodo = new(struct AVLnodo);
	Nodo->nro = x;
	Nodo->izq = NULL;
	Nodo->der = NULL;
	Nodo->hIzq = 0;
	Nodo->hDer = 0;
	Nodo->FE = 0;

	return Nodo;
}

void Hcount(AVL a);

//-----Metodo para insertar un nuevo nodo en el arbol AVL----------//
void insertAVL(AVL &tree, int x)
{
	system("cls");
	if (tree == NULL)
	{
		tree = crearNodoAVL(x);
		cout << "\n\t  Dato Insertado..!" << endl << endl;
	}
	else if (x < tree->nro)
		insertAVL(tree->izq, x);
	else if (x > tree->nro)
		insertAVL(tree->der, x);



}

void verArbolAVL(AVL tree, int n)
{
	//cout<<"Representacion Arbol AVL final"<<endl<<endl;

	if (tree == NULL)
		return;

	verArbolAVL(tree->der, n + 1);

	for (int i = 0; i<n; i++)
		cout << "   ";

	numNodosAVL++;
	cout << tree->nro << endl;

	verArbolAVL(tree->izq, n + 1);

}


//--------Metodos para reestructuracion del arbol---------

AVL rotarLL(AVL &A) { //precond: el árbol necesita una rotacion Izquierda-Izquierda

	AVL newTree = NULL;
	cout << "---------------Datos de prueba--------------" << endl << "----------Rotacion Izquierda-Izquierda-----------" << endl << "Nodo a evaluar: (A): " << A->nro << endl;

	AVL aux = A->izq->izq;

	A->izq->der = A;

	AVL aux2 = A->izq;





	cout << "Auxiliar (aux = A->izq->izq): " << aux->nro << endl;
	cout << "A izq-der (A->izq->der = A): " << A->izq->der->nro << endl;
	cout << "Auxiliar2 (aux2 = A->izq): " << aux2->nro << endl;

	A->izq = aux;

	newTree = aux2;


	cout << "A->izq = aux: " << A->izq->nro << endl;




	cout << "Nuevo Arbol(A = aux2): " << newTree->nro << endl << "A->izq: " << newTree->izq->nro << endl << "A->der: " << newTree->der->nro << endl << endl;



	cout << "Representacion arbol, rotacion II" << endl;
	verArbolAVL(newTree, 0);

	cout << "----------------------------------" << endl;

	return newTree;
}

AVL rotarRR(AVL &A) { //precond: el árbol necesita una rotacion Derecha-Derecha
	AVL aux = A->der->der;
	A->der->izq = A;
	AVL aux2 = A->der;
	A = aux2;
	cout << "Representacion arbol, rotacion DD" << endl;
	verArbolAVL(A, 0);
	return A;
}

AVL rotarLRalter(AVL &A) { //precond: el árbol necesita una rotacion LR
	rotarRR(A->izq);
	rotarLL(A);
	cout << "Representacion arbol, rotacion ID" << endl;
	verArbolAVL(A, 0);
	return A;
}

AVL rotarRLalter(AVL &A) { //precond: el árbol necesita una rotacion RL
	rotarLL(A->der);
	rotarRR(A);
	cout << "Representacion arbol, rotacion DI" << endl;
	verArbolAVL(A, 0);
	return A;
}



void balanceFE(AVL &n) {

	cout << "Balance del arbol, punto de partida, Nodo: " << n->nro << endl;

	AVL arbl;


	if (n->FE == 2) {
		if (n->der->der != NULL) {
			cout << "Rotar DD, Nodo: " << n->nro << endl;
			arbl = rotarRR(n);
		}
		else if (n->der->izq != NULL) {
			cout << "Rotar DI, Nodo: " << n->nro << endl;
			arbl = rotarRLalter(n);
		}
	}
	if (n->FE == -2) {
		if (n->izq->izq != NULL) {
			cout << "Rotar II, Nodo: " << n->nro << endl;
			arbl = rotarLL(n);
		}
		else if (n->izq->der != NULL) {
			cout << "Rotar ID, Nodo: " << n->nro << endl;
			arbl = rotarLRalter(n);
		}
	}

	//	Hcount(arbl);
}

void Hcount(AVL a) {

	if (a->der != NULL) {
		Hcount(a->der);
		if (a->der->der != NULL);
		if (a->der->izq != NULL);

		a->hDer += 1;

	}
	if (a->izq != NULL) {
		Hcount(a->izq);
		if (a->izq->der != NULL);
		if (a->izq->izq != NULL);

		a->hIzq += 1;
	}
	cout << "-------IMPRESION DE PRUEBA------" << endl << "-----VALORES-----" << endl
		<< "NODO: " << a->nro << endl << "ALTURA DERECHA: " << a->hDer << endl << "ALTURA IZQUIERDA: " << a->hIzq << endl << endl;

	a->FE = a->hDer - a->hIzq;

	cout << "Factor de equilibrio del nodo: ";
	cout << a->nro << "\t" << a->FE << endl;



	if (a->FE>1 || a->FE<-1) {
		balanceFE(a);
	}

}

