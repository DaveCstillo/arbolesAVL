#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	ProyectoFinal::MyForm form;
	Application::Run(%form);

	

	
}

inline System::Void ProyectoFinal::MyForm::button1_Click(System::Object ^ sender, System::EventArgs ^ e) {

	ABBscreen^ abbscreen = gcnew ABBscreen();
	this->Hide();
	abbscreen->ShowDialog();


}
