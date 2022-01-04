#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "ChainIterator.h"
#include <iostream>
#include <ostream>

using namespace std;

struct Term // all members of Term are public by default
{	int coef;	//coefficient
	int exp;	// exponential lorder
	Term Set(int c,int e){coef=c;exp=e; return *this;};

};

class Polynomial {
	Polynomial operator+(const Polynomial&) const;
	Polynomial operator*(const Polynomial&) const;
private:
	Chain <Term> poly;
};


Polynomial Polynomial::operator+(const Polynomial& b) const
{  // 相加多項式 *this（a）與b並且回傳它們的和
	Term temp;
	ChainIterator <Term> ai(poly), bi(b.poly);
	Polynomial c;
	while (ai.current && bi.current) { // 目前的節點不是空的
		if (ai->exp == bi->exp) {
			int sum = ai->coef + bi->coef;
			if (sum) c.poly.InsertBack(temp.Set(sum, ai->exp));
			ai++; bi++; // 前進至下一個項目
		}
		else if (ai->exp < bi->exp) {
			c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
			bi++; // b的下一個項目
		}
		else {
			c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
			ai++; // a的下一個項目
		}
	}
	while (ai.current) { // 複製a剩下的部份
		c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
		ai++;
	}
	while (bi.current) { // 複製b剩下的部份
		c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
		bi++;
	}
	return c;
};


Polynomial Polynomial::operator*(const Polynomial& b) const
{// 相乘多項式 *this（a）與b並且回傳它們的和
	return b;
};

#endif