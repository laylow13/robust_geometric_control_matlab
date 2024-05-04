function out = trajectory(u,P)

t = u(end);
% global P;
% if t>5
% P.mass=6;
% P.Jxx     = 0.3; % [kg-m2]
% P.Jyy     = 0.3; % [kg-m2]
% P.Jzz     = 0.5; 
% end
%% upside down
% xd = [0 0 0];
% b1d = [1 0 0];
%
% f = 0.5;
% % xd = [0 0 sin(2*pi*f*t)];

%% round
r=3;
w=1.2;
v_z=0.5;
xd = [r*cos(w*t) r*sin(w*t) 2];
% b1d = [1 0 0];% fixed yaw
b1d = [-xd(1) -xd(2) xd(3)];% followed yaw
%% double round
% r=3;
% w=0;
% v_z=0.5;
% if t>1.5 &&t<4 
%     w=0.5*(t-1.5);
% else
%     w=1.2;
% end
% if t<=1.5
%     xd = [3 0 -2];
%     b1d = [1 0 -2];
% else
%     xd = [r*cos(w*(t-1.5)) r*sin(w*(t-1.5)) -2];
%     b1d = [xd(1) xd(2) xd(3)];% followed yaw
% end
% % else
%     xd = [r*cos(-w*t+pi/2) -3+r*sin(-w*t+pi/2) -2];
%     b1d = [xd(1) xd(2)+3 xd(3)];% followed yaw
% end
%%
% persistent traj_plot;
% if t == 0
%     %%%%%%%%%%%%%%%%
%     figure(6),clf
%     traj_plot = plot3(xd(1), xd(2),xd(3), 'LineWidth', 2);
%     title("期望轨迹")
% else
%     XX = get(traj_plot,'XData'); YY = get(traj_plot,'YData');ZZ = get(traj_plot,'ZData');
%     set(traj_plot,'XData',[XX xd(1)],'YData',[YY xd(2)],'ZData',[YY xd(3)]);
%     drawnow
% end
out = [xd b1d];

end