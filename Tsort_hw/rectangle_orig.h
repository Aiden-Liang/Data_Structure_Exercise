#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
using namespace std;
class rect {
private:
          int nArea;
          int nLength;          
          int nWidth;
public:
          // constructor               
          rect::rect(int width = 0, int length = 0):
		  nWidth(width),nLength(length),nArea(length*width){}

          void calcArea() { nArea = nLength * nWidth; }                
		  void output() { cout << nArea << " ";}
          bool operator<(const rect& r1) const {
               return nArea < r1.nArea;
              }
		  friend ostream&operator << (ostream&, rect);
};

#endif

ostream &operator<<(ostream&os, rect x){
    os<<"(Width, Height, Area)="<<"("<< x.nWidth <<", "<< x.nLength <<", "<< x.nArea<< ")"<<endl;
    return(os);
}

template <class KeyType>
void sort(KeyType *a, int n)
 //sort the n KeyTypes a[0] to a[n-1] into nondecreasing order
{
 for (int i=0;i<n;i++)
  {
     int j=i; 
     // find smallest KeyType in a[i] to a[n-1]
     for (int k=i+1;k<n;k++)
     if (a[k]<a[j])  {  j = k; }
 	//interchange
     KeyType temp=a[i];a[i]=a[j]; a[j]=temp;
  }
};
