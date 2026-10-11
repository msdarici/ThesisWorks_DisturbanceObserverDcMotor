close all;
clear all;

%% Global Parametreler
g = 9.81;

%% Eklem-1 DC Motor Parametreleri
M1 = struct('Kt',9.32e-3, ...           % mNm/A -> Nm/A
            'Ke',1/(1020*2*pi/60), ...  % RPM/V -> V*s/rad
            'Rs',5.3, ...               % Ohm
            'Ls',0.14e-3, ...           % mH -> H
            'Jr',0.85e-7, ...           % gcm^2 -> kgm2
            'Br',5e-6, ...              % Nms/rad
            ... % Motor sürtünmesi (motor tarafı)
            'Bv',5e-6, ...              % viskoz [Nms/rad] (= Br)
            'Fc',0, ...                 % Coulomb [Nm]
            'Fs',0, ...                 % statik/breakaway [Nm], Fs >= Fc
            'ws',0.1, ...               % Stribeck hızı [rad/s], >0 olmalı
            'we',0.05);                 % tanh yumuşatma hızı [rad/s], >0 olmalı
M1.Fstr = M1.Fs - M1.Fc;                % statik fazlalık (blokta kullanılan)

G1 = struct('N',20, ...
            'eta',1, ...
            'Jg',0, ...
            'Bg',0, ...
            ... % Dişli sürtünmesi (yük tarafı)
            'Bv',0, ...                 % viskoz [Nms/rad]
            'Fc',0, ...                 % Coulomb [Nm]
            'Fs',0, ...                 % statik [Nm]
            'ws',0.1, ...               % [rad/s], >0
            'we',0.05);                 % [rad/s], >0
G1.Fstr = G1.Fs - G1.Fc;

L1 = struct('I',1.2e-4, ...
            'm',0.043, ...
            'lc',0.03);

Joint1 = struct('J', L1.I + G1.N^2 * (M1.Jr + G1.Jg), ...
                'tau_yuk_katsayisi', L1.m * g * L1.lc);
