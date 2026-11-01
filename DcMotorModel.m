% Tek giris: tum bilesen parametrelerini ve kontrolcu hesaplarini yukler.
% Degerler mevcut modelden aynen tasindi; redaktor orani halen eski N=20.
thesisRoot = fileparts(mfilename('fullpath'));
run(fullfile(thesisRoot,'components','motor_parameters.m'));
run(fullfile(thesisRoot,'components','gearbox_parameters.m'));
run(fullfile(thesisRoot,'components','link_parameters.m'));
run(fullfile(thesisRoot,'components','joint_parameters.m'));
run(fullfile(thesisRoot,'components','controller_parameters.m'));
clear thesisRoot

