function plot_pdf_Blue(measured, ground_truth)
    % Remove NaN values
    valid_indices = ~any(isnan(measured), 2) & ~any(isnan(ground_truth), 2);
    measured = measured(valid_indices, :);
    ground_truth = ground_truth(valid_indices, :);

    x_max = 1.5;
    x_min = -x_max;

    % Compute residual
    diff_x = measured(:, 1) - ground_truth(:, 1);
    diff_y = measured(:, 2) - ground_truth(:, 2);

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
    pd_x = fitdist(diff_x,"Kernel");
    pd_y = fitdist(diff_y,'Kernel');

    %% Plot PDF
figure;

subplot(2,1,1);
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
% legend('PDF', '95% CI', 'Median');
ylabel('Probability Density');
set(gca, 'FontSize', text_size);
xlim([min(diff_x), max(diff_x)])
hold off;

subplot(2,1,2);
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
set(gca, 'FontSize', text_size);
xlim([min(diff_y), max(diff_y)])
hold off;


saveas(gcf, 'PDF_Blue.png');
end
