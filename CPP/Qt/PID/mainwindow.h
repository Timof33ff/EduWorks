#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QtMath>
#include "qcustomplot.h"
#include "pid.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_doubleSpinBox_2_valueChanged(double arg1);
    void on_doubleSpinBox_3_valueChanged(double arg1);
    void on_doubleSpinBox_4_valueChanged(double arg1);
    void on_doubleSpinBox_5_valueChanged(double arg1);
    void on_doubleSpinBox_6_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
       int t;
       int th;

       QVector<double> x;

       int N;

       double start;
       double end;
       double step;

       double Kp;
       double Ki;
       double Kd;

       func SF;

       func PF;


       double minY;
       double maxY;

       PID CO;

       static double function_input_step(double x);
       static double function_input_sqrt(double x);
       static double function_input_sin(double x);
       static double function_process(double x);
};
#endif // MAINWINDOW_H
