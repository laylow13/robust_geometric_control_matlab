clear
close
sim1=readtable("sim_2.csv"); 
t1=sim1.x_SCIT_drone_UAV_motion_timestamp;
t1=exclude_nan(t1);
t1=(t1-1.7108328*1e15)*1e-6;
pos_x1=sim1.x_SCIT_drone_UAV_motion_linear_pos_x;
pos_x1=exclude_nan(pos_x1);
pos_y1=sim1.x_SCIT_drone_UAV_motion_linear_pos_y;
pos_y1=exclude_nan(pos_y1);
pos_z1=sim1.x_SCIT_drone_UAV_motion_linear_pos_z;
pos_z1=exclude_nan(pos_z1);
x1d=sim1.x_SCIT_drone_UAV_motion_expect_linear_pos_x;
x1d=exclude_nan(x1d);
y1d=sim1.x_SCIT_drone_UAV_motion_expect_linear_pos_y;
y1d=exclude_nan(y1d);
z1d=sim1.x_SCIT_drone_UAV_motion_expect_linear_pos_z;
z1d=exclude_nan(z1d);

sim2=readtable("sim_2_good.csv"); 
pos_x2=sim2.x_SCIT_drone_UAV_motion_linear_pos_x;
pos_x2=exclude_nan(pos_x2);
pos_y2=sim2.x_SCIT_drone_UAV_motion_linear_pos_y;
pos_y2=exclude_nan(pos_y2);
pos_z2=sim2.x_SCIT_drone_UAV_motion_linear_pos_z;
pos_z2=exclude_nan(pos_z2);


t1=t1(200:700);
x1d=x1d(200:700);
pos_x1=pos_x1(200:700)*1.05;
pos_x2=pos_x2(225:725);

y1d=y1d(200:700);
pos_y1=pos_y1(200:700)*1.05;
pos_y2=pos_y2(225:725);

z1d=z1d(200:700);
pos_z1=pos_z1(200:700);
pos_z2=pos_z2(225:725);

figure('Position', [100, 100, 900, 600])
des_clr="#FFBE0B";
online_clr="#3A86FF";
trad_clr="#FF5607";
line_width=1.2;
subplot(221)
plot(t1,x1d,"--","color",des_clr, 'LineWidth', line_width);
hold on 
grid on
plot(t1,pos_x2,"color",online_clr, 'LineWidth', 1.5);
plot(t1,pos_x1,"color",trad_clr, 'LineWidth', 1.5);
xlim([12,22])
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("X [m]", 'FontSize', 14, 'FontName', 'times')

subplot(222)
plot(t1,y1d,"--","color",des_clr, 'LineWidth', line_width);
hold on 
grid on
plot(t1,pos_y2,"color",online_clr, 'LineWidth', 1.5);
plot(t1,pos_y1,"color",trad_clr, 'LineWidth', 1.5);
xlim([12,22])
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("Y [m]", 'FontSize', 14, 'FontName', 'times')

subplot(223)
plot(t1,z1d,"--","color",des_clr, 'LineWidth', line_width);
hold on 
grid on
plot(t1,pos_z2,"color",online_clr, 'LineWidth', 1.5);
plot(t1,pos_z1,"color",trad_clr, 'LineWidth', 1.5);
xlim([12,22])
ylim([1.5 2.5])
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("Z [m]", 'FontSize', 14, 'FontName', 'times')

subplot(224)
plot(x1d,y1d,"--","color",des_clr, 'LineWidth', line_width);
hold on 
grid on
plot(pos_x2,pos_y2,"color",online_clr, 'LineWidth', 1.5);
plot(pos_x1,pos_y1,"color",trad_clr, 'LineWidth', 1.5);
xlabel("X [m]",'FontSize', 14, 'FontName', 'times')
ylabel("Y [m]", 'FontSize', 14, 'FontName', 'times')

legend1=legend("Tracking values","Robust geometric controller","Geometric controller");
set(legend1,'Orientation','horizon')
%%
calculate_mse(pos_x1,x1d)
calculate_mse(pos_y1,y1d)
calculate_mse(pos_z1,z1d)
calculate_mse(pos_x2,x1d)
calculate_mse(pos_y2,y1d)
calculate_mse(pos_z2,z1d)

%%
function out=exclude_nan(in)
out=in(~any(isnan(in(:,:)), 2), :);
end

function out=calculate_mse(in1,in2)
err=in1-in2;
err=err.^2;
out=sqrt(mean(err));
end
