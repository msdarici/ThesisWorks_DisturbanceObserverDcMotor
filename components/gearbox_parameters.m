% maxon GP 22 C, nominal 333:1, catalog part 143995.
% Source: maxon GP-22-C.pdf, March 2025, pp.421-422.
% https://www.maxongroup.com/medias/sys_master/root/9410429255710/GP-22-C.pdf
% N = motor speed / load speed. Jg is input-side equivalent gear inertia.
G1 = struct('N',69255/208, ...
            'eta',1, ... % ideal model assumption; NOT catalog efficiency
            'Jg',0.4e-7, ... % catalog 0.4 g*cm^2 -> kg*m^2
            'Bg',0, ...
            'Bv',0, ... % load-side viscous friction, not identified
            'Fc',0, ... % load-side Coulomb friction disabled
            'Fs',0, ... % load-side breakaway friction disabled
            'ws',0.1, ... % inactive friction-model shape setting, rad/s
            'we',0.05); % inactive smoothing setting, rad/s
G1.Fstr = G1.Fs - G1.Fc;

% Catalog reference data; these do not impose model limits or losses.
G1.catalog = struct('partNumber',143995, ...
                    'nominalRatio',333, ...
                    'continuousOutputTorque',1.8, ... % Nm
                    'intermittentOutputTorque',2.7, ... % Nm
                    'maxEfficiency',0.49, ...
                    'maxInputSpeedRpm',8000, ...
                    'averageNoLoadBacklashDeg',2.0, ...
                    'mass',0.081, ... % kg
                    'stages',4);
% Torque/speed limits, efficiency and backlash are NOT automatically modeled.
% Forward/backdrive losses require a separate, direction-aware model.

%% Torque limits [Nm], GEAR OUTPUT shaft
G1.tauContinuous = G1.catalog.continuousOutputTorque; % 1.8 Nm
G1.tauPeak = G1.catalog.intermittentOutputTorque;     % 2.7 Nm, NOT continuous
G1.tauMax = G1.tauContinuous; % Selected output limit for current experiment
% Fields are parameters only. Connect them to Saturation blocks explicitly.
