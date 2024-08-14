%% Plot Function
function plot_states(actual_states, desired_states, time_vector, line_width, text_size)
    % Check if line_width and text_size are provided, otherwise set default values 
    % The resolution used is 2560 by 1440 p
    if nargin < 4
        line_width = 2;
    end
    if nargin < 5
        text_size = 24;
    end
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Create desired and actual vs time for pose vector of 3x1
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    figure;
        subplot(3, 2, 1);
        plot(time_vector, actual_states(:,1),'k', 'LineWidth', line_width);
        hold on;
        plot(time_vector, desired_states(:,1),'r--', 'LineWidth', line_width);
        % title([]); % Titles are added in latex 
        % xlabel('Time'); % x lable only on last plot in the column
        ylabel('x Position [m]');
        % legend('Actual', 'Desired');
        set(gca, 'FontSize', text_size);
        grid on
        xlim([25.5, 152])
        hold off

        subplot(3, 2, 3);
        plot(time_vector, actual_states(:,2),'k', 'LineWidth', line_width);
        hold on;
        plot(time_vector, desired_states(:,2),'r--', 'LineWidth', line_width);
        % title([]); % Titles are added in latex
        % xlabel('Time'); % x lable only on last plot in the column
        ylabel('y Position [m]');
        legend('Actual', 'Desired');
        set(gca, 'FontSize', text_size);
        grid on
        xlim([25.5, 152])
        hold off

        subplot(3, 2, 5);
        plot(time_vector, actual_states(:,3),'k', 'LineWidth', line_width);
        hold on;
        plot(time_vector, desired_states(:,3),'r--', 'LineWidth', line_width);
        % title([]); % Titles are added in latex
        xlabel('Time [s]'); % x lable only on last plot in the column
        ylabel('\theta [rad]');
        % legend('Actual', 'Desired');
        set(gca, 'FontSize', text_size);
        grid on
        xlim([25.5, 152])
        hold off
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Create Error vs time for pose vector of 3x1
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% Creating zero error line
        sz = size(time_vector,1);
        Zero_Error_Line = zeros(sz,1);

        subplot(3, 2, 2);
        % plot(time_vector,Zero_Error_Line,'k','LineWidth',line_width)
        hold on;
        error = actual_states(:,1) - desired_states(:,1);
        plot(time_vector, error,'k', 'LineWidth', line_width);
        % title([]); % Titles are added in latex
        % xlabel('Time'); % x lable only on last plot in the column
        ylabel('x Error [m]');
        set(gca, 'FontSize', text_size);
        grid on
        xlim([25.5, 152])
        hold off

        subplot(3, 2, 4);
        % plot(time_vector,Zero_Error_Line,'k','LineWidth',line_width)
        hold on;
        error = actual_states(:,2) - desired_states(:,2);
        plot(time_vector, error,'k', 'LineWidth', line_width);
        % title([]); % Titles are added in latex
        % xlabel('Time'); % x lable only on last plot in the column
        ylabel('y Error [m]');
        % legend('Zero Error Line', 'Systems Effort');
        set(gca, 'FontSize', text_size);
        grid on
        xlim([25.5, 152])
        hold off

        subplot(3, 2,6);
        % plot(time_vector,Zero_Error_Line,'k','LineWidth',line_width)
        hold on;
        error = actual_states(:,3) - desired_states(:,3);
        plot(time_vector, error,'k', 'LineWidth', line_width);
        % title([]); % Titles are added in latex
        xlabel('Time [s]'); % x lable only on last plot in the column
        ylabel('\theta Error [rad]');
        set(gca, 'FontSize', text_size);
        grid on
        xlim([25.5, 152])
        hold off
        saveas(gcf, 'States_Blue.png');
    
    % Adjust figure properties
    % set(gcf, 'Position', [100, 100, 1200, 800]); % Adjust figure size
end