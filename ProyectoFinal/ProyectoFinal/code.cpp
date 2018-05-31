/******************************************************************************

Proyecto Final Programación 3
Ingenieria en Sistemas; Universidad Mariano Gálvez de Guatemala
Ing. Antonio Heriberto Escobar López

Developed by:

David Adolfo Castillo Almengor              0901-15-8050
Luis Valenzuela                             0901-14-314

*******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "ABB.h"
using namespace std;



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



















//
//
//
//
//void menu()
//{
//	//system("cls");
//	cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";
//	cout << "\t [1]  Insertar elemento      arbol ABB   \n";
//	cout << "\t [2]  Mostrar arbol          arbol ABB   \n";
//	//	cout << "\t [3]  Recorridos          				\n";
//	cout << "\t [3]  Eliminar elemento                  \n";
//	cout << "\t [4]  Contar Hojas						\n";
//	cout << "\t [5]  Contar Nodos						\n";
//	cout << "\t [6]  Sumar Nodos						\n";
//	cout << "\t [7]  Buscar elemento                    \n";
//	cout << "\t ....................................... \n";
//	cout << "\t [8]  Insertar elemento      arbol AVL   \n";
//	cout << "\t [9]  Mostrar arbol          arbol AVL   \n";
//	cout << "\t [0]  SALIR                              \n";
//
//	cout << "\n\t Ingrese opcion : ";
//}
//
//void menu2()
//{
//	system("cls");   // para limpiar pantalla
//	cout << endl;
//
//	cout << "\t [1] En Orden     \n";
//	cout << "\t [2] Pre Orden    \n";
//	cout << "\t [3] Post Orden   \n";
//	cout << "\n\t     Opcion :  ";
//}
//
//int main()
//{
//	ABB arbol = NULL;
//	AVL tree = NULL;
//	int x;
//	int op, op2;
//	ifstream ficheroEntrada;
//	string frase;
//
//	//ficheroEntrada.open ("list.txt");
//	//getline(ficheroEntrada, frase);
//	//ficheroEntrada.close();
//
//	//cout << "Frase leida: " << frase << endl;
//
//
//
//	system("color f9");   // poner color a la consola
//	do
//	{
//		menu();  cin >> op;
//		cout << endl;
//
//		switch (op)
//		{
//		case 0:
//			exit(0);
//			break;
//
//		case 1:
//			system("cls");
//
//			cout << " Ingrese valor : ";  cin >> x;
//			//insertar(arbol, x);
//			break;
//
//		case 2:
//			system("cls");
//			verArbol(arbol, 0);
//			break;
//
//		case 3: //ELiminar Elemento
//			system("cls");
//			cout << " Valor a eliminar: "; cin >> x;
//			//elimina(arbol, x);
//			cout << "\n\tEliminado..!";
//			break;
//
//			/*
//			case 3:  //Recorridos
//			system("cls");
//			menu2();  cin >> op2;
//
//			if (arbol != NULL)
//			{
//			switch (op2)
//			{
//			case 1:
//			enOrden(arbol); break;
//			case 2:
//			preOrden(arbol); break;
//			case 3:
//			postOrden(arbol); break;
//			}
//			}
//			else
//			cout << "\n\t Arbol vacio..!";
//			break;
//			*/
//		case 4:
//			int countH;
//			countH = contarHojas(arbol);
//			cout << "Cantidad de Hojas: " << countH << endl;
//			system("pause");
//			break;
//		case 5:
//			cout << "Cantidad de Nodos: " << numNodosABB << endl;
//			system("pause");
//			break;
//		case 6:
//			sumarNodosABB(arbol);
//			cout << "Suma de los valores de los Nodos: " << sumNodos << endl;
//			system("pause");
//			break;
//		case 7:
//			system("cls");
//			bool band;
//
//			cout << " Valor a buscar: "; cin >> x;
//
//			band = busquedaRec(arbol, x);
//
//			if (band == 1)
//				cout << "\n\tEncontrado...";
//			else
//				cout << "\n\tNo encontrado...";
//
//			system("pause");
//			break;
//		case 8:
//			system("cls");
//
//			cout << " Ingrese valor : ";  cin >> x;
//			insertAVL(tree, x);
//			Hcount(tree);
//
//			break;
//
//		case 9:
//			system("cls");
//			verArbolAVL(tree, 0);
//			break;
//
//		}
//
//
//		cout << endl << endl << endl;
//		//system("pause");  // hacer pausa y presionar una tecla para continuar
//	} while (op != 0);
//
//}
