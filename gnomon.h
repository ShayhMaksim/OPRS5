#ifndef GNOMON_H
#define GNOMON_H
#include "MyLinearAlgebra.h"
#include "spaceformule.h"
using namespace MyLinearAlgebra;
using namespace FSpace;
class Gnomon
{

public:
      long double l;//����� �������
    TVector OldR;//������-������ �� L,Fi,H
    TVector R0;
    TVector Rg;//������-������ ����� ������������ ������� � ������������ ��������������� ��
    Gnomon(long double L,long double Fi,long double H);//���������� ��������� ��� �������
  //  void NewPosition(long double L);
};

#endif // GNOMON_H
