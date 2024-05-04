close
figure()
subplot(311)
plot(commands.time,commands.signals.values(:,1),'k--', 'LineWidth', 1.5);
hold on 
plot(states_online.time,states_online.signals.values(:,1),'r', 'LineWidth', 1.5);
plot(states_trad.time,states_trad.signals.values(:,1),'b', 'LineWidth', 1.5);
legend("p_{x_d}","p_{x_1}","p_{x_2}")

subplot(312)
plot(commands.time,commands.signals.values(:,2),'k--', 'LineWidth', 1.5);
hold on
plot(states_online.time,states_online.signals.values(:,2),'r', 'LineWidth', 1.5);
plot(states_trad.time,states_trad.signals.values(:,2),'b', 'LineWidth', 1.5);
legend("p_{y_d}","p_{y_1}","p_{y_2}")

subplot(313)
plot(commands.time,commands.signals.values(:,3),'k--', 'LineWidth', 1.5);
hold on
plot(states_online.time,states_online.signals.values(:,3),'r', 'LineWidth', 1.5);
plot(states_trad.time,states_trad.signals.values(:,3),'b', 'LineWidth', 1.5);
legend("p_{z_d}","p_{z_1}","p_{z_2}")