close all;
clear all;

Kt = 9.32 * 1e-3;              % mNm/A -> Nm/A
Ke = 1 / (1020 * 2 *pi / 60);   % RPM/V -> rad/s
Br = 5e-6;                      % Ns
Jr = 0.85 * 1e-7;              % gcm^2 -> kgm2
Ls = 0.14 * 1e-3;              % mH -> H
Rs = 5.3;                       % Ohm

numDcMotor = Kt;
denDcMotor = [Ls*Jr Rs*Jr Kt*Ke];

%% Transfer Function
tfDcMotor = tf(numDcMotor, denDcMotor);

%% Bode Plot
figure;
bode(tfDcMotor);
grid on;
title('DC Motor Bode Diagram');

%% Poles and Zeros
fprintf('=============================\n');
fprintf('DC Motor Transfer Function\n');
fprintf('=============================\n\n');

fprintf('Poles:\n');
disp(pole(tfDcMotor));

fprintf('Zeros:\n');
disp(zero(tfDcMotor));

%% Root Locus
figure;
rlocus(tfDcMotor);
grid on;
title('DC Motor Root Locus');

Kp = 10^(-27/20);
Controller = Kp * tf([1 100], [1 0]);
figure;
bode(Controller * tfDcMotor);
grid on;
title('DC Motor Bode Diagram with controller');

T = feedback(Controller * tfDcMotor, 1);
pole(T)
step(T)

%% DOB Design
g_v = 100;
g_dob = 100;