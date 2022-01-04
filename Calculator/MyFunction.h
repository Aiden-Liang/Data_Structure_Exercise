#include <queue>
using namespace std;

enum {
	Operator_Plus,
	Operator_Minus,
	Operator_Product,
	Operator_Division,
	Operator_Left_Parenthesis,
	Operator_Right_Parenthesis,
	Operator_Dot,
};

enum ElementType {
	Element_Operator,
	Element_Operand,
};

class MyFunction
{
private:
	class Element;

public:
	MyFunction(void);

private:
	queue<char> m_func;

public:
	double PostfixAlgorithm();
	void Add(char c);
	bool Delete();

private:
	queue<Element> InfixFunction();

private:
	class Element
	{
	private:
		double m_value;
		bool m_isOperator;
		int m_priority;

	public:
		Element(double value, int priority, ElementType type)
		{
			m_value = value;
			m_priority = priority;
			m_isOperator = type == Element_Operator;
		}

		~Element() {}

		bool IsOperator() { return m_isOperator; }

		int GetPriority() { return m_priority; }

		double GetValue() { return m_value; }

		Element* operator +(const double& value)
		{
			this->m_value += value;
			return this;
		}

		Element* operator +(const Element& value)
		{
			this->m_value += value.m_value;
			return this;
		}

		Element* operator -(const double& value)
		{
			this->m_value -= value;
			return this;
		}

		Element* operator -(const Element& value)
		{
			this->m_value -= value.m_value;
			return this;
		}

		Element* operator *(const double& value)
		{
			this->m_value *= value;
			return this;
		}

		Element* operator *(const Element& value)
		{
			this->m_value *= value.m_value;
			return this;
		}

		Element* operator /(const double& value)
		{
			this->m_value /= value;
			return this;
		}

		Element* operator /(const Element& value)
		{
			this->m_value /= value.m_value;
			return this;
		}

	};
};
