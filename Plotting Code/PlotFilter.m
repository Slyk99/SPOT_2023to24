function PlotFilter(system_output,Filter_Name)

    % x_Desired = system_output(:,4);
    % y_Desired = system_output(:,5);
    % theta_Desired = system_output(:,6);

    x_real = system_output(:,1);
    y_real = system_output(:,2);
    theta_real = system_output(:,3);

    x_noisy = system_output(:,4);
    y_noisy = system_output(:,5);
    theta_noisy = system_output(:,6);

    x_Filtered = system_output(:,7);
    y_Filtered = system_output(:,8);
    theta_Filtered = system_output(:,9);

    sim_time = system_output(:,10);

    figure
    subplot(3,1,3)
    % plot(sim_time,theta_Desired,'Color','k')
    hold on
    plot(sim_time,theta_real,'Color','k')%,'LineWidth', 4)
    plot(sim_time,theta_noisy,'b*')%,'LineWidth', 4)
    plot(sim_time,theta_Filtered,'Color','r')%,'LineWidth', 4)
    hold off
    title('Angle Of SpaceCraft')
    xlabel('Time [s]')
    ylabel('Angle [Rad]')
    legend('Actualy Angle','VIS Data','Filtered Angle')
    % set(gca, 'FontSize', 60);
    grid on
    % ylim([-1.5, 1.5]);
    saveas(gcf, 'Kalman_Theta.png');
    % subplot(2,2,1)
    % % plot(x_Desired,y_Desired,'Color','k')
    % hold on
    % rectangle('position',[0 0 3.5 2.4])
    % axis([-0.2 3.7 -0.2 2.6])
    % plot(x_real,y_real,'Color','k')
    % plot(x_noisy,y_noisy,'Color','b','LineStyle',':')
    % plot(x_Filtered,y_Filtered,'Color','r','LineStyle','--')
    % title('Path Of SpaceCraft')
    % xlabel('Distance [m]')
    % ylabel('Distance [m]')
    % legend('Actualy Path','VIS Data','Filtered Path')
    % grid on
    % hold off
    
    subplot(3,1,1)
    % plot(sim_time,x_Desired,'Color','k')
    hold on
    plot(sim_time,x_real,'Color','k')%,'LineWidth', 4)
    plot(sim_time,x_noisy,'b*')%,'LineWidth', 4)
    plot(sim_time,x_Filtered,'Color','r')%,'LineWidth', 4)
    title('X Values of SpaceCraft')
    xlabel('Time [s]')
    ylabel('Distance [m]')
    legend('Actualy Path','VIS Data','Filtered Path')
    grid on
    % set(gca, 'FontSize', 60);
    % ylim([2.45 2.65]);
    hold off
    saveas(gcf, 'KalmanX.png');

    subplot(3,1,2)
    % plot(sim_time,y_Desired,'Color','k')
    hold on
    plot(sim_time,y_real,'Color','k')%,'LineWidth', 4)
    plot(sim_time,y_noisy,'b*')%,'LineWidth', 4)
    plot(sim_time,y_Filtered,'Color','r')%,'LineWidth', 4)
    title('Y Values of SpaceCraft')
    xlabel('Time [s]')
    ylabel('Distance [m]')
    legend('Actualy Path','VIS Data','Filtered Path')
    grid on
    % set(gca, 'FontSize', 60);
    % ylim([0.6 0.9]);
    hold off
    saveas(gcf, 'Kalman_Y.png');
    

    sgtitle(append('Results for ', Filter_Name))
end