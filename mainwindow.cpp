#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Add(sundial *a)
{
    arg=std::move(a);
}

void MainWindow::Paint()
{
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(arg->erg[0],  arg->erg[2]);
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,0.5));
    ui->widget->xAxis->setLabel("X");
    ui->widget->yAxis->setLabel("Z");
    ui->widget->xAxis->setRange(-20,20);
    ui->widget->yAxis->setRange(-20,20);


    ui->widget->replot();
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->xAxis->setRange((ui->lineEdit->text()).toInt(),ui->lineEdit_2->text().toInt());
    ui->widget->yAxis->setRange((ui->lineEdit_3->text()).toInt(),ui->lineEdit_4->text().toInt());
    ui->widget->replot();
}

void MainWindow::on_pushButton_2_clicked()
{
    TVector X0(6);
    X0.SetItem(0, -2.566123740124270e+7L);
    X0.SetItem(1, 1.339350231544666e+8L);
    X0.SetItem(2, 5.805149372446711e+7L);
    X0.SetItem(3, -2.983549561177192+1L);
    X0.SetItem(4, -4.846747552523134L);
    X0.SetItem(5, -2.100585886567924L);

    std::vector<double> month;
    month.push_back(31); //J
     month.push_back(28); //F
      month.push_back(31); //M
       month.push_back(30); //A
        month.push_back(31); //M
         month.push_back(30); //J
          month.push_back(31); //July
           month.push_back(31); //A
            month.push_back(30); //S
             month.push_back(31); //O
              month.push_back(30); //N
               month.push_back(31); //D
    int DYear=ui->lineEdit_8->text().toInt()-2019;
    int Month=ui->lineEdit_9->text().toInt();
    int Day=0;

    for (int i=0;i<Month-1;i++)
    {
        Day+=month.at(i);
    }

    Day=Day+ui->lineEdit_10->text().toInt();

    long double All=DYear*365*86400+Day*86400;

    sundial *Arg1=new sundial(0,All,All,X0);
    Arg1->SetGnomon(ui->lineEdit_5->text().toInt(),ui->lineEdit_6->text().toInt(),ui->lineEdit_7->text().toInt());
    TIntegrator * integrator=new TDormandPrince();
    integrator->setPrecision(1e-16);
    integrator->Run(Arg1);
    Arg1->SetTime(2019,3,21,0,0,0);
    TMatrix Result = Arg1->getResult();

    std::ofstream out;
    out.open("first.txt");
    if (out.is_open())
    {
           for (int i=0;i<Result.GetRowCount()-1;i++)
                   {
                           for(int j=1;j<Result.GetColCount()-3;j++)
                           {
                               out<< std::to_string(Result(i,j));
                               out<<(" ");
                           }
                           out <<std::endl;
                   }
                   out.close();
    }

TVector X(6);
X[0]=Result(Result.GetRowHigh(),1);
X[1]=Result(Result.GetRowHigh(),2);
X[2]=Result(Result.GetRowHigh(),3);
X[3]=Result(Result.GetRowHigh(),4);
X[4]=Result(Result.GetRowHigh(),5);
X[5]=Result(Result.GetRowHigh(),6);

    sundial *Arg=new sundial(0, 86400, 60, X);
     Arg->SetGnomon(ui->lineEdit_5->text().toDouble()+ui->lineEdit_11->text().toDouble()/60.,ui->lineEdit_6->text().toDouble()+ui->lineEdit_12->text().toDouble()/60.,ui->lineEdit_7->text().toDouble());
     Arg->SetTime(ui->lineEdit_8->text().toInt(),ui->lineEdit_9->text().toInt(),ui->lineEdit_10->text().toInt(),0,0,0);

    integrator->Run(Arg);

     out.open("eee.txt");
     int index=0;
     if (out.is_open())
     {
                     for(auto i=Arg->erg[0].begin();i<Arg->erg[0].end();i++)
                                          {
                                            out<<std::to_string(Arg->Ring->S_Record.at(index));
                                            out<<(" ");
                                            out<<std::to_string(Arg->erg[3].at(index));
                                            out<<(" ");
                                            out<<std::to_string(Arg->erg[4].at(index));

                                            out <<std::endl;

                                            index++;
                                         }
                    out.close();
     }
     Add(Arg);
     Paint();
     delete integrator;
     delete Arg1;
     delete Arg;
}


\
