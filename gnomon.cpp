#include "gnomon.h"

Gnomon::Gnomon(long double L,long double Fi,long double H)
{
    OldR=TVector(3);
    OldR[0]=L;
    OldR[1]=Fi;
    OldR[2]=H;
    R0=intoGSK(OldR).norm();
    this->l=H;
    Rg=l*R0;
}


