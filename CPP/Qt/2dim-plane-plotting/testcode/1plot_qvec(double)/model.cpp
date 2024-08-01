#include "model.h"


Model::Model()
{
}

void print(QVector<double> x, int N)
{
    for(int i = 0; i<N; i++)
    {
        qInfo() << "|\t" << x.at(i) << "\t|";
    }
}

void Model::calculation_loop( double start, double end, double step, double set_height, double set_velocity, double Kp_height, double Ki_height, double Kd_height,                                                                                                         double Kp_angle_velocity, double Ki_angle_velocity, double Kd_angle_velocity)
{
    if(!Height.isEmpty()) clear();//Если векторы уже заполнены предыдущими вычислениями, очищаем их и задаём новый размер
    int N = int((end-start)/step); // Количество итераций
    resize(N);

 /* -------------------------------------------ЦИКЛ--------------------------------------------------------- */
    double ErrHeightPrev = 0;
    double ErrHeight = 0;

    for(int i = 0; i<N; i++) // Непосредственно цикл рассчёта системы
    {
        if(i==0)
        {
            Height.push_back( height_start);     Velocity.push_back( velocity_start);
            AngleVelocity.push_back( angle_velocity_start);   AtackAngle.push_back( atack_angle_start);
            Tangazh.push_back( tangazh_angle_start);  TrajectoryAngle.push_back( trajectory_angle_start);

            ErrHeight = (Height.at(i)-set_height)+k1*(Velocity.at(i)-set_velocity);
            Ph = Kp_height*ErrHeight; Ih = Ki_height*ErrHeight*step; Dh = Kd_height*(ErrHeight/step);
            HeightControl.push_back(Ph+Ih+Dh);

            Pw = Kp_angle_velocity*AngleVelocity.at(i);
            Iw = Ki_angle_velocity*AngleVelocity.at(i)*step;
            Dw = Kd_angle_velocity*(AngleVelocity.at(i)/step);
            dP.push_back(Pw+Iw+Dw);

            X.push_back((Cx_a*AtackAngle.at(i) + Cx_b*HeightControl.at(i))*q(Height.at(i), Velocity.at(i))*s);
            Y.push_back((Cy_a*AtackAngle.at(i) + Cy_b*HeightControl.at(i))*q(Height.at(i), Velocity.at(i))*s);

            P.push_back(((X.at(i) + mass*G(Height.at(i))*qSin(degToRad*TrajectoryAngle.at(i)))/qCos(degToRad*AtackAngle.at(i))) + dP.at(i));
        }
        else
        {
//---------------МОДЕЛЬ---САМОЛЁТА------------------------------------------------------------------------------------------------------------------------------------------------------
    //ВЫСОТА
            Height.push_back(Height.at(i-1)+step*Velocity.at(i-1)*qSin(degToRad*TrajectoryAngle.at(i-1)));
    //СКОРОСТЬ
            Velocity.push_back(Velocity.at(i-1)+step*(P.at(i-1)*qCos(degToRad*AtackAngle.at(i-1))-X.at(i-1)-mass*G(Height.at(i-1))*qSin(degToRad*TrajectoryAngle.at((i-1))))/mass);
    //УГЛОВАЯ СКОРОСТЬ
            AngleVelocity.push_back(AngleVelocity.at(i-1)+step*Mz(Height.at(i-1), Velocity.at(i-1), HeightControl.at(i-1), AtackAngle.at(i-1), AngleVelocity.at(i-1))/Lz);
    //ТАНГАЖ
            Tangazh.push_back(Tangazh.at(i-1)+step*AngleVelocity.at(i-1));
    //УГОЛ НАКЛОНА ТРАЕКТОРИИ
            TrajectoryAngle.push_back(TrajectoryAngle.at(i-1)+step*(P.at(i-1)*qSin(degToRad*AtackAngle.at(i-1))+Y.at(i-1)-mass*G(Height.at(i-1))*qCos(degToRad*TrajectoryAngle.at(i-1)))/(Velocity.at(i-1)*mass));
    //УГОЛ АТАКИ
            AtackAngle.push_back(Tangazh.at(i-1)-TrajectoryAngle.at(i-1));
//---------------СИСТЕМА---УПРАВЛЕНИЯ---------------------------------------------------------------------------------------------------------------------------------------------------
        //ОШИБКА ПО ВЫСОТЕ
        ErrHeight = (Height.at(i)-set_height)+k1*(Velocity.at(i)-set_velocity);
        //ОШИБКА ПО УГЛОВОЙ СКОРОСТИ
        ErrAngleVelocity = AngleVelocity.at(i);
        //ПИД СОСТАВЛЯЮЩИЕ
        Ph = Kp_height*ErrHeight;
        Ih += Ki_height*ErrHeight*step;
        Dh = Kd_height*((ErrHeight-ErrHeightPrev)/step);

        Pw = Kp_angle_velocity*AngleVelocity.at(i);
        Iw += Ki_angle_velocity*AngleVelocity.at(i)*step;
        Dw = Kd_angle_velocity*((AngleVelocity.at(i)-AngleVelocity.at(i-1))/step);
        //РУЛЬ ВЫСОТЫ
        HeightControl.push_back(Ph+Ih+Dh);
        //КООРДИНАТЫ
        X.push_back((Cx_a*AtackAngle.at(i) + Cx_b*HeightControl.at(i))*q(Height.at(i), Velocity.at(i))*s);
        Y.push_back((Cy_a*AtackAngle.at(i) + Cy_b*HeightControl.at(i))*q(Height.at(i), Velocity.at(i))*s);
        //ТЯГА
        dP.push_back(Pw+Iw+Dw);
        P.push_back(((X.at(i) + mass*G(Height.at(i))*qSin(degToRad*TrajectoryAngle.at(i)))/qCos(degToRad*AtackAngle.at(i))) + dP.at(i));
        }
    ErrHeightPrev = ErrHeight;
    }

    print(Height, N);
}

double Model::G(double height)// Функция вычисления ускорения свободного падения относительно высоты
{
    return g0 * pow((R/(R+height)), 2);
}

double Model::Phi(double height)// Функция вычисления плотности атмосферы относительно высоты
{
    return phi0 * exp(height*(-lambda));
}

//Момент инерции
double Model::Mz(double h, double v, double height_control, double atack_angle, double angle_velocity)
{
    return (mz_0 + mz_a*atack_angle + mz_w*angle_velocity + mz_b*height_control)*q(h, v)*b;
}
//Скоростной напор
double Model::q(double h, double v)
{
    return (Phi(h) * pow(v, 2)) / 2;
}


