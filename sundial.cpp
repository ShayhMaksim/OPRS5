#include "sundial.h"
#include <cmath>
using namespace MyLinearAlgebra;

sundial::sundial(long double t0, long double t1, long double SamplingIncrement,const TVector& X)
    : TModel()
{
    this->t0=t0;
    this->t1=t1;
    this->SamplingIncrement=SamplingIncrement;
    RE_=TVector(3);
    RSH=TVector(3);//то что нужно найти
    X0=X;
}

TVector sundial::getRight( const TVector& X, long double t) {
    TVector Y(6);
    for (int i=0; i!=3; ++i)
        Y.SetItem(i, X[i+3]);
    TVector X_Coordin = X.Concat(0,2);

    TVector X_Dif = -mu_s*X_Coordin*(1/(pow(X_Coordin.length(),3)));
    for (int i=3; i!=6; ++i)
        Y.SetItem(i, X_Dif[i-3]);  

    Ring->Move(t);//прототип,вместе с функцией правых частей учитывается вращение Земли

    Ring->NewPosition();

    GetRE_(X_Coordin,Ring->gnomon->R0,Ring->gnomon->l);

    RSH=RE_+Ring->gnomon->Rg;

    ReadF(RSH,X_Coordin,t);
    return Y;
}

void sundial::GetRE_(const TVector &X,const TVector &X_G,long double l)
{
    TVector X_=X;
    X_=X_.norm();
    RE_=-l/(X_*X_G)*X_;
}

void sundial::ReadF(const TVector &X,const TVector &XR,double t)
{
    TMatrix A=intoA(  Ring->gnomon->OldR[1],Ring->S_G);
    TVector X_=A*X;

    long double alfa =acos(XR*Ring->gnomon->Rg/(XR.length()*Ring->gnomon->Rg.length()));

    if (alfa > M_PI_2) daytime = true;

   if (daytime == true){
    erg[0].push_back(X_[0]*1000);
     erg[1].push_back(X_[1]*1000);
      erg[2].push_back(X_[2]*1000);
       erg[3].push_back(t);
       double c=1000*sqrt(X_[0]*X_[0]+X_[2]*X_[2]);
       if (c>=20*Ring->gnomon->l*1000) c=20*Ring->gnomon->l*1000;
       erg[4].push_back(c);
    }
    daytime=false;
}

void sundial::SetTime(int year, int month, int day, int hour, int minute, int second)
{
    Ring->year=year;
    Ring->month=month;
    Ring->day=day;
    Ring->hour=hour;
    Ring->minute=minute;
    Ring->second=second;
}

void sundial::SetGnomon(long double L, long double Fi, long double H)
{
     Ring=new EarthRotation(L*M_PI/180,Fi*M_PI/180,H/1000.);
}


