#include "complex.h"
#include <math.h>
using namespace std;


//        CONSTRUCTOR
complex::complex(const complex &c)    // call by name
            {
               this->real=c.real;
               this->imag=c.imag;
            }


//         COPY CONSTRUCTOR
complex& complex::operator=(const complex &c)     // �إ� b ����ѳy a ���� call by name
            {
               real=c.real;
               imag=c.imag;
			   return *this;                     
            }


complex complex::operator +(const complex &c)     // �p��Ƽƪ��� a+b call by name
        {
	complex tmp, tmp1 = *this, tmp2(c);           // tmp2(c):tmp �ѳy c ���Ѽ�
	cout << "\n performing C1 + C2 =" << tmp1 << "+" << tmp2 << " =" ;
        tmp.real = this->real + c.real;
        tmp.imag = this->imag + c.imag;
        return tmp;
        }

complex complex::operator -(const complex c)     // �p��Ƽƪ��� a-b call by value
		{
	complex tmp(0,0), tmp1 = *this, tmp2 = c;    // c ��������� tmp2 ���� // tmp(0,0) == tmp
	cout << "\n performing C1 - C2 =" << tmp1 << "-" << tmp2 << " =" ;
/* you have to implement the code  */
		tmp.real = tmp1.real - tmp2.real;
		tmp.imag = tmp1.imag - tmp2.imag;
		return tmp;
		}

complex complex::operator *(const complex c)     // �p��Ƽƪ��� a*b call by value
        {
	complex tmp(0,0), tmp1 = *this, tmp2 = c;    // c ��������� tmp2 ���� // tmp(0,0) == tmp
	cout << "\n performing C1 * C2 =" << tmp1 << "*" << tmp2 << " =" ;
/* you have to implement the code */             
// �Ƽƭ��k: A = (a+bi),B = (c+di), than A*B = (ac-bd) + (bc+ad)i
		tmp.real = (this->real * c.real) - (this->imag * c.imag);
		tmp.imag = (this->imag * c.real) + (this->real * c.imag);
		return tmp;
        }

complex complex::operator /(const complex c)    // �p��Ƽƪ��� a/b call by value
        {
	complex tmp, tmp1 = *this, tmp2 = c;        // c ��������� tmp2 ���� // tmp(0,0) == tmp
	cout << "\n performing C1 / C2 =" << tmp1 << "/" << tmp2 << " =" ;
/* you have to implement the code */
// �Ƽư��k: A = (a+bi),B = (c+di), than A/B = (ac+bd)/(c^2+d^2) + (bc-ad)i/(c^2+d^2)
		tmp.real = (this->real * c.real) + (this->imag * c.imag) / pow(c.real, 2) + pow(c.imag, 2);
		tmp.imag = (this->real * c.real) - (this->imag * c.imag) / pow(c.real, 2) + pow(c.imag, 2);
		return tmp;
		}

complex complex::getconjugate()    // �@�m�Ƽ�
        {
	complex tmp(0,0) ;
	cout << "\n performing C2 = conjugate(C1) =" ;
/* you have to implement the code */
		tmp.imag = this->imag*(-1);      // �p�G��Ƥ��� 0 �h�N��� * (-1)
		tmp.real = this->real;
        return tmp;
        }

complex complex::getreciprocal()  // �˼�: Z = a+bi -> 1/Z = a/[a^2+b^2] - b/[a^2+b^2]i
        {
	// Performing C^(-1)
	complex t(0,0) ;
/* you have to implement the code */
		t.real = this->real / pow(this->real,2) + pow(this->imag,2);   // include <math.h> �I�s pow(x,n) ����禡
		t.imag = this->imag / pow(this->real,2) + pow(this->imag,2);
		return t;
		cout << "\n performing C2 = getreciprocal(C1) =" << t << endl;
        }

float complex::getmodulus()         // �D�ƼƤj�p:square(a^2+b^2)
        {
	complex tmp = *this;
	float z = 0;
	cout << "\n performing getmodulus |C| = " << "| " << tmp << "| = ";
/* you have to implement the code */
	    z = sqrt(pow(this->real,2) + pow(this->imag,2));   // include <math.h> �I�s pow(x,n) ����禡�M sqrt() �}�ڸ��禡
        return z;
        }

void complex::setdata(float r,float i)
            {
               real=r;
               imag=i;
            }

void complex::getdata()
            {
               cout<<"Enter Real:";
               cin>>this->real;
               cout<<"Enter Imaginary:";
               cin>>this->imag;

            }

float complex::getreal()
            {
                 return real;
            }

float complex::getimaginary()
            {
                 return imag;
            }
bool complex::operator ==(const complex & c)         // �غc����ƥ� or �Űƥ�
            {
             return (real==c.real)&&(imag==c.imag) ? 1 : 0;
             }

ostream& operator<<(ostream &s,complex &c)          // ���� << ���s�禡
            {

               s <<" ("<< c.real << setiosflags(ios::showpos)
                 << c.imag << "i"<< ") "<< resetiosflags(ios::showpos);
                 return s;
            }
