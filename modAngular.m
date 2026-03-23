function [] = modAngular()
%modAngular Модель углового движения КА
%   Формирует параметры ориентации КА относительно различных систем
%   координат и угловую скорость
global modQJ2k2Body;    %-> Кватернион разворота связанного базиса относительно ИСК J2000
global modQJ2k2Osk;     %<- Кватернион перехода от ИСК J2000 к ОСК
global modQOsk2Body;    %-> Кватернион перехода от ОСК к связанному базису
global modWorb;         %<- Модуль уголовой скорости орбитального движения, рад/с
global modMTI;          %<- Матрица тензора инерции КА, кг*м2
global bortStep;        %<- Шаг моделирования, с
global modCtrlTorque;   %<- Управляющий момент от исполнительных органов, Нм
global modWSolid;       %-> Угловая скорость КА как твердого тела, рад/с
global modNSub;         %<- Количество подтактов, на которое разбивается интегрирование углового движения
global modW_sub;        %-> Угловая скорость КА на подтактах
global modMTI;          %<- Матрица тензора инерции КА


%% Цикл интегрирования по подтактам
for sub=1:1:modNSub
    modQOsk2Body = quatmultiply(modQJ2k2Body, quatconj(modQJ2k2Osk));
    j = [0 1 0];
    j = quatrotate(modQOsk2Body, j)';
    Tgrav = 3*modWorb^2*cross(j, modMTI*j);
end


end

