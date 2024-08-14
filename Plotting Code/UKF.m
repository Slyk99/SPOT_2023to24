function [no_IC,States,P_K,P_xz_k,P_z_k,X_Cal_k1,dm,residual] = UKF(Measurments,Force,States_k1,P_K1, lamda, J, m, dt, Q, a, b, H, R,thresh,method)
%% Block diagram got messy so i put it all in one block
if isempty(Force)
    Force = [0;0;0];
end

%% Inital position
if all(States_k1 == 0) || anynan(States_k1)
    if anynan(Measurments)
        States = NaN(6,1);
        no_IC = 1;
        P_K = P_K1;
        P_xz_k = [0.2*eye(3);0.2*eye(3)];
        P_z_k = 0.2*eye(3);
        dm = 0;
        residual = zeros(3,1);
        X_Cal_k1 = zeros(6,13);
    else
        States = [Measurments(1);Measurments(2);Measurments(3);zeros(3,1)];
        no_IC = 0;
        P_K = P_K1;
        P_xz_k = [0.2*eye(3);0.2*eye(3)];
        P_z_k = 0.2*eye(3);
        dm = 0;
        residual = zeros(3,1);
        X_Cal_k1 = zeros(6,13);
    end
else
    no_IC = 0;

    X_Cal = fcn1(States_k1,P_K1,lamda,method);
    
    X_Cal_k1 = fcn2(Force,X_Cal,J,m,dt);
    
    [w_m,w_c,X_tilda_k,P_K1] = fcn3(X_Cal_k1,lamda, Q, a, b);
    
    [Z_Bar,Z_Cal] = fcn4(X_Cal_k1, w_m,H);
    
    [P_xz_k,P_z_k] = fcn5(Z_Bar,Z_Cal,w_c,X_tilda_k,X_Cal,R);
    
    K_k = fcn6(P_xz_k,P_z_k);
    
    Z_k = fcn7(Measurments);
    
    [Reject,dm] = fcn8(Z_k,Z_Bar,P_z_k,thresh);

    residual = Z_k - Z_Bar;
    
    States = fcn9(Z_k,Reject,X_tilda_k,Z_Bar,K_k);
    
    P_K = fcn10(P_K1,P_z_k,K_k,Reject);
    
    States = removeImaginary(States);
    P_K = removeImaginary(P_K);
    
end
end

function X_Cal = fcn1(x_tilda_k,P_k,lamda,method)
%% Calculate size of sigma var
sz = 6;
N = 2*sz + 1;
X_Cal = zeros(sz,N);

%% Calculate initial sigma point
X_Cal(:,1) = x_tilda_k;

%% Calculate sigma distance
sigma = (6 + lamda)*P_k;
sigma = Cholesky_Decomposition(sigma,method);

%% Calculate Sigma Points
% Positive points
for i = 2:1:((N-1)/2) + 1
    fill = zeros(size(x_tilda_k));
    fill(i-1,1) = sigma(i-1,i-1);
    X_Cal(:,i) = x_tilda_k + fill;
end
% Negative Points
j = 1;
for i = N + 1 - ((N-1)/2):1:N
    fill = zeros(size(x_tilda_k));
    fill(j,1) = sigma(j,j);
    X_Cal(:,i) = x_tilda_k - fill;
    j = j + 1;
end
end

function L = Cholesky_Decomposition(mat,method)

%% Getting size of matrix
[row,col] = size(mat);

%% Make sure matrix can be decomposed
if ~isequal(size(mat), size(mat'))
    error('Input matrix must be symmetric');
end

if any(eig(mat) <= 0)
    % error('Input matrix must be positive definite'); %% Added Error
    % Handling
    mat = NearPositiveDefinite(mat,method);
end

%% Pre allocating Space
L = zeros(row,col);

% Perform Cholesky decomposition
    for i = 1:col
        % Compute the diagonal element
        L(i, i) = sqrt(mat(i, i) - sum(L(i, 1:i-1).^2));
        
        % Compute the elements below the diagonal
        for j = i+1:col
            L(j, i) = (mat(j, i) - sum(L(j, 1:i-1).*L(i, 1:i-1))) / L(i, i);
        end
    end
end

function A_P = NearPositiveDefinite(A,method)
%% Method 1 (Symmetric Polar Factor)
%% Method 2 (Eigenvalue Recomposition)
    % enforce symmetry
    if isreal(A)
        B = 0.5*(A + A');
    else
        B = 0.5*(A + A');
        B = real(B) + 1i*hermSign(B).*imag(B);
    end

    if method == 1
        [~,~,U] = svd(B);
        H = U*U';
        A = (B + H)/2;

    elseif method == 2
        % Eigenvalue recomposition with modification for complex matrices
        [V,D] = eig(B);
        if isreal(A)
            D = max(real(D), 0); % Ensure real part of eigenvalues is non-negative
        else
            % For complex matrices, ensure positive semidefinite
            D = max(D, 0); % Ensure eigenvalues are non-negative
            V = real(V); % Take the real part of eigenvectors
        end
        A = real(V)*real(D)*real(V)'; % Now this really real product really should be really real right?
    else
        error('Please select proper method for Near Positive Definite Iteration')
    end

    % enforce symmetry again
    A_P = 0.5*(A + A');

    % Iteration
    i = 1;
    j = 0;
    max_iterations = 1000; % Maximum iterations allowed before increment starts increasing exponentially
    large_j_threshold = 500; % Threshold value for j to start increasing increment exponentially

    while i ~= 0
        [~,i] = chol(A_P);
        j = j + 1;
        if i ~= 0 % if close, add a multiple of the identity scaled by the smallest eigenvalue
            eig_min = min(eig(A_P));
            if j <= large_j_threshold
                increment = (-real(eig_min)*j.^2 + eps(real(eig_min)))*eye(size(A));
            else
                % Increase increment exponentially
                increment = (abs(real(eig_min))*j.^2 + eps(real(eig_min)))*exp(0.1*(j - large_j_threshold))*eye(size(A));
            end
            A_P = A_P + increment*10^13;
        end
        if j > max_iterations % If j exceeds the maximum allowed iterations, break the loop
            break;
        end
    end
end

function X_Cal_k1  = fcn2( F, X_Cal_k, J, m, dt)
%% Pre-Define
X_Cal_k1 = zeros(size(X_Cal_k));
%% System Dynamics
A = [eye(3), eye(3)*dt;
    zeros(3), eye(3)];

B = [eye(2)*(dt^2)/(2*m), zeros(2,1);
     0,0, (dt^2)/(2*J);
     eye(2)*(dt)/(m), zeros(2,1);
     0,0, (dt)/(J)];

%% State propigation
f = size(X_Cal_k,2);
for i = 1:1:f
    X_Cal_k1(:,i) = A*X_Cal_k(:,i) + B*F; 
end
end

function [w_m,w_c,X_tilda_k,P_K] = fcn3(X_Cal_k1,lamda, Q, alpha, beta)
%% Sigma weights
sz = size(X_Cal_k1,2);
N = 6;

%% For non modifyed variation
% w_0 = kappa/(N + kappa);
% w_i = 1/(2*(N + kappa));
% w = w_i*ones(1,N);
% w(1,1) = w_0;

%% Additional step - Sigma Points Weights
w_m_0 = lamda/(N + lamda);
w_c_0 = (lamda/(N + lamda)) + beta + (1 - alpha^2);
w_i = 1/(2*(N + lamda));

w = w_i*ones(1,sz-1);
w_m = [w_m_0, w];
w_c = [w_c_0, w];

w_m = diag(w_m);
w_c = diag(w_c);

%% State Prediction
X_tilda_k = X_Cal_k1*w_m;
X_tilda_k = sum(X_tilda_k,2);


%% Covariance Prediction
P_K = (X_Cal_k1 - X_tilda_k)*w_c*(X_Cal_k1 - X_tilda_k)' + Q;

end

function [Z_Bar,Z_Cal] = fcn4(x_Cal_k1, w_m,H)
%% calc Z_Cal
N = size(x_Cal_k1,2);
Z_Cal = zeros(3,N);
for i = 1:1:N
    Z_Cal(:,i) = H*x_Cal_k1(:,i);
end

%% Calc Z_Bar
Z_Bar = Z_Cal*w_m;
Z_Bar = sum(Z_Bar,2);
end

function [P_xz_k,P_z_k] = fcn5(Z_Bar,Z_Cal,w_c,x_tilda_k1,X_Cal,R)
%% calc P_z
P_z_k = (Z_Cal - Z_Bar)*w_c*(Z_Cal - Z_Bar)' + R;

%% calc P_xz
P_xz_k = (X_Cal - x_tilda_k1)*w_c*(Z_Cal - Z_Bar)';
end

function K_k = fcn6(P_xz_k,P_z_k)
K_k = (P_xz_k)*P_z_k';
end

function Z_k = fcn7(z_k)
    %% Assuming that all states are given or no states are given
    if anynan(z_k)
        Z_k = 10000*ones(3,1); % could just set Reject to 1 here but thats too easy
    else
    Z_k = z_k;
    end
end

function  [Reject,dm] = fcn8(Z_k,Z_Bar,P_z_k,thresh)
%% Calc Mahalanobis Distance
D_square = (transpose(Z_k - Z_Bar))*P_z_k*(Z_k - Z_Bar);
dm = sqrt(D_square);

%% Determine if data should be rejected
if D_square < thresh
    Reject = 0;
else
    Reject = 1;
end
end

function [x] = fcn9(z,Reject,X_tilda_k,z_bar,K_k)
%% State estimate
    if Reject == 0
        x = X_tilda_k + K_k*(z - z_bar);
    else
        x = X_tilda_k;
    end
end

function P_K = fcn10(P_k1,P_z_k,K_k,Reject)
if Reject == 0
    P_K = P_k1 - (K_k*P_z_k)*K_k';
else
    P_K = P_k1;
end
end

function realArray = removeImaginary(inputArray)
    % Check if the input array is complex
    if ~isreal(inputArray)
        % Remove the imaginary part
        realArray = real(inputArray);
    else
        % If the input array is already real, return it as is
        realArray = inputArray;
    end
end