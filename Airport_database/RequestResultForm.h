#pragma once

#include "Route.h"
#include "DB.h"
#include <iostream>

#define MAX_ROUTE_LEN 77

namespace Airportdatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RequestResultForm
	/// </summary>
	public ref class RequestResultForm : public System::Windows::Forms::Form
	{
	public:
		RequestResultForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//


			FILE* routeDB = fopen(getRequestFileName(), "r");

			if (routeDB == 0) return;
			rewind(routeDB);

			char* str = (char*)calloc(MAX_ROUTE_LEN, sizeof(char));
			Route^ route = gcnew Route();



			// Здесь работаем точно также как с strtok
			fgets(str, MAX_ROUTE_LEN, routeDB);
			while (serialiseRoute(str, route))
			{
				routes->Add(route);

				fgets(str, MAX_ROUTE_LEN, routeDB);
				route = gcnew Route();
			}
			fclose(routeDB);

			RoutesGrid->DataSource = routes;
		}

	protected:
		BindingList<Route^>^ routes = gcnew BindingList<Route^>();
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~RequestResultForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ RoutesGrid;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Num;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ City;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Plane;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Days;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TimeFrom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TimeTo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Sell;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RequestResultForm::typeid));
			this->RoutesGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Num = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->City = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Plane = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Days = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TimeFrom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TimeTo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sell = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->RoutesGrid->Location = System::Drawing::Point(3, 2);
			this->RoutesGrid->Name = L"RoutesGrid";
			this->RoutesGrid->ReadOnly = true;
			this->RoutesGrid->Size = System::Drawing::Size(744, 604);
			this->RoutesGrid->TabIndex = 1;
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
			// RequestResultForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 608);
			this->Controls->Add(this->RoutesGrid);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RequestResultForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Результаты запроса";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RoutesGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
