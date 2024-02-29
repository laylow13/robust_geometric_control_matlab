syms Omega_x Omega_y Omega_z I_x I_y I_z M_x M_y M_z delta_t
dotOmega_x = (M_x - Omega_y * Omega_z * (I_z - I_y)) / I_x;
dotOmega_y = (M_y - Omega_x * Omega_z * (I_x - I_z)) / I_y;
dotOmega_z = (M_z - Omega_x * Omega_y * (I_y - I_x)) / I_z;
Omega_x_Next=dotOmega_x*delta_t+Omega_x;
Omega_y_Next=dotOmega_y*delta_t+Omega_y;
Omega_z_Next=dotOmega_z*delta_t+Omega_z;
F = [Omega_x_Next; Omega_y_Next ;Omega_z_Next;I_x ;I_y ;I_z];
vars = [Omega_x Omega_y Omega_z I_x I_y I_z];

J = jacobian(F, vars)

stateFunction = matlabFunction(J, 'Vars', {Omega_x, Omega_y, Omega_z, I_x, I_y, I_z, M_x, M_y, M_z, delta_t});
% 假设这些是给定的数值输入
Omega_x_val = 1.0;
Omega_y_val = 2.0;
Omega_z_val = 3.0;
I_x_val = 0.5;
I_y_val = 0.6;
I_z_val = 0.7;
tau_x_val = 0.1;
tau_y_val = 0.2;
tau_z_val = 0.3;
delta_t=0.1;
% 计算状态转移方程的数值结果
result = stateFunction(Omega_x_val, Omega_y_val, Omega_z_val, I_x_val, I_y_val, I_z_val, tau_x_val, tau_y_val, tau_z_val,delta_t)

% paramEstimator([ones(22,1);0],P)