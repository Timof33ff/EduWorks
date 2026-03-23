function [] = modOrb()
%modOrb Модель орбитального движения
%   Формирует текущее пространственное положение 
%   КА и его скорость движения
global bortStep;    % <- Шаг моделирования, с
global julianDays;  % <- Количество Юлианских суток с эпохи J2000, сутки
global julianCent;  % <- Количество Юлианских столетий с эпохи J2000, столетия
global modRJ2k;     % -> Вектор координат центра масс КА в ИСК, км 
global modVJ2k;     % -> Вектор скоростей центра масс КА в ИСК, км/с 
global modRGsk;     % -> Вектор координат центра масс КА в гринвичской СК, км 
global modVGsk;     % -> Вектор скоростей центра масс КА в гринвичской СК, км/с 
global modQJ2k2Osk; % -> Кватернион перехода от ИСК J2000 к ОСК
global modQJ2k2Grn; % -> Кватернион перехода от ИСК J2000 к ГСК
global modWorb;     % -> Модуль уголовой скорости орбитального движения, рад/с

wE = [0 0 7.292115e-5]';    % Вектор угловой скорости вращения Земли

g = modGravAccel(modRJ2k);

%% Расчет матрицы перехода от ГСК к J2000
P = ePrecession(julianCent);
[N Na] = eNutation(julianCent);
R = eRotation(julianDays, Na);
MJ2k2Gsk = R*N*P;
modQJ2k2Grn = dcm2quat(MJ2k2Gsk);
modRJ2k = MJ2k2Gsk'*modRGsk;
modVJ2k = MJ2k2Gsk'*(modVGsk+cross(wE,modRGsk));


%% Расчет матрицы перехода от ИСК J2000 к ОСК
Oy = modRJ2k/norm(modRJ2k);
Oz = cross(modVJ2k,modRJ2k)/(norm(cross(modVJ2k,modRJ2k)));
Ox = cross(Oy, Oz)/norm(cross(Oy, Oz));
Mosk2J2k = [Ox Oy Oz];
MJ2k2osk = Mosk2J2k';
modQJ2k2Osk = dcm2quat(MJ2k2osk);

%% Нахождение угловой скорости орбитального движения
w = cross(modRJ2k, modVJ2k)/norm(modRJ2k)^2;
modOrbWOrb = quatrotate(modQJ2k2Osk, w');
modWorb = norm(modOrbWOrb);

end

