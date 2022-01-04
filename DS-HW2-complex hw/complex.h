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
	   // 翴琌﹚竡ㄧΑ妮玡ン耴妮ㄢ翴玥ㄧ计﹍
	   {}
          complex(const complex&);
          complex operator +(const complex&);
          complex operator -(const complex);
          complex operator *(const complex);
          complex operator /(const complex);
          complex getconjugate();              // ―砿狡计
          complex getreciprocal();             // ―计
          float getmodulus();                  // ―狡计:square(a^2+b^2)
          void setdata(float,float);           // 砞﹚把计
          void getdata();                      // 眔把计
          float getreal();                     // 龟计场だ
          float getimaginary();                // 店计场だ
          bool operator ==(const complex&);    // ゑ耕ㄢ琌妓bool:if yes return 1if no return 0
          complex& operator =(const complex&);
          friend ostream & operator<<(ostream &s,complex &c);    // outputstream摸 cout 
};


