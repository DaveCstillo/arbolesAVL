#pragma once 
#pragma comment(lib, "glut32.lib")
#pragma comment(lib, "glaux.lib")
#define MARKER // declarations #endif 
#include <iostream>
#include "ABB.h"

using namespace std;

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ABBscreen
	/// </summary>
	public ref class ABBscreen : public System::Windows::Forms::Form
	{
	public:
		ABBscreen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ABBscreen()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	public:


	public:
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 28);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Insertar Dato:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 70);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 31);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ABBscreen::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(236, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(174, 30);
			this->textBox1->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label2->Location = System::Drawing::Point(231, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(170, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"texto informativo";
			// 
			// ABBscreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(470, 127);
			this->ControlBox = false;
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"ABBscreen";
			this->ShowIcon = false;
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	public: void setText(String^ txt) {
			this->label1->Text = txt;
			
		}


#pragma endregion


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {



	}



	//------Metodo de insertar en el arbol ABB------------//

	void insertar(ABB &arbol, int x)
	{
		
		if (arbol == NULL)
		{
			arbol = crearNodo(x);
			this->label2->ForeColor = System::Drawing::Color::ForestGreen;
			this->label2->Text = "Insertado..!";
			
		}
		else if (x < arbol->nro)
			insertar(arbol->izq, x);
		else if (x > arbol->nro)
			insertar(arbol->der, x);
		else {
			this->label2->ForeColor = System::Drawing::Color::Firebrick;
			this->label2->Text = "Insertado..!";
		}
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



ABB desencola(struct cola &q)
{
	struct nodoCola *p;
	p = q.delante;
	ABB n = p->ptr;
	q.delante = (q.delante)->sgte;
	delete(p);
	return n;
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
		};
}
