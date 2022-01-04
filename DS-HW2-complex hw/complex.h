#include <cmath>
#include <iostream>
#include <iomanip>
#include <ostream>
#include <math.h>
using namespace std;

class complex
{
   public:
         float real;      // Real Part
         float imag;      //  Imaginary Part

   public:
 
	   complex::complex(float r=0,float im=0):real(r),imag(im)
	   // �|���I�᭱�O�w�q�禡�ݩ�e�������k�ݡA����I�᭱�h�N���ƪ�l�Ȫ��ŧi
	   {}
          complex(const complex&);
          complex operator +(const complex&);
          complex operator -(const complex);
          complex operator *(const complex);
          complex operator /(const complex);
          complex getconjugate();              // �D�@�m�Ƽ�
          complex getreciprocal();             // �D�˼�
          float getmodulus();                  // �D�ƼƤj�p:square(a^2+b^2)
          void setdata(float,float);           // �]�w�Ѽ�
          void getdata();                      // ���o�Ѽ�
          float getreal();                     // ������Ƴ���
          float getimaginary();                // ������Ƴ���
          bool operator ==(const complex&);    // �����̬O�_�@�ˡAbool:if yes return 1�Aif no return 0
          complex& operator =(const complex&);
          friend ostream & operator<<(ostream &s,complex &c);    // outputstream�A���� cout �\��
};


