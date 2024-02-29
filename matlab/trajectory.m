function out = trajectory(u,P)

t = u(end);
%% upside down
% xd = [0 0 0];
% b1d = [1 0 0];
% 
% f = 0.5;
% % xd = [0 0 sin(2*pi*f*t)];

%% round
r=3;
w=1.5;
v_z=0.5;
xd = [r*cos(w*t) r*sin(w*t) v_z*t];
% b1d = [1 0 0];% fixed yaw
b1d = [-xd(1) -xd(2) xd(3)];% followed yaw

%%
out = [xd b1d];

end