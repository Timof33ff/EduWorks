#include "model.h"


Model::Model()
{
    // Инициализируем начальные значения
    Height = new double[N]; Velocity = new double[N]; AngleVelocity = new double[N];
    Tangazh = new double[N]; AtackAngle = new double[N]; TrajectoryAngle = new double[N];
    P = new double[N]; dP = new double[N]; HeightControl = new double[N];
    X = new double[N]; Y = new double[N];
    ErrHeight = new double[N]; ErrAngleVelocity = new double[N];
    Ph = new double[N]; Ih = new double[N]; Dh = new double[N];
    Pw = new double[N]; Iw = new double[N]; Dw = new double[N];
}

void Model::writeToBuffFile( double* x)
{
 std::ofstream f(filename);
 for(int i = 0; i<N; i++)
 f<<x[i]<<'\n';
 f.close();
}

void Model::calculation_loop( double start, double end, double step, double set_height, double set_velocity, double Kp_height, double Ki_height, double Kd_height,                                                                                                         double Kp_angle_velocity, double Ki_angle_velocity, double Kd_angle_velocity)
{
    N = int((end-start)/step); // Количество итераций

    clearResize(N);// Очищаем массивы и даем им новый размер

    int i = 0; // Итератор

//---------------СИСТЕМА---УПРАВЛЕНИЯ---------------------------------------------------------------------------------------------------------------------------------------------------
    ErrHeight[i] = (height_start - set_height)+k1*(velocity_start - set_velocity);
    ErrAngleVelocity[i] = angle_velocity_start;

    Ph[i] = Kp_height * ErrHeight[i]; Ih[i] = Ki_height * ErrHeight[i]*step; Dh[i] = Kd_height * ErrHeight[i]/step;
    Pw[i] = Kp_angle_velocity * ErrAngleVelocity[i]; Iw[i] = Ki_angle_velocity * ErrAngleVelocity[i]*step; Dw[i] = Kd_angle_velocity * ErrAngleVelocity[i]/step;

    HeightControl[i] = Ph[i]+Ih[i]+Dh[i];

    dP[i] = Pw[i] + Iw[i] + Dw[i];

//---------------МОДЕЛЬ---АЭРОДИНАМИЧЕСКИХ---ХАРАКТЕРИСТИК------------------------------------------------------------------------------------------------------------------------------
    X[i] = ((M_PI/180) * Cx_a * atack_angle_start + (M_PI/180) * Cx_b * HeightControl[i])*q(height_start, velocity_start)*s;
    Y[i] = ((M_PI/180) * Cy_a * atack_angle_start + (M_PI/180) * Cy_b * HeightControl[i])*q(height_start, velocity_start)*s;

//---------------МОДЕЛЬ---САМОЛЁТА------------------------------------------------------------------------------------------------------------------------------------------------------

    Height[i] = height_start; Velocity[i] = velocity_start; AngleVelocity[i] = angle_velocity_start;
    Tangazh[i] = tangazh_angle_start; AtackAngle[i] = atack_angle_start; TrajectoryAngle[i] = trajectory_angle_start;

    //ТЯГА
    P[i] = ((X[i] + mass*G(height_start)*sin((M_PI/180)*trajectory_angle_start))/cos((M_PI/180)*atack_angle_start)) + dP[i];

    for(int i = 1; i<N; i++) // Непосредственно цикл рассчёта системы
    {
//---------------МОДЕЛЬ---АЭРОДИНАМИЧЕСКИХ---ХАРАКТЕРИСТИК------------------------------------------------------------------------------------------------------------------------------
    //КООРДИНАТЫ
        X[i] = ((M_PI/180) * Cx_a * AtackAngle[i-1] + (M_PI/180) * Cx_b * HeightControl[i-1])*q(Height[i-1], Velocity[i-1])*s;

        Y[i] = ((M_PI/180) * Cy_a * AtackAngle[i-1] + (M_PI/180) * Cy_b * HeightControl[i-1])*q(Height[i-1], Velocity[i-1])*s;

//---------------СИСТЕМА---УПРАВЛЕНИЯ---------------------------------------------------------------------------------------------------------------------------------------------------
    //ОШИБКА ПО ВЫСОТЕ
        ErrHeight[i] = ((Height[i-1] - set_height)+k1*(Velocity[i-1] - set_velocity));
    //ОШИБКА ПО УГЛОВОЙ СКОРОСТИ
        ErrAngleVelocity[i] = AngleVelocity[i-1];
    //ПИД СОСТАВЛЯЮЩИЕ
        Ph[i] = Kp_height * ErrHeight[i]; Ih[i] = Ih[i-1] + Ki_height *ErrHeight[i]*step; Dh[i] = Kd_height * ((ErrHeight[i] - ErrHeight[i-1])/step);
        Pw[i] = Kp_angle_velocity * ErrAngleVelocity[i]; Iw[i] = Iw[i-1] + Ki_angle_velocity * ErrAngleVelocity[i] * step; Dw[i] = Kd_angle_velocity * ((ErrAngleVelocity[i] - ErrAngleVelocity[i-1])/step);
    //РУЛЬ ВЫСОТЫ
        HeightControl[i] = Ph[i] + Ih[i] + Dh[i];
    //ТЯГА
        dP[i] = Pw[i] + Iw[i] + Dw[i];
        P[i] = ((X[i] + mass*G(Height[i-1])*sin((M_PI/180)*TrajectoryAngle[i-1]))/cos((M_PI/180)*AtackAngle[i-1])) + dP[i];
//---------------МОДЕЛЬ---САМОЛЁТА------------------------------------------------------------------------------------------------------------------------------------------------------
    //ВЫСОТА
        Height[i] = Height[i-1] + step*Velocity[i-1]*sin((M_PI/180)*TrajectoryAngle[i-1]);
    //СКОРОСТЬ
    //if(isnan(cos(0.1745*AtackAngle[i-1]))) cout<<"cos(0.1745*AtackAngle[i-1]) = NAN";
        Velocity[i] = Velocity[i-1] + step*(P[i]*cos((M_PI/180)*AtackAngle[i-1])-X[i]-mass*G(Height[i])*sin(0.1745*TrajectoryAngle[i-1]))/mass;
    //УГЛОВАЯ СКОРОСТЬ
        AngleVelocity[i] = AngleVelocity[i-1] + step*Mz(Height[i], Velocity[i], HeightControl[i-1], AtackAngle[i-1], AngleVelocity[i-1])/Lz;
    //ТАНГАЖ
        Tangazh[i] = Tangazh[i-1] + AngleVelocity[i] * step;
    //УГОЛ НАКЛОНА ТРАЕКТОРИИ
        TrajectoryAngle[i] = TrajectoryAngle[i-1] + (180/M_PI) * step*(P[i]*sin((M_PI/180)*AtackAngle[i-1])+Y[i]-mass*G(Height[i])*cos((M_PI/180)*TrajectoryAngle[i-1]))/(Velocity[i] * mass);
    //УГОЛ АТАКИ
        AtackAngle[i] = Tangazh[i] - TrajectoryAngle[i];
    }
}


double Model::G(double height)// Функция вычисления ускорения свободного падения относительно высоты
{
    return g0 * pow(R/(R+height), 2);
}

double Model::Phi(double height)// Функция вычисления плотности атмосферы относительно высоты
{
    return phi0 * exp(height*(lambda));
}

//Момент инерции
double Model::Mz(double h, double v, double height_control, double atack_angle, double angle_velocity)
{
    return (mz_0 + (M_PI/180)*mz_a*atack_angle + (M_PI/180)*mz_w*angle_velocity + (M_PI/180)*mz_b*height_control)*q(h, v)*b;
}
//
double Model::q(double h, double v)
{
    return (Phi(h) * pow(v, 2)) / 2;
}


