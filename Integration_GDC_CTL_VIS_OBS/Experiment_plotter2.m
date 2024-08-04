close all

TX2_x = dataClass_rt.CustomUserData57/100; % Relative
TX2_y = dataClass_rt.CustomUserData58/100; % Relative
TX2_theta = dataClass_rt.CustomUserData59*pi/180; % Relative

%% VIS Data

PS_x_BLACK = dataClass_rt.BLACK_Px_m;
PS_y_BLACK = dataClass_rt.BLACK_Py_m;
PS_theta_BLACK = dataClass_rt.BLACK_Rz_rad;


ps_theta_RED = dataClass_rt.RED_Rz_rad;

CVIS_x = dataClass_rt.CustomUserData63;
CVIS_y = dataClass_rt.CustomUserData64;
CVIS_theta = dataClass_rt.CustomUserData65;

Kalman_x = dataClass_rt.CustomUserData60;
Kalman_y = dataClass_rt.CustomUserData61;
Kalman_theta = dataClass_rt.CustomUserData62;



%% CTL Data
X_gain_P = dataClass_rt.CustomUserData51;
X_gain_D = dataClass_rt.CustomUserData52;

Y_gain_P = dataClass_rt.CustomUserData53;
Y_gain_D = dataClass_rt.CustomUserData54;

T_gain_P = dataClass_rt.CustomUserData55;
T_gain_D = dataClass_rt.CustomUserData56;

%% GDC Data
Path_D_X = dataClass_rt.CustomUserData48;
Path_D_Y = dataClass_rt.CustomUserData49;
Path_D_T = dataClass_rt.CustomUserData50;

PS_x_RED = dataClass_rt.RED_Px_m;
PS_y_RED = dataClass_rt.RED_Py_m;
PS_theta_RED = dataClass_rt.RED_Rz_rad;

%% Time
time = dataClass_rt.Time_s;



%% Plot
%% Vis

tile = tiledlayout(3,9);
tile.Padding = "compact";

nexttile([3,3])
plot(time,CVIS_x,'DisplayName','Computer Vision')
hold on
plot(time,PS_x_BLACK,'DisplayName','PhaseSpace')
plot(time,Kalman_x,'DisplayName','Kalman Filtered')
ylim([2 3.5])
xlabel('Time [s]')
ylabel('[m]')
title('X Position')


nexttile([3,3])
plot(time,CVIS_y,'DisplayName','Computer Vision')
hold on
plot(time,PS_y_BLACK,'DisplayName','PhaseSpace')
plot(time,Kalman_y,'DisplayName','Kalman Filtered')
ylim([0 2.4])
xlabel('Time [s]')
ylabel('[m]')
title('Y Position')


nexttile([3,3])
plot(time,CVIS_theta,'DisplayName','Computer Vision')
hold on
plot(time,PS_theta_BLACK,'DisplayName','PhaseSpace')
plot(time,Kalman_theta,'DisplayName','Kalman Filtered')
%plot(time,TX2_theta,'DisplayName','Relative')
%plot(time,PS_theta_RED,'r','DisplayName','RED')

title('Attitude')
xlabel('Time [s]')
ylabel('[rad]')
legend('Location','northeast')



% figure
% plot(time,TX2_x,'DisplayName','tx2')
% hold on
% plot(time,PS_theta_BLACK,'DisplayName','PhaseSpace')
% plot(time,Kalman_theta,'DisplayName','Kalman Filtered')
% title('Attitude')
% legend
% 
% figure
% plot(time,TX2_y,'DisplayName','tx2')
% hold on
% plot(time,PS_theta_BLACK,'DisplayName','PhaseSpace')
% plot(time,Kalman_theta,'DisplayName','Kalman Filtered')
% title('Attitude')
% legend
% 
% figure
% plot(time,TX2_theta,'DisplayName','tx2')
% hold on
% plot(time,PS_theta_RED,'DisplayName','Red')
% plot(time,PS_theta_BLACK,'DisplayName','PhaseSpace')
% plot(time,Kalman_theta,'DisplayName','Kalman Filtered')
% title('Attitude')
% legend

%% GDC
% figure
% plot(time,Path_D_X,'DisplayName','Path_D')
% hold on
% plot(time,PS_x_RED,'DisplayName','Path_A')
% legend
% title('A vs D Path X')
% 
% figure
% plot(time,Path_D_Y,'DisplayName','Path_D')
% hold on
% plot(time,PS_y_RED,'DisplayName','Path_A')
% legend
% title('A vs D Path Y')
% 
% figure
% plot(time,Path_D_T,'DisplayName','Path_D')
% hold on
% plot(time,PS_theta_RED,'DisplayName','Path_A')
% legend
% title('A vs D Path Theta')
% 
% %% CTL
% figure
% plot(time,X_gain_P,'DisplayName','Gain P')
% hold on
% plot(time,X_gain_D,'DisplayName','Gain D')
% legend
% title('Gain vs time x')
% 
% figure
% plot(time,Y_gain_P,'DisplayName','Gain P')
% hold on
% plot(time,Y_gain_D,'DisplayName','Gain D')
% legend
% title('Gain vs time Y')
% 
% figure
% plot(time,T_gain_P,'DisplayName','Gain P')
% hold on
% plot(time,T_gain_D,'DisplayName','Gain D')
% legend
% title('Gain vs time Theta')