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


