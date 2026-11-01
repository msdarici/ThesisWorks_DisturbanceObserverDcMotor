% Angular unilateral wall. All quantities are LOAD-side.
% Initial exploratory settings, not identified physical material properties.
Wall = struct();
Wall.theta = pi/2 + 0.1; % rad; contact starts above this angle
Wall.Ke = 5; % Nm/rad; soft initial wall
Wall.zeta = 0.7; % contact-only damping scale (not full closed-loop damping)
Wall.De = 2*Wall.zeta*sqrt(Joint1.J*Wall.Ke); % Nm*s/rad
