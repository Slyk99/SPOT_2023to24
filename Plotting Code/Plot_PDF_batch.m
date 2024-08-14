%% Blue is black
% load("ExperimentData_RED_2024_4_5_18_45_26_0977\ExperimentData_RED_2024_4_5_18_45_26_0977_1.mat") % For with blue
% load("ExperimentData_RED_2024_4_5_15_45_21_4293_Dock_almost_Off_Table\ExperimentData_RED_2024_4_5_15_45_21_4293_1.mat")
load("ExperimentData_RED_2024_4_5_15_25_20_2559\ExperimentData_RED_2024_4_5_15_25_20_2559_1.mat")
% load("ExperimentData_RED_2024_4_5_15_33_38_7893\ExperimentData_RED_2024_4_5_15_33_38_7893_1.mat")
% load("ExperimentData_RED_2024_4_5_15_38_13_6063\ExperimentData_RED_2024_4_5_15_38_13_6063_1.mat")
% load("ExperimentData_RED_2024_4_5_15_45_21_4293_Dock_almost_Off_Table\ExperimentData_RED_2024_4_5_15_45_21_4293_1.mat")
% load("ExperimentData_RED_2024_4_5_16_33_17_3913\ExperimentData_RED_2024_4_5_16_33_17_3913_1.mat")
% load("ExperimentData_RED_2024_4_5_16_33_17_3913\ExperimentData_RED_2024_4_5_16_33_17_3913_2.mat")
% load("ExperimentData_RED_2024_4_5_17_18_58_1671\ExperimentData_RED_2024_4_5_17_18_58_1671_1.mat")
% load("ExperimentData_RED_2024_4_5_17_23_48_3178\ExperimentData_RED_2024_4_5_17_23_48_3178_1.mat")
% load("ExperimentData_RED_2024_4_5_17_28_55_3303\ExperimentData_RED_2024_4_5_17_28_55_3303_1.mat")
% load("ExperimentData_RED_2024_4_5_18_45_26_0977\ExperimentData_RED_2024_4_5_18_45_26_0977_1.mat")
% load("ExperimentData_RED_2024_4_5_18_45_26_0977\ExperimentData_RED_2024_4_5_18_45_26_0977_2.mat")
% load("ExperimentData_RED_2024_4_5_18_45_26_0977\ExperimentData_RED_2024_4_5_18_45_26_0977_3.mat")   
dataClass = dataClass_rt;
BisB = 1; % Black is Blue
t_s = 3050;
if BisB ==1
    %% Black Data
    States_Blue = [dataClass.BLACK_Px_m,dataClass.BLACK_Py_m,dataClass.BLACK_Rz_rad];
    States_Black_Measured = [dataClass.CustomUserData63,dataClass.CustomUserData64,dataClass.CustomUserData65];
    
    %% Blue Data
    States_Black = [dataClass.BLUE_Px_m,dataClass.BLUE_Py_m,dataClass.BLUE_Rz_rad];
    States_Blue_Measured = [dataClass.CustomUserData70,dataClass.CustomUserData71];
    % figure
% plot(dataClass_rt.Time_s,States_Blue_Measured(:,1),'r*')
% hold on
% plot(dataClass_rt.Time_s,States_Blue(:,1))
% 
% figure
% plot(dataClass_rt.Time_s,States_Blue_Measured(:,2),'r*')
% hold on
% plot(dataClass_rt.Time_s,States_Blue(:,2))
% 
% figure
% plot(dataClass_rt.Time_s,States_Blue(:,1))
% hold on
% plot(dataClass_rt.Time_s,States_Blue(:,2))

    %% Plots
    plot_pdf_Black(States_Black_Measured(t_s:end,1:3),States_Black(t_s:end,1:3))

    plot_pdf_Blue(States_Blue(t_s:end,1:2),States_Blue_Measured(t_s:end,1:2))
    
else
    %% Black Data
    States_Black = [dataClass.BLACK_Px_m,dataClass.BLACK_Py_m,dataClass.BLACK_Rz_rad];
    States_Black_Measured = [dataClass.CustomUserData63,dataClass.CustomUserData64,dataClass.CustomUserData65];
    %% Plots
    plot_pdf_Black(States_Black_Measured(t_s:end,1:3),States_Black(t_s:end,1:3))
end