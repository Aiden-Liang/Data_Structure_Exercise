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
// �ѨϥΪ̥��L�b Function Textbox ���ন InfixFunction
queue<MyFunction::Element> MyFunction::InfixFunction() 
{
	queue<Element> infix;
	infix.push(Element(0, -1, Element_Operand));
	while (m_func.size() > 0)
	{
		char a = m_func.front();
		m_func.pop();    // m_func �O MyFunction class ���U�� Queue

		// �ˬd �B�⤸ �٬O �B��l�H
		if (a == '+')       infix.push(Element(Operator_Plus, 1, Element_Operator));      // Element(double value, int priority, ElementType type)
		else if (a == '-')  infix.push(Element(Operator_Minus, 1, Element_Operator));     // ��m��C�̭� (�Ÿ��A�u���v�A���A(�B�⤸�٬O�B��l))
		else if (a == 'x')  infix.push(Element(Operator_Product, 2, Element_Operator));   // ��C�S�ʡG���i���X
		else if (a == '/')  infix.push(Element(Operator_Division, 2, Element_Operator));

		else if (a == '(')  infix.push(Element(Operator_Left_Parenthesis, 8, Element_Operator));
		else if (a == ')')  infix.push(Element(Operator_Right_Parenthesis, 7, Element_Operator));

		else if (a == '%') infix.back() * 0.01 ;
		else if (a == '^') infix.back() * infix.back() ;
		else if (a == 'p') infix.back() * 3.14 ;
		else if (a == 'i') infix.back() ;
		else
		{	
			if (!infix.back().IsOperator())   //�ˬd�B�⤸���U�@�X�O�_���B�⤸�A�Y�O�Y��10���A�[�W�@�X�A����I��B��l
			{
				infix.back() * 10;
				infix.back() + atof(&a);
			}
			// �p�G infix.back () == �B��l�A�h�U�@�Ӷi�� infix ���@�w�O�Ʀr�A�G Priority() = -1�AElement_Operand = �B�⤸
			else infix.push(Element(atof(&a), -1, Element_Operand));
		}
	}
	return infix;
}

double MyFunction::PostfixAlgorithm()
{
	queue<Element> infix = InfixFunction(); // �Ѻc�Ҧ���J���B�⤸�P�B��l�A��binfix��C��

	queue<Element> postfix;   // ��ǵ��G�s��B�G��C(���i���X)
	stack<Element> stk;       // ��Ǩ�ơu�B��l�v�s��B�G���|(���i��X)

	//Infix to Postfix ��������      1+2*3+4  =>  12+34+*   Priority: +-:1  */:2
	while (infix.size() > 0)
	{
		Element e = infix.front();     // �N infix Queue �� front ���ܼ� e �s��
		infix.pop();                   // �s����N front ���

		if (e.IsOperator()) 
		{  //e �O�Y�N�Q�B�z���B��l(�B��Ÿ�)
			do 
			{
				if(!stk.empty()) 
				{  //���|���|���B��l
					if (e.GetPriority() <= stk.top().GetPriority()) // �s�Ӫ��B��l�u���v�p��(<)���|����
					{  
						if (stk.top().GetPriority() == 8) 
						{    // �p�G�B��l == '('
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
				    else    // // �s�Ӫ��B��l�u���v�j��(>)���|����
					{
						stk.push(e);

						while (stk.top().GetPriority() == 7) 
						{    // �p�G�B��l == '('
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
	    else postfix.push(e);   // �p�G e �O�Ʀr������� postfix
	}


	// �M�� Stack
	while (!stk.empty())
	{
		postfix.push(stk.top());
		stk.pop();
	}

	//Calculate Postfix Function  ��ǭp��G����ഫ������A���F�Ĥ@�����~���B�⤸�Ұt�X�B��l(�[���)��Ĥ@�����h�B��
	while (!postfix.empty())
	{
		Element e = postfix.front();
		postfix.pop();

		if (e.IsOperator())   //�bpostfix��C���J��B��l
		{
			Element n = stk.top();
			stk.pop();   //�]��stk.top����|�̤W�ݩ�b�ܼ�n���A�G�qstack�������@�Ʀr����

			switch ((int)e.GetValue())
			{
			case Operator_Plus:     stk.top() + n; break;
			case Operator_Minus:    stk.top() - n; break;
			case Operator_Product:  stk.top() * n; break;
			case Operator_Division: stk.top() / n; break;
			}
		}
		else stk.push(e);    //�bpostfix��C���J��B�⤸�A��Ʀr��Jstack��
	}

	return stk.top().GetValue();
}