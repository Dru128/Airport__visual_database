#pragma once
#include "Route.h"
#include "DB.h"

namespace Airportdatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RouteConstructorForm
	/// </summary>
	public ref class RouteConstructorForm : public System::Windows::Forms::Form
	{
	public:
		RouteConstructorForm(void)
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
		~RouteConstructorForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  DoneButton;
	private: System::Windows::Forms::Button^  CanselButton;
	protected:


		/*
		mode
		0 nothing
		1 add route
		2 change route
		*/
	public:
		int mode = 0;
		Route^ route;


	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  NumText;
	private: System::Windows::Forms::TextBox^  CityText;


	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  PlaneText;

	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  DaysText;

	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  TimeFromText;

	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  TimeToText;

	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  SellText;

	private: System::Windows::Forms::TextBox^  textBox14;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RouteConstructorForm::typeid));
			this->DoneButton = (gcnew System::Windows::Forms::Button());
			this->CanselButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->NumText = (gcnew System::Windows::Forms::TextBox());
			this->CityText = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->PlaneText = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->DaysText = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->TimeFromText = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->TimeToText = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->SellText = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// DoneButton
			// 
			this->DoneButton->Location = System::Drawing::Point(200, 221);
			this->DoneButton->Name = L"DoneButton";
			this->DoneButton->Size = System::Drawing::Size(103, 23);
			this->DoneButton->TabIndex = 0;
			this->DoneButton->Text = L"Продолжить";
			this->DoneButton->UseVisualStyleBackColor = true;
			this->DoneButton->Click += gcnew System::EventHandler(this, &RouteConstructorForm::DoneButton_Click);
			// 
			// CanselButton
			// 
			this->CanselButton->Location = System::Drawing::Point(97, 221);
			this->CanselButton->Name = L"CanselButton";
			this->CanselButton->Size = System::Drawing::Size(97, 23);
			this->CanselButton->TabIndex = 1;
			this->CanselButton->Text = L"Отмена";
			this->CanselButton->UseVisualStyleBackColor = true;
			this->CanselButton->Click += gcnew System::EventHandler(this, &RouteConstructorForm::CanselButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(109, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Номер рейса";
			// 
			// NumText
			// 
			this->NumText->Location = System::Drawing::Point(130, 12);
			this->NumText->MaxLength = 10;
			this->NumText->Name = L"NumText";
			this->NumText->Size = System::Drawing::Size(173, 20);
			this->NumText->TabIndex = 4;
			// 
			// CityText
			// 
			this->CityText->Location = System::Drawing::Point(130, 38);
			this->CityText->MaxLength = 10;
			this->CityText->Name = L"CityText";
			this->CityText->Size = System::Drawing::Size(173, 20);
			this->CityText->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 38);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(109, 20);
			this->textBox4->TabIndex = 5;
			this->textBox4->Text = L"Пункт прибытия";
			// 
			// PlaneText
			// 
			this->PlaneText->Location = System::Drawing::Point(130, 64);
			this->PlaneText->MaxLength = 10;
			this->PlaneText->Name = L"PlaneText";
			this->PlaneText->Size = System::Drawing::Size(173, 20);
			this->PlaneText->TabIndex = 8;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(12, 64);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(109, 20);
			this->textBox6->TabIndex = 7;
			this->textBox6->Text = L"Самолет";
			// 
			// DaysText
			// 
			this->DaysText->Location = System::Drawing::Point(130, 90);
			this->DaysText->MaxLength = 10;
			this->DaysText->Name = L"DaysText";
			this->DaysText->Size = System::Drawing::Size(173, 20);
			this->DaysText->TabIndex = 10;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(12, 90);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(109, 20);
			this->textBox8->TabIndex = 9;
			this->textBox8->Text = L"Дни недели";
			// 
			// TimeFromText
			// 
			this->TimeFromText->Location = System::Drawing::Point(130, 116);
			this->TimeFromText->MaxLength = 10;
			this->TimeFromText->Name = L"TimeFromText";
			this->TimeFromText->Size = System::Drawing::Size(173, 20);
			this->TimeFromText->TabIndex = 12;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(12, 116);
			this->textBox10->Name = L"textBox10";
			this->textBox10->ReadOnly = true;
			this->textBox10->Size = System::Drawing::Size(109, 20);
			this->textBox10->TabIndex = 11;
			this->textBox10->Text = L"Время вылета";
			// 
			// TimeToText
			// 
			this->TimeToText->Location = System::Drawing::Point(130, 142);
			this->TimeToText->MaxLength = 10;
			this->TimeToText->Name = L"TimeToText";
			this->TimeToText->Size = System::Drawing::Size(173, 20);
			this->TimeToText->TabIndex = 14;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(12, 142);
			this->textBox12->Name = L"textBox12";
			this->textBox12->ReadOnly = true;
			this->textBox12->Size = System::Drawing::Size(109, 20);
			this->textBox12->TabIndex = 13;
			this->textBox12->Text = L"Время прибытия";
			// 
			// SellText
			// 
			this->SellText->Location = System::Drawing::Point(130, 168);
			this->SellText->MaxLength = 10;
			this->SellText->Name = L"SellText";
			this->SellText->Size = System::Drawing::Size(173, 20);
			this->SellText->TabIndex = 16;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(12, 168);
			this->textBox14->Name = L"textBox14";
			this->textBox14->ReadOnly = true;
			this->textBox14->Size = System::Drawing::Size(109, 20);
			this->textBox14->TabIndex = 15;
			this->textBox14->Text = L"Цена";
			// 
			// RouteConstructorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(315, 251);
			this->Controls->Add(this->SellText);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->TimeToText);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->TimeFromText);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->DaysText);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->PlaneText);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->CityText);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->NumText);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->CanselButton);
			this->Controls->Add(this->DoneButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RouteConstructorForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Конструктор рейса";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &RouteConstructorForm::RouteConstructorForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &RouteConstructorForm::RouteConstructorForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RouteConstructorForm_Load(System::Object^  sender, System::EventArgs^  e) {
		if (mode == 1)
		{

		}
		else if (mode == 2)
		{
			NumText->Text = Convert::ToString(route->Num);
			CityText->Text = route->City;
			PlaneText->Text = route->Plane;
			DaysText->Text = route->Days;
			TimeFromText->Text = route->TimeFrom;
			TimeToText->Text = route->TimeTo;
			SellText->Text = Convert::ToString(route->Sell);
		}
	}
	private: System::Void DoneButton_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (SellText->Text == "")
			route->Sell = -1;
		else if (isNumber(SellText->Text))
		{
			if (validateSell(Convert::ToDouble(SellText->Text)))
				route->Sell = Convert::ToDouble(SellText->Text);
			else
				return;
		}
		else
			return;

		if (NumText->Text == "")
			route->Num = -1;
		else if(isNumber(NumText->Text) && validateNum(Convert::ToInt32(NumText->Text)))
			route->Num = Convert::ToInt32(NumText->Text);
		else
			return;
		
		if ((isNumber(DaysText->Text) && validateDays(DaysText->Text))
			|| DaysText->Text == "")
			route->Days = NumText->Text;
		else
			return;

		if (TimeFromText->Text != "")
		{
			if (isTime(TimeFromText->Text))
				route->TimeFrom = TimeFromText->Text;
			else 
				return;
		} else 			
			route->TimeFrom = TimeFromText->Text;

		if (TimeToText->Text != "")
		{
			if (isTime(TimeToText->Text))
				route->TimeTo = TimeToText->Text;
			else 
				return;
		} else 			
			route->TimeTo = TimeToText->Text;


		if (CityText->Text == "" || PlaneText->Text == "")
			return;

		route->City = CityText->Text;
		route->Plane = PlaneText->Text;			
			
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: System::Void CanselButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->Close();
	}
	private: System::Void RouteConstructorForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

	}
};
}
