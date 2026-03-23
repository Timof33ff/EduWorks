function [] = timeProgramm()
%timeProgramm Расчет бортового времени
global bortStep;    % <- Шаг моделирования, с
global bortTime;    % -> Бортовое время, с
global julianDays;  % -> Время в юлианских днях от J2000
global julianCent;  % -> Время в юлианских столетиях от J2000

%% Определение абсолютной величины времени
referenceTime = datenum(2026,02,16,10,41,56);
dateNumber = referenceTime + bortTime/86400;
dateVector = datevec(dateNumber);

year = dateVector(1);
month = dateVector(2);
day = dateVector(3);
hour = dateVector(4);
minute = dateVector(5);
second = dateVector(6);

%% Нахождение количества Юлианских дней от начала эпохи
JD=367*year-floor(7*(year+floor((month+9)/12))/4)+...
   floor(275*month/9)+day+1721013.5+...
   ((second/60+minute)/60+hour)/24;

julianDays = JD-2451545.0;
julianCent = julianDays/36525;

end

