function [m, A, Eigenfaces]=lps_Trainit()
% A sample script, which shows the usage of functions, included in
% PCA-based face recognition system (Eigenface method)
clear all
clc
close all

% You can customize and fix initial directory paths
lps_TrainDatabasePath = uigetdir('F:\code\face_by_lps\Database_system\', 'Select training database path' );
T = lps_TrainDatabase(lps_TrainDatabasePath);
[m, A, Eigenfaces] =lps_EigenfaceCore(T);
end
