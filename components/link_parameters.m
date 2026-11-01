% Link geometry: 150 mm agreed target; section/density are provisional assumptions.
% Homogeneous solid rectangular PLA link; rotation about Z, length along X.
L1 = struct('length',0.150, ... % m; agreed design target
            'width',0.020, ... % m; provisional
            'thickness',0.010, ... % m; provisional
            'rho',1240); % kg/m^3; provisional solid PLA
L1.m = L1.rho*L1.length*L1.width*L1.thickness;
L1.lc = L1.length/2;
L1.Icom = L1.m/12 * [L1.width^2+L1.thickness^2, ...
                     L1.length^2+L1.thickness^2, ...
                     L1.length^2+L1.width^2];
L1.I = L1.Icom(3)+L1.m*L1.lc^2; % pivot inertia about Z
% Existing consumers keep using L1.m, L1.lc and L1.I.
