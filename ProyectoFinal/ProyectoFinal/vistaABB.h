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
		ABB arbol = NULL;
		vistaABB(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
		}

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
			this->ClientSize = System::Drawing::Size(370, 308);
			this->ControlBox = false;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold));
			this->Location = System::Drawing::Point(228, 0);
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"vistaABB";
			this->ShowIcon = false;
			this->ResumeLayout(false);

		}

#pragma endregion


	void verArbol(ABB arbol, int n)
		{
			if (arbol == NULL)
				return;
			verArbol(arbol->der, n + 1);
		
			//for (int i = 0; i<n; i++)
				//cout << "   ";
		
			numNodosABB++;
			dibujarNodo(arbol->nro);
		
			verArbol(arbol->izq, n + 1);
		}




	void dibujarNodo(int nro) {


	}


	};
}
