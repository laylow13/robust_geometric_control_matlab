clear
close
load("online_5_0.8.mat")
online_states=states;
load("trad_5.mat")
trad_states=states;

online_pos=online_states.signals.values(:,1:3);
trad_pos=trad_states.signals.values(:,1:3);


online_att=online_states.signals.values(:,7:15);
[lens,~]=size(online_att);
online_yaw=zeros(lens,1);
for(i=1:lens)
R=reshape(online_att(i,:),3,3);
eulerAngles=rotm2eul(R, 'ZYX');
online_yaw(i,1)=eulerAngles(1);
end

trad_att=trad_states.signals.values(:,7:15);
[lens,~]=size(trad_att);
trad_yaw=zeros(lens,1);
for(i=1:lens)
R=reshape(trad_att(i,:),3,3);
eulerAngles=rotm2eul(R, 'ZYX');
trad_yaw(i,1)=eulerAngles(1);
end

posd=xd.signals.values;
x1d=b1d.signals.values;
[lens,~]=size(x1d);
yawd=zeros(lens,1);
for(i=1:lens)
    yawd(i,1)=atan2(x1d(i,2),x1d(i,1));
end

online_t=online_states.time;
trad_t=states.time;
t=trad_t;

online_err=online_pos(1:1007,1:3)-posd;
online_err=online_err.^2;
online_err=mean(online_err)
online_err_stable=online_pos(500:1007,1:3)-posd(500:1007,1:3);
online_err_stable=online_err_stable.^2;
online_err_stable=mean(online_err_stable)

trad_err=trad_pos-posd;
trad_err=trad_err.^2;
trad_mse=mean(trad_err)
trad_err_stable=trad_pos(500:1007,1:3)-posd(500:1007,1:3);
trad_err_stable=trad_err_stable.^2;
trad_mse_stable=mean(trad_err_stable)


figure('Position', [100, 100, 900, 600])
des_clr="#FFBE0B";
online_clr="#3A86FF";
trad_clr="#FF5607";
line_width=1.2;
subplot(321)
plot(t,posd(:,1),"--","color",des_clr, 'LineWidth', line_width);
hold on 
grid on
plot(online_t,online_pos(:,1),"color",online_clr, 'LineWidth', 1.5);
plot(t,trad_pos(:,1),"color",trad_clr, 'LineWidth', 1.5);
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("X [m]", 'FontSize', 14, 'FontName', 'times')

subplot(322)
plot(t,posd(:,2),"--","color",des_clr, 'LineWidth', line_width);
hold on 
grid on
plot(online_t,online_pos(:,2),"color",online_clr, 'LineWidth', 1.5);
plot(t,trad_pos(:,2),"color",trad_clr, 'LineWidth', 1.5);
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("Y [m]", 'FontSize', 14, 'FontName', 'times')

subplot(323)
plot(t,posd(:,3),"--","color",des_clr, 'LineWidth', line_width);
hold on 
grid on
plot(online_t,online_pos(:,3),"color",online_clr, 'LineWidth', 1.5);
plot(t,trad_pos(:,3),"color",trad_clr, 'LineWidth', 1.5);
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("Z [m]", 'FontSize', 14, 'FontName', 'times')

subplot(324)
plot(t,yawd(:,1),"--","color",des_clr, 'LineWidth', line_width);
hold on 
grid on
plot(online_t,online_yaw(:,1),"color",online_clr, 'LineWidth', 1.5);
plot(t,trad_yaw(:,1),"color",trad_clr, 'LineWidth', 1.5);
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("Yaw [rad]", 'FontSize', 14, 'FontName', 'times')

load("online_atterr.mat")
online_psi=psi.signals.values(:,10);
t3=psi.time;
load("trad_atterr.mat")
trad_psi=psi.signals.values(:,10);
t4=psi.time;
subplot(325)
plot(t3,online_psi,"color",online_clr, 'LineWidth', 1.5);
hold on
grid on
plot(t4,trad_psi,"color",trad_clr, 'LineWidth', 1.5);
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("\Psi", 'FontSize', 14, 'FontName', 'times')

psi_improv=trad_psi-online_psi;
mean(psi_improv)

start_index=400;
subplot(326)
plot(posd(start_index:1007,1),posd(start_index:1007,2),"--","color",des_clr, 'LineWidth', line_width);
hold on 
grid on
plot(online_pos(start_index:1007,1),online_pos(start_index:1007,2),"color",online_clr, 'LineWidth', 1.5);
plot(trad_pos(start_index:1007,1),trad_pos(start_index:1007,2),"color",trad_clr, 'LineWidth', 1.5);
xlabel("X [m]",'FontSize', 14, 'FontName', 'times')
ylabel("Y [m]", 'FontSize', 14, 'FontName', 'times')

legend1=legend("Tracking values","Robust geometric controller","Geometric controller");
set(legend1,'Orientation','horizon')