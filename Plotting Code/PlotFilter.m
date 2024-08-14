function PlotFilter(PhaseSpace, Pre_Filter_Data, Filter_Data,error_covariance, Time, Filter_Name, line_size,Angle)
    % Extracting data from system_output
    x_real = PhaseSpace(:,1);
    y_real = PhaseSpace(:,2);
    theta_real = PhaseSpace(:,3);
    x_noisy = Pre_Filter_Data(:,1);
    y_noisy = Pre_Filter_Data(:,2);
    theta_noisy = wrapTo180(unwrap(Pre_Filter_Data(:,3)));
    x_Filtered = Filter_Data(:,1);
    y_Filtered = Filter_Data(:,2);
    theta_Filtered = Filter_Data(:,3);
    sim_time = Time;

    if Angle
        j = 3;
    else
        j = 2;
    end

    % Setting default font properties
    set(groot, 'DefaultTextFontName', 'Times New Roman');
    set(groot, 'DefaultAxesFontName', 'Times New Roman');
    set(groot, 'DefaultAxesFontSize', 24);

    figure
    % Plotting X Values of SpaceCraft
    subplot(j,1,1)
    hold on
    plot(sim_time, x_real, 'k', 'LineWidth', line_size)
    plot(sim_time, x_noisy, 'b*', 'LineWidth', line_size)
    plot(sim_time, x_Filtered, 'r', 'LineWidth', line_size)
    
    % Plotting 95% confidence range based on error covariance
    x_confidence = 1.96 * sqrt(error_covariance(1:6:end,1));
    plot(sim_time, x_Filtered + x_confidence, 'r--', 'LineWidth', line_size);
    plot(sim_time, x_Filtered - x_confidence, 'r--', 'LineWidth', line_size);

    % Filling the area between the confidence lines
    patch([sim_time', fliplr(sim_time')], [x_Filtered' + x_confidence', fliplr(x_Filtered' - x_confidence')], 'r', 'FaceAlpha', 0.2, 'EdgeColor', 'r', 'LineStyle', '--');
    Plot_Patch(sim_time, x_Filtered, x_confidence)

    ylim([-0.25, 3.25]); % Y limits
    ylabel('X Distance [m]')
    grid on
    hold off

    % Plotting Y Values of SpaceCraft
    subplot(j,1,2)
    hold on
    plot(sim_time, y_real, 'k', 'LineWidth', line_size)
    plot(sim_time, y_noisy, 'b*', 'LineWidth', line_size)
    plot(sim_time, y_Filtered, 'r', 'LineWidth', line_size)
    
    % Plotting 95% confidence range based on error covariance
    y_confidence = 1.96 * sqrt(error_covariance(2:6:end,2));
    plot(sim_time, y_Filtered + y_confidence, 'r--', 'LineWidth', line_size);
    plot(sim_time, y_Filtered - y_confidence, 'r--', 'LineWidth', line_size);
    

    % Filling the area between the confidence lines
    patch([sim_time', fliplr(sim_time')], [y_Filtered' + y_confidence', fliplr(y_Filtered' - y_confidence')], 'r', 'FaceAlpha', 0.2, 'EdgeColor', 'r', 'LineStyle', '--');
    Plot_Patch(sim_time, y_Filtered, y_confidence)


    ylim([-1.1, 2.2]); % Y limits
    ylabel('Y Distance [m]')
    legend('Actual States', 'Measured States', 'Filtered States', '95% Confidence')
    grid on
    hold off


    if Angle
        % Plotting Angle Of SpaceCraft
        subplot(j,1,3)
        hold on
        plot(sim_time, theta_real, 'k', 'LineWidth', line_size)
        plot(sim_time, theta_noisy, 'b*', 'LineWidth', line_size)
        plot(sim_time, theta_Filtered, 'r', 'LineWidth', line_size)
    
        % Plotting 95% confidence range based on error covariance
        theta_confidence = 1.96 * sqrt(error_covariance(3:6:end,3));
        plot(sim_time, theta_Filtered + theta_confidence, 'r--', 'LineWidth', line_size);
        plot(sim_time, theta_Filtered - theta_confidence, 'r--', 'LineWidth', line_size);
    
        % Filling the area between the confidence lines
        patch([sim_time', fliplr(sim_time')], [theta_Filtered' + theta_confidence', fliplr(theta_Filtered' - theta_confidence')], 'r', 'FaceAlpha', 0.2, 'EdgeColor', 'r', 'LineStyle', '--');
        Plot_Patch(sim_time, theta_Filtered, theta_confidence)
    
        ylim([0, 2*pi]); % Y limits
        hold off
        xlabel('Time [s]')
        ylabel('\theta [Rad]')
        grid on
    end


    saveas(gcf, 'UKF_Blue_NOTITLE.png');
    sgtitle(append('Results for ', Filter_Name))
end

function Plot_Patch(sim_time, x_Filtered, x_confidence, color, alpha)
    % addConfidenceIntervalPatch Adds a confidence interval patch to the current plot.
    %
    % Inputs:
    %   sim_time    - Time array (1xn) for the x-axis
    %   x_Filtered  - Filtered data array (1xn) for the y-axis
    %   x_confidence- Confidence interval array (1xn) for y-axis
    %   color       - Color for the patch (e.g., 'r' for red)
    %   alpha       - Transparency of the patch (0 to 1)
    %
    % Example Usage:
    %   figure;
    %   plot(sim_time, x_Filtered);
    %   addConfidenceIntervalPatch(sim_time, x_Filtered, x_confidence, 'r', 0.2);
    %   grid on;

    if nargin < 5
        alpha = 0.2; % Default transparency
    end

    if nargin < 4
        color = 'r'; % Default color
    end

    % Extract non-NaN indices
    valid_indices = ~isnan(sim_time) & ~isnan(x_Filtered) & ~isnan(x_confidence);

    % Filter the data to remove NaN values
    sim_time_valid = sim_time(valid_indices);
    x_Filtered_valid = x_Filtered(valid_indices);
    x_confidence_valid = x_confidence(valid_indices);

    % Add the confidence interval patch to the current plot
    patch([sim_time_valid', fliplr(sim_time_valid')], ...
          [x_Filtered_valid' + x_confidence_valid', fliplr(x_Filtered_valid' - x_confidence_valid')], ...
          color, 'FaceAlpha', alpha, 'EdgeColor', color, 'LineStyle', '--');
end
