#ifndef PID_H
#define PID_H

#include <QVector>
#include <QDebug>

typedef double(*func)(double t);

class PID
{
public:
    int N;

    const double maxI = 1000.0;
    const double minI = -1000.0;
    //init arrays
    QVector<double> input;
    QVector<double> output;
    QVector<double> error;

    QVector<double> P_vector;
    QVector<double> I_vector;
    QVector<double> D_vector;

    QVector<double> PID_sum;
    //constructor

    PID();
    ~PID()
    {
        clearAll();
    };

        void calculation(func signal, func process, double start, double end, double step,
                         double P, double I, double D);
        void clearAll(){
           input.clear();
           output.clear();
           error.clear();
           P_vector.clear();
           I_vector.clear();
           D_vector.clear();
           PID_sum.clear();
        }

        void calc_base_pid(func signal, double start, double end, double step,
                           double P, double I, double D);

private:
};

#endif // PID_H
