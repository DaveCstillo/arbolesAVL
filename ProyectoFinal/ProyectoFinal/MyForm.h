//<<<<<<< HEAD
#pragma once
#include "ABBscreen.h"
#define MARKER // declarations #endif 


//=======
//#pragma once 
//#pragma comment(lib, "glut32.lib")
//#pragma comment(lib, "glaux.lib")
//#include "ABBtree.h"
//>>>>>>> 71a903ed84cbb5ca0ec0f202c0452d4f8a8e2a7a

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		};
		ABB arbolabb = NULL;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 19);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"INSERTAR";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 57);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(146, 32);
			this->button2->TabIndex = 1;
			this->button2->Text = L"MOSTRAR";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 95);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(146, 32);
			this->button3->TabIndex = 2;
			this->button3->Text = L"ELIMINAR";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(6, 133);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(146, 32);
			this->button4->TabIndex = 3;
			this->button4->Text = L"CONTAR HOJAS";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(6, 171);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(146, 32);
			this->button5->TabIndex = 4;
			this->button5->Text = L"CONTAR NODOS";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(6, 209);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(146, 32);
			this->button6->TabIndex = 5;
			this->button6->Text = L"SUMAR NODOS";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(6, 247);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(146, 32);
			this->button7->TabIndex = 6;
			this->button7->Text = L"BUSCAR ELEMENTO";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(6, 19);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(146, 32);
			this->button8->TabIndex = 7;
			this->button8->Text = L"INSERTAR";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(6, 57);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(146, 32);
			this->button9->TabIndex = 8;
			this->button9->Text = L"MOSTRAR";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(6, 95);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(146, 32);
			this->button10->TabIndex = 9;
			this->button10->Text = L"ALGO MAS";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(186, 325);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ABB";
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(226, 18);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(498, 480);
			this->panel1->TabIndex = 11;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button10);
			this->groupBox2->Controls->Add(this->button8);
			this->groupBox2->Controls->Add(this->button9);
			this->groupBox2->Location = System::Drawing::Point(12, 343);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(186, 155);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"AVL";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 510);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"Inicio";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		limpiarPanel();
		ABBscreen^ abbscreen = gcnew ABBscreen(arbolabb);
		abbscreen->TopLevel = false;
		this->panel1->Controls->Add(abbscreen);
		this->panel1->Tag = abbscreen;
		abbscreen->Show();
	
	};


	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void limpiarPanel() {

		if (this->panel1->Controls->Count > 0) {
			this->panel1->Controls->RemoveAt(0);
				 }
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	limpiarPanel();
	ABBscreen^ abbscreen = gcnew ABBscreen(arbolabb);
	abbscreen->TopLevel = false;
	this->panel1->Controls->Add(abbscreen);
	this->panel1->Tag = abbscreen;
	abbscreen->Show();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	limpiarPanel();
	ABBscreen^ abbscreen = gcnew ABBscreen(arbolabb);
	abbscreen->TopLevel = false;
	this->panel1->Controls->Add(abbscreen);
	this->panel1->Tag = abbscreen;
	abbscreen->Show();
}
};


//-------Creacion de un nuevo nodo para el arbol ABB------------//
ABB crearNodo(int x)
{
	ABB nuevoNodo = new(struct ABBnodo);
	nuevoNodo->nro = x;
	nuevoNodo->izq = nullptr;
	nuevoNodo->der = nullptr;

	return nuevoNodo;
}


}
