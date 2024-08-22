close all

TC = 1; % 1 or 2
i = 1; % 1-5 for TC1
calculateDesiredAngleManually = 1; % 0 or 1

% For TC1
if TC == 1
    BisB = 0; % Black is Blue is false
    if i == 1
        load("../Results/Vision Test Case 1 Reversed - Harsh Lighting\ExperimentData_RED_2024_3_11_10_34_53_8679_FullIntegrationSuccess_MultiArUco_SunGun1\ExperimentData_RED_2024_3_11_10_34_53_8679_1.mat") 
        t_end_offset = 0;
    elseif i == 2
        load("../Results/Vision Test Case 1 Reversed - Harsh Lighting\ExperimentData_RED_2024_3_23_11_12_44_3273_FullIntegrationSuccess_MultiArUco_SunGun2\ExperimentData_RED_2024_3_23_11_12_44_3273_1.mat") 
        t_end_offset = 2500;
    elseif i == 3
        load("../Results/Vision Test Case 1 Reversed - Harsh Lighting\ExperimentData_RED_2024_3_23_11_34_37_5333_FullIntegrationSuccess_MultiArUco_SunGun3\ExperimentData_RED_2024_3_23_11_34_37_5333_2.mat") 
        t_end_offset = 2900;
    elseif i == 4
        load("../Results/Vision Test Case 1 Reversed - Harsh Lighting\ExperimentData_RED_2024_3_23_11_45_3_2403_FullIntegrationSuccess_MultiArUco_SunGun4\ExperimentData_RED_2024_3_23_11_45_3_24030_1.mat") 
        t_end_offset = 3100;
    elseif i == 5
        load("../Results/Vision Test Case 1 Reversed - Harsh Lighting\ExperimentData_RED_2024_3_23_11_48_36_807_FullIntegrationSuccess_MultiArUco_SunGun5\ExperimentData_RED_2024_3_23_11_48_36_8070_1.mat") 
        t_end_offset = 0;
    end
elseif TC == 2  % For TC2, Blue is black
    load("../Results/ExperimentData_RED_2024_4_5_15_45_21_4293_Dock_almost_Off_Table\ExperimentData_RED_2024_4_5_15_45_21_4293_1.mat") % Test Case 2
    BisB = 1; % Black is Blue is true
    t_end_offset = 0;
end

dataClass = dataClass_rt;
if BisB ==1
    % Black Data
    States_Blue = [dataClass.BLACK_Px_m,dataClass.BLACK_Py_m,dataClass.BLACK_Rz_rad];
    States_Black_UKF = [dataClass.CustomUserData60,dataClass.CustomUserData61,dataClass.CustomUserData62];
    
    % Blue Data
    States_Black = [dataClass.BLUE_Px_m,dataClass.BLUE_Py_m,dataClass.BLUE_Rz_rad];
    States_Blue_UKF = [dataClass.CustomUserData68,dataClass.CustomUserData69];
else
    % Black Data
    States_Black = [dataClass.BLACK_Px_m,dataClass.BLACK_Py_m,dataClass.BLACK_Rz_rad];
    States_Black_UKF = [dataClass.CustomUserData60,dataClass.CustomUserData61,dataClass.CustomUserData62];
end


t_s =293;
t_end = length(dataClass.RED_Px_m);

States_Red = [dataClass.RED_Px_m, dataClass.RED_Py_m, dataClass.RED_Rz_rad];
Desired_States_Red = [dataClass.CustomUserData48, dataClass.CustomUserData49, dataClass.CustomUserData50];

%% Plotting DAC error

fig = figure("Position",[155.6666666666667,131,742,420]);

subplot(3,1,1)
DAC_X_error = States_Red(t_s:t_end-t_end_offset,1) - Desired_States_Red(t_s:t_end-t_end_offset,1);
plot(dataClass_rt.Time_s(t_s:t_end-t_end_offset), DAC_X_error,'k-')
xlim([26 dataClass_rt.Time_s(t_end-t_end_offset)])
% ylim([-0.03, 0.02])
ylabel("$x$ [m]",'Interpreter','latex')
grid on
set(gca, 'FontSize', 12);

subplot(3,1,2)
DAC_Y_error = States_Red(t_s:t_end-t_end_offset,2) - Desired_States_Red(t_s:t_end-t_end_offset,2);
plot(dataClass_rt.Time_s(t_s:t_end-t_end_offset), DAC_Y_error,'k-')
xlim([26 dataClass_rt.Time_s(t_end-t_end_offset)])
ylabel("$y$ [m]",'Interpreter','latex')
% ylim([-0.02, 0.02])
grid on
set(gca, 'FontSize', 12);

if calculateDesiredAngleManually
    for ij = 1:length( States_Red(:,3))
        Desired_States_Red(ij,3) = lookingangle(States_Black_UKF(ij,:), States_Red(ij,:) , 0.165);
    end
end

subplot(3,1,3)
DAC_T_error = States_Red(t_s:t_end-t_end_offset,3) - Desired_States_Red(t_s:t_end-t_end_offset,3); % OG
% DAC_T_error = States_Red(t_s:t_end-t_end_offset,3) - dataClass.CustomUserData50(t_s:t_end-t_end_offset);
plot(dataClass_rt.Time_s(t_s:t_end-t_end_offset), DAC_T_error,'k-')
xlim([26 dataClass_rt.Time_s(t_end-t_end_offset)])
ylabel("$\theta$ [rad]",'Interpreter','latex')
xlabel("Time [s]")
% ylim([-1, 2])
grid on
set(gca, 'FontSize', 12);

fontname(fig,"Times New Roman");

figure
plot(dataClass_rt.Time_s(t_s:t_end-t_end_offset),wrapTo180(Desired_States_Red(t_s:t_end-t_end_offset,3)),'k')
% plot(dataClass_rt.Time_s(t_s:t_end-t_end_offset),wrapTo180(dataClass.CustomUserData50(t_s:t_end-t_end_offset)),'k')

hold on
plot(dataClass_rt.Time_s(t_s:t_end-t_end_offset),wrapTo180(States_Red(t_s:t_end-t_end_offset,3)),'r')


function theta_desired = lookingangle(state_black, state_red, r_off)
    
    p_l = [state_black(1) + r_off*cos(state_black(3));
           state_black(2) + r_off*sin(state_black(3))];
    
    p_c_1 = state_red(1:2);
    r_cl = p_c_1 - p_l;
    
    r_cl_x = r_cl(1);
    r_cl_y = r_cl(2);
    
    theta_desired = atan2(r_cl_y,r_cl_x) + pi;

end