function [Result_table, Result_table_summary] = ORACLE_logit(simulation_size, Data_x, y_real, sample_size, row_size, col_size, beta_real, gamma_real,...
                         eps_initial, iter_max_initial_in, cv_number, tuning_start, tuning_end, tuning_number, if_fix)
%-------------------------------------函数功能----------------------------------------%
% 根据oracle情形的模型进行矩阵变量线性回归，比较sc值，均方误差等参数
%-------------------------------------使用方法----------------------------------------%
% [Result_table, Result_table_summary] = ORACLE_logit(simulation_size, Data_x, y_real,...
%            sample_size, row_size, col_size, beta_real, gamma_real, [], [], [], [], [], [], [])
%----------------------------------需要的前置函数-------------------------------------%
% Matlab Function:         respclust_single_regression     
%                          respclust_k_means_sc
%-----------------------------------输出变量说明--------------------------------------%
% Result_table:            每次simulation结果的表格
% Result_table_summary:    所有simulation的评价结果取均值或标准差的表格汇总
%-----------------------------------输入变量说明--------------------------------------%
% simulation_size:         模拟重复的次数
% Data_x:                  矩阵数据(row_size*col_size*sample_size*simulation_size)
% y_real:                  连续响应变量
% sample_size:             样本量
% col_size:                矩阵变量的列数
% row_size:                矩阵变量的行数
% beta_real:               真实的行回归系数
% gamma_real:              真实的列回归系数
% eps_initial:             矩阵回归模型的对数似然的收敛容差
% iter_max_initial_in      矩阵回归模型迭代的最大步数
% 解决多次模拟和单次模拟的维度不一致
if simulation_size == 1
    Data_x = reshape(Data_x, [row_size,col_size,sample_size,1]);
    y_real = reshape(y_real, [sample_size, 1]);
end
% 设置默认参数
if isempty(eps_initial)
    eps_initial = 1e-3;
end
if isempty(iter_max_initial_in)
    iter_max_initial_in = 200;
end
if isempty(beta_real)
    beta_real = zeros(sample_size*row_size,1);
end
if isempty(gamma_real)
    gamma_real = zeros(sample_size*col_size,1);
end
if isempty(cv_number)
    cv_number = 3;
end
if isempty(tuning_number)
    tuning_number = 3;
end
if isempty(tuning_start)
    tuning_start = 0.1;
end
if isempty(tuning_end)
    tuning_end = 5;%5
end
if isempty(if_fix)
    if_fix = 1;%1
end
% 设置存储的结构体Result
Result = struct;
Result(simulation_size).per_if = [];
Result(simulation_size).sc = [];
Result(simulation_size).k = [];
Result(simulation_size).mse_beta = [];
Result(simulation_size).mse_gamma =[];
Result(simulation_size).beta_back = [];
Result(simulation_size).gamma_back = [];
Result(simulation_size).convergence = [];
% 抽出第i次模拟的样本
for i = 1:simulation_size
    y = y_real(:, i);
    x = Data_x(:,:,:,i);
    [result] = oracle_single_regression_logit(x, y, sample_size, row_size, col_size, beta_real, gamma_real,...
                                            eps_initial, iter_max_initial_in, cv_number, tuning_start, tuning_end, tuning_number, if_fix);
    Result(i).per_if = result.per_if;
    Result(i).sc = result.sc;
    Result(i).k = result.k;
    Result(i).mse_beta = result.mse_beta;
    Result(i).mse_gamma = result.mse_gamma;
    Result(i).beta_back = result.beta_back;
    Result(i).gamma_back = result.gamma_back;
    Result(i).convergence = result.convergence;
    fprintf("已完成基于oracle情形下的异质矩阵回归模型第%.1f %%\n",(i/simulation_size)*100)
end
Result_table = struct2table(Result,"AsArray",true);
per = sum(Result_table.per_if)/simulation_size;
K_mean = mean(Result_table.k);
K_sd = std(Result_table.k);
SC_mean = mean(Result_table.sc);
SC_sd  = std(Result_table.sc);
MSE_beta_mean = mean(Result_table.mse_beta);
MSE_beta_sd = std(Result_table.mse_beta);
MSE_gamma_mean = mean(Result_table.mse_gamma);
MSE_gamma_sd = std(Result_table.mse_gamma);
convergence_mean = mean(Result_table.convergence);
convergence_sd = std(Result_table.convergence);
Result_table_summary = [K_mean,K_sd,per,SC_mean,SC_sd,MSE_beta_mean,MSE_beta_sd,MSE_gamma_mean,MSE_gamma_sd,convergence_mean,convergence_sd];
Result_table_summary = array2table(Result_table_summary, 'VariableNames', {'K_mean','K_sd','per','SC_mean','SC_sd','MSE_beta_mean','MSE_beta_sd',...
                                 'MSE_gamma_mean','MSE_gamma_sd','convergence_mean','convergence_sd'});
disp(Result_table);
disp(Result_table_summary);
save('D:\MATLAB_Document2\ADMM_BCD_new\多方法结果\ORACLE\非平衡设计\mu=1\B2\Result_table',"Result_table")
save('D:\MATLAB_Document2\ADMM_BCD_new\多方法结果\ORACLE\非平衡设计\mu=1\B2\Result_table_summary',"Result_table_summary")
end















