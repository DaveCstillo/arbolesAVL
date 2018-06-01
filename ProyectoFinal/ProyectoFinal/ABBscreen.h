//<<<<<<< HEAD
#pragma once 
#define MARKER // declarations #endif 
#include <iostream>
#include "librerias.h"
//#pragma once
//=======
//#pragma comment(lib, "glut32.lib")
//#pragma comment(lib, "glaux.lib")
//>>>>>>> 71a903ed84cbb5ca0ec0f202c0452d4f8a8e2a7a

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
		ABB arbol = NULL;
		ABBscreen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}
		ABBscreen(ABB arbol) {
			InitializeComponent();
			this->arbol = arbol;
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

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::MaskedTextBox^  textbox1;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textbox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 28);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 20);
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::SystemColors::InfoText;
			this->label2->Location = System::Drawing::Point(13, 118);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 20);
			this->label2->TabIndex = 3;
			// 
			// textbox1
			// 
			this->textbox1->Location = System::Drawing::Point(148, 25);
			this->textbox1->Mask = L"000";
			this->textbox1->Name = L"textbox1";
			this->textbox1->Size = System::Drawing::Size(38, 26);
			this->textbox1->TabIndex = 4;
			this->textbox1->ValidatingType = System::Int32::typeid;
			this->textbox1->TextChanged += gcnew System::EventHandler(this, &ABBscreen::textBox1_TextChanged);
			// 
			// ABBscreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(212, 162);
			this->ControlBox = false;
			this->Controls->Add(this->textbox1);
			this->Controls->Add(this->label2);
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

		/*if (textBox1->Text == "") {
			label2->ForeColor = System::Drawing::Color::Navy;
			label2->Text = "Error! Ingrese un Dato Valido!";
		}*/
		/*else {*/
			String^ num = textbox1->Text;
			int x;// = System::Convert::ToInt32(num);
			textbox1->Text = "";
			
				x = System::Convert::ToInt32(num);
				insertar(arbol, x);
			
				/*label2->ForeColor = System::Drawing::Color::DarkRed;
				label2->Text = "Error! Ingrese un Dato Valido!";*/
			

		//}
	}

			 
		private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			label2->Text = "";
		}

	

	//------Metodo de insertar en el arbol ABB------------//

	void insertar(ABB arbol, int x)
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
			this->label2->Text = "Error..!";
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

