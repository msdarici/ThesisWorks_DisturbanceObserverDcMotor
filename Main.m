% Tek giris: tum bilesen parametrelerini ve kontrolcu hesaplarini yukler.
% GP 22 C ve link parametreleri components dosyalarindan yuklenir.
thesisRoot = fileparts(mfilename('fullpath'));
%% Motor Parametreleri tanimlaniyor.
run(fullfile(thesisRoot,'components','motor_parameters.m'));

%% Disli Parametreleri tanimlaniyor.
run(fullfile(thesisRoot,'components','gearbox_parameters.m'));

%% Effective motor torque command bound: CURRENT IDEAL GEAR MODEL
% Gear-derived provisional bound, not a verified motor rating.
M1.tauMax = G1.tauMax / G1.N;
if isfinite(M1.tauContinuous)
    M1.tauMax = min(M1.tauContinuous, M1.tauMax);
end
% Do not use tauPeak as a continuous bound; no thermal duty model exists.

%% Link Parametreleri tanimlaniyor.
run(fullfile(thesisRoot,'components','link_parameters.m'));

%% Eklem Parametreleri tanimlaniyor.
run(fullfile(thesisRoot,'components','joint_parameters.m'));

%% Cevre: acisal tek tarafli yay-damper
run(fullfile(thesisRoot,'components','environment_parameters.m'));

%% Kontrolcu parametreleri tanimlaniyor
run(fullfile(thesisRoot,'components','controller_parameters.m'));
clear thesisRoot




