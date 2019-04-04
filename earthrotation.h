#ifndef REARTH_H
#define REARTH_H
#include <vector>
#include <memory>
#include <MyLinearAlgebra.h>
#include "spaceformule.h"
#include "gnomon.h"
#include <QTime>
class EarthRotation
{
   const double theta= 7.292115e-5;
public:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
       Gnomon * gnomon;
       double S_G;
     std::vector<double>S_Record;
   EarthRotation(long double L,long double Fi,long double H);
   void Move(long double t);
   void StepTime(long double t);
   void NewPosition();
};

#endif // REARTH_H
