#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "ChainIterator.h"
#include <iostream>
#include <ostream>

using namespace std;

struct Term // all members of Term are public by default
{
	int coef;	//coefficient
	int exp;	// exponential lorder
	Term Set(int c, int e) { coef = c; exp = e; return *this; };

};

class Polynomial {
	friend ostream &operator<<(ostream &, Polynomial &);
public:
	Polynomial operator+(const Polynomial&) const;
	Polynomial operator*(const Polynomial&) const;
public:
	Chain <Term> poly;
};

Polynomial Polynomial::operator+(const Polynomial& b) const
{   
	// 相加多項式 *this（a）與b並且回傳它們的和
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
{	// 相乘多項式 *this（a）與b並且回傳它們的和
	Term temp;
	Polynomial c , d;
	ChainIterator <Term> ai(this->poly), bi(b.poly), b_first(b.poly);
	ChainIterator <Term> ci(c.poly), c_tmp(c.poly), di(c.poly), d_first(c.poly);;

	while (ai.current) {
		while (bi.current) {
			int new_coef = ai->coef * bi->coef;
			int new_exp = ai->exp + bi->exp;
			c.poly.InsertBack(temp.Set(new_coef, new_exp));
			bi++;
		}
		bi.current = b_first.current;
		ai++;
		continue;
	}

	while (ci.current) {
		c_tmp++;
		while (c_tmp.current) {
			if (c_tmp->exp == ci->exp) {
				ci->coef = ci->coef + c_tmp->coef;
				c_tmp.current = c_tmp.current - 1;
				c_tmp.Jump();
				c_tmp.current = c_tmp.current + 1;
				delete c_tmp.current;
				c_tmp++;
			}
			else c_tmp++;
			continue;
		}
		ci++;
		c_tmp.current = ci.current;
		continue;
	}
	
	return c;
};


ostream & operator<<(ostream &out, Polynomial &p) {
	ChainIterator <Term> ct(p.poly);
	out << endl<<"(";
	while (ct.NextNotNull())
	{
		out << ct->coef << "x^" << ct->exp << " + " ;
		ct++;
	}
	out << ct->coef << "x^" << ct->exp <<")";
	return out;
};

#endif
