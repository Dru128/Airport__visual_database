#pragma once
#include "Route.h"
#include "RouteConstructorForm.h"
#include "RequestParamsForm.h"
#include "RequestResultForm.h"
#include "AuthForm.h"
#include "ButtonGameForm.h"


namespace Airportdatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			AuthUser();
			RefillGrid();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:






	private: System::Windows::Forms::Button^  ChangeButton;
	private: System::Windows::Forms::Button^  AddButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Num;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  City;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Plane;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Days;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TimeFrom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TimeTo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Sell;
	private: System::Windows::Forms::Button^  RequestButton;
	private: System::Windows::Forms::Button^ LastRequestButton;












	protected:


	protected:

	public:
		Int32 TypeUser = 1;
	private: System::Windows::Forms::Button^ GameButton;
	public:

	protected:











		BindingList<Route^>^ routes = gcnew BindingList<Route^>();
		// 1 common
		// 2 admin

		void RefillGrid();

	private: System::Windows::Forms::DataGridView^  RoutesGrid;
	private: System::Windows::Forms::Button^  DeleteButton;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->RoutesGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Num = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->City = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Plane = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Days = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TimeFrom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TimeTo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sell = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			this->ChangeButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->RequestButton = (gcnew System::Windows::Forms::Button());
			this->LastRequestButton = (gcnew System::Windows::Forms::Button());
			this->GameButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RoutesGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// RoutesGrid
			// 
			this->RoutesGrid->AllowUserToAddRows = false;
			this->RoutesGrid->AllowUserToDeleteRows = false;
			this->RoutesGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->RoutesGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Num, this->City,
					this->Plane, this->Days, this->TimeFrom, this->TimeTo, this->Sell
			});
			this->RoutesGrid->Location = System::Drawing::Point(3, 41);
			this->RoutesGrid->Name = L"RoutesGrid";
			this->RoutesGrid->ReadOnly = true;
			this->RoutesGrid->Size = System::Drawing::Size(744, 604);
			this->RoutesGrid->TabIndex = 0;
			// 
			// Num
			// 
			this->Num->DataPropertyName = L"Num";
			this->Num->HeaderText = L"Номер рейса";
			this->Num->Name = L"Num";
			this->Num->ReadOnly = true;
			// 
			// City
			// 
			this->City->DataPropertyName = L"City";
			this->City->HeaderText = L"Пункт прибытия";
			this->City->Name = L"City";
			this->City->ReadOnly = true;
			// 
			// Plane
			// 
			this->Plane->DataPropertyName = L"Plane";
			this->Plane->HeaderText = L"Самолет";
			this->Plane->Name = L"Plane";
			this->Plane->ReadOnly = true;
			this->Plane->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// Days
			// 
			this->Days->DataPropertyName = L"Days";
			this->Days->HeaderText = L"Дни недели";
			this->Days->Name = L"Days";
			this->Days->ReadOnly = true;
			// 
			// TimeFrom
			// 
			this->TimeFrom->DataPropertyName = L"TimeFrom";
			this->TimeFrom->HeaderText = L"Вылет";
			this->TimeFrom->Name = L"TimeFrom";
			this->TimeFrom->ReadOnly = true;
			// 
			// TimeTo
			// 
			this->TimeTo->DataPropertyName = L"TimeTo";
			this->TimeTo->HeaderText = L"Посадка";
			this->TimeTo->Name = L"TimeTo";
			this->TimeTo->ReadOnly = true;
			// 
			// Sell
			// 
			this->Sell->DataPropertyName = L"Sell";
			this->Sell->HeaderText = L"Цена";
			this->Sell->Name = L"Sell";
			this->Sell->ReadOnly = true;
			// 
			// DeleteButton
			// 
			this->DeleteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->DeleteButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteButton.BackgroundImage")));
			this->DeleteButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->DeleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DeleteButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->DeleteButton->Location = System::Drawing::Point(82, 3);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(32, 32);
			this->DeleteButton->TabIndex = 1;
			this->DeleteButton->UseVisualStyleBackColor = false;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &MainForm::DeleteButton_Click);
			// 
			// ChangeButton
			// 
			this->ChangeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ChangeButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ChangeButton.BackgroundImage")));
			this->ChangeButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ChangeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ChangeButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ChangeButton->Location = System::Drawing::Point(44, 3);
			this->ChangeButton->Name = L"ChangeButton";
			this->ChangeButton->Size = System::Drawing::Size(32, 32);
			this->ChangeButton->TabIndex = 2;
			this->ChangeButton->UseVisualStyleBackColor = false;
			this->ChangeButton->Click += gcnew System::EventHandler(this, &MainForm::ChangeButton_Click);
			// 
			// AddButton
			// 
			this->AddButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->AddButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddButton.BackgroundImage")));
			this->AddButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->AddButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->AddButton->Location = System::Drawing::Point(6, 3);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(32, 32);
			this->AddButton->TabIndex = 3;
			this->AddButton->UseVisualStyleBackColor = false;
			this->AddButton->Click += gcnew System::EventHandler(this, &MainForm::AddButton_Click);
			// 
			// RequestButton
			// 
			this->RequestButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->RequestButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RequestButton.BackgroundImage")));
			this->RequestButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->RequestButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->RequestButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->RequestButton->Location = System::Drawing::Point(155, 3);
			this->RequestButton->Name = L"RequestButton";
			this->RequestButton->Size = System::Drawing::Size(32, 32);
			this->RequestButton->TabIndex = 4;
			this->RequestButton->UseVisualStyleBackColor = false;
			this->RequestButton->Click += gcnew System::EventHandler(this, &MainForm::RequestButton_Click);
			// 
			// LastRequestButton
			// 
			this->LastRequestButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->LastRequestButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LastRequestButton.BackgroundImage")));
			this->LastRequestButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->LastRequestButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LastRequestButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->LastRequestButton->Location = System::Drawing::Point(193, 3);
			this->LastRequestButton->Name = L"LastRequestButton";
			this->LastRequestButton->Size = System::Drawing::Size(32, 32);
			this->LastRequestButton->TabIndex = 5;
			this->LastRequestButton->UseVisualStyleBackColor = false;
			this->LastRequestButton->Click += gcnew System::EventHandler(this, &MainForm::LastRequestButton_Click);
			// 
			// GameButton
			// 
			this->GameButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GameButton->Location = System::Drawing::Point(651, 3);
			this->GameButton->Name = L"GameButton";
			this->GameButton->Size = System::Drawing::Size(86, 32);
			this->GameButton->TabIndex = 6;
			this->GameButton->Text = L"Game";
			this->GameButton->UseVisualStyleBackColor = true;
			this->GameButton->Click += gcnew System::EventHandler(this, &MainForm::GameButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(749, 641);
			this->Controls->Add(this->GameButton);
			this->Controls->Add(this->LastRequestButton);
			this->Controls->Add(this->RequestButton);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->ChangeButton);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->RoutesGrid);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"СУБД Аэропорта";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RoutesGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DeleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Route^ curRoute = dynamic_cast<Route^>(RoutesGrid->CurrentRow->DataBoundItem);
		routes->Remove(curRoute);
		deleteRoute(getFileName(), curRoute->Num);
	}

	private: System::Void ChangeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		createRouteConstructorForm(2);
	}
	private: System::Void AddButton_Click(System::Object^  sender, System::EventArgs^  e) {
		createRouteConstructorForm(1);
	}

	private: void createRouteConstructorForm(int mode)
	{
		RouteConstructorForm^ form = gcnew RouteConstructorForm();
		form->mode = mode;
		Route^ Createdroute = gcnew Route();
		Route^ Changedroute = dynamic_cast<Route^>(RoutesGrid->CurrentRow->DataBoundItem);



		if (mode == 1)
		{
			form->route = Createdroute;
		}
		else if (mode == 2)
		{
			form->route = Changedroute;
		}


		if (form->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
		{
			if (mode == 1)
			{
				routes->Add(Createdroute);
				addRoute(getFileName(), Createdroute);
			}
			else if (mode == 2) // update routes
			{
				RoutesGrid->Refresh();
				changeRoute(getFileName(), Changedroute);
			}
		}

	}

	private: System::Void RequestButton_Click(System::Object^  sender, System::EventArgs^  e) {
		RequestParamsForm^ form = gcnew RequestParamsForm();

		if (form->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
		{
			RequestResultForm^ resForm = gcnew RequestResultForm();
			resForm->ShowDialog(this);
		}
	}


	
	private: System::Void LastRequestButton_Click(System::Object^ sender, System::EventArgs^ e) {
		RequestResultForm^ resForm = gcnew RequestResultForm();
		resForm->ShowDialog(this);
	}

	void AuthUser()
	{
		AuthForm^ form = gcnew AuthForm();

		if (form->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
		{
			TypeUser = form->TypeUser;
			if (TypeUser == 1)
			{
				AddButton->Visible = false;
				ChangeButton->Visible = false;
				DeleteButton->Visible = false;
			}
			else if (TypeUser == 2)
			{
				AddButton->Visible = true;
				ChangeButton->Visible = true;
				DeleteButton->Visible = true;
			}	

		}
		else
		{
			this->Close();
		}
	}

	private: System::Void GameButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ButtonGameForm^ form = gcnew ButtonGameForm();
		form->ShowDialog(this);
	}
};
}