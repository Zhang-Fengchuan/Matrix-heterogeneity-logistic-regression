function [Result_table, Result_table_summary] = INITIAL_logit(simulation_size, Data_x, y_real, sample_size, row_size, col_size, beta_real, gamma_real,...
                                                        num_partitions_list, eps_initial, eps_out, iter_max_initial_in, iter_max_initial_out,...
                                                        combine_principle_list, split_principle_list, random_number_list, disp_if, cv_number, tuning_start, tuning_end, tuning_number, if_fix)
%-------------------------------------函数功能----------------------------------------------------%
% 使用初值搜索算法的异质矩阵回归模型，返回聚类数，sc值，均方误差等参数以及估计的初始值(可多次模拟)
%-----------------------------------------使用方式----------------------------------------------------------------------%
%[Result_table, Result_table_summary] = INITIAL_logit(simulation_size, Data_x, y_real, sample_size, row_size, col_size, beta_real, gamma_real,...
%                                                        [], [], [], [], [], [], [], [], [], [], [], [], [], [])
%----------------------------------需要的前置函数---------------------------------------------------------------------------%
% Matlab Function:         k_means_regression_initial_logit     
%                          k_means_regression_tree_single_logit    
%                          k_means_regression_cv_logit
%                          k_means_regression_logit
%-----------------------------------输出变量说明--------------------------------------------------%
% Result_table:            每次simulation结果的表格
% Result_table_summary:    所有simulation的评价结果取均值或标准差的表格汇总
%-----------------------------------输入变量说明--------------------------------------------------%
% num_partitions_list       将数据分成几份,参数矩阵
% eps_initial               每次进行同质模型回归时，每个模型收敛的精度
% iter_max_initial_in       每次进行同质模型回归时，交替优化的最大步数上限
% eps_out                   第 n 次与第 n-1 次样本重新划分后模型的系数差精度，收敛精度
% iter_max_initial_out      样本重新划分的最大次数上限
% sample_size               样本量
% row_size                  行向量维数
% col_size                  列向量维数
% x                         一次模拟中的解释变量[row_size*col_size*sample_size]
% y                         一次模拟中的响应变量[sample_size*1]
% random_number_list        随机种子参数矩阵
% combine_principle_list    最少元素个数组合并准则的参数矩阵

% split_principle_list      最多元素个数分数准则的参数矩阵
% disp_if                   是否输出过程进度信息
% beta_real:                真实的行回归系数
% gamma_real:               真实的列回归系数
% 解决多次模拟和单次模拟的维度不一致
if simulation_size == 1
    Data_x = reshape(Data_x, [row_size,col_size,sample_size,1]);
    y_real = reshape(y_real, [sample_size, 1]);
end
% 设置默认参数
if isempty(eps_initial)
    eps_initial = 1e-3;
    %对数似然函数收敛条件1e-5
end
if isempty(eps_out)
    eps_out = 1e-3;
    %初值算法收敛条件1e-8
end
if isempty(iter_max_initial_in)
    iter_max_initial_in = 200;
end
if isempty(iter_max_initial_out)
    iter_max_initial_out = 200;
end
if isempty(num_partitions_list)
    num_partitions_list = 6:8;
end
if isempty(combine_principle_list)
    combine_principle_list = linspace(0.1, 0.3, 10)*sample_size; 
end
if isempty(split_principle_list)
    split_principle_list = linspace(0.6,0.6,1)*sample_size;
end
if isempty(random_number_list)
    random_number_list = 1:25;
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
    tuning_end = 5;
end
if isempty(if_fix)
    if_fix = 1;
end
if isempty(disp_if)
    disp_if = 1;
end
if isempty(beta_real)
    beta_real = zeros(sample_size*row_size,1);
end
if isempty(gamma_real)
    gamma_real = zeros(sample_size*col_size,1);
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
Result(simulation_size).partitions = [];
Result(simulation_size).coefficients = [];
Result(simulation_size).num_partitions_best = [];
Result(simulation_size).combine_principle_best = [];
Result(simulation_size).split_principle_best = [];
Result(simulation_size).random_number_best = [];
% 抽出第i次模拟的样本
parfor i = 1:simulation_size
    y = y_real(:, i);
    x = Data_x(:,:,:,i);
    [~, ~, partitions, result] = k_means_regression_initial_logit(num_partitions_list, eps_initial, eps_out,...
                                                    iter_max_initial_in, iter_max_initial_out,...
                                                    combine_principle_list, split_principle_list, random_number_list,...
                                                    sample_size, row_size, col_size, x, y, disp_if,...
                                                    beta_real, gamma_real,cv_number,tuning_start,tuning_end,tuning_number,if_fix);
    Result(i).per_if = result.per_if;
    Result(i).sc = result.sc;
    Result(i).k = result.k;
    Result(i).mse_beta = result.mse_beta;
    Result(i).mse_gamma = result.mse_gamma;
    Result(i).beta_back = result.beta_back;
    Result(i).gamma_back = result.gamma_back;
    Result(i).convergence = result.convergence;
    Result(i).partitions = partitions;
    Result(i).coefficients = result.coefficients;
    Result(i).num_partitions_best = result.num_partitions_best;
    Result(i).combine_principle_best = result.combine_principle_best;
    Result(i).split_principle_best = result.split_principle_best;
    Result(i).random_number_best = result.random_number_best;
    fprintf("已完成初值搜索算法的异质矩阵回归模型第%.1f %%\n",(i/simulation_size)*100)
end
Result_table = struct2table(Result);
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
save('D:\MATLAB_Document2\ADMM_BCD_new\多方法结果\初值\非平衡设计\mu=1\B2\Result_table',"Result_table")
save('D:\MATLAB_Document2\ADMM_BCD_new\多方法结果\初值\非平衡设计\mu=1\B2\Result_table_summary',"Result_table_summary")
end