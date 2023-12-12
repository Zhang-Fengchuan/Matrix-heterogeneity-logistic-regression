function [beta_back,gamma_back,coefficients,...
    partitions,combine,residual_coefficients] = k_means_regression_tree_single_logit(num_partitions,eps_initial,eps_out,iter_max_initial_in,...
                                                iter_max_initial_out,combine_principle,row_size,col_size,x,y,random_number,beta0,gamma0,partitions_old,sample_size_sum,...
                                                cv_number,tuning_start,tuning_end,tuning_number,if_fix)
%-------------------------------------------函数功能-----------------------------------------------%
% 对于任意给定的 partitions_old（为一组的索引值），可以进行二分裂，利用残差迭代算法进行求解
% 得到分裂后的分组 coefficients 和对应的分组索引 partitions。
% 需要注意的是 partitions_old 需要的格式为：partitions_old = cell(1,1);partitions_old{1} = partitions{k};
%-----------------------------------------输出变量说明---------------------------------------------%
% beta_back             一棵二叉树模型返回的行向量取值 [row_size*sample_size] matrix
% gamma_back            一颗二叉树模型返回的列向量取值 [col_size*sample_size] matrix
% coefficients          一棵二叉树模型返回的两个模型分别的回归系数值 [(row_size+col_size)*2] matrix
% partitions            一棵二叉树模型返回的两个模型的分组索引（相对于原始的x、y的分组索引）[2*1] cell
% combine               一棵二叉树模型返回的两个模型对应的样本数量 [2*1] matrix
%-----------------------------------------输入变量说明---------------------------------------------%
% num_partitions        将数据分成几份 默认取2
% eps_initial           每次进行同质模型回归时，每个模型收敛的精度
% iter_max_initial_in   每次进行同质模型回归时，交替优化的最大步数上限
% eps_out               第 n 次与第 n-1 次样本重新划分后模型的系数差精度，收敛精度
% iter_max_initial_out  样本重新划分的最大次数上限
% sample_size           样本量
% row_size              行向量维数
% col_size              列向量维数
% x                     一次模拟中的解释变量[row_size*col_size*sample_size]
% y                     一次模拟中的响应变量[sample_size*1]
% random_number         随机种子数，确保结果可重现
% beta0                 每次同质模型计算时关于beta的初值
% gamma0                每次同质模型计算时关于gamma的初值
% combine_principle     c*sample_size; 最小元素个数组合并准则
% sample_size_sum       总的样本数
% partitions_old        待分裂的索引值

count = 1;
random_number_change = random_number;
if_two = 0;

while (if_two~=1)
num_partitions = 2;
rng(random_number_change);
sample_size = length(partitions_old{1});
index = randperm(sample_size);
partition_lengths = [floor(sample_size / num_partitions) * ones(1, num_partitions - 1), sample_size - floor(sample_size / num_partitions) * (num_partitions - 1)];
partitions = cell(num_partitions,1);
%计算分组后的索引
start_idx = 1;
for i = 1:num_partitions
    end_idx = start_idx + partition_lengths(i) - 1;
    partitions{i} = partitions_old{1}(index(start_idx:end_idx));
    start_idx = end_idx + 1;
end
for i = 1:num_partitions
    partitions{i} = sort(partitions{i});
end
partitions0 = partitions;
coefficients = zeros((row_size+col_size),num_partitions);%系数存储矩阵
residuals = zeros(sample_size,num_partitions);%残差存储矩阵
beta_back = zeros(sample_size_sum*row_size,1);%返回初值结果
gamma_back = zeros(sample_size_sum*col_size,1);%返回初值结果
beta_back0 = zeros(sample_size_sum*row_size,1);%返回初值结果
gamma_back0 = zeros(sample_size_sum*col_size,1);%返回初值结果
residual_coefficients = 1;
%初始值随机化机制
coefficients0 = [beta0;gamma0];%每次重新分配样本后回归时使用的初值，不使用warm start
iter_initial_out = 0;
while(residual_coefficients > eps_out&&iter_initial_out<=iter_max_initial_out)
    for i = 1:num_partitions
        iter_initial_in = 0;
        n_part = length(partitions{i});
        if n_part < (0.05*sample_size_sum)
            continue;
        end
        x_part = x(:,:,partitions{i});
        y_part = y(partitions{i});
        [beta_part, gamma_part, ~, ~, ~] = logit_matrix_ridge_regression_mex(x_part, y_part, n_part,...
            row_size, col_size, cv_number , coefficients0, tuning_start, tuning_end, tuning_number, eps_initial, iter_max_initial_in, if_fix);
        coefficients((1:row_size),i) = beta_part;%系数存储矩阵
        coefficients(((row_size+1):end),i) = gamma_part;%系数存储矩阵
        for k = 1:sample_size
            residuals(k,i) = -(y(partitions_old{1}(k))*(beta_part'*(x(:,:,partitions_old{1}(k)))*gamma_part)-...
                log(1+exp((beta_part'*(x(:,:,partitions_old{1}(k)))*gamma_part))));
        end
    end 
    partitions = cell(num_partitions,1);
    for i = 1:num_partitions
        partitions{i,1} = 0;
    end
    [~, min_col_indices] = min(residuals, [], 2);
    for k = 1:sample_size
        for j = 1:num_partitions
            if min_col_indices(k)==j
                partitions{j} = [partitions{j},partitions_old{1}(k)];
            end
        end
    end
    
    for j = 1:num_partitions
        partitions{j} = partitions{j}(2:end);
    end
    
    combine = zeros(num_partitions,1);
    for j = 1:num_partitions
        combine(j,1) = length(partitions{j});
    end
    combine_index = min(combine);
    combine_min_index = find(combine==min(combine));

    %合并机制
    while (combine_index < combine_principle)
    num_partitions = num_partitions - length(combine_min_index);
    residuals(:,combine_min_index) = [];
    coefficients(:,combine_min_index) = [];
    %重复上面的操作
    partitions = cell(num_partitions,1);
    [~, min_col_indices] = min(residuals, [], 2);
    for k = 1:sample_size
       for j = 1:num_partitions
           if min_col_indices(k)==j
               partitions{j} = [partitions{j},partitions_old{1}(k)];
           end
       end
    end
    combine = zeros(num_partitions,1);
    for j = 1:num_partitions
       combine(j,1) = length(partitions{j});
    end
    combine_index = min(combine);
    combine_min_index = find(combine==min(combine));
    end
    iter_initial_out = iter_initial_out + 1;
    for j = 1:num_partitions
        for k = 1:length(partitions{j})
            beta_back((((partitions{j}(k)-1)*row_size)+1):(partitions{j}(k)*row_size),:) = coefficients((1:row_size),j);
            gamma_back((((partitions{j}(k)-1)*col_size)+1):(partitions{j}(k)*col_size),:) = coefficients(((row_size+1):(row_size+col_size)),j);
        end
    end
    residual_coefficients = norm([beta_back;gamma_back]-[beta_back0;gamma_back0]);
    beta_back0 = beta_back;%返回初值结果
    gamma_back0 = gamma_back;%返回初值结果
    if isnan(max(residual_coefficients)) 
        break;
    end
end
            if_two = (max(size(partitions))==2);
            random_number_change = random_number_change + count;
            if abs(random_number - random_number_change) > 10
                num_partitions = 2;
                rng(random_number_change);
                sample_size = length(partitions_old{1});
                index = randperm(sample_size);
                partition_lengths = [floor(sample_size / num_partitions) * ones(1, num_partitions - 1), sample_size - floor(sample_size / num_partitions) * (num_partitions - 1)];
                partitions = cell(num_partitions,1);
                %计算分组后的索引
                start_idx = 1;
                for i = 1:num_partitions
                    end_idx = start_idx + partition_lengths(i) - 1;
                    partitions{i} = partitions_old{1}(index(start_idx:end_idx));
                    start_idx = end_idx + 1;
                end
                for i = 1:num_partitions
                    partitions{i} = sort(partitions{i});
                end
                partitions0 = partitions;
                coefficients = zeros((row_size+col_size),num_partitions);%系数存储矩阵
                residuals = zeros(sample_size,num_partitions);%残差存储矩阵
                beta_back = zeros(sample_size_sum*row_size,1);%返回初值结果
                gamma_back = zeros(sample_size_sum*col_size,1);%返回初值结果
                beta_back0 = zeros(sample_size_sum*row_size,1);%返回初值结果
                gamma_back0 = zeros(sample_size_sum*col_size,1);%返回初值结果
                residual_coefficients = 1;
                %初始值随机化机制
                coefficients0 = [beta0;gamma0];%每次重新分配样本后回归时使用的初值，不使用warm start
                iter_initial_out = 0;
                for i = 1:num_partitions
                    iter_initial_in = 0;
                    n_part = length(partitions{i});
                    if n_part < (0.05*sample_size_sum)
                        continue;
                    end
                    x_part = x(:,:,partitions{i});
                    y_part = y(partitions{i});
                    [beta_part, gamma_part, ~, ~, ~] = logit_matrix_ridge_regression_mex(x_part, y_part, n_part,...
                        row_size, col_size, cv_number, coefficients0, tuning_start, tuning_end, tuning_number, eps_initial, iter_max_initial_in, if_fix);
                    coefficients((1:row_size),i) = beta_part;%系数存储矩阵
                    coefficients(((row_size+1):end),i) = gamma_part;%系数存储矩阵
                    for k = 1:sample_size
                        residuals(k,i) = -(y(partitions_old{1}(k))*(beta_part'*(x(:,:,partitions_old{1}(k)))*gamma_part)-log(1+exp((beta_part'*(x(:,:,partitions_old{1}(k)))*gamma_part))));
                    end
                end
                if_two =1;
            end
            combine = zeros(num_partitions,1);
            for j = 1:num_partitions
                combine(j,1) = length(partitions{j});
            end
end
end






