function [result] = oracle_single_regression_logit(x, y, sample_size, row_size, col_size, beta_real, gamma_real,...
                         eps_initial, iter_max_initial_in, cv_number, tuning_start, tuning_end, tuning_number, if_fix)
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
[~, Ireal, class] = unique(real_class,'rows');
k_real_num = length(Ireal);
k_best = k_real_num;
index_store = cell(k_best, 1);
for i = 1: k_best
    index_store{i,1} = find(class==i);
end
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
% 对每个分组分别用矩阵回归线性模型进行拟合
[beta_back, gamma_back, convergence] = matrix_homogeneity_regression_logit(x, y, index_store, sample_size, row_size, col_size, eps_initial, iter_max_initial_in,...
                                                                    cv_number, tuning_start, tuning_end, tuning_number, if_fix);
% 计算估计参数的MSE
mse_beta = sum((beta_back-beta_real).^2)/(sample_size*row_size);
mse_gamma = sum((gamma_back-gamma_real).^2)/(sample_size*col_size);
result.per_if = per_if;
result.sc = sc;
result.k = k_best;
result.mse_beta = mse_beta;
result.mse_gamma = mse_gamma;
result.beta_back = beta_back;
result.gamma_back = gamma_back;
result.convergence = convergence;
end









