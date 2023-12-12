function [beta_back, gamma_back, diff_loglikelihood] = matrix_homogeneity_regression_logit(x, y, partitions, sample_size,...
                                                                    row_size, col_size, eps_initial, iter_max_initial_in,...
                                                                    cv_number, tuning_start, tuning_end, tuning_number, if_fix)
num_partitions = length(partitions);
coefficients = zeros((row_size+col_size),num_partitions);
beta_back = zeros(sample_size*row_size,1);
gamma_back = zeros(sample_size*col_size,1);
beta_back0 = zeros(sample_size*row_size,1);
gamma_back0 = zeros(sample_size*col_size,1);
residual_coefficients = 1;
%初始值随机化机制
beta0 = rand(row_size,1);
gamma0 = (1/sqrt(col_size))*rand(col_size,1);
gamma0(1) = sqrt(1-sum(gamma0.^2));
gamma0 = gamma0/gamma0(1);
coefficients0 = [beta0;gamma0];

pai_gamma = zeros(row_size*col_size);
for i = 1:(row_size*col_size)
    if mod(i,row_size)~=0
        pai_gamma(((floor(i/row_size)+1)+(mod(i,row_size)-1)*col_size),i) = 1;
    else
        pai_gamma((floor(i/row_size)+(mod((i-1),row_size))*col_size),i) = 1;
    end
end
pai_gamma = pai_gamma';
iter_initial_out = 0;
%对每个分组的数据进行矩阵回归
for i = 1: num_partitions
    iter_initial_in = 0;
    n_part = length(partitions{i});
    x_part = x(:,:,partitions{i});
    y_part = y(partitions{i});
    [beta_part, gamma_part, ~, ~, diff_loglikelihood] = logit_matrix_ridge_regression_mex(x_part, y_part, n_part,...
                                            row_size, col_size, cv_number, coefficients0,...
                                            tuning_start, tuning_end, tuning_number, eps_initial, iter_max_initial_in, if_fix);
    
    coefficients((1:row_size),i) = beta_part;
    coefficients(((row_size+1):end),i) = gamma_part;
end
for j = 1:num_partitions
   for k = 1:length(partitions{j})
       beta_back((((partitions{j}(k)-1)*row_size)+1):(partitions{j}(k)*row_size),:) = coefficients((1:row_size),j);
       gamma_back((((partitions{j}(k)-1)*col_size)+1):(partitions{j}(k)*col_size),:) = coefficients(((row_size+1):(row_size+col_size)),j);
   end
end
end