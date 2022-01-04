#include "ChainNode.h"
// #include "Polynomial.h"
#include "Polynomial_test.h"
#include <iostream>
#include <ostream>
using namespace std;


// ****** MAIN  *************

int main() {
	Polynomial p1, p2, p3, p4, p5;
	Term temp;
	for (int i = 7; i > 0; i -= 2) { p1.poly.InsertBack(temp.Set(i, i)); };
	// temp.Set(i, i) : first i is coef, second i is exp
	for (int i = 6; i > 0; i -= 2) { p2.poly.InsertBack(temp.Set(i, i)); };
	cout << "多項式加法 :";
	cout << p1 << " +" << p2 << " =";
	p3 = p1 + p2;
	cout << p3 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "多項式乘法 :";
	cout << p1 << " *" << p2 << " =";
	p4 = p1 * p2;
	cout << p4 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "多項式乘法加法混合 :";
	p5 = p3 + p4;
	cout << p5 << endl;
	cout << "--------------------------------------------------" << endl;

	return 0;
};

