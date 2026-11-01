% Run Main first. This script inspects the nominal cascade, not the full SLX.
[bw,Bload,designControllers] = bandwidth_design(M1,G1,Joint1);
s = tf('s');
Pi = 1/(M1.Ls*s+M1.Rs);
Ci = designControllers.akim.Kp+designControllers.akim.Ki/s;
Li = minreal(Ci*Pi);
Ti = minreal(feedback(Li,1));
Pv = G1.N/(Joint1.J*s+Bload);
Cv = designControllers.hiz.Kp+designControllers.hiz.Ki/s;
LvIdeal = minreal(Cv*Pv);
TvIdeal = minreal(feedback(LvIdeal,1));
% Finite current-loop approximation; excludes residual back-EMF coupling.
Lv = minreal(Cv*Ti*Pv);
Tv = minreal(feedback(Lv,1));
Cp = designControllers.poz.Kp;
Lp = minreal(Cp*Tv/s);
Tp = minreal(feedback(Lp,1));
w = logspace(-2,6,2500);
f = figure('Name','Nominal cascade bandwidths');
tiledlayout(3,2);
nexttile; bodemag(Li,w); grid on; title('Current: open loop (0 dB crossing)');
nexttile; bodemag(Ti,w); grid on; title('Current: closed loop (-3 dB bandwidth)');
nexttile; bodemag(LvIdeal,Lv,w); grid on; title('Speed: open loop');
legend('Ideal current loop','Finite current loop','Location','southwest');
nexttile; bodemag(TvIdeal,Tv,w); grid on; title('Speed: closed loop');
legend('Ideal current loop','Finite current loop','Location','southwest');
nexttile; bodemag(Lp,w); grid on; title('Position: open loop');
nexttile; bodemag(Tp,w); grid on; title('Position: closed loop');
% Default Control System Toolbox frequency unit is rad/s.
[~,pmI,~,wcI]=margin(Li);
[~,pmV,~,wcV]=margin(Lv);
[~,pmP,~,wcP]=margin(Lp);
bandwidthSummary=table(["Current";"Speed";"Position"], ...
 [bw.current;bw.speed;bw.position],[wcI;wcV;wcP], ...
 [bandwidth(Ti);bandwidth(Tv);bandwidth(Tp)],[pmI;pmV;pmP], ...
 'VariableNames',{'Loop','Target_rad_s','Crossover_rad_s','Bandwidth_rad_s','PhaseMargin_deg'});
disp(bandwidthSummary);
assert(abs(designControllers.hiz.Ki/designControllers.hiz.Kp-Bload/Joint1.J)<1e-10);
assert(isstable(Ti)&&isstable(Tv)&&isstable(Tp),'Nominal cascade unstable');
assert(abs(dcgain(Tp)-1)<1e-8);
dest=fullfile(fileparts(mfilename('fullpath')),'report','figures');
if ~exist(dest,'dir'), mkdir(dest); end
exportgraphics(f,fullfile(dest,'cascade_bode.png'),'Resolution',150);
writetable(bandwidthSummary,fullfile(dest,'bandwidth_summary.csv'));
fprintf('Nominal checks passed. Bload=%.9g; speed Kp=%.9g Ki=%.9g\n', ...
 Bload,designControllers.hiz.Kp,designControllers.hiz.Ki);

