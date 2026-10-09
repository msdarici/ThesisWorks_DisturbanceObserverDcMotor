close all;
clear all;

%% DC Motor Parametreleri
Kt = 9.32 * 1e-3;              % mNm/A -> Nm/A
Ke = 1 / (1020 * 2 *pi / 60);  % RPM/V -> rad/s
Br = 5e-6;                     % Ns
Jr = 0.85 * 1e-7;              % gcm^2 -> kgm2
Ls = 0.14 * 1e-3;              % mH -> H
Rs = 5.3;                      % Ohm

%% Pendulum Parametreleri
I1 = 0.00012;
m = 0.043;
l_c = 0.03;

g = 9.81;

%% Sistem Parametreleri
J_sys = Jr + I1;