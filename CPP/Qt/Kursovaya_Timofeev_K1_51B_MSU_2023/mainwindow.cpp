#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qcplot = new QCustomPlot();

    start = ui->start_spinbox->value();
    end = ui->end_spinbox->value();
    step = ui->step_spinbox->value();

    N = (end-start)/step;

    M = new Model();
}

MainWindow::~MainWindow()
{
    time.clear();
    data.clear();
    delete M;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//Если нужно, то очищаем все графики
    ui->widget->clearGraphs();

    ui->widget->addGraph();

    N = int((end-start)/step);

    if(!time.empty()){
        time.clear();
        data.clear();
    }

    time = data = QVector<double>(N);
    for(int i = 0; i<N; i++)time.push_back(start+i*step);

    M->calculation_loop(start, end, step, set_h, set_v, Ph, Ih, Dh, Pv, Iv, Dv);

    if(ui->height->isChecked()) for(int i = 0; i < N; i++)data.push_back(M->Height[i]);
    else if(ui->velocity->isChecked()) for(int i = 0; i < N; i++)data.push_back(M->Velocity[i]);
    else if(ui->angleVelocity->isChecked()) for(int i = 0; i < N; i++)data.push_back(M->AngleVelocity[i]);
    else if(ui->tyaga->isChecked()) for(int i = 0; i < N; i++)data.push_back(M->P[i]);
    else if(ui->dp->isChecked()) for(int i = 0; i < N; i++)data.push_back(M->dP[i]);
    else if(ui->heightControl->isChecked()) for(int i = 0; i < N; i++)data.push_back(M->HeightControl[i]);
    else if(ui->atackAngle->isChecked()) for(int i = 0; i < N; i++)data.push_back(M->AtackAngle[i]);
    else if(ui->tangazh->isChecked()) for(int i = 0; i < N; i++)data.push_back(M->Tangazh[i]);
    else if(ui->trajectoryAngle->isChecked()) for(int i = 0; i < N; i++)data.push_back(M->TrajectoryAngle[i]);
    else {QMessageBox msg; msg.setText("Не выбрана величина для вывода"); msg.exec();}

    M->writeToBuffFile(M->Height);

    ui->widget->graph(0)->addData(time, data);

    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

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



