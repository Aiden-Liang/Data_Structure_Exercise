#include "complex.h" 
#include <math.h>
using namespace std;

int main()
{
	complex a(10.0f, -2.f); // Calls Constructor
 	cout << "a =" << a << endl;               // Calls the overloaded << operator
	complex b(-2);         // Calls Constructor
	complex c = a;                    // Calls Copy Constructor
	c = a;                          // calls overloaded = operator
	b.getdata();                    // Calls Getdata()
	c.getdata();
	cout << "b =" << b << endl;
	cout << "c =" << c << endl;

	if (b == c)            // calls overloaded == operator
		cout << "b == c";
	else
		cout << "b != c";

    c = a;
	cout << c.getconjugate() << endl;      // calls getconjugate() function
	cout << c.getmodulus() << endl; // calls the getmodulus() function
	cout << " Performing C*C^(-1) = " << c * c.getreciprocal() << endl; // calls the receiprocal() function
																		
	// ok

	cout << a + b << endl;     // Calls overloaded + and <<
	cout << a - b << endl;     // Calls overloaded -  and << 
	cout << a * b << endl;     // calls overloaded *  and << 
	cout << a / b << endl;     // calls overloaded / and <<
	cout << (a + b)*(a - b) / c << endl;  // combine + - * / operations
	getchar();
	return 0;
}