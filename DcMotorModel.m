%% Current Controller Design
% Ana struct tanımlaması
kontrolculer = struct();

% Ham sistem
tFuncElec = tf(1, [M1.Ls M1.Rs]);
figure('Name','Elektriksel Transfer Fonksiyonu');
bode(tFuncElec);

% Akım kontrolcüsü parametreleri
kontrolculer.akim.Kp = M1.Ls * 5e3 * 2 * pi;
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
kontrolculer.hiz.Kp = Joint1.J * 5e2 * 2 * pi;
kontrolculer.hiz.Ki = kontrolculer.hiz.Kp * M1.Bv / Joint1.J;
kontrolculer.hiz.Kd = 0.0;
kontrolculer.hiz.Kaw = 0.0;

%% Position Controller Design

% Poz kontrolcüsü parametreleri
kontrolculer.poz.Kp = 200 * 2 * pi;
kontrolculer.poz.Ki = 0.0;
kontrolculer.poz.Kd = 0.0;
kontrolculer.poz.Kaw = 0.0;