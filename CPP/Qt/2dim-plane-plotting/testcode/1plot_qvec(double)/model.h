#ifndef MODEL_H
#define MODEL_H
#include <QVector>
#include <QDebug>
#include <QtMath>

class Model
{
public:
    Model();
    ~Model(){clear();};

    void clear(){
        Height.clear();
        Velocity.clear();
        AngleVelocity.clear();
        Tangazh.clear();
        AtackAngle.clear();
        TrajectoryAngle.clear();
        P.clear();
        HeightControl.clear();
        dP.clear();
        X.clear();
        Y.clear();
    }
    void resize(int N)
    {
        Height.resize(N);
        Velocity.resize(N);
        AngleVelocity.resize(N);
        Tangazh.resize(N);
        AtackAngle.resize(N);
        TrajectoryAngle.resize(N);
        P.resize(N);
        HeightControl.resize(N);
        dP.resize(N);
        X.resize(N);
        Y.resize(N);
    }

    QVector<double> Height;            // Высота
    QVector<double> Velocity;          // Скорость
    QVector<double> AngleVelocity;     // Угловая скорость
    QVector<double> Tangazh;           // Угол тангажа
    QVector<double> AtackAngle;        // Угол атаки
    QVector<double> TrajectoryAngle;   // Угол наклона траектории
    QVector<double> P;                 // Тяга

    //Control System

    double ErrHeight;          // Ошибка по высоте
    double ErrAngleVelocity;   // Ошибка по угловой скорости

    double Ph, Ih, Dh;         // Значения составляющих обоих ПИД-регуляторов
    double Pw, Iw, Dw;

    QVector<double> HeightControl;     // Руль высоты
    QVector<double> dP;                // Произодная по тяге

    QVector<double> X;                 // Горизонтальная координата
    QVector<double> Y;                 // Вертикальная координата

    void calculation_loop( double start, double end, double step, double set_height, double set_velocity, double Kp_height, double Ki_height, double Kd_height,
                           double Kp_angle_velocity, double Ki_angle_velocity, double Kd_angle_velocity);

private:
        
    const double mass = 350.0;
    
    //Environment
    double G(double height);   // Ускорение свободного падения начальное
    double Phi(double height); // Плотность атмосферы на уровне начальной высоты
    
    const double g0 = 10.0;
    const double phi0 = 0.025;    
    const double lambda = 0.001; // Показатель уменьшения плотности с увеличением высоты
    const double R = 6000000.0;   // Радиус Земли
    
    //Aerodynamics
    double Mz(double h, double v, double height_control, double atack_angel, double angle_velocity); // Момент аэродинамических сил
    double q(double h, double v);
    
    const double Cx_a = 0.2; // Приведенный коэффициент производной подъемной силы по угла атаки
    const double Cx_b = 0.1; // Приведенный коэффициент производной подъемной силы по рулю высоты
    
    const double Cy_a = 1.0; // Приведенный коэффициент производной подъемной силы по угла атаки
    const double Cy_b = 0.1; // Приведенный коэффициент производной подъемной силы по рулю высоты
    
    const double b = 5.0; // Хорда крыла
    const double s = 5.0; // Площадь крыла
    
    //Производные момента вращения
    const double mz_0 = -1.0;
    const double mz_w = -0.2;
    const double mz_b = 0.1;
    const double mz_a = 0.2;
    
    //Airplane
    const double height_start = 100.0; // Высота на старте

    const double velocity_start = 100.0; // Скорость начальная

    const double angle_velocity_start = 0.0; // Угловая скорость начальная

    const double tangazh_angle_start = 0.0087; // Угол тангажа (между главной осью и горизонтом) *радианы
    const double trajectory_angle_start = 0.0; // Угол наклона траектории
    const double atack_angle_start = tangazh_angle_start-trajectory_angle_start; // Угол между главной осью самолета и траекторией

    const double Lz = 1000.0; // Продольный момент инерции (относительно главной оси)

    double degToRad = 0.01745; //Коэффициент для перевода градусов в радианы

    const double k1 = 2;
};

#endif // MODEL_H
