    function [beta0, gamma0, partitions, result] = k_means_regression_initial_logit(num_partitions_list, eps_initial, eps_out,...
                                                        iter_max_initial_in, iter_max_initial_out,...
                                                        combine_principle_list, split_principle_list, random_number_list,...
                                                        sample_size, row_size, col_size, x, y, disp_if,...
                                                        beta_real, gamma_real,cv_number,tuning_start,tuning_end,tuning_number,if_fix)

%k_means_regression_initial_logit(num_partitions_list, eps_initial, eps_out,...
%                                                    iter_max_initial_in, iter_max_initial_out,...
%                                                   combine_principle_list, split_principle_list, random_number_list,...
%                                                    sample_size, row_size, col_size, x, y, disp_if,...
%                                                    beta_real, gamma_real,cv_number,tuning_start,tuning_end,tuning_number,if_fix)
%-----------------------------------------函数功能-------------------------------------------%
% 使用初值搜索算法的异质矩阵回归模型，返回聚类数，sc值，均方误差等参数以及估计的初始值
%-----------------------------------------使用方式--------------------------------------------%
% [beta0, gamma0, partitions, result] = k_means_regression_initial_logit([], [], [],...
%                                                    [], [], [], [], [], sample_size, row_size, col_size,...
%                                                    x, y, [], beta_real, gamma_real,cv_number,...
%                                                   tuning_start,tuning_end,tuning_number,if_fix)
%--------------------------------------需要的前置函数-----------------------------------------%
% Matlab Function:         k_means_regression_tree_single_logit    
%                          k_means_regression_cv_logit 
%                          k_means_regression_logit 
%---------------------------------------输出变量说明------------------------------------------%
% beta0:                   单次simulation时，使用初值搜索算法的异质矩阵回归模型返回的beta估计值
% gamma0:                  单次simulation时，使用初值搜索算法的异质矩阵回归模型返回的gamma估计值
% partitions:              单次simulation时，使用初值搜索算法的异质矩阵回归模型返回的分组情况
% result:                  单次simulation时，返回结果结构体，包括k、sc、最优cv参数、参数估计值等
%---------------------------------------输入变量说明------------------------------------------%
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
    combine_principle_list = linspace(0.2,0.4,3)*sample_size; 
    %改为BIC时可修改为linspace(0.1,0.5,3)*sample_size
end
if isempty(split_principle_list)
    split_principle_list = linspace(0.6,0.6,1)*sample_size;
end
if isempty(random_number_list)
    random_number_list = 1:5;
    %或许可以改为1:25
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
result = struct;
result.per_if = [];
result.sc = [];
result.k = [];
result.mse_beta = [];
result.mse_gamma = [];
result.beta_back = [];
result.gamma_back = [];
result.convergence = [];
result.coefficients = [];
result.num_partitions_best = [];
result.combine_principle_best = [];
result.split_principle_best = [];
result.random_number_best = [];
[num_partitions_best,combine_principle_best,split_principle_best,random_number_best, cv_matrix] = k_means_regression_cv_logit(num_partitions_list,eps_initial,eps_out,iter_max_initial_in,...
    iter_max_initial_out,combine_principle_list,split_principle_list,random_number_list,sample_size,row_size,col_size,x,y,disp_if,...
        cv_number,tuning_start,tuning_end,tuning_number,if_fix);
[beta0,gamma0,coefficients,partitions,combine,residual_coefficients] = k_means_regression_logit(num_partitions_best,eps_initial,eps_out,iter_max_initial_in,...
    iter_max_initial_out,combine_principle_best,split_principle_best,sample_size,row_size,col_size,x,y,random_number_best,cv_number,tuning_start,tuning_end,tuning_number,if_fix);
% 获得单次simulation的k_means的分组数和分类情况
k_best = length(partitions);
index_store = cell(k_best, 1);
for i = 1: k_best
    index_store{i,1} = partitions{i}';
end
% 真实参数下的分组情况
real_class = zeros(sample_size, sample_size);
for i = 1: (sample_size - 1)
    for j = (i+1): sample_size
        ifsame = norm([beta_real(((i-1)*row_size+1):(i*row_size), 1);gamma_real(((i-1)*col_size+1):(i*col_size), 1)]-...
        [beta_real(((j-1)*row_size+1):(j*row_size), 1);gamma_real(((j-1)*col_size+1):(j*col_size), 1)]);
        if ifsame ~= 0
            real_class(i, j) = 1;
            real_class(j, i) = 1;
        end
    end
end
% 判断基于响应变量k_means聚类的结果与真实系数类数是否相同
[~, Ireal, ~] = unique(real_class,'rows');
k_real_num = length(Ireal);
per_if = 0;
if k_real_num == k_best
    per_if = 1;
end
% 计算一致性指数SC
est_class = ones(sample_size, sample_size);
est_class(sample_size, sample_size) = 0;
for i = 1: (sample_size-1)
    for j = (i+1): sample_size
        for k = 1:k_best
            if any(index_store{k}(:) == i)&&any(index_store{k}(:) == j)
                est_class(i, j) = 0;
                est_class(j, i) = 0;
            end
        end
    end
    est_class(i, i) = 0;
end
count = 0;
for i = 1: (sample_size-1)
    for j = (i+1): sample_size
        if real_class(i,j)==est_class(i,j)
            count = count + 1;
        end
    end
end
sc = count/nchoosek(sample_size,2);
% 计算估计参数的MSE
mse_beta = sum((beta0-beta_real).^2)/(sample_size*row_size);
mse_gamma = sum((gamma0-gamma_real).^2)/(sample_size*col_size);
result.per_if = per_if;
result.sc = sc;
result.k = k_best;
result.mse_beta = mse_beta;
result.mse_gamma = mse_gamma;
result.beta_back = beta0;
result.gamma_back = gamma0;
result.convergence = residual_coefficients;
result.coefficients = coefficients;
result.num_partitions_best = num_partitions_best;
result.combine_principle_best = combine_principle_best/sample_size;
result.split_principle_best = split_principle_best/sample_size;
result.random_number_best = random_number_best;
end



