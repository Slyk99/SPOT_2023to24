% Plot for SPOT Simulations done by the control team
% CTL Team
% 9/21/2023
%
% function plotSim(System_Output)
%
% Purpose: Creates a plot that will show the path and orientation of a
% spacecraft on the lab table, capable of plotting black blue and red at
% the same time
%
% Inputs:  o System output   - System output the simulink model for our controller
%           Spacecraft Name - Spacecraft name, either 'blue' or 'black' first input is 
%                 always red, and does not require a name
%           Spacecraft Path - Spacecraft path, a 3xn array where the first column is the x
%                 values, second column is the y values and the final
%                 column is the Yaw values
%
% Note:    o The sim will run if red has an equal array length or smaller array length 
%            than black or blue
%
%
% Outputs: o Path Of SpaceCraft  - Plots a top down veiw of the table, the
%                                  desired path for the spacecraft, and the 
%                                  orientation of the spacecraft


function PlotSim_V2(system_output,Spacecraft_name,Path,Spacecraft_name2,Path2)
    % Set up the video file properties
    outputVideo = VideoWriter('myVideo.mp4', 'MPEG-4');
    outputVideo.FrameRate = 100; % Set the frame rate (frames per second)
    % Open the video object
    open(outputVideo);

    if nargin == 1
        black = 0;
        blue = 0;
    elseif nargin == 2
        disp('Please give path for Spacecraft')
        black = 0;
        blue = 0;
    elseif nargin == 3
        if strcmp(Spacecraft_name,'black')
            black = 1;
            blue = 0;
            x_k = Path(:,1);
            y_k = Path(:,2);
            theta_k = Path(:,3);
        elseif strcmp(Spacecraft_name,'blue')
            black = 0;
            blue = 1;
            x_b = Path(:,1);
            y_b = Path(:,2);
            theta_b = Path(:,3);
        else
            disp('Please name Spacecraft, black or blue')
            black = 0;
            blue = 0;
        end
    elseif nargin == 4
        disp('Please give path for Spacecraft')
        if strcmp(Spacecraft_name,'black')
            black = 1;
            blue = 0;
            x_k = Path(:,1);
            y_k = Path(:,2);
            theta_k = Path(:,3);
        elseif strcmp(Spacecraft_name,'blue')
            black = 0;
            blue = 1;
            x_b = Path(:,1);
            y_b = Path(:,2);
            theta_b = Path(:,3);
        else
            disp('Please name Spacecraft, black or blue')
            black = 0;
            blue = 0;
        end
    elseif nargin == 5
        if strcmp(Spacecraft_name,'black')
            black = 1;
            x_k = Path(:,1);
            y_k = Path(:,2);
            theta_k = Path(:,3);
        elseif strcmp(Spacecraft_name,'blue')
            blue = 1;
            x_b = Path(:,1);
            y_b = Path(:,2);
            theta_b = Path(:,3);
        else
            disp('Please name Spacecraft, black or blue')
            black = 0;
            blue = 0;
        end
        if strcmp(Spacecraft_name2,'black')
            black = 1;
            x_k = Path2(:,1);
            y_k = Path2(:,2);
            theta_k = Path2(:,3);
        elseif strcmp(Spacecraft_name2,'blue')
            blue = 1;
            x_b = Path2(:,1);
            y_b = Path2(:,2);
            theta_b = Path2(:,3);
        else
            disp('Please name Spacecraft, black or blue')
            black = 0;
            blue = 0;
        end


    end

    % Creat the trajectory
    x_r = system_output(:,1); % Retriving x data
    y_r = system_output(:,2); % Retriving y data
    theta_r = system_output(:,3); % Retriving theta data
    sz = size(system_output); % Finding size of array
    sz = sz(1,1); % removing unwanted demensions
    
    % Set up axes
    fig = figure();
    axh = axes('Parent',fig);
    hold(axh,'on')
    
    rectangle('position',[0 0 3.5 2.4]) % Creating table
    axis([-0.2 3.7 -0.2 2.6]) % Setting axis 
    xlabel('Distance [m]')
    ylabel('Distance [m]')
    
    % plot empty line objects (with NaN values)
    line1 = plot(axh,x_r, nan(size(x_r)),'-','Color','r');
    if black == 1
        line2 = plot(axh,x_k, nan(size(x_k)),'-','Color','k');
    end
    if blue == 1
        line3 = plot(axh,x_b, nan(size(x_b)),'-','Color','b');
    end

    % Red
    marker1 = plot(axh,nan,nan,'Color','r');
    marker2 = plot(axh,nan,nan,'color','r');
    marker25 = plot(axh,nan,nan,'color','r');
    
    % Black
    if black == 1
        marker3 = plot(axh,nan,nan,'color','k');
        marker4 = plot(axh,nan,nan,'color','k');
        marker45 = plot(axh,nan,nan,'color','k');
    end

    % Blue
    if blue == 1
        marker5 = plot(axh,nan,nan,'color','b');
        marker6 = plot(axh,nan,nan,'color','b');
    end

    % Loop through t and make each point appear
    for k=1:5:sz
        %% Plotting Red
        % Marker plots
        marker1.XData = x_r(k);
        marker1.YData = y_r(k);
    
        % Line plots
        line1.YData(1:k) = y_r(1:k);
    
        % Creating the spacecraft
        x_r_1 = x_r(k) + 0.15*(sqrt(2))*cos(theta_r(k) + (pi/4)); 
        y_r_1 = y_r(k) + 0.15*(sqrt(2))*sin(theta_r(k) + (pi/4));
        x_r_2 = x_r(k) + 0.15*(sqrt(2))*cos(theta_r(k) + (-pi/4)); 
        y_r_2 = y_r(k) + 0.15*(sqrt(2))*sin(theta_r(k) + (-pi/4));
        y_r_3 = y_r(k) + 0.15*(sqrt(2))*sin(theta_r(k) + (-3*pi/4));
        x_r_3 = x_r(k) + 0.15*(sqrt(2))*cos(theta_r(k) + (-3*pi/4));
        x_r_4 = x_r(k) + 0.15*(sqrt(2))*cos(theta_r(k) + (3*pi/4)); 
        y_r_4 = y_r(k) + 0.15*(sqrt(2))*sin(theta_r(k) + (3*pi/4));
        corner_r_1 = [x_r_1 y_r_1];
        corner_r_2 = [x_r_2 y_r_2];
        corner_r_3 = [x_r_3 y_r_3];
        corner_r_4 = [x_r_4 y_r_4];
        Corners_r = [corner_r_1; corner_r_2; corner_r_3; corner_r_4; corner_r_1];
        marker2.XData = Corners_r(:,1);
        marker2.YData = Corners_r(:,2);

        % Rotate the docking port coordinates by theta
            Rr = [cos(theta_r(k)-pi/2) -sin(theta_r(k)-pi/2); sin(theta_r(k)-pi/2) cos(theta_r(k)-pi/2)];

        % male docking cone
            male_cone_origin = [0.0825;0.15];
            rm1 = male_cone_origin + [0.025;0];
            rm2 = male_cone_origin + [0.025;0.0008];
            rm3 = male_cone_origin + [0.045;0.0008];
            rm4 = male_cone_origin + [0.02;0.0508];
            rm5 = male_cone_origin + [-0.02;0.0508];
            rm6 = male_cone_origin + [-0.045;0.0008];
            rm7 = male_cone_origin + [-0.025;0.0008];
            rm8 = male_cone_origin + [-0.025;0];

            % Rotating
            rm1 = Rr*rm1 + [x_r(k); y_r(k)];
            rm2 = Rr*rm2 + [x_r(k); y_r(k)];
            rm3 = Rr*rm3 + [x_r(k); y_r(k)];
            rm4 = Rr*rm4 + [x_r(k); y_r(k)];
            rm5 = Rr*rm5 + [x_r(k); y_r(k)];
            rm6 = Rr*rm6 + [x_r(k); y_r(k)];
            rm7 = Rr*rm7 + [x_r(k); y_r(k)];
            rm8 = Rr*rm8 + [x_r(k); y_r(k)];

            % Plotting docking port
            marker25.XData = [rm1(1), rm2(1), rm3(1), rm4(1), rm5(1), rm6(1), rm7(1), rm8(1)];
            marker25.YData = [rm1(2), rm2(2), rm3(2), rm4(2), rm5(2), rm6(2), rm7(2), rm8(2)];

        a = 0.05;

        %% Plotting Black
        if black == 1
            % Marker plots
            marker3.XData = x_k(k);
            marker3.YData = y_k(k);
        
            % Line plots
            line2.YData(1:k) = y_k(1:k);
        
            % Creating the spacecraft
            x_k_1 = x_k(k) + 0.15*(sqrt(2))*cos(theta_k(k) + (pi/4)); 
            y_k_1 = y_k(k) + 0.15*(sqrt(2))*sin(theta_k(k) + (pi/4));
            x_k_2 = x_k(k) + 0.15*(sqrt(2))*cos(theta_k(k) + (-pi/4)); 
            y_k_2 = y_k(k) + 0.15*(sqrt(2))*sin(theta_k(k) + (-pi/4));
            y_k_3 = y_k(k) + 0.15*(sqrt(2))*sin(theta_k(k) + (-3*pi/4));
            x_k_3 = x_k(k) + 0.15*(sqrt(2))*cos(theta_k(k) + (-3*pi/4));
            x_k_4 = x_k(k) + 0.15*(sqrt(2))*cos(theta_k(k) + (3*pi/4)); 
            y_k_4 = y_k(k) + 0.15*(sqrt(2))*sin(theta_k(k) + (3*pi/4));
            corner_k_1 = [x_k_1 y_k_1];
            corner_k_2 = [x_k_2 y_k_2];
            corner_k_3 = [x_k_3 y_k_3];
            corner_k_4 = [x_k_4 y_k_4];

            % Plotting spacecraft
            Corners_k = [corner_k_1; corner_k_2; corner_k_3; corner_k_4; corner_k_1];
            marker4.XData = Corners_k(:,1);
            marker4.YData = Corners_k(:,2);

            % Rotate the docking port coordinates by theta
            Rb = [cos(theta_k(k)) -sin(theta_k(k)); sin(theta_k(k)) cos(theta_k(k))];

            % Docking port coordinates
            female_cone_origin = [0.0825;0.15];
            bkm1 = female_cone_origin + [0.025;0];
            bkm2 = female_cone_origin + [0.025;0.0762];
            bkm3 = female_cone_origin + [0.0675;0.127];
            bkm4 = female_cone_origin + [-0.0675;0.127];
            bkm5 = female_cone_origin + [-0.025;0.0762];
            bkm6 = female_cone_origin + [-0.025;0];

            % Rotating
            bkm1 = Rb*bkm1 + [x_k(k); y_k(k)];
            bkm2 = Rb*bkm2 + [x_k(k); y_k(k)];
            bkm3 = Rb*bkm3 + [x_k(k); y_k(k)];
            bkm4 = Rb*bkm4 + [x_k(k); y_k(k)];
            bkm5 = Rb*bkm5 + [x_k(k); y_k(k)];
            bkm6 = Rb*bkm6 + [x_k(k); y_k(k)];

            % Plotting docking port
            marker45.XData = [bkm1(1), bkm2(1), bkm3(1), bkm4(1), bkm5(1), bkm6(1)];
            marker45.YData = [bkm1(2), bkm2(2), bkm3(2), bkm4(2), bkm5(2), bkm6(2)];
        end

        %% Plotting Black
        if blue == 1
            % Marker plots
            marker5.XData = x_b(k);
            marker5.YData = y_b(k);
        
            % Line plots
            line3.YData(1:k) = y_b(1:k);
        
            % Creating the spacecraft
            x_b_1 = x_b(k) + 0.15*(sqrt(2))*cos(theta_b(k) + (pi/4)); 
            y_b_1 = y_b(k) + 0.15*(sqrt(2))*sin(theta_b(k) + (pi/4));
            x_b_2 = x_b(k) + 0.15*(sqrt(2))*cos(theta_b(k) + (-pi/4)); 
            y_b_2 = y_b(k) + 0.15*(sqrt(2))*sin(theta_b(k) + (-pi/4));
            y_b_3 = y_b(k) + 0.15*(sqrt(2))*sin(theta_b(k) + (-3*pi/4));
            x_b_3 = x_b(k) + 0.15*(sqrt(2))*cos(theta_b(k) + (-3*pi/4));
            x_b_4 = x_b(k) + 0.15*(sqrt(2))*cos(theta_b(k) + (3*pi/4)); 
            y_b_4 = y_b(k) + 0.15*(sqrt(2))*sin(theta_b(k) + (3*pi/4));
            corner_b_1 = [x_b_1 y_b_1];
            corner_b_2 = [x_b_2 y_b_2];
            corner_b_3 = [x_b_3 y_b_3];
            corner_b_4 = [x_b_4 y_b_4];
            Corners_b = [corner_b_1; corner_b_2; corner_b_3; corner_b_4; corner_b_1];
            marker6.XData = Corners_b(:,1);
            marker6.YData = Corners_b(:,2);
        end
    
        drawnow(); 
        % Capture the current figure or axes as an image frame
        frame = getframe(gcf); % gcf captures the current figure
    
        % Write the frame to the video object
        writeVideo(outputVideo, frame); 
    end
    % Close the video object
    close(outputVideo);

end

function PlayVideo(videoFileName)
    % Create a VideoReader object
    v = VideoReader(videoFileName);

    % Read the frames from the video
    frames = read(v);

    % Play the video using implay
    implay(frames);
end