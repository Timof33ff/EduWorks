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
}

MainWindow::~MainWindow()
{
    time.clear();
    data.clear();data1.clear();data2.clear();data3.clear();data4.clear();
    data5.clear();data6.clear();data7.clear();data8.clear();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//Если нужно, то очищаем все графики
    ui->widget->clearGraphs();     ui->widget_2->clearGraphs();     ui->widget_3->clearGraphs();
         ui->widget_6->clearGraphs();     ui->widget_5->clearGraphs();     ui->widget_4->clearGraphs();
             ui->widget_7->clearGraphs();     ui->widget_8->clearGraphs();    ui->widget_9->clearGraphs();

    ui->widget->addGraph();     ui->widget_2->addGraph();     ui->widget_3->addGraph();
        ui->widget_4->addGraph();     ui->widget_5->addGraph();     ui->widget_6->addGraph();
            ui->widget_7->addGraph();     ui->widget_8->addGraph();    ui->widget_9->addGraph();

    N = (end-start)/step;

    if(!time.empty()){
        time.clear();
        data.clear();
        data1.clear();
        data2.clear();
        data3.clear();
        data4.clear();
        data5.clear();
        data6.clear();
        data7.clear();
        data8.clear();
    }

    time = data = data1 = data2 = data3 = data4 = data5 = data6 = data7 = data8 = QVector<double>(N);

    M.calculation_loop(start, end, step, set_h, set_v, Ph, Ih, Dh, Pv, Iv, Dv);

    if(ui->Model_radioButton->isChecked())
    {
        for(int i = 0; i < N; i++)
        {
            time.push_back(start + i*step);
            data.push_back(M.Height[i]);
            data1.push_back(M.Velocity[i]);
            data2.push_back(M.AngleVelocity[i]);
            data3.push_back(M.AtackAngle[i]);
            data4.push_back(M.Tangazh[i]);
            data5.push_back(M.TrajectoryAngle[i]);
            data6.push_back(M.P[i]);
            data7.push_back(M.dP[i]);
            data8.push_back(M.HeightControl[i]);
        }

        ui->widget->graph(0)->setData(time, data);     ui->widget_2->graph(0)->setData(time, data1);     ui->widget_3->graph(0)->setData(time, data2);
            ui->widget_4->graph(0)->setData(time, data4);     ui->widget_5->graph(0)->setData(time, data5);     ui->widget_6->graph(0)->setData(time, data6);
                ui->widget_7->graph(0)->setData(time, data7);     ui->widget_8->graph(0)->setData(time, data7);    ui->widget_9->graph(0)->setData(time, data8);

        ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);     ui->widget_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);     ui->widget_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
            ui->widget_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);     ui->widget_5->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);     ui->widget_6->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
                ui->widget_7->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);     ui->widget_8->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);    ui->widget_9->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

        ui->widget->replot();     ui->widget_2->replot();     ui->widget_3->replot();
             ui->widget_4->replot();     ui->widget_5->replot();     ui->widget_6->replot();
                 ui->widget_7->replot();     ui->widget_8->replot();    ui->widget_9->replot();
    }
    else if(ui->CS_radioButton->isChecked())
    {
        for(int i = 0; i < N; i++)
        {
            time.push_back(start + i*step);
            data.push_back(M.ErrHeight[i]);
            data1.push_back(M.ErrAngleVelocity[i]);
            data2.push_back(M.X[i]);
            data3.push_back(M.Y[i]);
        }

        ui->widget->graph(0)->setData(time, data);     ui->widget_2->graph(0)->setData(time, data1);     ui->widget_5->graph(0)->setData(data2, data3);

        ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);     ui->widget_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        ui->widget_5->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

        ui->widget->replot();     ui->widget_2->replot();     ui->widget_5->replot();
    }
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



