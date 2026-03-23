function [N, Na] = eNutation(tau)
%eNutation Расчет матрицы нутации Земли
eps0 = 0.4090928042 - 0.2269655*10^-3*tau - 0.29*10^-8*tau^2 + 0.88*10^-8*tau^3;

%   Расчет матрицы нутации Земли на основе времени от эпохи J2000 в
%   Юлианских столетиях
Mm = 2.355548393 + 8328.69142288*tau + 1.517952*10^-4*tau^2 + 3.103*10^-7*tau^3;
Ms = 6.24003594 + 628.30195602*tau - 2.7974*10^-6*tau^2 - 5.82*10^-8*tau^3;
Fm = 1.62790193 + 8433.46615831*tau - 6.42717*10^-5*tau^2 + 5.33*10^-8*tau^3;
Ds = 5.19846951 + 7771.37714617*tau - 3.34085*10^-5*tau^2 + 9.21*10^-8*tau^3;
Om = 2.182438624 - 33.757045936*tau + 3.61429*10^-5*tau^2 + 3.88*10^-8*tau^3;

Nf = -0.83386e-4*sin(Om)+0.9997e-6*sin(2*Om)-0.63932e-5*sin(2*Fm-2*Ds+2*Om)...
     +0.6913e-6*sin(Ms)-0.11024e-5*sin(2*Fm+2*Om);
Ne = 0.44615e-4*cos(Om)+0.27809e-5*cos(2*Fm-2*Ds+2*Om)+0.474e-6*cos(2*Fm+2*Om);

eps = eps0 + Ne;
N = [cos(Nf)          -sin(Nf)*cos(eps0)                             -sin(Nf)*sin(eps0)
     sin(Nf)*cos(eps)  cos(Nf)*cos(eps)*cos(eps0)+sin(eps)*sin(eps0)  cos(Nf)*cos(eps)*sin(eps0)-sin(eps)*cos(eps0)
     sin(Nf)*sin(eps)  cos(Nf)*sin(eps)*cos(eps0)-cos(eps)*sin(eps0)  cos(Nf)*sin(eps)*sin(eps0)+cos(eps)*cos(eps0)];
Na = Nf*cos(eps);


end

