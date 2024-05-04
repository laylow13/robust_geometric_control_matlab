function out = untitled(u,P)
% inputs
f       = u(1);
M       = reshape(u(2:4),3,1);
% states
p_m     = reshape(u(5:7),3,1);
v_m     = reshape(u(8:10),3,1);
R_m     = reshape(u(11:19),3,3);
q_m     = reshape(rotm2quat(R_m),4,1);
Omega_m = reshape(u(20:22),3,1);
t = u(23);

persistent ekf;
if isempty(ekf)
    % 初始状态和协方差
    initialState = ones(17,1)*1e-1;
    initialState(7:10)=[1;0;0;0];
    initialCovariance = ones(17)*1e-1+eye(17)*1;
    processNoise=eye(17)*1e-2;
    measurementNoise=eye(13)*1e-2;

    % 创建trackingEKF对象
    ekf = trackingEKF('StateTransitionFcn',@stateTransitionFcn, ...
        'MeasurementFcn',@measurementFcn, ...
        "State",initialState, ...
        'StateCovariance', initialCovariance, ...
        "ProcessNoise",processNoise, ...
        "MeasurementNoise",measurementNoise);
end
%% inertia estimate
predict(ekf,[f;M;P.Ts]); % 预测下一时刻的状态

correct(ekf, [p_m;v_m;q_m;Omega_m]); % 根据实际测量值更新状态估计

% 获取更新后的状态和协方差
stateEstimate = ekf.State;
covarianceEstimate = ekf.StateCovariance;

%% output

out=[stateEstimate(:);covarianceEstimate(:)];


end

function out= stateTransitionFcn(x,p_)
f=p_(1);
M=p_(2:4);
sample_T=p_(5);

p=x(1:3);
v=x(4:6);
q=quaternion(x(7:10)');
R=rotmat(q,'point');
Omega=x(11:13);
mass=x(14);
inertia=diag(x(15:17));

e_3=[0;0;1];
Omega_q=quaternion(0,Omega(1),Omega(2),Omega(3));

p_next=p+v*sample_T;
v_next=v+(f*R*e_3-mass*9.81*e_3)/mass*sample_T;
q_next=q+0.5*times(q,Omega_q)*sample_T;
Omega_next=Omega+inertia \ (M - cross(Omega,inertia * Omega))*sample_T;
mass_next=mass;
inertia_next=inertia;

out=zeros(17,1);
out(1:3)=p_next;
out(4:6)=v_next;
[w,i,j,k]=parts(q_next);
out(7:10)=[w;i;j;k];
out(11:13)=Omega_next;
out(14)=mass_next;
out(15:17)=diag(inertia_next);
end

function out=measurementFcn(x)
out=x(1:13);
end