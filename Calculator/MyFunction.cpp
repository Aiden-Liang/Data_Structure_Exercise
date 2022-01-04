#include <stdafx.h>
#include <stdio.h>
#include "MyFunction.h"
#include <stack>
#include <queue>
using namespace std;

MyFunction::MyFunction()
{
	while (!m_func.empty()) m_func.pop();
}

void MyFunction::Add(char c)
{
	m_func.push(c);
}

bool MyFunction::Delete()
{
	if (m_func.size() <= 0)
		return false;

	int last = m_func.size() - 1;
	for (int i = 0; i <= last; i++)
	{
		char c = m_func.front();
		m_func.pop();
		if (i != last)
			m_func.push(c);
	}

	return m_func.size() > 0;
}


// ********************************************************************** //
// 由使用者打印在 Function Textbox 後轉成 InfixFunction
queue<MyFunction::Element> MyFunction::InfixFunction() 
{
	queue<Element> infix;
	infix.push(Element(0, -1, Element_Operand));
	while (m_func.size() > 0)
	{
		char a = m_func.front();
		m_func.pop();    // m_func 是 MyFunction class 底下的 Queue

		// 檢查 運算元 還是 運算子？
		if (a == '+')       infix.push(Element(Operator_Plus, 1, Element_Operator));      // Element(double value, int priority, ElementType type)
		else if (a == '-')  infix.push(Element(Operator_Minus, 1, Element_Operator));     // 放置佇列裡面 (符號，優先權，型態(運算元還是運算子))
		else if (a == 'x')  infix.push(Element(Operator_Product, 2, Element_Operator));   // 佇列特性：先進先出
		else if (a == '/')  infix.push(Element(Operator_Division, 2, Element_Operator));

		else if (a == '(')  infix.push(Element(Operator_Left_Parenthesis, 8, Element_Operator));
		else if (a == ')')  infix.push(Element(Operator_Right_Parenthesis, 7, Element_Operator));

		else if (a == '%') infix.back() * 0.01 ;
		else if (a == '^') infix.back() * infix.back() ;
		else if (a == 'p') infix.back() * 3.14 ;
		else if (a == 'i') infix.back() ;
		else
		{	
			if (!infix.back().IsOperator())   //檢查運算元的下一碼是否為運算元，若是即乘10倍再加上一碼，直到碰到運算子
			{
				infix.back() * 10;
				infix.back() + atof(&a);
			}
			// 如果 infix.back () == 運算子，則下一個進來 infix 的一定是數字，故 Priority() = -1，Element_Operand = 運算元
			else infix.push(Element(atof(&a), -1, Element_Operand));
		}
	}
	return infix;
}

double MyFunction::PostfixAlgorithm()
{
	queue<Element> infix = InfixFunction(); // 解構所有輸入的運算元與運算子，放在infix佇列中

	queue<Element> postfix;   // 後序結果存放處：佇列(先進先出)
	stack<Element> stk;       // 後序具備「運算子」存放處：堆疊(先進後出)

	//Infix to Postfix 中序轉後序      1+2*3+4  =>  12+34+*   Priority: +-:1  */:2
	while (infix.size() > 0)
	{
		Element e = infix.front();     // 將 infix Queue 的 front 用變數 e 存取
		infix.pop();                   // 存取後將 front 丟棄

		if (e.IsOperator()) 
		{  //e 是即將被處理的運算子(運算符號)
			do 
			{
				if(!stk.empty()) 
				{  //堆疊中尚有運算子
					if (e.GetPriority() <= stk.top().GetPriority()) // 新來的運算子優先權小於(<)堆疊內的
					{  
						if (stk.top().GetPriority() == 8) 
						{    // 如果運算子 == '('
							stk.push(e);
							break;
						}
						
						else 
						{
							postfix.push(stk.top());
							stk.pop(); 
						}
						if(stk.empty()) 
						{
							stk.push(e);
							break;
						}
						else continue;
					}
				    else    // // 新來的運算子優先權大於(>)堆疊內的
					{
						stk.push(e);

						while (stk.top().GetPriority() == 7) 
						{    // 如果運算子 == '('
							stk.pop();          // pop ')'
							do 
							{ 
								postfix.push(stk.top());
								stk.pop();
							} while (stk.top().GetPriority() < 8);
							stk.pop();         // pop '('
						}
						break;
					}
				}
				else {  // stk is empty() initial
					stk.push(e);
					break;
				}
				

			} while (!stk.empty());
		}
	    else postfix.push(e);   // 如果 e 是數字直接丟到 postfix
	}


	// 清空 Stack
	while (!stk.empty())
	{
		postfix.push(stk.top());
		stk.pop();
	}

	//Calculate Postfix Function  後序計算：後序轉換完成後，除了第一元素外的運算元皆配合運算子(加減乘除)到第一元素去運算
	while (!postfix.empty())
	{
		Element e = postfix.front();
		postfix.pop();

		if (e.IsOperator())   //在postfix佇列中遇到運算子
		{
			Element n = stk.top();
			stk.pop();   //因為stk.top把堆疊最上端放在變數n當中，故從stack中提取一數字元素

			switch ((int)e.GetValue())
			{
			case Operator_Plus:     stk.top() + n; break;
			case Operator_Minus:    stk.top() - n; break;
			case Operator_Product:  stk.top() * n; break;
			case Operator_Division: stk.top() / n; break;
			}
		}
		else stk.push(e);    //在postfix佇列中遇到運算元，把數字放入stack中
	}

	return stk.top().GetValue();
}