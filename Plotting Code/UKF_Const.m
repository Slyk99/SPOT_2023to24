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
x = [0.814723871669493	0.162183146010935	0.644318485875562	0.0596198079607716	0.422886266214395	0.582249582278063	8.50712689217740	0.559032985956150	34.1857789367023	49.3967367596900	0.631189103080277	0.782872290107050	0.503781281995370	4.06726974416672];
Q_Black  =  [x(1) 0 0 0 0 0;
               0 x(1) 0 0 0 0;
               0 0 x(2) 0 0 0;
               0 0 0 x(3) 0 0;
               0 0 0 0 x(3) 0;
               0 0 0 0 0 x(4)]; %% Change this
R_Black = [x(5) 0 0;
            0 x(5) 0;
            0 0 x(6)];
thresh_Black = 7;%x(7);
alpha_Black = x(8); % very small var, never > 1
beta_Black = 2; % 2 for gaussian
kappa_Black = x(9); % Starts at zero, usually small
lamda_Black = (alpha_Black^2)*(N + kappa_Black) - N; % N is the number of dimensions
P_IC_Black = [x(10) 0 0 0 0 0;
               0 x(10) 0 0 0 0;
               0 0 x(11) 0 0 0;
               0 0 0 x(12) 0 0;
               0 0 0 0 x(12) 0;
               0 0 0 0 0 x(13)]; %% Change this
thresh_Factor_Black = x(14);

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