load('../Results/ExperimentData_RED_2024_4_5_15_45_21_4293_Dock_almost_Off_Table/ExperimentData_RED_2024_4_5_15_45_21_4293_1.mat')

% Exp start indicies
T_s = 2960; %% Exp start time not first data point!!!

%% Load Data
Blue_States_tx2 = [dataClass_rt.CustomUserData66(T_s:end),dataClass_rt.CustomUserData67(T_s:end), zeros(size(dataClass_rt.CustomUserData70(T_s:end)))];
Blue_States_Pre_Kalman = [dataClass_rt.CustomUserData70(T_s:end), dataClass_rt.CustomUserData71(T_s:end), zeros(size(dataClass_rt.CustomUserData70(T_s:end)))];
Blue_States_Post_Kalman = [dataClass_rt.CustomUserData68(T_s:end), dataClass_rt.CustomUserData69(T_s:end), zeros(size(dataClass_rt.CustomUserData70(T_s:end)))];

Black_States_tx2 = [dataClass_rt.CustomUserData57(T_s:end),dataClass_rt.CustomUserData58(T_s:end), zeros(size(dataClass_rt.CustomUserData59(T_s:end)))];
Black_States_Pre_Kalman = [dataClass_rt.CustomUserData63(T_s:end), dataClass_rt.CustomUserData64(T_s:end), dataClass_rt.CustomUserData65(T_s:end)];
Black_States_Post_Kalman = [dataClass_rt.CustomUserData60(T_s:end), dataClass_rt.CustomUserData61(T_s:end), dataClass_rt.CustomUserData62(T_s:end)];

%% Change if blue is black
% Blue_States_PhaseSpace = [dataClass_rt.BLUE_Px_m,dataClass_rt.BLUE_Py_m,zeros(size(dataClass_rt.CustomUserData70))];
Blue_States_PhaseSpace = [dataClass_rt.BLACK_Px_m(T_s:end), dataClass_rt.BLACK_Py_m(T_s:end), zeros(size(dataClass_rt.CustomUserData70(T_s:end)))];

% Black_States_PhaseSpace = [dataClass_rt.BLACK_Px_m,dataClass_rt.BLACK_Py_m,zeros(size(dataClass_rt.CustomUserData70))];
Black_States_PhaseSpace = [dataClass_rt.BLUE_Px_m(T_s:end), dataClass_rt.BLUE_Py_m(T_s:end), dataClass_rt.BLUE_Rz_rad(T_s:end)];



Time = [dataClass_rt.Time_s(T_s:end)];

Time = Fix_Time(Time); % time array is unique and always increasing

plots = false;

if plots 
figure
title('Blue x')
plot(Time,Blue_States_PhaseSpace(:,1),'k')
hold on
plot(Time,Blue_States_Pre_Kalman(:,1),'b*')
plot(Time,Blue_States_Post_Kalman(:,1),'r')
grid on
legend('Phase Space', 'Pre Kalman', 'Post Kalman')

figure
title('Blue x')
plot(Time,Blue_States_PhaseSpace(:,2),'k')
hold on
plot(Time,Blue_States_Pre_Kalman(:,2),'b*')
plot(Time,Blue_States_Post_Kalman(:,2),'r')
grid on
legend('Phase Space', 'Pre Kalman', 'Post Kalman')

figure
title('Blue x')
plot(Time,Blue_States_PhaseSpace(:,3),'k')
hold on
plot(Time,Blue_States_Pre_Kalman(:,3),'b*')
plot(Time,Blue_States_Post_Kalman(:,3),'r')
grid on
legend('Phase Space', 'Pre Kalman', 'Post Kalman')
end

function unique_time = Fix_Time(time_array)
    % Fix_Time adjusts duplicate entries in time_array
    % to ensure all values are unique and strictly increasing.
    % 
    % Input:
    %   time_array - 1xn array of time values
    % 
    % Output:
    %   unique_time - 1xn array with unique and increasing time values
    
    % Sort the time array to ensure it's in increasing order
    time_array = sort(time_array); % will only fix any round off errors
    
    % Preallocate
    unique_time = time_array;
    
    % Set a small value to add to duplicates
    epsilon = 0.00001;
    
    for i = 2:length(unique_time)
        if unique_time(i) <= unique_time(i-1)
            % If the current time is not greater than the previous, add epsilon
            unique_time(i) = unique_time(i-1) + epsilon;
        end
    end
end

