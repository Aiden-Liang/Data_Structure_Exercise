#include "rectangle.h"

ostream &operator<<(ostream&os, rect x){
    os<<"(Width, Height, Area)"<<"("<< x.nWidth <<", "<< x.nLength <<", "<< x.nArea<< ")"<<endl;
    return(os);
}