#pragma once

namespace ProyectoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ABBdelete
	/// </summary>
	public ref class ABBdelete : public System::Windows::Forms::Form
	{
	public:
		ABBdelete(void)
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
		~ABBdelete()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private:

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
			// ABBdelete
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 322);
			this->ControlBox = false;
			this->Font = (gcnew System::Drawing::Font(L"Minion Pro Med", 12, System::Drawing::FontStyle::Bold));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"ABBdelete";
			this->ShowIcon = false;
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
