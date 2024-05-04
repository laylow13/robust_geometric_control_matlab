function out = paramEstimator(u,P)

% inputs
f       = u(1);
M       = reshape(u(2:4),3,1);
% states
x     = u(5:7);
v     = reshape(u(8:10),3,1);
R     = reshape(u(11:19),3,3);
Omega = reshape(u(20:22),3,1);
t = u(23);
sample_T=0.01;
persistent dvdt;

persistent m;
persistent var_m R_m Q_m;

persistent ekf;
% persistent traj_plot;
if t==0
    % figure(7),clf
    % traj_plot = plot3(0, 0,0, 'LineWidth', 2);
    % title("轨迹")
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    dvdt = DirtyDerivative(1, 0.05, 0.01);
    m = 2.0;
    var_m = 1;
    R_m = 0.001;
    Q_m = 0.01;
%% 初始化惯性矩阵估计 
    measurementJacobianFcn = @(x)[eye(3) zeros(3)];
    
    % 初始状态和协方差
    initialState = ones(6,1)*1e-3;
    initialState(4:6)=[0.05,0.05,0.1];
    initialCovariance = ones(6)*1e-3+eye(6)*1;
    processNoise=eye(6)*1e-4;
    measurementNoise=eye(3)*1e-4;
    
    % 创建trackingEKF对象
    ekf = trackingEKF('StateTransitionFcn',@stateTransitionFcn, ...
        'MeasurementFcn',@measurementFcn, ...
        "State",initialState, ...
        'StateCovariance', initialCovariance, ...
        'MeasurementJacobianFcn', measurementJacobianFcn, ...
        "ProcessNoise",processNoise, ...
        "MeasurementNoise",measurementNoise);
end
%%%%%%%%%%%%%%%%
% XX = get(traj_plot,'XData'); YY = get(traj_plot,'YData');ZZ = get(traj_plot,'ZData');
% set(traj_plot,'XData',[XX x(1)],'YData',[YY x(2)],'ZData',[YY x(3)]);
% drawnow
%%%%%%%%%%%%%%%%
%% mass estimate
% numerical derivatives
acc = dvdt.calculate(v);
% 1 predict
var_m = var_m + R_m;
% 2 update
e_z = [0;0;1];
body_z = R * e_z;
% calculate H
H_m = -f * body_z(3) / (m * m);
% calculate K
K_m = var_m * H_m / (H_m * var_m * H_m + Q_m);
% update
acc_hat = f * body_z(3) / m - P.gravity;
m = m + K_m * (acc(3) - acc_hat);
var_m = (1.0 - K_m * H_m) * var_m;

%% inertia estimate
predict(ekf,[M;sample_T]); % 预测下一时刻的状态
correct(ekf, Omega); % 根据实际测量值更新状态估计

% 获取更新后的状态和协方差
stateEstimate = ekf.State;
covarianceEstimate = ekf.StateCovariance;


%% output
m_=m;

Omega_est=stateEstimate(1:3);
jxx=stateEstimate(4);
jyy=stateEstimate(5);
jzz=stateEstimate(6);

m_err=m-P.mass;
jxx_err=jxx-P.Jxx;
jyy_err=jyy-P.Jyy;
jzz_err=jzz-P.Jzz;
out=[m_;m_err;jxx;jyy;jzz;jxx_err;jyy_err;jzz_err];




end

function out= stateTransitionFcn(x,p_)
out=zeros(6,1);

% disp(x);
Omega=x(1:3);
inertia = diag(x(4:6));
M=p_(1:3);
sample_T=p_(4);
dotOmega=inertia \ (M - cross(Omega,inertia * Omega));
out(1:3)=x(1:3)+sample_T*dotOmega;
out(4:6)=x(4:6);
end

function out=measurementFcn(x)
out=x(1:3);
end

% function out = stateTransitionJacobianFcn(x,p_)
% syms Omega_x Omega_y Omega_z I_x I_y I_z M_x M_y M_z delta_t;
% dotOmega_x = (M_x - Omega_y * Omega_z * (I_z - I_y)) / I_x;
% dotOmega_y = (M_y - Omega_x * Omega_z * (I_x - I_z)) / I_y;
% dotOmega_z = (M_z - Omega_x * Omega_y * (I_y - I_x)) / I_z;
% Omega_x_Next=dotOmega_x*delta_t+Omega_x;
% Omega_y_Next=dotOmega_y*delta_t+Omega_y;
% Omega_z_Next=dotOmega_z*delta_t+Omega_z;
% F = [Omega_x_Next; Omega_y_Next ;Omega_z_Next;I_x ;I_y ;I_z];
% vars = [Omega_x Omega_y Omega_z I_x I_y I_z];
% 
% J = jacobian(F, vars);
% 
% calculateJacobian = matlabFunction(J, 'Vars', {Omega_x, Omega_y, Omega_z, I_x, I_y, I_z, M_x, M_y, M_z, delta_t});
% out=calculateJacobian(x(1),x(2),x(3),x(4),x(5),x(6),p_(1),p_(2),p_(3),p_(4));
% 
% end