#pragma once
#include "MainForm.h"
#include "windows.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	
	Airportdatabase::MainForm form;
	Application::Run(%form);
}