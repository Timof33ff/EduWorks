#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    start = ui->doubleSpinBox->value();
    end =   ui->doubleSpinBox_2->value();
    step =  ui->doubleSpinBox_3->value();
    N = int((end - start)/step);
    Kp = ui->doubleSpinBox_4->value();
    Ki = ui->doubleSpinBox_5->value();
    Kd = ui->doubleSpinBox_6->value(); 
}

MainWindow::~MainWindow()
{
    x.clear();
    delete ui;
}


void MainWindow::on_startButton_clicked()
{

    ui->plotLayOut->clearGraphs();

    N = (end - start) / step;
    if(!x.empty()){x.clear(); x.resize(N);}
    else {x = QVector<double>(N);}

    for(int i = 0; i<N; i++){ x.push_back(start + i*step);}

         if(ui->Step_radioButton->isChecked()) SF = function_input_step;
    else if(ui->SQRT_radioButton->isChecked()) SF = function_input_sqrt;
    else if(ui->Sin_radioButton->isChecked()) SF = function_input_sin;
    else SF = function_input_step;

    ui->plotLayOut->addGraph();
    ui->plotLayOut->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);    

    ui->plotLayOut->xAxis2->setVisible(true);
    ui->plotLayOut->xAxis2->setTickLabels(false);
    ui->plotLayOut->yAxis2->setVisible(true);
    ui->plotLayOut->yAxis2->setTickLabels(false);

    if(ui->In_radioButton->isChecked())
    {
    CO.calculation(SF, function_process, start, end, step, Kp, Ki, Kd);
    ui->plotLayOut->graph(0)->setData(x, CO.input);
    }
    else if(ui->Out_radioButton->isChecked())
    {
    CO.calculation(SF, function_process, start, end, step, Kp, Ki, Kd);
        ui->plotLayOut->graph(0)->setData(x, CO.output);
    }
    else if(ui->Err_radioButton->isChecked())
    {
        CO.calculation(SF, function_process, start, end, step, Kp, Ki, Kd);
        ui->plotLayOut->graph(0)->setData(x, CO.error);
    }
    else if(ui->PID_radioButton->isChecked())
    {
        CO.calculation(SF, function_process, start, end, step, Kp, Ki, Kd);
        ui->plotLayOut->graph(0)->setData(x, CO.PID_sum);
    }
    else if(ui->P_I_D_radioButton->isChecked())
    {
        CO.calculation(SF, function_process, start, end, step, Kp, Ki, Kd);
        ui->plotLayOut->graph(0)->setData(x, CO.P_vector);
        ui->plotLayOut->addGraph();
        ui->plotLayOut->graph(1)->rescaleAxes(true);
        ui->plotLayOut->graph(1)->setData(x, CO.I_vector);
        ui->plotLayOut->graph(1)->setPen(QPen(Qt::blue));
        ui->plotLayOut->addGraph();
        ui->plotLayOut->graph(2)->rescaleAxes(true);
        ui->plotLayOut->graph(2)->setData(x, CO.D_vector);
        ui->plotLayOut->graph(2)->setPen(QPen(Qt::green));
    }
    else if(ui->BasePIDRadioButton->isChecked())
    {
        CO.calc_base_pid(SF, start, end, step, Kp, Ki, Kd);
        ui->plotLayOut->graph(0)->setData(x, CO.P_vector);
        ui->plotLayOut->addGraph();
        ui->plotLayOut->graph(1)->rescaleAxes(true);
        ui->plotLayOut->graph(1)->setData(x, CO.I_vector);
        ui->plotLayOut->graph(1)->setPen(QPen(Qt::blue));
        ui->plotLayOut->addGraph();
        ui->plotLayOut->graph(2)->rescaleAxes(true);
        ui->plotLayOut->graph(2)->setData(x, CO.D_vector);
        ui->plotLayOut->graph(2)->setPen(QPen(Qt::green));
    }
    else
    {
        CO.calculation(SF, function_process, start, end, step, Kp, Ki, Kd);
        ui->plotLayOut->graph(0)->setData(x, CO.input);
    }

    connect(ui->plotLayOut->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->plotLayOut->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->plotLayOut->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->plotLayOut->yAxis2, SLOT(setRange(QCPRange)));

    ui->plotLayOut->graph(0)->setPen(QPen(Qt::red));
    ui->plotLayOut->graph(0)->rescaleAxes();
    ui->plotLayOut->xAxis->setLabel("Time");
    ui->plotLayOut->replot();

    CO.clearAll();
}


double MainWindow::function_input_step(double x)
{
    //step function
    if(x<1) return 0;
    else return 1;
}

double MainWindow::function_input_sqrt(double x)
{
    //sqrt function
    return  qSqrt(x);
}

double MainWindow::function_input_sin(double x)
{
    //sin function
    return qSin(x);
}

double MainWindow::function_process(double x)
{
    //process function
    double k = 1;
    double T = 0.13;
    return (k)/(pow(T*x,2)+T*2*x+1);
}



void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    start = arg1;
}
void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    end = arg1;
}
void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
    step = arg1;
}
void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    Kp = arg1;
}
void MainWindow::on_doubleSpinBox_5_valueChanged(double arg1)
{
    Ki = arg1;
}
void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1)
{
    Kd = arg1;
}


