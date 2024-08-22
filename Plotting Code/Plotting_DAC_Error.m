close all
clear
clc

TC = 2; % 1 or 2
i = 1; % 1-5 for TC1
offset = 0.165; % docking port offset

calculateDesiredAngleManually = 1; % 0 or 1
fix_angle = true;
play_video = 0; % 0 for no video, 1 for the video of desired, 2 for actual and desired
true_states = false; % if true, plays video with phasespace data 

% For TC1
if TC == 1
    BisB = 2; % Black is Blue is false
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
    States_Blue_UKF = [dataClass.CustomUserData68,dataClass.CustomUserData69,zeros(size(dataClass.CustomUserData69))];
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
hold on
xlim([26 dataClass_rt.Time_s(t_end-t_end_offset)])
% ylim([-0.03, 0.02])
ylabel("$x$ [m]",'Interpreter','latex')
grid on
set(gca, 'FontSize', 12);

subplot(3,1,2)
DAC_Y_error = States_Red(t_s:t_end-t_end_offset,2) - Desired_States_Red(t_s:t_end-t_end_offset,2);
plot(dataClass_rt.Time_s(t_s:t_end-t_end_offset), DAC_Y_error,'k-')
hold on
xlim([26 dataClass_rt.Time_s(t_end-t_end_offset)])
ylabel("$y$ [m]",'Interpreter','latex')
% ylim([-0.02, 0.02])
grid on
set(gca, 'FontSize', 12);

if calculateDesiredAngleManually
    for ij = 1:length( States_Red(:,3))
        Desired_States_Red(ij,3) = lookingangle(States_Black_UKF(ij,:),States_Red(ij,:), offset,fix_angle);
    end
end

subplot(3,1,3)

if fix_angle
    DAC_T_error = zeros(size(States_Red(:,3)));
    for ijk = t_s:1:t_end-t_end_offset
        DAC_T_error(ijk,1) = att_error(Desired_States_Red(ijk,3),States_Red(ijk,3));%dataClass.CustomUserData50(t_s:t_end-t_end_offset);
    end
else
    DAC_T_error = Desired_States_Red(:,3) - States_Red(:,3);
end

plot(dataClass_rt.Time_s(t_s:t_end-t_end_offset), DAC_T_error(t_s:t_end-t_end_offset),'k-')
hold on
xlim([26 dataClass_rt.Time_s(t_end-t_end_offset)])
ylabel("$\theta$ [rad]",'Interpreter','latex')
xlabel("Time [s]")
% ylim([-1, 2])
grid on
set(gca, 'FontSize', 12);

fontname(fig,"Times New Roman");

if true_states
    if TC == 1
        if play_video == 1
            PlotSim_V2(Desired_States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black(t_s-1:t_end-t_end_offset,:))
        elseif play_video == 2
            PlotSim_V2(States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black(t_s-1:t_end-t_end_offset,:))
            PlotSim_V2(Desired_States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black(t_s-1:t_end-t_end_offset,:))
        end
    elseif TC == 2
        if play_video == 1
            PlotSim_V2(Desired_States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black(t_s-1:t_end-t_end_offset,:),'blue',States_Blue(t_s-1:t_end-t_end_offset,:))
        elseif play_video == 2
            PlotSim_V2(States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black(t_s-1:t_end-t_end_offset,:),'blue',States_Blue(t_s-1:t_end-t_end_offset,:))
            PlotSim_V2(Desired_States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black(t_s-1:t_end-t_end_offset,:),'blue',States_Blue(t_s-1:t_end-t_end_offset,:))
        end
    end
else
    if TC == 1
        if play_video == 1
            PlotSim_V2(Desired_States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black_UKF(t_s-1:t_end-t_end_offset,:))
        elseif play_video == 2
            PlotSim_V2(States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black_UKF(t_s-1:t_end-t_end_offset,:))
            PlotSim_V2(Desired_States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black_UKF(t_s-1:t_end-t_end_offset,:))
        end
    elseif TC == 2
        if play_video == 1
            PlotSim_V2(Desired_States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black_UKF(t_s-1:t_end-t_end_offset,:),'blue',States_Blue_UKF(t_s-1:t_end-t_end_offset,:))
        elseif play_video == 2
            PlotSim_V2(States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black_UKF(t_s-1:t_end-t_end_offset,:),'blue',States_Blue_UKF(t_s-1:t_end-t_end_offset,:))
            PlotSim_V2(Desired_States_Red(t_s-1:t_end-t_end_offset,:),'black',States_Black_UKF(t_s-1:t_end-t_end_offset,:),'blue',States_Blue_UKF(t_s-1:t_end-t_end_offset,:))
        end
    end
end


function theta_desired = lookingangle(state_black, state_red, r_off,fix_angle)

if fix_angle

    p_l = [state_red(1);
           state_red(2)];
    
    p_c_1 = [state_black(1) + r_off*cos(state_black(3));
        state_black(2) + r_off*sin(state_black(3))];
    r_cl = p_c_1 - p_l;
    
    r_cl_x = r_cl(1);
    r_cl_y = r_cl(2);
    
    theta_desired = angle(r_cl_x + j*r_cl_y);
else
    p_l = [state_black(1) + r_off*cos(state_black(3));
       state_black(2) + r_off*sin(state_black(3))];

p_c_1 = state_red(1:2);
r_cl = p_c_1 - p_l;

r_cl_x = r_cl(1);
r_cl_y = r_cl(2);

theta_desired = angle(r_cl_x + j*r_cl_y) + pi;

    theta_desired = atan2(r_cl_y,r_cl_x) + pi;
end
end

function error = att_error(ref,act)
% Hough Control
u_x_ref = [cos(ref) sin(ref);
          -sin(ref) cos(ref)] * [1; 0];

u_y_ref = [cos(ref) sin(ref);
          -sin(ref) cos(ref)] * [0; 1];

u_x_act = [cos(act) sin(act);
          -sin(act) cos(act)] * [1; 0];

error = -1*norm(u_x_ref - u_x_act)*sign(u_y_ref'*(u_x_ref - u_x_act));

end
