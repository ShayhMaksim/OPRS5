#include "earthrotation.h"


using namespace FSpace;

EarthRotation::EarthRotation(long double L,long double Fi,long double H)
{
    gnomon=new Gnomon(L,Fi,H); // последниц параметр это высота гномона
    //сколько дней в каждом месяце

}

void EarthRotation::Move(long double t)
{  
    double S_G0=2*M_PI/86400.*fmod(SiderialTime(year, month,day,hour, minute, second),86400.);
    S_G=S_G0 + theta * t + gnomon->OldR[0];
    S_Record.push_back(2*M_PI*fmod(S_G,86400.)/86400.);
}


void EarthRotation::NewPosition()
{
   TVector old=gnomon->OldR;
   old[0]=S_G;
   gnomon->R0=intoGSK(old).norm();
   gnomon->Rg=gnomon->l*gnomon->R0;
}

