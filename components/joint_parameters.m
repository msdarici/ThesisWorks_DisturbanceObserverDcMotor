g = 9.81; % m/s^2; physical gravity; plane selection is not changed here
Joint1 = struct('J', L1.I + G1.N^2 * (M1.Jr + G1.Jg), ...
                'tau_yuk_katsayisi', L1.m * g * L1.lc);



% Motor friction is subtracted before gear torque multiplication.
% omega_motor=N*omega_load => equivalent load damping N^2*Bmotor.
Joint1.B = G1.N^2 * M1.Bv + G1.Bv; % N*m*s/rad, load side

