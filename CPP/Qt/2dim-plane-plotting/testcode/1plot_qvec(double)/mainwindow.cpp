#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    start = ui->start_spinbox->value();
    end = ui->end_spinbox->value();
    step = ui->step_spinbox->value();

    N = (end-start)/step;

    M = new Model;
}

MainWindow::~MainWindow()
{
    xdata.clear();
    ydata.clear();
    delete M;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//Если нужно, то очищаем график
    ui->widget->clearGraphs();

    N = (end-start)/step;

    if(!xdata.empty()){
        xdata.clear();
        xdata.resize(N);
    }
    else xdata = ydata = QVector<double>(N);

    for(double i = start; i<end; i+=step) xdata.push_back(i);
    ui->widget->xAxis->setLabel("Time");

    M->calculation_loop(start, end, step, set_h, set_v, Ph, Ih, Dh, Pv, Iv, Dv);

    if(ui->HradioButton->isChecked())
    {  ydata = M->Height;
       ui->widget->yAxis->setLabel("Height");
    }
    if(ui->VradioButton->isChecked())
    { ydata=M->Velocity;
      ui->widget->yAxis->setLabel("Velocity");
    }
    if(ui->WradioButton->isChecked())
    {  ydata=M->AngleVelocity;
       ui->widget->yAxis->setLabel("Angle velocity");
    }
    if(ui->aradioButton->isChecked())
    {  ydata=M->AtackAngle;
       ui->widget->yAxis->setLabel("Atack angle");
    }
    if(ui->TradioButton->isChecked())
    {  ydata=M->Tangazh;
       ui->widget->yAxis->setLabel("Tangazh");
    }
    if(ui->OradioButton->isChecked())
    {  ydata=M->TrajectoryAngle;
       ui->widget->yAxis->setLabel("Trajectory angle");
    }
    if(ui->dPradioButton->isChecked())
    {  ydata=M->dP;
       ui->widget->yAxis->setLabel("dP");
    }
    if(ui->PradioButton->isChecked())
    {  ydata=M->P;
       ui->widget->yAxis->setLabel("P - tyaga");
    }
    if(ui->HCradioButton->isChecked())
    {  ydata=M->HeightControl;
       ui->widget->yAxis->setLabel("Height control");
    }
    if(ui->YXradioButton->isChecked())
    {   xdata=M->X;
        ydata=M->Y;
        ui->widget->yAxis->setLabel("Y");
        ui->widget->xAxis->setLabel("X");
    }

        ui->widget->addGraph();
        ui->widget->graph(0)->setData(xdata, ydata);
        ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
        connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));

        ui->widget->graph(0)->setPen(QPen(Qt::red));
        ui->widget->graph(0)->rescaleAxes();
        ui->widget->replot();
}

// PID Height
void MainWindow::on_P_spinbox_valueChanged(double arg1)
{
    Ph = arg1;
}
void MainWindow::on_I_spinbox_valueChanged(double arg1)
{
    Ih = arg1;
}
void MainWindow::on_D_spinbox_valueChanged(double arg1)
{
    Dh = arg1;
}
// TIME
void MainWindow::on_start_spinbox_valueChanged(double arg1)
{
    start = arg1;
}
void MainWindow::on_end_spinbox_valueChanged(double arg1)
{
    end = arg1;
}
void MainWindow::on_step_spinbox_valueChanged(double arg1)
{
    step = arg1;
}
//PID Velocity
void MainWindow::on_PSpinBox_valueChanged(double arg1)
{
    Pv = arg1;
}
void MainWindow::on_ISpinBox_valueChanged(double arg1)
{
    Iv = arg1;
}
void MainWindow::on_DSpinBox_valueChanged(double arg1)
{
    Dv = arg1;
}



