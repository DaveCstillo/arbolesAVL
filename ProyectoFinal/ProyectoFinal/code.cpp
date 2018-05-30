/******************************************************************************

Proyecto Final Programaci�n 3
Ingenieria en Sistemas; Universidad Mariano G�lvez de Guatemala
Ing. Antonio Heriberto Escobar L�pez

Developed by:

David Adolfo Castillo Almengor              0901-15-8050
Luis Valenzuela                             0901-14-314

*******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "ABB.h"
using namespace std;


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

bool busquedaRec(ABB arbol, int dato)
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


//
//void elimina(ABB &arbol, int x)
//{
//	if (arbol == NULL) return;
//
//	if (x<arbol->nro)
//		elimina(arbol->izq, x);
//	else if (x>arbol->nro)
//		elimina(arbol->der, x);
//
//	else
//	{
//		ABB p = arbol;
//		arbol = unirABB(arbol->izq, arbol->der);
//		delete p;
//	}
//	system("PAUSE");
//}



//void recorrerxNivel(ABB arbol)
//{
//	struct cola q;
//	inicializaCola(q);
//	cout << "\t";
//
//	if (arbol != NULL)
//	{
//		encola(q, arbol);
//
//		while (q.delante != NULL)
//		{
//			arbol = desencola(q);
//			cout << arbol->nro << ' ';
//
//			if (arbol->izq != NULL)
//				encola(q, arbol->izq);
//			if (arbol->der != NULL)
//				encola(q, arbol->der);
//		}
//	}
//}


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

AVL rotarLL(AVL &A) { //precond: el �rbol necesita una rotacion Izquierda-Izquierda

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

AVL rotarRR(AVL &A) { //precond: el �rbol necesita una rotacion Derecha-Derecha
	AVL aux = A->der->der;
	A->der->izq = A;
	AVL aux2 = A->der;
	A = aux2;
	cout << "Representacion arbol, rotacion DD" << endl;
	verArbolAVL(A, 0);
	return A;
}

AVL rotarLRalter(AVL &A) { //precond: el �rbol necesita una rotacion LR
	rotarRR(A->izq);
	rotarLL(A);
	cout << "Representacion arbol, rotacion ID" << endl;
	verArbolAVL(A, 0);
	return A;
}

AVL rotarRLalter(AVL &A) { //precond: el �rbol necesita una rotacion RL
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























void menu()
{
	//system("cls");
	cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";
	cout << "\t [1]  Insertar elemento      arbol ABB   \n";
	cout << "\t [2]  Mostrar arbol          arbol ABB   \n";
	//	cout << "\t [3]  Recorridos          				\n";
	cout << "\t [3]  Eliminar elemento                  \n";
	cout << "\t [4]  Contar Hojas						\n";
	cout << "\t [5]  Contar Nodos						\n";
	cout << "\t [6]  Sumar Nodos						\n";
	cout << "\t [7]  Buscar elemento                    \n";
	cout << "\t ....................................... \n";
	cout << "\t [8]  Insertar elemento      arbol AVL   \n";
	cout << "\t [9]  Mostrar arbol          arbol AVL   \n";
	cout << "\t [0]  SALIR                              \n";

	cout << "\n\t Ingrese opcion : ";
}

void menu2()
{
	system("cls");   // para limpiar pantalla
	cout << endl;

	cout << "\t [1] En Orden     \n";
	cout << "\t [2] Pre Orden    \n";
	cout << "\t [3] Post Orden   \n";
	cout << "\n\t     Opcion :  ";
}

int main()
{
	ABB arbol = NULL;
	AVL tree = NULL;
	int x;
	int op, op2;
	ifstream ficheroEntrada;
	string frase;

	//ficheroEntrada.open ("list.txt");
	//getline(ficheroEntrada, frase);
	//ficheroEntrada.close();

	//cout << "Frase leida: " << frase << endl;



	system("color f9");   // poner color a la consola
	do
	{
		menu();  cin >> op;
		cout << endl;

		switch (op)
		{
		case 0:
			exit(0);
			break;

		case 1:
			system("cls");

			cout << " Ingrese valor : ";  cin >> x;
			//insertar(arbol, x);
			break;

		case 2:
			system("cls");
			verArbol(arbol, 0);
			break;

		case 3: //ELiminar Elemento
			system("cls");
			cout << " Valor a eliminar: "; cin >> x;
			//elimina(arbol, x);
			cout << "\n\tEliminado..!";
			break;

			/*
			case 3:  //Recorridos
			system("cls");
			menu2();  cin >> op2;

			if (arbol != NULL)
			{
			switch (op2)
			{
			case 1:
			enOrden(arbol); break;
			case 2:
			preOrden(arbol); break;
			case 3:
			postOrden(arbol); break;
			}
			}
			else
			cout << "\n\t Arbol vacio..!";
			break;
			*/
		case 4:
			int countH;
			countH = contarHojas(arbol);
			cout << "Cantidad de Hojas: " << countH << endl;
			system("pause");
			break;
		case 5:
			cout << "Cantidad de Nodos: " << numNodosABB << endl;
			system("pause");
			break;
		case 6:
			sumarNodosABB(arbol);
			cout << "Suma de los valores de los Nodos: " << sumNodos << endl;
			system("pause");
			break;
		case 7:
			system("cls");
			bool band;

			cout << " Valor a buscar: "; cin >> x;

			band = busquedaRec(arbol, x);

			if (band == 1)
				cout << "\n\tEncontrado...";
			else
				cout << "\n\tNo encontrado...";

			system("pause");
			break;
		case 8:
			system("cls");

			cout << " Ingrese valor : ";  cin >> x;
			insertAVL(tree, x);
			Hcount(tree);

			break;

		case 9:
			system("cls");
			verArbolAVL(tree, 0);
			break;

		}


		cout << endl << endl << endl;
		//system("pause");  // hacer pausa y presionar una tecla para continuar
	} while (op != 0);

}
