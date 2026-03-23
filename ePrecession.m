function [P] = ePrecession(tau)
%ePrecession Вычисление матрицы прецессии Земли
%   Расчет матрицы прецессии Земли на основе времени от эпохи J2000 в
%   Юлианских столетиях

zeta = 0.111808609e-1*tau + 0.146356e-5*tau^2 + 0.872e-7*tau^3;
z    = 0.111808609e-1*tau + 0.53072e-5*tau^2 + 0.883e-7*tau^3;
theta= 0.97171735e-2*tau - 0.20685e-5*tau^2 - 0.2028e-6*tau^3;

P= [cos(zeta)*cos(z)*cos(theta)-sin(zeta)*sin(z) -sin(zeta)*cos(z)*cos(theta)-cos(zeta)*sin(z) -cos(z)*sin(theta)
    cos(zeta)*sin(z)*cos(theta)+sin(zeta)*cos(z) -sin(zeta)*sin(z)*cos(theta)+cos(zeta)*cos(z) -sin(z)*sin(theta)
    cos(zeta)*sin(theta)                         -sin(zeta)*sin(theta)                          cos(theta)];
end

