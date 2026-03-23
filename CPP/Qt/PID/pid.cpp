#include "pid.h"

PID::PID()
{
}

void print(QVector<double> x)
{
    QVector<double>::Iterator itr = x.begin();
    for(;itr!=x.end();++itr)
    {
        qInfo() << *itr << "\t|\n|\t";
    }
}

void PID::calculation( func signal, func process, double start, double end, double step,
                      double P, double I, double D)
{
    N = int(end - start)/step;

    if(!input.empty())
    {
        clearAll();
        input.resize(N);
        output.resize(N);
        error.resize(N);
        P_vector.resize(N);
        I_vector.resize(N);
        D_vector.resize(N);
        PID_sum.resize(N);
    }
    else
    {
        input = QVector<double>(N);
        output = QVector<double>(N);
        error = QVector<double>(N);
        P_vector = QVector<double>(N);
        I_vector = QVector<double>(N);
        D_vector = QVector<double>(N);
        PID_sum = QVector<double>(N);
    }

    for(int i=0; i<N; i++)
    {
        input.push_back(signal(start + i*step));

        if(i!=0)
        {
            error.push_back(input.last()-output.last());

            P_vector.push_back(P * error.last());

            I_vector.push_back(I * (I_vector.last() +  error.last()*step));
            if(I_vector.last() < minI){I_vector.pop_back(); I_vector.push_back(minI);}
            if(I_vector.last() > maxI){I_vector.pop_back(); I_vector.push_back(maxI);}

            D_vector.push_back(D*(error.last()-error.at(i-1))/step);
            if(D_vector.last() < minI){D_vector.pop_back(); D_vector.push_back(minI);}
            if(D_vector.last() > maxI){D_vector.pop_back(); D_vector.push_back(maxI);}

            PID_sum.push_back(P_vector.last() + I_vector.last() + D_vector.last());
            output.push_back(process(PID_sum.last()));
        }
        else
        {
            error.push_back(input.last());

            P_vector.push_back(P * error.last());

            I_vector.push_back(I * (error.last()*step));
            if(I_vector.last() < minI){I_vector.pop_back(); I_vector.push_back(minI);}
            if(I_vector.last() > maxI){I_vector.pop_back(); I_vector.push_back(maxI);}

            D_vector.push_back(D * (error.last()/step));
            PID_sum.push_back(P_vector.last());
            output.push_back(process(PID_sum.last()));
        }
    }

    // print(output);
}

void PID::calc_base_pid(func signal, double start, double end, double step, double P, double I, double D)
{
    N = int(end - start)/step;

    if(!input.empty())
    {
        clearAll();
        input.resize(N);
        error.resize(N);
        output.resize(N);
        P_vector.resize(N);
        I_vector.resize(N);
        D_vector.resize(N);
        PID_sum.resize(N);
    }
    else
    {
        input = QVector<double>(N);
        error = QVector<double>(N);
        output = QVector<double>(N);
        P_vector = QVector<double>(N);
        I_vector = QVector<double>(N);
        D_vector = QVector<double>(N);
        PID_sum = QVector<double>(N);
    }

    for(int i=0; i<N; i++)
    {
        input.push_back(signal(start + i*step));

        if(i!=0)
        {
            error.push_back(input.last()-output.last());

            P_vector.push_back(P * error.last());

            I_vector.push_back(I_vector.last() + I*error.last());
            if(I_vector.last() < minI){I_vector.pop_back(); I_vector.push_back(minI);}
            if(I_vector.last() > maxI){I_vector.pop_back(); I_vector.push_back(maxI);}

            D_vector.push_back(D*(error.last()-error.at(i-1)));
            if(D_vector.last() < minI){D_vector.pop_back(); D_vector.push_back(minI);}
            if(D_vector.last() > maxI){D_vector.pop_back(); D_vector.push_back(maxI);}

            PID_sum.push_back(P_vector.last() + I_vector.last() + D_vector.last());
            output.push_back(PID_sum.last());
        }
        else
        {
            error.push_back(input.last());
            P_vector.push_back(P * error.last());

            I_vector.push_back(I*error.last());
            if(I_vector.last() < minI){I_vector.pop_back(); I_vector.push_back(minI);}
            if(I_vector.last() > maxI){I_vector.pop_back(); I_vector.push_back(maxI);}

            D_vector.push_back(D*error.last());
            PID_sum.push_back(P_vector.last());
            output.push_back(PID_sum.last());
        }
    }

};
