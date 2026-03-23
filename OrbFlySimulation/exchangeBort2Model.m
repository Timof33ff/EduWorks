function [] = exchangeBort2Model()
%exchangeBort2Model Передача данных из бортовых программ в модели
global bortCtrlAct;     % <-Управляющее воздействие, расчитанное в бортовых алгоритмах
global modCtrlAct;      % ->Управляющее воздействие, расчитанное в бортовых алгоритмах

modCtrlAct = bortCtrlAct;
end

