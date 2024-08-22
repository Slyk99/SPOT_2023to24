%% Clear
close all
clear
clc

%% Load Data
i = 1;

BisB = 2; % Black is Blue is false
if i == 1
    load("../Results/Vision Test Case 1 Reversed - Harsh Lighting\ExperimentData_RED_2024_3_11_10_34_53_8679_FullIntegrationSuccess_MultiArUco_SunGun1\ExperimentData_RED_2024_3_11_10_34_53_8679_1.mat")
    t_end_offset = 0; 
    T_s = 2791;
elseif i == 2
    load("../Results/Vision Test Case 1 Reversed - Harsh Lighting\ExperimentData_RED_2024_3_23_11_12_44_3273_FullIntegrationSuccess_MultiArUco_SunGun2\ExperimentData_RED_2024_3_23_11_12_44_3273_1.mat")
    t_end_offset = 2500;
    T_s = 2804;
elseif i == 3
    load("../Results/Vision Test Case 1 Reversed - Harsh Lighting\ExperimentData_RED_2024_3_23_11_34_37_5333_FullIntegrationSuccess_MultiArUco_SunGun3\ExperimentData_RED_2024_3_23_11_34_37_5333_2.mat")
    t_end_offset = 2900;
    T_s = 2778;
elseif i == 4
    load("../Results/Vision Test Case 1 Reversed - Harsh Lighting\ExperimentData_RED_2024_3_23_11_45_3_2403_FullIntegrationSuccess_MultiArUco_SunGun4\ExperimentData_RED_2024_3_23_11_45_3_24030_1.mat")
    t_end_offset = 3100;
    T_s = 2789;
elseif i == 5
    load("../Results/Vision Test Case 1 Reversed - Harsh Lighting\ExperimentData_RED_2024_3_23_11_48_36_807_FullIntegrationSuccess_MultiArUco_SunGun5\ExperimentData_RED_2024_3_23_11_48_36_8070_1.mat")
    t_end_offset = 0;
    T_s = 2771;
end
dataClass = dataClass_rt;

% Black Data
Black_States_PhaseSpace = [dataClass.BLACK_Px_m(T_s:end),dataClass.BLACK_Py_m(T_s:end),dataClass.BLACK_Rz_rad(T_s:end)];
Black_States_Post_Kalman = [dataClass.CustomUserData60(T_s:end),dataClass.CustomUserData61(T_s:end),dataClass.CustomUserData62(T_s:end)];
Black_States_Pre_Kalman = [dataClass_rt.CustomUserData63(T_s:end), dataClass_rt.CustomUserData64(T_s:end), dataClass_rt.CustomUserData65(T_s:end)];
Time = dataClass.Time_s(T_s:end);

%% Run Ukf to get close app to error covar
UKF_Const % load UKF constants
u = zeros(3,1); % no known force
IC = NaN(6,1); % no IC

% Preallocate
PK_black = zeros(6,6*size(Black_States_Pre_Kalman,1));
States = [Black_States_Post_Kalman,zeros(size(Black_States_Post_Kalman))];

[~,States_temp,PK_black(1:6,1:6),~,~,~,~,~] = UKF(Black_States_Pre_Kalman(1,1:3)',u,IC,P_IC_Black, lamda_Black, J, m, dt, Q_Black, alpha_Black, beta_Black, H, R_Black,thresh_Black,method);
States(1,:) = [Black_States_Post_Kalman(1,:),States_temp(4:6)'];

for i = 1:1:size(Black_States_Pre_Kalman,1)-1
    [~,States_temp,PK_black(1:6,(i)*6+1:6*(i+1)),~,~,~,~,~] = UKF(Black_States_Pre_Kalman(i+1,1:3)',u,States(i,1:6)',PK_black(1:6,(i-1)*6+1:6*i), lamda_Black, J, m, dt, Q_Black, alpha_Black, beta_Black, H, R_Black,thresh_Black,method);
    States(i,:) = [Black_States_Post_Kalman(i,:),States_temp(4:6)'];
    % States(i,:) = States_temp(1:6)';
end

%% Plot Data
% plot_pdf_Black(Black_States_Pre_Kalman, Black_States_PhaseSpace,'TC1_1_Black')
PlotFilter(Black_States_PhaseSpace, Black_States_Pre_Kalman, Black_States_Post_Kalman,PK_black', Time, 'UKF_TC1_1_black', 1,true)