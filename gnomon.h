#ifndef GNOMON_H
#define GNOMON_H
#include "MyLinearAlgebra.h"
#include "spaceformule.h"
using namespace MyLinearAlgebra;
using namespace FSpace;
class Gnomon
{

public:
      long double l;//длина Гномона
    TVector OldR;//радиус-вектор по L,Fi,H
    TVector R0;
    TVector Rg;//радиус-вектор точки расположения гномона в инерциальной геоцентрической СК
    Gnomon(long double L,long double Fi,long double H);//координаты начальные для Гномона
  //  void NewPosition(long double L);
};

#endif // GNOMON_H
