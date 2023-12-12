function [num_partitions_best,combine_principle_best,split_principle_best,random_number_best,cv_matrix] = k_means_regression_cv_logit(num_partitions_list,eps_initial,eps_out,iter_max_initial_in,...
                                                iter_max_initial_out,combine_principle_list,split_principle_list,random_number_list,sample_size,row_size,col_size,x,y,disp_if,cv_number,tuning_start,tuning_end,tuning_number,if_fix)
%-------------------------------------------函数功能-----------------------------------------------%
% （残差迭代模型的交叉验证模型）选取最优参数
%-----------------------------------------输出变量说明---------------------------------------------%
% num_partitions_best      交叉验证得到的最优份数
% combine_principle_best   交叉验证得到的最优合并准则数
% split_principle_best     交叉验证得到的最优分裂准则数
% random_number_best       交叉验证得到的最优随机种子数
% cv_matrix                交叉验证得到的对应参数的误差张量
%-----------------------------------------输入变量说明---------------------------------------------%
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
cv_matrix = inf*ones(length(num_partitions_list),length(combine_principle_list),length(split_principle_list),length(random_number_list));
for kk = 1:length(random_number_list)
    for ii = 1:length(num_partitions_list)
        for jj = 1:length(combine_principle_list)
            for qq = 1:length(split_principle_list)
                random_number = random_number_list(kk);
                num_partitions = num_partitions_list(ii);
                combine_principle = combine_principle_list(jj);
                split_principle = split_principle_list(qq);
                [beta_back,gamma_back,coefficients,...
                    partitions,combine,residual_coefficients] = k_means_regression_logit(num_partitions,eps_initial,eps_out,iter_max_initial_in,...
                    iter_max_initial_out,combine_principle,split_principle,sample_size,row_size,col_size,x,y,random_number,...
                    cv_number,tuning_start,tuning_end,tuning_number,if_fix);
            end
                try
                    cv_matrix(ii,jj,qq,kk) = 0;
                    for k = 1:sample_size
                        cv_matrix(ii,jj,qq,kk) = cv_matrix(ii,jj,qq,kk) + (y(k)*((beta_back(((k-1)*row_size+1):(k*row_size),1)')*x(:,:,k)*gamma_back(((k-1)*col_size+1):(k*col_size),1)) -...
                                                 log(1 + exp(((beta_back(((k-1)*row_size+1):(k*row_size),1)')*x(:,:,k)*gamma_back(((k-1)*col_size+1):(k*col_size),1)))));
                    end
                    cv_matrix(ii,jj,qq,kk) = -2*log(exp(cv_matrix(ii,jj,qq,kk)))+ 2.4*log(log(sample_size*(row_size+col_size)))*((log(sample_size)/sample_size)*(col_size+row_size)*length(partitions));
                catch
                    cv_matrix(ii,jj,qq,kk) = inf;
                    continue;
                end
        end
    end
    if disp_if >0
        fprintf('Initial value solving process completed %.1f%%\n',(100*kk/length(random_number_list)))
    end
end
[minValue, linearIndex] = min(cv_matrix(:));
% 计算最小值所在的位置索引（行、列、层）
[row, col, layer, layer2] = ind2sub(size(cv_matrix), linearIndex);
num_partitions_best = num_partitions_list(row);
combine_principle_best = combine_principle_list(col);
split_principle_best = split_principle_list(layer);
random_number_best = random_number_list(layer2);
end






