% Tek giris: tum bilesen parametrelerini ve kontrolcu hesaplarini yukler.
% GP 22 C ve link parametreleri components dosyalarindan yuklenir.
thesisRoot = fileparts(mfilename('fullpath'));
%% Motor Parametreleri tanimlaniyor.
run(fullfile(thesisRoot,'components','motor_parameters.m'));

%% Disli Parametreleri tanimlaniyor.
run(fullfile(thesisRoot,'components','gearbox_parameters.m'));

%% Link Parametreleri tanimlaniyor.
run(fullfile(thesisRoot,'components','link_parameters.m'));

%% Eklem Parametreleri tanimlaniyor.
run(fullfile(thesisRoot,'components','joint_parameters.m'));

%% Kontrolcu parametreleri tanimlaniyor
run(fullfile(thesisRoot,'components','controller_parameters.m'));
clear thesisRoot


