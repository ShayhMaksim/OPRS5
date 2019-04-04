#include <QApplication>
#include <iostream>
#include <cmath>
#include "spaceformule.h"
#include "sundial.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "mainwindow.h"
//using namespace std;


using namespace FSpace;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow window;

    window.show();

//    FILE *gp=popen("gnuplot -persist","w");
//    if (gp==nullptr)
//    {
//        printf("error opening pipe to GNU");
//        exit(1);
//    }
//    fprintf(gp, "splot \"/home/maksim/build-OPRS_lab5-Desktop_Qt_5_12_0_GCC_64bit-Debug/first.txt\" w l\n");
//    pclose(gp);


    return a.exec();
}


