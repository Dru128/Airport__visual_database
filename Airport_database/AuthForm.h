#pragma once

namespace Airportdatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AuthForm
	/// </summary>
	public ref class AuthForm : public System::Windows::Forms::Form
	{
	public:
		AuthForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AuthForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ AuthButton;
	private: System::Windows::Forms::GroupBox^ groupBox;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::RadioButton^ AdminRadio;
	private: System::Windows::Forms::RadioButton^ CommonRadio;
	private: System::Windows::Forms::TextBox^ PasswordText;


	public:
		Int32 TypeUser = 1;

	protected:
		String^ Password = "кукумбер";
	private: System::Windows::Forms::TextBox^ HintText;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AuthForm::typeid));
			this->AuthButton = (gcnew System::Windows::Forms::Button());
			this->groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->PasswordText = (gcnew System::Windows::Forms::TextBox());
			this->AdminRadio = (gcnew System::Windows::Forms::RadioButton());
			this->CommonRadio = (gcnew System::Windows::Forms::RadioButton());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->HintText = (gcnew System::Windows::Forms::TextBox());
			this->groupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// AuthButton
			// 
			this->AuthButton->Location = System::Drawing::Point(153, 139);
			this->AuthButton->Name = L"AuthButton";
			this->AuthButton->Size = System::Drawing::Size(75, 23);
			this->AuthButton->TabIndex = 0;
			this->AuthButton->Text = L"Войти";
			this->AuthButton->UseVisualStyleBackColor = true;
			this->AuthButton->Click += gcnew System::EventHandler(this, &AuthForm::AuthButton_Click);
			// 
			// groupBox
			// 
			this->groupBox->Controls->Add(this->HintText);
			this->groupBox->Controls->Add(this->PasswordText);
			this->groupBox->Controls->Add(this->AdminRadio);
			this->groupBox->Controls->Add(this->CommonRadio);
			this->groupBox->Location = System::Drawing::Point(12, 12);
			this->groupBox->Name = L"groupBox";
			this->groupBox->Size = System::Drawing::Size(203, 95);
			this->groupBox->TabIndex = 1;
			this->groupBox->TabStop = false;
			this->groupBox->Text = L"Выберите пользователя";
			this->groupBox->Enter += gcnew System::EventHandler(this, &AuthForm::groupBox_Enter);
			// 
			// PasswordText
			// 
			this->PasswordText->Location = System::Drawing::Point(94, 65);
			this->PasswordText->Name = L"PasswordText";
			this->PasswordText->PasswordChar = '*';
			this->PasswordText->Size = System::Drawing::Size(103, 20);
			this->PasswordText->TabIndex = 2;
			this->PasswordText->Visible = false;
			// 
			// AdminRadio
			// 
			this->AdminRadio->AutoSize = true;
			this->AdminRadio->Location = System::Drawing::Point(6, 42);
			this->AdminRadio->Name = L"AdminRadio";
			this->AdminRadio->Size = System::Drawing::Size(58, 17);
			this->AdminRadio->TabIndex = 1;
			this->AdminRadio->Text = L"Админ";
			this->AdminRadio->UseVisualStyleBackColor = true;
			this->AdminRadio->CheckedChanged += gcnew System::EventHandler(this, &AuthForm::Radio_CheckedChanged);
			// 
			// CommonRadio
			// 
			this->CommonRadio->AutoSize = true;
			this->CommonRadio->Checked = true;
			this->CommonRadio->Location = System::Drawing::Point(6, 19);
			this->CommonRadio->Name = L"CommonRadio";
			this->CommonRadio->Size = System::Drawing::Size(72, 17);
			this->CommonRadio->TabIndex = 0;
			this->CommonRadio->TabStop = true;
			this->CommonRadio->Text = L"Обычный";
			this->CommonRadio->UseVisualStyleBackColor = true;
			this->CommonRadio->CheckedChanged += gcnew System::EventHandler(this, &AuthForm::Radio_CheckedChanged);
			// 
			// HintText
			// 
			this->HintText->Location = System::Drawing::Point(6, 65);
			this->HintText->Name = L"HintText";
			this->HintText->ReadOnly = true;
			this->HintText->Size = System::Drawing::Size(82, 20);
			this->HintText->TabIndex = 3;
			this->HintText->Text = L"Пароль";
			this->HintText->Visible = false;
			// 
			// AuthForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(240, 174);
			this->Controls->Add(this->groupBox);
			this->Controls->Add(this->AuthButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AuthForm";
			this->Text = L"Вход";
			this->groupBox->ResumeLayout(false);
			this->groupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void groupBox_Enter(System::Object^ sender, System::EventArgs^ e) {


	}


	private: System::Void Radio_CheckedChanged(Object^ sender, System::EventArgs^ e) {
		RadioButton^ radioButton = dynamic_cast<RadioButton^>(sender);


		if (radioButton->Name == "CommonRadio")
		{
			PasswordText->Visible = false;
			HintText->Visible = false;
			TypeUser = 1;
		}
		else if (radioButton->Name == "AdminRadio")
		{
			TypeUser = 2;
			PasswordText->Visible = true;
			HintText->Visible = true;
		}
	}
	private: System::Void AuthButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (TypeUser == 1 || TypeUser == 2 && PasswordText->Text == Password)
		{
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
		}
	}
	};
}
