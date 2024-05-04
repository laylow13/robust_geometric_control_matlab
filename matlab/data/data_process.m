close
figure()
subplot(321)
hold on;
grid on
plot(full_state_est.time,full_state_est.signals.values(:,1),"r-", 'LineWidth', 1.5);
plot(full_state_est.time,full_state_est.signals.values(:,2),"g-", 'LineWidth', 1.5);
plot(full_state_est.time,full_state_est.signals.values(:,3),"b-", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,1),"r--", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,2),"g--", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,3),"b--", 'LineWidth', 1.5);
% legend("p_x","p_y","p_z","err_x","err_y","err_z")
legend("p_x","p_y","p_z")
subplot(322)
hold on;
grid on
plot(full_state_est.time,full_state_est.signals.values(:,4),"r-", 'LineWidth', 1.5);
plot(full_state_est.time,full_state_est.signals.values(:,5),"g-", 'LineWidth', 1.5);
plot(full_state_est.time,full_state_est.signals.values(:,6),"b-", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,4),"r--", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,5),"g--", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,6),"b--", 'LineWidth', 1.5);
% legend("v_x","v_y","v_z","err_x","err_y","err_z")
legend("v_x","v_y","v_z")
subplot(323)
hold on;
grid on
plot(full_state_est.time,full_state_est.signals.values(:,7),"r-", 'LineWidth', 1.5);
plot(full_state_est.time,full_state_est.signals.values(:,8),"g-", 'LineWidth', 1.5);
plot(full_state_est.time,full_state_est.signals.values(:,9),"b-", 'LineWidth', 1.5);
plot(full_state_est.time,full_state_est.signals.values(:,10),'k-', 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,7),"r--", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,8),"g--", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,9),"b--", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,10),"k--", 'LineWidth', 1.5);
% legend("q_1","q_2","q_3","q_4","err_1","err_2","err_3","err_4");
legend("q_1","q_2","q_3","q_4");
subplot(324)
hold on;
grid on
plot(full_state_est.time,full_state_est.signals.values(:,11),"r-", 'LineWidth', 1.5);
plot(full_state_est.time,full_state_est.signals.values(:,12),"g-", 'LineWidth', 1.5);
plot(full_state_est.time,full_state_est.signals.values(:,13),"b-", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,11),"r--", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,12),"g--", 'LineWidth', 1.5);
% plot(full_est_err.time,full_est_err.signals.values(:,13),"b--", 'LineWidth', 1.5);
legend("\Omega_x","\Omega_y","\Omega_z")
subplot(325)
hold on;
grid on
plot(full_param_est.time,full_param_est.signals.values(:,1),"r-", 'LineWidth', 1.5);
plot(full_est_err.time,full_est_err.signals.values(:,14),"r--", 'LineWidth', 1.5);
legend("mass","err")
subplot(326)
hold on;
grid on
plot(full_param_est.time,full_param_est.signals.values(:,2),"r-", 'LineWidth', 1.5);
plot(full_param_est.time,full_param_est.signals.values(:,3),"g-", 'LineWidth', 1.5);
plot(full_param_est.time,full_param_est.signals.values(:,4),"b-", 'LineWidth', 1.5);
plot(full_est_err.time,full_est_err.signals.values(:,15),"r--", 'LineWidth', 1.5);
plot(full_est_err.time,full_est_err.signals.values(:,16),"g--", 'LineWidth', 1.5);
plot(full_est_err.time,full_est_err.signals.values(:,17),"b--", 'LineWidth', 1.5);
legend("J_x","J_y","J_z","err_x","err_y","err_z")