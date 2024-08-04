%% Constants
m = mRED; % kg
J = IRED; % kgm^2
F_max = 0.22; % N
T_max = 0.0235;% Nm
a = 25.028; % Value for low pass filter

%% Roaming Constants
Time_Look = 25; % seconds
Hz = 0.01;
Red_Rate = 0.025;

%% Bad PD
%PD control gains
%x-direction
Kp_x = 3.5;
Kd_x = 28;% 23
%y-direction
Kp_y = Kp_x;
Kd_y = Kd_x;
%rotation angle
Kp_t = 1;
Kd_t = 9.5;%25

%% CTL DAC Gains
k_1_0 = 3.5; % 3.5
k_1_t_0 = 1;
k_2_0 = 28;
k_2_t_0 = 1; % 9.5

lambda1 = 0.4;
lambda2 = 0.4;
lambda12 = 0.4;
p = 0.4;

lambda1_t = 0.05;
lambda2_t = 0.05;
lambda12_t = 0.05;
p_t = 0.05;

%% CTL LQR
    %% Setting up dynamics of system
    % Method 1 based off of PD damping ratio
    % w = 3.5;
    % wd = 16*w^(2);
    % t = 1;
    % td = 20*t^(1/2);
    % r = 1;
    % Method 2 based off of Sat damping ratio
    w = 15;
    wd = 30*w^(2);
    t = 1;
    td = 20*t^(1/2);
    r = 1;

  % Tuned for best tracking
    % w = 9138.41131640842;
    % wd = w;
    %  t = 1.00000117521453;
    % td = t;
    % r = 9.99998843608298;

    A = [0 0 0 1 0 0;
        0 0 0 0 1 0;
        0 0 0 0 0 1;
        0 0 0 0 0 0;
        0 0 0 0 0 0;
        0 0 0 0 0 0];

    B1 = [0 0 0;
        0 0 0;
        0 0 0;
        1/m 0 0;
        0 1/m 0;
        0 0 1/J];

    % Weighting matrix
    Q = [w 0 0 0 0 0;
        0 w 0 0 0 0;
        0 0 t 0 0 0;
        0 0 0 wd 0 0;
        0 0 0 0 wd 0;
        0 0 0 0 0 td];

    R = [r 0 0;
        0 r 0;
        0 0 r];

    % Solving cost eq
    k = lqr(A,B1,Q,R);

%% Saturation
gain_matrix = [0.950 0.0496 0.950;
               0.950 4.186 2.058];
a1 = gain_matrix(1,1);
b = gain_matrix(1,2);
e = gain_matrix(1,3);
c = gain_matrix(2,1);
d = gain_matrix(2,2);
e2 = gain_matrix(2,3);
% tf([a,1],[1,a],0.01)

%% CSM
k1 = m;
kt = J;
alphap = 0.25; %52.5 close
alphat = 1;
epsilon = F_max/2;
epsilont = T_max/2;

%% Homo
k1 = 5;
k2 = 28;
k1t = 2;
k2t = 16;
alphap = 1.1;
alphat = 1.1;

%% Filter
delta = 2; % offset from body to camera frame (deg)
UKF_SPOT

%% H_inf
s = zpk('s');
G = 1/(m_red*s^2);

W1 = 92.522*(s+650)/(100*s+0.01); 
W2 = 0.1; 
W3 = 1/(s+0.01);

P = augw(G,W1,W2,W3);

[K,CL,gamma_temp] = hinfsyn(P, 1, 1);

% H-Infinity Attitude Controller

G_t = 1/(I_z_red*s^2);

W1_t = 602.5*(s+650)/(100*s+0.01); 
W2_t = 0.1; 
W3_t = 1/(s+0.01); 

P_t = augw(G_t,W1_t,W2_t,W3_t);

[K_t,CL_t,~] = hinfsyn(P_t, 1, 1);

%% SAC
alpha_m = 0.1;
wn = 1.75 ;
zeta = 8 ;
Am = [0 0 1 0; 0 0 0 1; -wn^2 0 -2*zeta*wn 0; 0 -wn^2 0 -2*zeta*wn];
Bm = [0 0; 0 0; -wn^2 0; 0 -wn^2] ;
Cm = [alpha_m 0 0 0; 0 alpha_m 0 0; 0 0 1 0; 0 0 0 1];
Dm = zeros(4,2) ;
alphap = 1;

xm_0 = [RED_ini(1,1:2),0,0];