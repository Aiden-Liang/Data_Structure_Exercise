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

		  void calcArea() { nArea = nLength * nWidth; }			// 計算長方形面積               
//        You have to finish the a[k]<a[j] function that will return 1 or 0 
//        for rectangle object comparisions.  

		  bool operator<(rect& b)   // 傳入值為 rect& b::(rect class 位址型態的 b)
		  {
			  this->calcArea();
			  b.calcArea();
			  if (this->nArea < b.nArea)
				  return true;      // 1
			  else return false;    // 0
		  }
//        ...........
		  friend ostream&operator << (ostream&, rect);
};

#endif

ostream &operator<<(ostream&os, rect x){
    os<<"(Width, Height, Area)="<<"("<< x.nWidth <<", "<< x.nLength <<", "<< x.nArea<< ")"<<endl;
    return(os);
}

// you have to finish the Template sorting function
// by your self. This program can be found from the lecture notes

template <class KeyType>
void sort(KeyType *a, int n)
//sort the n KeyTypes a[0] to a[n-1] into nondecreasing order
{	
	// Do it by your self
	for (int i = 0; i < n; i++) 
	{
		int j = i;
		for (int k=i+1; k<n; k++)
		if (a[k] < a[j]) {j = k;}
		// interchange
		KeyType temp = a[i]; a[i] = a[j]; a[j] = temp;	
	}
} 