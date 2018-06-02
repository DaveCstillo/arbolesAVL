#pragma once
#include "librerias.h"
#include <iostream>
using namespace std;

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for vistaABB
	/// </summary>
	public ref class vistaABB : public System::Windows::Forms::Form
	{
	public:
		Graphics^ graficador;
		ABB arbol;
		vistaABB(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			arbol = NULL;
			graficador = this->CreateGraphics();
		}
		vistaABB(ABB arbol) {
			InitializeComponent();
			this->arbol = arbol;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~vistaABB()
		{
			if (components)
			{
				delete components;
			}
			delete graficador;
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// vistaABB
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(384, 384);
			this->ControlBox = false;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"vistaABB";
			this->ShowIcon = false;
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &vistaABB::vistaABB_Paint);
			this->ResumeLayout(false);

		}

	private: System::Void vistaABB_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Point p1(70,30), p2(45,50);

		/*if (arbol == NULL);
		return;*/

		drawSeparator(p1, p2);
		//Para dibujar el Nodo: parametros: Numero, posicion X, posicion Y
		drawNode(5,38, 48);

		verArbol(arbol, 0);

	}

#pragma endregion

	void drawNode(int nro, int x, int y) {
		Rectangle rectangle;
		rectangle.X = x;
		rectangle.Y = y;
		rectangle.Width = 20;
		rectangle.Height = 20;
		String^ texto = nro.ToString();
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Microsoft Sans Serif", 12);
		graficador->DrawString(texto, drawFont, Brushes::Black, rectangle);
		graficador->DrawEllipse(Pens::Red, rectangle);
	}

	void drawSeparator(Point inicio, Point fin) {
		graficador->DrawLine(Pens::Black, inicio, fin);
	}

	void verArbol(ABB arbol, int n)
		{
			if (arbol == NULL)
				return;
			verArbol(arbol->der, n + 1);
		
			//for (int i = 0; i<n; i++)
				//cout << "   ";
		
			numNodosABB++;
			drawNode(arbol->nro, n, n+20);
		
			verArbol(arbol->izq, n + 1);
		}




	void dibujarNodo(int nro) {


	}


	};
}
