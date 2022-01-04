#pragma once
#include <string>
#include "MyFunction.h"
#include "stdafx.h"

#define _USE_MATH_DEFINES 
#include <math.h>
using namespace std;

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
			Function_Index=0;
			f = new MyFunction();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_Num_0;
	protected: 

	private: System::Windows::Forms::Button^  button_operator_equ;
	private: System::Windows::Forms::Button^  button_Num_1;
	private: System::Windows::Forms::Button^  button_Num_2;
	private: System::Windows::Forms::Button^  button_Num_3;
	private: System::Windows::Forms::Button^  button_operator_plus;
	private: System::Windows::Forms::Button^  button_operator_minus;
	private: System::Windows::Forms::Button^  button_Num_4;
	private: System::Windows::Forms::Button^  button_Num_5;
	private: System::Windows::Forms::Button^  button_Num_6;
	private: System::Windows::Forms::Button^  button_operator_product;
	private: System::Windows::Forms::Button^  button_operator_divide;
	private: System::Windows::Forms::Button^  button_Num_7;
	private: System::Windows::Forms::Button^  button_Num_8;
	private: System::Windows::Forms::Button^  button_Num_9;
	private: System::Windows::Forms::Button^  button_instr_delete;
	private: System::Windows::Forms::Button^  button_instr_allclear;
	private: System::Windows::Forms::TextBox^  textBox_function;
	private: System::Windows::Forms::Label^  label_function;
	private: System::Windows::Forms::TextBox^  textBox_answer;

	private: System::Windows::Forms::Label^  label_answer;
	private: System::Windows::Forms::Button^  button_Left_Parentheses;
	private: System::Windows::Forms::Button^  button_Right_Parentheses;
	private: System::Windows::Forms::Button^  button_Left_Shift;
	private: System::Windows::Forms::Button^  button_Right_Shift;
	private: System::Windows::Forms::Button^  button_Percent;


	private: System::Windows::Forms::Button^  button_Square;
	private: System::Windows::Forms::Button^  button_PI;





	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_Num_0 = (gcnew System::Windows::Forms::Button());
			this->button_operator_equ = (gcnew System::Windows::Forms::Button());
			this->button_Num_1 = (gcnew System::Windows::Forms::Button());
			this->button_Num_2 = (gcnew System::Windows::Forms::Button());
			this->button_Num_3 = (gcnew System::Windows::Forms::Button());
			this->button_operator_plus = (gcnew System::Windows::Forms::Button());
			this->button_operator_minus = (gcnew System::Windows::Forms::Button());
			this->button_Num_4 = (gcnew System::Windows::Forms::Button());
			this->button_Num_5 = (gcnew System::Windows::Forms::Button());
			this->button_Num_6 = (gcnew System::Windows::Forms::Button());
			this->button_operator_product = (gcnew System::Windows::Forms::Button());
			this->button_operator_divide = (gcnew System::Windows::Forms::Button());
			this->button_Num_7 = (gcnew System::Windows::Forms::Button());
			this->button_Num_8 = (gcnew System::Windows::Forms::Button());
			this->button_Num_9 = (gcnew System::Windows::Forms::Button());
			this->button_instr_delete = (gcnew System::Windows::Forms::Button());
			this->button_instr_allclear = (gcnew System::Windows::Forms::Button());
			this->textBox_function = (gcnew System::Windows::Forms::TextBox());
			this->label_function = (gcnew System::Windows::Forms::Label());
			this->textBox_answer = (gcnew System::Windows::Forms::TextBox());
			this->label_answer = (gcnew System::Windows::Forms::Label());
			this->button_Left_Parentheses = (gcnew System::Windows::Forms::Button());
			this->button_Right_Parentheses = (gcnew System::Windows::Forms::Button());
			this->button_Left_Shift = (gcnew System::Windows::Forms::Button());
			this->button_Right_Shift = (gcnew System::Windows::Forms::Button());
			this->button_Percent = (gcnew System::Windows::Forms::Button());
			this->button_Square = (gcnew System::Windows::Forms::Button());
			this->button_PI = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_Num_0
			// 
			this->button_Num_0->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Num_0->Location = System::Drawing::Point(131, 459);
			this->button_Num_0->Margin = System::Windows::Forms::Padding(4);
			this->button_Num_0->Name = L"button_Num_0";
			this->button_Num_0->Size = System::Drawing::Size(87, 50);
			this->button_Num_0->TabIndex = 0;
			this->button_Num_0->Text = L"0";
			this->button_Num_0->UseVisualStyleBackColor = true;
			this->button_Num_0->Click += gcnew System::EventHandler(this, &Form1::button_Num_0_Click);
			// 
			// button_operator_equ
			// 
			this->button_operator_equ->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_operator_equ->Location = System::Drawing::Point(473, 458);
			this->button_operator_equ->Margin = System::Windows::Forms::Padding(4);
			this->button_operator_equ->Name = L"button_operator_equ";
			this->button_operator_equ->Size = System::Drawing::Size(87, 50);
			this->button_operator_equ->TabIndex = 4;
			this->button_operator_equ->Text = L"=";
			this->button_operator_equ->UseVisualStyleBackColor = true;
			this->button_operator_equ->Click += gcnew System::EventHandler(this, &Form1::button_operator_equ_Click);
			// 
			// button_Num_1
			// 
			this->button_Num_1->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Num_1->Location = System::Drawing::Point(16, 386);
			this->button_Num_1->Margin = System::Windows::Forms::Padding(4);
			this->button_Num_1->Name = L"button_Num_1";
			this->button_Num_1->Size = System::Drawing::Size(87, 50);
			this->button_Num_1->TabIndex = 5;
			this->button_Num_1->Text = L"1";
			this->button_Num_1->UseVisualStyleBackColor = true;
			this->button_Num_1->Click += gcnew System::EventHandler(this, &Form1::button_Num_1_Click);
			// 
			// button_Num_2
			// 
			this->button_Num_2->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Num_2->Location = System::Drawing::Point(131, 386);
			this->button_Num_2->Margin = System::Windows::Forms::Padding(4);
			this->button_Num_2->Name = L"button_Num_2";
			this->button_Num_2->Size = System::Drawing::Size(87, 50);
			this->button_Num_2->TabIndex = 6;
			this->button_Num_2->Text = L"2";
			this->button_Num_2->UseVisualStyleBackColor = true;
			this->button_Num_2->Click += gcnew System::EventHandler(this, &Form1::button_Num_2_Click);
			// 
			// button_Num_3
			// 
			this->button_Num_3->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Num_3->Location = System::Drawing::Point(245, 386);
			this->button_Num_3->Margin = System::Windows::Forms::Padding(4);
			this->button_Num_3->Name = L"button_Num_3";
			this->button_Num_3->Size = System::Drawing::Size(87, 50);
			this->button_Num_3->TabIndex = 7;
			this->button_Num_3->Text = L"3";
			this->button_Num_3->UseVisualStyleBackColor = true;
			this->button_Num_3->Click += gcnew System::EventHandler(this, &Form1::button_Num_3_Click);
			// 
			// button_operator_plus
			// 
			this->button_operator_plus->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_operator_plus->Location = System::Drawing::Point(360, 386);
			this->button_operator_plus->Margin = System::Windows::Forms::Padding(4);
			this->button_operator_plus->Name = L"button_operator_plus";
			this->button_operator_plus->Size = System::Drawing::Size(87, 50);
			this->button_operator_plus->TabIndex = 8;
			this->button_operator_plus->Text = L"+";
			this->button_operator_plus->UseVisualStyleBackColor = true;
			this->button_operator_plus->Click += gcnew System::EventHandler(this, &Form1::button_operator_plus_Click);
			// 
			// button_operator_minus
			// 
			this->button_operator_minus->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_operator_minus->Location = System::Drawing::Point(473, 386);
			this->button_operator_minus->Margin = System::Windows::Forms::Padding(4);
			this->button_operator_minus->Name = L"button_operator_minus";
			this->button_operator_minus->Size = System::Drawing::Size(87, 50);
			this->button_operator_minus->TabIndex = 9;
			this->button_operator_minus->Text = L"-";
			this->button_operator_minus->UseVisualStyleBackColor = true;
			this->button_operator_minus->Click += gcnew System::EventHandler(this, &Form1::button_operator_minus_Click);
			// 
			// button_Num_4
			// 
			this->button_Num_4->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Num_4->Location = System::Drawing::Point(16, 313);
			this->button_Num_4->Margin = System::Windows::Forms::Padding(4);
			this->button_Num_4->Name = L"button_Num_4";
			this->button_Num_4->Size = System::Drawing::Size(87, 50);
			this->button_Num_4->TabIndex = 10;
			this->button_Num_4->Text = L"4";
			this->button_Num_4->UseVisualStyleBackColor = true;
			this->button_Num_4->Click += gcnew System::EventHandler(this, &Form1::button_Num_4_Click);
			// 
			// button_Num_5
			// 
			this->button_Num_5->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Num_5->Location = System::Drawing::Point(131, 313);
			this->button_Num_5->Margin = System::Windows::Forms::Padding(4);
			this->button_Num_5->Name = L"button_Num_5";
			this->button_Num_5->Size = System::Drawing::Size(87, 50);
			this->button_Num_5->TabIndex = 11;
			this->button_Num_5->Text = L"5";
			this->button_Num_5->UseVisualStyleBackColor = true;
			this->button_Num_5->Click += gcnew System::EventHandler(this, &Form1::button_Num_5_Click);
			// 
			// button_Num_6
			// 
			this->button_Num_6->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Num_6->Location = System::Drawing::Point(245, 313);
			this->button_Num_6->Margin = System::Windows::Forms::Padding(4);
			this->button_Num_6->Name = L"button_Num_6";
			this->button_Num_6->Size = System::Drawing::Size(87, 50);
			this->button_Num_6->TabIndex = 12;
			this->button_Num_6->Text = L"6";
			this->button_Num_6->UseVisualStyleBackColor = true;
			this->button_Num_6->Click += gcnew System::EventHandler(this, &Form1::button_Num_6_Click);
			// 
			// button_operator_product
			// 
			this->button_operator_product->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_operator_product->Location = System::Drawing::Point(360, 313);
			this->button_operator_product->Margin = System::Windows::Forms::Padding(4);
			this->button_operator_product->Name = L"button_operator_product";
			this->button_operator_product->Size = System::Drawing::Size(87, 50);
			this->button_operator_product->TabIndex = 13;
			this->button_operator_product->Text = L"×";
			this->button_operator_product->UseVisualStyleBackColor = true;
			this->button_operator_product->Click += gcnew System::EventHandler(this, &Form1::button_operator_product_Click);
			// 
			// button_operator_divide
			// 
			this->button_operator_divide->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_operator_divide->Location = System::Drawing::Point(473, 313);
			this->button_operator_divide->Margin = System::Windows::Forms::Padding(4);
			this->button_operator_divide->Name = L"button_operator_divide";
			this->button_operator_divide->Size = System::Drawing::Size(87, 50);
			this->button_operator_divide->TabIndex = 14;
			this->button_operator_divide->Text = L"÷";
			this->button_operator_divide->UseVisualStyleBackColor = true;
			this->button_operator_divide->Click += gcnew System::EventHandler(this, &Form1::button_operator_divide_Click);
			// 
			// button_Num_7
			// 
			this->button_Num_7->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Num_7->Location = System::Drawing::Point(16, 242);
			this->button_Num_7->Margin = System::Windows::Forms::Padding(4);
			this->button_Num_7->Name = L"button_Num_7";
			this->button_Num_7->Size = System::Drawing::Size(87, 50);
			this->button_Num_7->TabIndex = 15;
			this->button_Num_7->Text = L"7";
			this->button_Num_7->UseVisualStyleBackColor = true;
			this->button_Num_7->Click += gcnew System::EventHandler(this, &Form1::button_Num_7_Click);
			// 
			// button_Num_8
			// 
			this->button_Num_8->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Num_8->Location = System::Drawing::Point(131, 242);
			this->button_Num_8->Margin = System::Windows::Forms::Padding(4);
			this->button_Num_8->Name = L"button_Num_8";
			this->button_Num_8->Size = System::Drawing::Size(87, 50);
			this->button_Num_8->TabIndex = 16;
			this->button_Num_8->Text = L"8";
			this->button_Num_8->UseVisualStyleBackColor = true;
			this->button_Num_8->Click += gcnew System::EventHandler(this, &Form1::button_Num_8_Click);
			// 
			// button_Num_9
			// 
			this->button_Num_9->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Num_9->Location = System::Drawing::Point(245, 242);
			this->button_Num_9->Margin = System::Windows::Forms::Padding(4);
			this->button_Num_9->Name = L"button_Num_9";
			this->button_Num_9->Size = System::Drawing::Size(87, 50);
			this->button_Num_9->TabIndex = 17;
			this->button_Num_9->Text = L"9";
			this->button_Num_9->UseVisualStyleBackColor = true;
			this->button_Num_9->Click += gcnew System::EventHandler(this, &Form1::button_Num_9_Click);
			// 
			// button_instr_delete
			// 
			this->button_instr_delete->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_instr_delete->Location = System::Drawing::Point(360, 242);
			this->button_instr_delete->Margin = System::Windows::Forms::Padding(4);
			this->button_instr_delete->Name = L"button_instr_delete";
			this->button_instr_delete->Size = System::Drawing::Size(87, 50);
			this->button_instr_delete->TabIndex = 18;
			this->button_instr_delete->Text = L"DEL";
			this->button_instr_delete->UseVisualStyleBackColor = true;
			this->button_instr_delete->Click += gcnew System::EventHandler(this, &Form1::button_cmd_delete_Click);
			// 
			// button_instr_allclear
			// 
			this->button_instr_allclear->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_instr_allclear->Location = System::Drawing::Point(473, 242);
			this->button_instr_allclear->Margin = System::Windows::Forms::Padding(4);
			this->button_instr_allclear->Name = L"button_instr_allclear";
			this->button_instr_allclear->Size = System::Drawing::Size(87, 50);
			this->button_instr_allclear->TabIndex = 19;
			this->button_instr_allclear->Text = L"AC";
			this->button_instr_allclear->UseVisualStyleBackColor = true;
			this->button_instr_allclear->Click += gcnew System::EventHandler(this, &Form1::button_cmd_allclear_Click);
			// 
			// textBox_function
			// 
			this->textBox_function->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->textBox_function->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->textBox_function->Location = System::Drawing::Point(16, 39);
			this->textBox_function->Margin = System::Windows::Forms::Padding(4);
			this->textBox_function->Name = L"textBox_function";
			this->textBox_function->ReadOnly = true;
			this->textBox_function->Size = System::Drawing::Size(429, 43);
			this->textBox_function->TabIndex = 20;
			// 
			// label_function
			// 
			this->label_function->AutoSize = true;
			this->label_function->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label_function->Location = System::Drawing::Point(17, 16);
			this->label_function->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_function->Name = L"label_function";
			this->label_function->Size = System::Drawing::Size(73, 20);
			this->label_function->TabIndex = 21;
			this->label_function->Text = L"Function";
			// 
			// textBox_answer
			// 
			this->textBox_answer->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->textBox_answer->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->textBox_answer->Location = System::Drawing::Point(455, 39);
			this->textBox_answer->Margin = System::Windows::Forms::Padding(4);
			this->textBox_answer->Name = L"textBox_answer";
			this->textBox_answer->ReadOnly = true;
			this->textBox_answer->Size = System::Drawing::Size(105, 43);
			this->textBox_answer->TabIndex = 22;
			// 
			// label_answer
			// 
			this->label_answer->AutoSize = true;
			this->label_answer->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label_answer->Location = System::Drawing::Point(456, 11);
			this->label_answer->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_answer->Name = L"label_answer";
			this->label_answer->Size = System::Drawing::Size(67, 20);
			this->label_answer->TabIndex = 23;
			this->label_answer->Text = L"Answer";
			// 
			// button_Left_Parentheses
			// 
			this->button_Left_Parentheses->Font = (gcnew System::Drawing::Font(L"新細明體", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Left_Parentheses->Location = System::Drawing::Point(16, 166);
			this->button_Left_Parentheses->Name = L"button_Left_Parentheses";
			this->button_Left_Parentheses->Size = System::Drawing::Size(87, 50);
			this->button_Left_Parentheses->TabIndex = 24;
			this->button_Left_Parentheses->Text = L"(";
			this->button_Left_Parentheses->UseVisualStyleBackColor = true;
			this->button_Left_Parentheses->Click += gcnew System::EventHandler(this, &Form1::button_Left_Parentheses_Click);
			// 
			// button_Right_Parentheses
			// 
			this->button_Right_Parentheses->Font = (gcnew System::Drawing::Font(L"新細明體", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Right_Parentheses->Location = System::Drawing::Point(131, 166);
			this->button_Right_Parentheses->Name = L"button_Right_Parentheses";
			this->button_Right_Parentheses->Size = System::Drawing::Size(87, 50);
			this->button_Right_Parentheses->TabIndex = 25;
			this->button_Right_Parentheses->Text = L")";
			this->button_Right_Parentheses->UseVisualStyleBackColor = true;
			this->button_Right_Parentheses->Click += gcnew System::EventHandler(this, &Form1::button_Right_Parentheses_Click);
			// 
			// button_Left_Shift
			// 
			this->button_Left_Shift->Font = (gcnew System::Drawing::Font(L"新細明體", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Left_Shift->Location = System::Drawing::Point(245, 166);
			this->button_Left_Shift->Name = L"button_Left_Shift";
			this->button_Left_Shift->Size = System::Drawing::Size(87, 50);
			this->button_Left_Shift->TabIndex = 26;
			this->button_Left_Shift->Text = L"←";
			this->button_Left_Shift->UseVisualStyleBackColor = true;
			this->button_Left_Shift->Click += gcnew System::EventHandler(this, &Form1::button_Left_Shift_Click);
			// 
			// button_Right_Shift
			// 
			this->button_Right_Shift->Font = (gcnew System::Drawing::Font(L"新細明體", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Right_Shift->Location = System::Drawing::Point(360, 166);
			this->button_Right_Shift->Name = L"button_Right_Shift";
			this->button_Right_Shift->Size = System::Drawing::Size(87, 50);
			this->button_Right_Shift->TabIndex = 27;
			this->button_Right_Shift->Text = L"→";
			this->button_Right_Shift->UseVisualStyleBackColor = true;
			this->button_Right_Shift->Click += gcnew System::EventHandler(this, &Form1::button_Right_Shift_Click);
			// 
			// button_Percent
			// 
			this->button_Percent->Font = (gcnew System::Drawing::Font(L"新細明體", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Percent->Location = System::Drawing::Point(360, 459);
			this->button_Percent->Name = L"button_Percent";
			this->button_Percent->Size = System::Drawing::Size(87, 50);
			this->button_Percent->TabIndex = 28;
			this->button_Percent->Text = L"%";
			this->button_Percent->UseVisualStyleBackColor = true;
			this->button_Percent->Click += gcnew System::EventHandler(this, &Form1::button_Percent_Click);
			// 
			// button_Square
			// 
			this->button_Square->Font = (gcnew System::Drawing::Font(L"新細明體", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_Square->Location = System::Drawing::Point(16, 459);
			this->button_Square->Name = L"button_Square";
			this->button_Square->Size = System::Drawing::Size(87, 50);
			this->button_Square->TabIndex = 29;
			this->button_Square->Text = L"x²";
			this->button_Square->UseVisualStyleBackColor = true;
			this->button_Square->Click += gcnew System::EventHandler(this, &Form1::button_Square_Click);
			// 
			// button_PI
			// 
			this->button_PI->Font = (gcnew System::Drawing::Font(L"新細明體", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->button_PI->Location = System::Drawing::Point(245, 459);
			this->button_PI->Name = L"button_PI";
			this->button_PI->Size = System::Drawing::Size(87, 50);
			this->button_PI->TabIndex = 30;
			this->button_PI->Text = L"π";
			this->button_PI->UseVisualStyleBackColor = true;
			this->button_PI->Click += gcnew System::EventHandler(this, &Form1::button_PI_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 564);
			this->Controls->Add(this->button_PI);
			this->Controls->Add(this->button_Square);
			this->Controls->Add(this->button_Percent);
			this->Controls->Add(this->button_Right_Shift);
			this->Controls->Add(this->button_Left_Shift);
			this->Controls->Add(this->button_Right_Parentheses);
			this->Controls->Add(this->button_Left_Parentheses);
			this->Controls->Add(this->label_answer);
			this->Controls->Add(this->textBox_answer);
			this->Controls->Add(this->label_function);
			this->Controls->Add(this->textBox_function);
			this->Controls->Add(this->button_instr_allclear);
			this->Controls->Add(this->button_instr_delete);
			this->Controls->Add(this->button_Num_9);
			this->Controls->Add(this->button_Num_8);
			this->Controls->Add(this->button_Num_7);
			this->Controls->Add(this->button_operator_divide);
			this->Controls->Add(this->button_operator_product);
			this->Controls->Add(this->button_Num_6);
			this->Controls->Add(this->button_Num_5);
			this->Controls->Add(this->button_Num_4);
			this->Controls->Add(this->button_operator_minus);
			this->Controls->Add(this->button_operator_plus);
			this->Controls->Add(this->button_Num_3);
			this->Controls->Add(this->button_Num_2);
			this->Controls->Add(this->button_Num_1);
			this->Controls->Add(this->button_operator_equ);
			this->Controls->Add(this->button_Num_0);
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximumSize = System::Drawing::Size(594, 611);
			this->MinimumSize = System::Drawing::Size(594, 611);
			this->Name = L"Form1";
			this->Text = L"Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		int Function_Index;    //算式索引
		MyFunction* f;         //算式變數

    // ********************************************************************************************************* //
	// 顯示在 Function Textbox 的字串 //
	public: void EditFunction(String^ s)  //編輯要顯示在textbox的算式
			{   
				// 按按鈕顯示字在 Function Textbox 裡然後字串 index +1 儲存下一個按鈕按的字
				this->textBox_function->Text = this->textBox_function->Text->Insert(Function_Index,s);
				Function_Index += s->Length;
				textBox_function->Focus();
				textBox_function->Select(Function_Index,0);

				f->Add((char)s->ToCharArray()[0]);
			}

#pragma region BUTTON_NUMBER   運算元群組
	private: System::Void button_Num_0_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("0");
			 }
	private: System::Void button_Num_1_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("1");
			 }
	private: System::Void button_Num_2_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("2");
			 }
	private: System::Void button_Num_3_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("3");
			 }
	private: System::Void button_Num_4_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("4");
			 }
	private: System::Void button_Num_5_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("5");
			 }
	private: System::Void button_Num_6_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("6");
			 }
	private: System::Void button_Num_7_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("7");
			 }
	private: System::Void button_Num_8_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("8");
			 }
	private: System::Void button_Num_9_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("9");
			 }
#pragma endregion

#pragma region BUTTON_OPERATOR   運算子群組
	private: System::Void button_operator_plus_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("+");
			 }
	private: System::Void button_operator_minus_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("-");
			 }
	private: System::Void button_operator_product_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("x");
			 }
	private: System::Void button_operator_divide_Click(System::Object^  sender, System::EventArgs^  e) {
				 EditFunction("/");
			 }
	private: System::Void button_operator_equ_Click(System::Object^  sender, System::EventArgs^  e) {
				 double answer = f->PostfixAlgorithm();
				 textBox_answer->Text=answer.ToString("0.000");
			 }

#pragma endregion

#pragma region CALCULATOR_COMMAMD  特殊符號群組
	private: System::Void button_cmd_allclear_Click(System::Object^  sender, System::EventArgs^  e) {
				 Function_Index=0;
				 textBox_function->Clear();
				 while(f->Delete());  //跑迴圈直到刪光光
			 }
	private: System::Void button_cmd_delete_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(textBox_function->TextLength>Function_Index-1&&Function_Index>0){
					 textBox_function->Focus();
					 textBox_function->Select(--Function_Index,1);
					 textBox_function->SelectedText="";
					 f->Delete();
				 }
			 }
#pragma endregion

private: System::Void button_Left_Parentheses_Click(System::Object^  sender, System::EventArgs^  e) {
			 EditFunction("(");
		 }
private: System::Void button_Right_Parentheses_Click(System::Object^  sender, System::EventArgs^  e) {
			 EditFunction(")");
		 }
private: System::Void button_Left_Shift_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(textBox_function->TextLength >= Function_Index && Function_Index > 0){
					 textBox_function->Focus();
					 textBox_function->Select(--Function_Index,1);
				 }
		 }
private: System::Void button_Right_Shift_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(textBox_function->TextLength >= Function_Index+1 && Function_Index > 0){
					 textBox_function->Focus();
					 textBox_function->Select(++Function_Index,1);
				 }
		 }
private: System::Void button_Percent_Click(System::Object^  sender, System::EventArgs^  e) {
			 EditFunction("%");
		 }
private: System::Void button_Square_Click(System::Object^  sender, System::EventArgs^  e) {
			 EditFunction("^");
		 }
private: System::Void button_PI_Click(System::Object^  sender, System::EventArgs^  e) {
			 EditFunction("pi");		 
		 }
};

}

