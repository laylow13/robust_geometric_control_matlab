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

persistent dvdt;
persistent dOmegadt;

persistent m;
persistent var_m R_m Q_m;

persistent j;
persistent var_j R_j Q_j;

if t == 0
    dvdt = DirtyDerivative(1, P.tau, P.Ts);
    dOmegadt= DirtyDerivative(1, P.tau, P.Ts);%cutoff!!!
    % initialize m=; m_var=; Jxx=; Jyy=; Jzz=; J_var;
    m = 0.001;
    var_m = 0.001;
    R_m = 0.001;
    Q_m = 1.0;

    j = [0.001; 0.001; 0.001;];
    var_j =[0.01, 0.001, 0.001;
        0.001, 0.01, 0.001;
        0.001, 0.001, 0.01];
    R_j = [0.01, 0.001, 0.001;
        0.001, 0.01, 0.001;
        0.001, 0.001, 0.01;];
    Q_j = [0.01, 0.001, 0.001;
        0.001, 0.01, 0.001;
        0.001, 0.001, 0.01;];

end
% numerical derivatives 
acc = dvdt.calculate(v);
ang_acc = dOmegadt.calculate(Omega);
%EKF algorithm
%%%%%%%%%%%%%%%%%%%1 predict
var_m = var_m + R_m;
var_j = var_j + R_j;
%%%%%%%%%%%%%%%%%%%2 update
e_z = [0;0;1];
body_z = R * e_z;
% calculate H
H_m = -f * body_z(3) / (m * m);

jx = j(1);
jy = j(2);
jz = j(3);
avx = Omega(1);
avy = Omega(2);
avz = Omega(3);

H_j(1, 1) = (jz - jy) / (jx * jx) * avy * avz - M(1) / (jx * jx);
H_j(1, 2) = avy * avz / jx;
H_j(1, 3) = -avy * avz / jx;

H_j(2, 1) = -avx * avz / jy;
H_j(2, 2) = (jx - jz) / (jy * jy) * avx * avz - M(2) / (jy * jy);
H_j(2, 3) = avx * avz / jy;

H_j(3, 1) = avy * avx / jz;
H_j(3, 2) = -avy * avx / jz;
H_j(3, 3) = (jy - jx) / (jz * jz) * avx * avy - M(3) / (jz * jz);

% calculate K
K_m = var_m * H_m / (H_m * var_m * H_m + Q_m);
var_innov = H_j * var_j * H_j' + Q_j;
K_j = (var_j * H_j')/var_innov;

%update
acc_hat = f * body_z(3) / m - P.gravity;
m = m + K_m * (acc(3) - acc_hat);
var_m = (1.0 - K_m * H_m) * var_m;

I =eye(3);
inertia = [j(1), 0, 0;
    0, j(2), 0;
    0, 0, j(3);];
% inertia_inv = inv(inertia);
ang_acc_hat = inertia \ (M - cross(Omega,inertia * Omega));
j = j + K_j * (ang_acc - ang_acc_hat);
var_j = (I - K_j * H_j) * var_j;

% output
m_=m;
jxx=j(1);
jyy=j(2);
jzz=j(3);

m_err=m-P.mass;
jxx_err=jxx-P.Jxx;
jyy_err=jyy-P.Jyy;
jzz_err=jzz-P.Jzz;
out=[m_;m_err;jxx;jyy;jzz;jxx_err;jyy_err;jzz_err];


end