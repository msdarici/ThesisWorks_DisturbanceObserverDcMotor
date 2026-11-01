function [bw,Bload,c] = bandwidth_design(M1,G1,Joint1)
% Proposed nominal gains; does not alter the active controller workspace.
bw = struct('current',5000*2*pi,'speed',500*2*pi,'position',2*pi);
Bload = G1.N^2*M1.Bv+G1.Bv;
c.akim=struct('Kp',M1.Ls*bw.current,'Ki',M1.Rs*bw.current,'Kd',0,'Kaw',0);
c.hiz=struct('Kp',Joint1.J*bw.speed/G1.N,'Ki',Bload*bw.speed/G1.N,'Kd',0,'Kaw',0);
c.poz=struct('Kp',bw.position,'Ki',0,'Kd',0,'Kaw',0);
end
