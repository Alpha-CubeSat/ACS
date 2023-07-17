% EKF sample implementation for Lorenz Attractor system
% developed by: Ethem Hakan Orhan - 12/2018
%
close all;
clear all;

% simulation timestep
dT = 0.01; % sec
k_noise = 1; % noise switch

% Lorenz attractor coefficients
rho     = 28;
sigma   = 10;
beta    = 8/3;

% H (output) Matrix
H = eye(3);

% R (process noise variance) Matrix
R = [0.0025, 0,       0;
     0,    0.0025,    0;
     0,    0,      0.0025];

% Q (measurement noise variance) Matrices
Q = [100,  0,  0; 
     0,  1000,  0;
     0,  0,  1000];

% Discretize H, R
Hd = H;
Rd = (1/dT)*R;
 


