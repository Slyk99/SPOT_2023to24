%% Clear
close all
clear
clc

%% Load Data
Load_Data

%% Run Ukf to get close app to error covar
UKF_Const % load UKF constants
u = zeros(3,1); % no known force
IC = NaN(6,1); % no IC

% Black Preallocate
PK_black = zeros(6,6*size(Blue_States_Pre_Kalman,1));
States = [Black_States_Post_Kalman,zeros(size(Black_States_Post_Kalman))];

[~,States_temp,PK_black(1:6,1:6),~,~,~,~,~] = UKF(Black_States_Pre_Kalman(1,1:3)',u,IC,P_IC_Black, lamda_Black, J, m, dt, Q_Black, alpha_Black, beta_Black, H, R_Black,thresh_Black,method);
States(1,:) = [Black_States_Post_Kalman(1,:),States_temp(4:6)'];

for i = 1:1:size(Blue_States_Pre_Kalman,1)-1
    [~,States_temp,PK_black(1:6,(i)*6+1:6*(i+1)),~,~,~,~,~] = UKF(Black_States_Pre_Kalman(i+1,1:3)',u,States(i,1:6)',PK_black(1:6,(i-1)*6+1:6*i), lamda_Black, J, m, dt, Q_Black, alpha_Black, beta_Black, H, R_Black,thresh_Black,method);
    States(i,:) = [Black_States_Post_Kalman(i,:),States_temp(4:6)'];
    % States(i,:) = States_temp(1:6)';
end

% Blue
% Preallocate
PK_blue = zeros(6,6*size(Blue_States_Pre_Kalman,1));
States = [Blue_States_Post_Kalman,zeros(size(Blue_States_Post_Kalman))];

[~,States_temp,PK_blue(1:6,1:6),~,~,~,~,~] = UKF(Blue_States_Pre_Kalman(1,1:3)',u,IC,P_IC_Blue, lamda_Blue, J, m, dt, Q_Blue, alpha_Blue, beta_Blue, H, R_Blue,thresh_Blue,method);
States(1,:) = [Blue_States_Post_Kalman(1,:),States_temp(4:6)'];

for i = 1:1:size(Blue_States_Pre_Kalman,1)-1
    [~,States_temp,PK_blue(1:6,(i)*6+1:6*(i+1)),~,~,~,~,~] = UKF(Blue_States_Pre_Kalman(i+1,1:3)',u,States(i,1:6)',PK_blue(1:6,(i-1)*6+1:6*i), lamda_Blue, J, m, dt, Q_Blue, alpha_Blue, beta_Blue,H, R_Blue,thresh_Blue,2);
    States(i,:) = [Blue_States_Post_Kalman(i,:),States_temp(4:6)'];
    % States(i,:) = States_temp(1:6)';
end

%% Plot Data
% Black
plot_pdf_Black(Black_States_Pre_Kalman, Black_States_PhaseSpace)
PlotFilter(Black_States_PhaseSpace, Black_States_Pre_Kalman, Black_States_Post_Kalman,PK_black', Time, 'UKF', 2,true)

% Blue
plot_pdf_Blue(Blue_States_Pre_Kalman, Blue_States_PhaseSpace)
PlotFilter(Blue_States_PhaseSpace, Blue_States_Pre_Kalman, Blue_States_Post_Kalman,PK_blue', Time, 'UKF', 2,false)





