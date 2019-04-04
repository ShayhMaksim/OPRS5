#ifndef SUNDIAL_H
#define SUNDIAL_H
#include "model.h"
#include "earthrotation.h"
#include <QVector>
class sundial : public TModel
{
protected:
    //TVector X;

    const double mu_s = 132712.43994e6;
public:

    EarthRotation *Ring;
    TVector RE_;
    TVector RSH;
    bool daytime = false; //is it day or night
    QVector <double> erg[5];
    sundial(long double t0, long double t1, long double SamplingIncrement,const TVector& X);
    TVector getRight( const TVector& X, long double t);
   void GetRE_(const TVector &X,const TVector &X_G,long double l);
   void ReadF(const TVector &X,const TVector &XR,double t);
   void SetTime(int year, int month, int day, int hour, int minute, int second);
   void SetGnomon(long double L,long double Fi,long double H);
};

#endif // SUNDIAL_H
