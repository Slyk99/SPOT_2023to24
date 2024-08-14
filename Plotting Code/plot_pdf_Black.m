function plot_pdf_Black(measured, ground_truth)
    % Remove NaN values
    valid_indices = ~any(isnan(measured), 2) & ~any(isnan(ground_truth), 2);
    measured = measured(valid_indices, :);
    ground_truth = ground_truth(valid_indices, :);

    % Compute residual
    diff_x = measured(:, 1) - ground_truth(:, 1);
    diff_y = measured(:, 2) - ground_truth(:, 2);
    diff_theta = measured(:, 3) - ground_truth(:, 3);
    % diff_theta = findSmallestAngles(measured(:, 3), ground_truth(:, 3));

    x_max = 0.3;
    x_min = -x_max;

    text_size = 24;
        % Plot histograms
    % figure;
    % subplot(3,1,1);
    % histogram(diff_x, 'Normalization', 'pdf');
    % title('Histogram of Difference in X');
    % xlabel('Difference');
    % ylabel('Probability Density');
    % 
    % subplot(3,1,2);
    % histogram(diff_y, 'Normalization', 'pdf');
    % title('Histogram of Difference in Y');
    % xlabel('Difference');
    % ylabel('Probability Density');
    % 
    % subplot(3,1,3);
    % histogram(diff_theta, 'Normalization', 'pdf');
    % title('Histogram of Difference in Theta');
    % xlabel('Difference');
    % ylabel('Probability Density');

    % Fit PDFs
    pd_x = fitdist(diff_x,'Kernel');
    pd_y = fitdist(diff_y,'Kernel');
    pd_theta = fitdist(diff_theta,'Kernel');

    %% Plot PDF
figure;

subplot(3,1,1);
x_range = linspace(min(diff_x), max(diff_x), 100);
pdf_x = pdf(pd_x, x_range);
plot(x_range, pdf_x, 'k', 'LineWidth', 2); % Change color to black and linewidth to 2
hold on;
fill([x_range, fliplr(x_range)], [pdf_x, zeros(size(pdf_x))], 'k', 'FaceAlpha', 0.3); % Fill area under the curve in black
x_mean = mean(diff_x);
x_std = std(diff_x);
plot([x_mean - x_std, x_mean - x_std], [0, max(pdf_x)], 'r--', 'LineWidth', 2);
plot([x_mean + x_std, x_mean + x_std], [0, max(pdf_x)], 'r--', 'LineWidth', 2);
plot([x_mean, x_mean], [0, max(pdf_x)], 'b-', 'LineWidth', 2); % Change median line color to blue
xlabel('X Measurement Residual');
ylabel('Probability Density');
% legend('PDF', '95% CI', 'Median');
xlim([x_min,x_max])
set(gca, 'FontSize', text_size);
hold off;

subplot(3,1,2);
y_range = linspace(min(diff_y), max(diff_y), 100);
pdf_y = pdf(pd_y, y_range);
plot(y_range, pdf_y, 'k', 'LineWidth', 2); % Change color to black and linewidth to 2
hold on;
fill([y_range, fliplr(y_range)], [pdf_y, zeros(size(pdf_y))], 'k', 'FaceAlpha', 0.3); % Fill area under the curve in black
y_mean = mean(diff_y);
y_std = std(diff_y);
plot([y_mean + y_std, y_mean + y_std], [0, max(pdf_y)], 'r--', 'LineWidth', 2);
plot([y_mean - y_std, y_mean - y_std], [0, max(pdf_y)], 'r--', 'LineWidth', 2);
plot([y_mean, y_mean], [0, max(pdf_y)], 'b-', 'LineWidth', 2); % Change median line color to blue
xlabel('Y Measurement Residual');
ylabel('Probability Density');
legend('PDF', 'Probability Density', '1 STD','','Mean');
xlim([x_min,x_max])
set(gca, 'FontSize', text_size);
hold off;

subplot(3,1,3);
theta_range = linspace(min(diff_theta), max(diff_theta), 100);
pdf_theta = pdf(pd_theta, theta_range);
plot(theta_range, pdf_theta, 'k', 'LineWidth', 2); % Change color to black and linewidth to 2
hold on;
fill([theta_range, fliplr(theta_range)], [pdf_theta, zeros(size(pdf_theta))], 'k', 'FaceAlpha', 0.3); % Fill area under the curve in black
theta_mean = mean(diff_theta);
theta_std = std(diff_theta);
plot([theta_mean - theta_std, theta_mean - theta_std], [0, max(pdf_theta)], 'r--', 'LineWidth', 2);
plot([theta_mean + theta_std, theta_mean + theta_std], [0, max(pdf_theta)], 'r--', 'LineWidth', 2);
plot([theta_mean, theta_mean], [0, max(pdf_theta)], 'b-', 'LineWidth', 2); % Change median line color to blue
xlabel('\theta Measurement Residual');
ylabel('Probability Density');
% legend('PDF', '95% CI', 'Median');
xlim([-2,2])
set(gca, 'FontSize', text_size);
hold off;

saveas(gcf, 'PDF_Black_Blue.png');
end

function minAngles = findSmallestAngles(vec1, vec2)
    % Ensure both vectors are column vectors
    if ~iscolumn(vec1)
        vec1 = vec1(:);
    end
    if ~iscolumn(vec2)
        vec2 = vec2(:);
    end
    
    % Calculate the absolute difference between corresponding angles
    angleDiff = abs(vec1 - vec2);
    
    % Normalize the angle differences to the range [0, 2*pi]
    angleDiff = mod(angleDiff, 2*pi);
    
    % Find the smallest angle in between, which should be min(angleDiff, 2*pi - angleDiff)
    minAngles = min(angleDiff, 2*pi - angleDiff);
end