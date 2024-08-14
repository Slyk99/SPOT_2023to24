    %% Spacecraft Data
    m = 11.210; % kg  
    J = 0.20184; % kgm^2
    dt = 0.01; % seconds
    N = 6; % Number of states
    method = 1; % Method of NSPDM

    %% Kalman Filter setup
    % State transition matrix
    A = [1 0 0 dt 0 0;
         0 1 0 0 dt 0;
         0 0 1 0 0 dt;
         0 0 0 1 0 0;
         0 0 0 0 1 0;
         0 0 0 0 0 1];
    % sensor data
    H = [1 0 0 0 0 0;
         0 1 0 0 0 0;
         0 0 1 0 0 0];

%% Black
Q_Black = [0.0000005 0 0 0 0 0;
               0 0.0000005 0 0 0 0;
               0 0 0.00005 0 0 0;
               0 0 0 0.00005 0 0;
               0 0 0 0 0.00005 0;
               0 0 0 0 0 0.00005];
variance = 0.99;
R_Black = [variance 0 0;
    0 variance 0;
    0 0 variance];
alpha_Black = 0.9; % very small var, never > 1
beta_Black = 2; % 2 for gaussian
kappa_Black = 20; % Starts at zero, usually small
lamda_Black = (alpha_Black^2)*(N + kappa_Black) - N; % N is the number of dimensions
P_IC_Black = 0.2*eye(6); %% Change this

thresh_Black = 7.815;
thresh_Factor_Black = 0.1;

%% Blue
var = 0.005;
Q_Blue  =  [dt 0 0 0 0 0;
               0 dt 0 0 0 0;
               0 0 dt 0 0 0;
               0 0 0 dt 0 0;
               0 0 0 0 dt 0;
               0 0 0 0 0 dt]*var; %% Change this
variance = 0.99;
R_Blue = [variance 0 0;
    0 variance 0;
    0 0 variance];
thresh_Blue = 7.815;
alpha_Blue = 0.9; % very small var, never > 1
beta_Blue = 2; % 2 for gaussian
kappa_Blue = 20; % Starts at zero, usually small
lamda_Blue = (alpha_Blue^2)*(N + kappa_Blue) - N; % N is the number of dimensions
P_IC_Blue = 0.2*eye(6); %% Change this
thresh_Factor_Blue = 0.5;