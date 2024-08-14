function plot_effort(effort,time)
line_width = 2;
text_size = 24;

sz = size(effort,1);
Zero_thrust = zeros(sz,1);


%% Plot
figure
subplot(3,1,1)
hold on
% plot(time, Zero_thrust(:,1),'k', 'LineWidth', line_width);
plot(time, effort(:,1),'k', 'LineWidth', line_width);
% title([]); % Titles are added in latex
% xlabel('Time'); % x lable only on last plot in the column
ylabel('x Effort [Ns]');
% legend('Actual', 'Desired');
set(gca, 'FontSize', text_size);
grid on
xlim([25.5, 152])
hold off

subplot(3,1,2)
hold on
% plot(time, Zero_thrust(:,1),'k', 'LineWidth', line_width);
plot(time, effort(:,2),'k', 'LineWidth', line_width);
% title([]); % Titles are added in latex
% xlabel('Time'); % x lable only on last plot in the column
ylabel('y Effort [Ns]');
%legend('Zero Thrust Line', 'Systems Effort');
set(gca, 'FontSize', text_size);
grid on
xlim([25.5, 152])
hold off

subplot(3,1,3)
hold on
% plot(time, Zero_thrust(:,1),'k', 'LineWidth', line_width);
plot(time, effort(:,3),'k', 'LineWidth', line_width);
% title([]); % Titles are added in latex
xlabel('Time [s]'); % x lable only on last plot in the column
ylabel('\theta Effort [Ns]');
% legend('Actual', 'Desired');
set(gca, 'FontSize', text_size);
grid on
xlim([25.5, 152])
hold off
saveas(gcf, 'Effort_Blue.png');
end