close all;

numDcMotor = M1.Kt;
denDcMotor = [M1.Ls*M1.Jr M1.Rs*M1.Jr M1.Kt*M1.Ke];

%% Transfer Function
tfDcMotor = tf(numDcMotor, denDcMotor);

%% Bode Plot
% figure;
% bode(tfDcMotor);
% grid on;
% title('DC Motor Bode Diagram');

%% Poles and Zeros
% fprintf('=============================\n');
% fprintf('DC Motor Transfer Function\n');
% fprintf('=============================\n\n');
% 
% fprintf('Poles:\n');
% disp(pole(tfDcMotor));
% 
% fprintf('Zeros:\n');
% disp(zero(tfDcMotor));

%% Root Locus
% figure;
% rlocus(tfDcMotor);
% grid on;
% title('DC Motor Root Locus');
% 
% Kp = 10^(-27/20);
% Controller = Kp * tf([1 100], [1 0]);
% figure;
% bode(Controller * tfDcMotor);
% grid on;
% title('DC Motor Bode Diagram with controller');
% 
% T = feedback(Controller * tfDcMotor, 1);
% pole(T)
% step(T)

%% DOB Design
% g_v = 100;
% g_dob = 100;

%% Current Controller Design
% Ana struct tanımlaması
kontrolculer = struct();

% Ham sistem
tFuncElec = tf(1, [M1.Ls M1.Rs]);
figure('Name','Elektriksel Transfer Fonksiyonu');
bode(tFuncElec);

% Akım kontrolcüsü parametreleri
kontrolculer.akim.Kp = M1.Ls * 4e3 * 2 * pi;
kontrolculer.akim.Ki = kontrolculer.akim.Kp * M1.Rs / M1.Ls;
kontrolculer.akim.Kd = 0.0;
kontrolculer.akim.Kaw = 0.0;

controller = tf([kontrolculer.akim.Kp kontrolculer.akim.Ki], [1 0]);
figure('Name','Kontrolcu Eklenmis Elektriksel Transfer Fonksiyonu');
bode(controller * tFuncElec);

%% Speed Controller Design
% Ham sistem
tFuncElec = tf(1, [Joint1.J M1.Bv]);
figure('Name','Mekanik Transfer Fonksiyonu');
bode(tFuncElec);

% Hiz kontrolcüsü parametreleri
kontrolculer.hiz.Kp = Joint1.J * 4e2 * 2 * pi;
kontrolculer.hiz.Ki = kontrolculer.akim.Kp * M1.Bv / Joint1.J;
kontrolculer.hiz.Kd = 0.0;
kontrolculer.hiz.Kaw = 0.0;

%% Position Controller Design

% Poz kontrolcüsü parametreleri
kontrolculer.poz.Kp = 4e1 * 2 * pi;
kontrolculer.poz.Ki = 0.0;
kontrolculer.poz.Kd = 0.0;
kontrolculer.poz.Kaw = 0.0;