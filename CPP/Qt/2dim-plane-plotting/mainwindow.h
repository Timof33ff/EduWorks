 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "model.h"
#include "qcustomplot.h"
#include <QDebug>
#include <QTimer>

//using namespace std;

#define w0 ui->widget

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
    void on_pushButton_clicked();

    void on_P_spinbox_valueChanged(double arg1);

    void on_I_spinbox_valueChanged(double arg1);

    void on_D_spinbox_valueChanged(double arg1);

    void on_start_spinbox_valueChanged(double arg1);

    void on_end_spinbox_valueChanged(double arg1);

    void on_step_spinbox_valueChanged(double arg1);

    void on_PSpinBox_valueChanged(double arg1);

    void on_ISpinBox_valueChanged(double arg1);

    void on_DSpinBox_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;

    QVector<double> time, data, data1, data2, data3, data4, data5, data6, data7, data8;

    Model* M;
    double start;
    double end;
    double step;

    int N;

    double set_h;
    double set_v;

    double Ph, Ih, Dh;
    double Pv, Iv, Dv;
};
#endif // MAINWINDOW_H
