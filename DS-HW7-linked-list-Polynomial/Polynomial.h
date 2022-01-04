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
{  // �ۥ[�h���� *this�]a�^�Pb�åB�^�ǥ��̪��M
	Term temp;
	ChainIterator <Term> ai(poly), bi(b.poly);
	Polynomial c;
	while (ai.current && bi.current) { // �ثe���`�I���O�Ū�
		if (ai->exp == bi->exp) {
			int sum = ai->coef + bi->coef;
			if (sum) c.poly.InsertBack(temp.Set(sum, ai->exp));
			ai++; bi++; // �e�i�ܤU�@�Ӷ���
		}
		else if (ai->exp < bi->exp) {
			c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
			bi++; // b���U�@�Ӷ���
		}
		else {
			c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
			ai++; // a���U�@�Ӷ���
		}
	}
	while (ai.current) { // �ƻsa�ѤU������
		c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
		ai++;
	}
	while (bi.current) { // �ƻsb�ѤU������
		c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
		bi++;
	}
	return c;
};


Polynomial Polynomial::operator*(const Polynomial& b) const
{// �ۭ��h���� *this�]a�^�Pb�åB�^�ǥ��̪��M
	return b;
};

#endif