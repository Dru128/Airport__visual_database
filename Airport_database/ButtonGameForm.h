#pragma once
#include <time.h>


namespace Airportdatabase {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ButtonGameForm
	/// </summary>
	public ref class ButtonGameForm : public System::Windows::Forms::Form
	{
	public:
		ButtonGameForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			randomizer = gcnew Random();
			initGame();

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ButtonGameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  PlayerButton;
	protected:
		const int winScore = 100;
		const int loseScore = -100;
		int startHeight;
		int startWidth;
		int score;	
		Random ^randomizer;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ButtonGameForm::typeid));
			this->PlayerButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// PlayerButton
			// 
			this->PlayerButton->Location = System::Drawing::Point(320, 310);
			this->PlayerButton->Name = L"PlayerButton";
			this->PlayerButton->Size = System::Drawing::Size(75, 23);
			this->PlayerButton->TabIndex = 0;
			this->PlayerButton->UseVisualStyleBackColor = false;
			this->PlayerButton->Click += gcnew System::EventHandler(this, &ButtonGameForm::PlayerButton_Click);
			// 
			// ButtonGameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 861);
			this->Controls->Add(this->PlayerButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ButtonGameForm";
			this->Text = L"Tap button!";
			this->Click += gcnew System::EventHandler(this, &ButtonGameForm::Playerlayout_Click);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ButtonGameForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void PlayerButton_Click(System::Object^  sender, System::EventArgs^  e) {
		score += 3;
		this->BackColor = System::Drawing::Color::Green;
		gameTap();
	}

	private: System::Void Playerlayout_Click(System::Object^  sender, System::EventArgs^  e) {
		score -= 10;
		this->BackColor = System::Drawing::Color::Red;
		gameTap();
	}

	private: void gameTap()
	{
		if (score <= loseScore)
			endGameDialog(0);
		else if (score >= winScore)
			endGameDialog(1);

		PlayerButton->Size = System::Drawing::Size(startHeight - score, startWidth - score);
		PlayerButton->Location = Point(
			randomizer->Next(this->Size.Width * 0.1, this->Size.Width * 0.9 - PlayerButton->Size.Width),
			randomizer->Next(this->Size.Height * 0.1, this->Size.Height * 0.9 - PlayerButton->Size.Height)
		);

		this->Text = "Tap button! Score:" + Convert::ToString(score);

		PlayerButton->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(randomizer->Next(0, 255))),
			static_cast<System::Int32>(static_cast<System::Byte>(randomizer->Next(0, 255))),
			static_cast<System::Int32>(static_cast<System::Byte>(randomizer->Next(0, 255)))
		);
	}


	void endGameDialog(int isWin)
	{
		String^ text;
		if (isWin) text = "Поздравляем! Вы выиграли :D";
		else text = "Вы проиграли :(";

		if (
			MessageBox::Show(
				"Играть ещё?",
				text,
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question
			) == System::Windows::Forms::DialogResult::No
			)
			this->Close();
		else
			initGame();

	}

	void initGame()
	{
		score = 0;
		startHeight = this->Size.Height / 5;
		startWidth = this->Size.Width / 5;
		PlayerButton->Size = System::Drawing::Size(startHeight, startWidth);
		this->BackColor = System::Drawing::Color::Green;
		PlayerButton->BackColor = System::Drawing::Color::Gray;
	}

	};
}
