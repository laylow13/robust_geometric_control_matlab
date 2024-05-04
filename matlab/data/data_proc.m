clear
close
load("online_5_0.8.mat")   
online_param=full_param;
figure('Position', [100, 100, 900, 400])
est_clr="#FF6F4F";
true_clr="#FFBE0B";
line_width=1.2;
subplot(221)
plot(online_param.time,online_param.signals.values(:,1),"color",est_clr, 'LineWidth', line_width);
hold on 
grid on
plot(online_param.time,ones(1001,1)*P.mass,"--","color",true_clr, 'LineWidth', 1.5);
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("m [kg]", 'FontSize', 14, 'FontName', 'times')

subplot(222)
plot(online_param.time,online_param.signals.values(:,2),"color",est_clr, 'LineWidth', line_width);
hold on
grid on
plot(online_param.time,ones(1001,1)*P.Jxx,"--","color",true_clr, 'LineWidth', 1.5);
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("J_x [kgm^2]", 'FontSize', 14, 'FontName', 'times')

subplot(223)
plot(online_param.time,online_param.signals.values(:,3),"color",est_clr, 'LineWidth', line_width);
hold on
grid on
plot(online_param.time,ones(1001,1)*P.Jyy,"--","color",true_clr, 'LineWidth', 1.5);
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("J_y [kgm^2]", 'FontSize', 14, 'FontName', 'times')

subplot(224)
plot(online_param.time,online_param.signals.values(:,4),"color",est_clr, 'LineWidth', line_width);
hold on
grid on
plot(online_param.time,ones(1001,1)*P.Jzz,"--","color",true_clr, 'LineWidth', 1.5);
xlabel("time [s]",'FontSize', 14, 'FontName', 'times')
ylabel("J_z [kgm^2]", 'FontSize', 14, 'FontName', 'times')

legend1= legend("Estimated values","Actual values");
set(legend1,'Orientation','horizon')