function [Results,results,Results_opt,results_opt,...
    initial,Results_list_opt,Results_single_opt] = Matrix_heterogeneous_regression_logit(simulation_size,Data_x,y_real,sample_size,row_size,col_size,beta_real,gamma_real,...
    num_partitions_list,eps_initial,eps_out,iter_max_initial_in,iter_max_initial_out,combine_principle_list,split_principle_list,...
    random_number_list,...
    ifauto,lambda_size,lambda_start_point,change_constant,log_change_constant,iter_max1,iter_max1_interval,...
    iter_max2,iter_max2_interval,iter_max3,iter_max3_interval,eps1,eps1_interval,eps2,eps2_interval,eps3,eps3_interval,...
    k,a,lambda_left,lambda_right,c,min_class_num,cv_number,tuning_start,tuning_end,tuning_number,if_fix,...
    disp_if,initial_if,initial_position)

%
%-----------------------------------输出参数------------------------------------------%
% Results:                  每次模拟的DATA(每个lambda的详细信息)
% results:                  每次模拟的data(每个lambda的简略信息)
% Results_opt:              每次模拟的DATA_opt(最优lambda对应的详细信息)
% results_opt:              每次模拟的data_opt(最优lambda对应的简略信息)
% Results_list_opt:         每次模拟的最优lambda对应的简略信息拼成的table
% Results_single_opt:       综合每次模拟最优lambda对应的评价信息获得的table
% initial:                  每次模拟初值搜索算法的信息
%----------------------------------使用方法-------------------------------------------%
%模拟时必须输入的参数有simulation_size、Data_x、y_real、sample_size、row_size、col_size、beta_real、gamma_real

%[Results,results,Results_opt,results_opt,...
% initial,Results_list_opt,Results_single_opt] = Matrix_heterogeneous_regression_logit(simulation_size,Data_x,y_real,sample_size,...
%                                                                              row_size,col_size,beta_real,gamma_real,...
%                                                                              [],[],[],[],[],[],[],[],[],[],[],[],[],[],...
%                                                                              [],[],[],[],[],[],[],[],[],[],[],[],[],[],...
%                                                                              [],[],[],[],[],[],[],[],[],[],[])

%实际数据时必须输入的参数有simulation_size、Data_x、y_real、sample_size、row_size、col_size

% % % 解决多次模拟和单次模拟的维度不一致
% % if simulation_size == 1
% %     Data_x = reshape(Data_x, [row_size,col_size,sample_size,1]);
% %     y_real = reshape(y_real, [sample_size, 1]);
% % end

if isempty(num_partitions_list)
    num_partitions_list = 6:8;%默认初值搜索分割组数区间4:8
end
if isempty(eps_initial)
    eps_initial = 1e-3;%默认对数似然函数收敛条件1e-3
end
if isempty(eps_out)
    eps_out = 1e-3;%默认初值算法收敛条件1e-3
end
if isempty(iter_max_initial_in)
    iter_max_initial_in = 200;%默认迭代最大步数10
end
if isempty(iter_max_initial_out)
    iter_max_initial_out = 200;%默认迭代最大步数10
end
if isempty(combine_principle_list)
    combine_principle_list = linspace(0.2, 0.4, 3)*sample_size;%默认合并机制阈值0.3*sample_size
end
if isempty(split_principle_list)
    split_principle_list = linspace(0.6, 0.6, 1)*sample_size;%默认分裂机制阈值0.6*sample_size
end
if isempty(random_number_list)
    random_number_list = 1:25;%默认随机种子数列表1:100
end
if isempty(ifauto)
    ifauto = 1;%默认采取自动搜索区间 1
end
if isempty(lambda_size)
    lambda_size = 25;%默认lambda因子个数 50
end
if isempty(lambda_start_point)
    lambda_start_point = 0.3;%lambda因子搜索初始点为0.3
end
if isempty(change_constant)
    change_constant = 0.9;%lambda因子区间搜索变动系数为0.5
end
if isempty(log_change_constant)
    log_change_constant = 1;%lambda因子区间log-exp变换系数
end
if isempty(iter_max1)
    iter_max1 = 50;%默认内部最小二乘迭代的最大步数为50
end
if isempty(iter_max1_interval)
    iter_max1_interval = 50;%默认区间搜索时内部最小二乘迭代的最大步数为50
end
if isempty(iter_max2)
    iter_max2 = 50;%默认外部坐标下降的最大轮数为50
end
if isempty(iter_max2_interval)
    iter_max2_interval = 50;%默认区间搜索时外部坐标下降的最大轮数为50
end
if isempty(iter_max3)
    iter_max3 = 50;%默认ADMM最大交替迭代步数为50
end
if isempty(iter_max3_interval)
    iter_max3_interval = 50;%默认区间搜索时ADMM最大交替迭代步数为50
end
if isempty(eps1)
    eps1 = 1e-3;%默认内部最小二乘迭代时两步系数差的二范数的容差为1e-4
end
if isempty(eps1_interval)
    eps1_interval = 1e-3;%默认区间搜索时内部最小二乘迭代时两步系数差的二范数的容差为1e-4
end
if isempty(eps2)
    eps2 = 1e-3;%默认外部坐标下降时两轮系数差的二范数的容差为1e-4
end
if isempty(eps2_interval)
    eps2_interval = 1e-3;%默认区间搜索时外部坐标下降时两轮系数差的二范数的容差为1e-4
end
if isempty(eps3)
    eps3 = 5e-3;%默认ADMM原始残差二范数的容差为1e-3
end
if isempty(eps3_interval)
    eps3_interval = 5e-3;%默认区间搜索时ADMM原始残差二范数的容差为1e-3
end
if isempty(beta_real)
    beta_real = zeros(sample_size*row_size,1);%预测时不输入beta_real时默认的beta_real
end
if isempty(gamma_real)
    gamma_real = zeros(sample_size*col_size,1);%预测时不输入gamma_real时默认的gamma_real
end
if isempty(k)
    k = 10;%默认ADMM算法的惩罚参数为10
end
if isempty(a)
    a = 3;%默认ADMM算法的惩罚参数为3
end
if isempty(lambda_left)
    lambda_left = 0.005;%手动设置lambda左初始点0.005
end
if isempty(lambda_right)
    lambda_right = 3;%手动设置lambda右初始点0.6
end
if isempty(c)
    c = 5; %默认BIC准则第二部分的权重参数为5
end
if isempty(min_class_num)
    min_class_num = 2;%默认lambda右端点对应的可接受的最小亚组数为2
end
if isempty(cv_number)
    cv_number = 3;%初值算法求解时最内层同质回归时岭回归选lambda的交叉验证折数
end
if isempty(tuning_number)
    tuning_number = 3;%初值算法求解时最内层同质回归时岭回归交叉验证选lambda的备选个数
end
if isempty(tuning_start)
    tuning_start = 0.1;%初值算法求解时最内层同质回归时岭回归交叉验证选lambda的最小lambda值
end
if isempty(tuning_end)
    tuning_end = 5;%5 %初值算法求解时最内层同质回归时岭回归交叉验证选lambda的最大lambda值
end
if isempty(if_fix)
    if_fix = 1;%1 %初值算法求解时最内层同质回归时岭回归是否选用固定lambda值
end
if isempty(disp_if)
    disp_if = 1;%默认不显示过程信息
end
if isempty(initial_if)
    initial_if = 0; %1:不重新计算初值
end
if isempty(initial_position)
    initial_position = 'D:\MATLAB_Document2\ADMM_BCD_new\多方法结果\初值\非平衡设计\mu=1\B2\'; %初值结果存放地址
end
position = strcat(initial_position, '', 'Result_table.mat');
Results = struct;
Results(simulation_size).DATA = [];
results = struct;
results(simulation_size).data = [];
Results_opt = struct;%
Results_opt(simulation_size).DATA = [];
results_opt = struct;%
results_opt(simulation_size).data = [];
Results_list_opt = [];
initial = struct;
initial(simulation_size).beta0 = [];
initial(simulation_size).gamma0 = [];
initial(simulation_size).partitions = [];
initial(simulation_size).result = [];

for local_i = 1:simulation_size
    if initial_if == 0
        y = y_real(:,local_i);%将第yangbencishu次模拟中心化后的y抽出来记为y
        x = Data_x(:,:,:,local_i);%将第yangbencishu次模拟的矩阵变量抽出来记为x(维度为p*q*n)
        [beta0, gamma0, partitions, result] = k_means_regression_initial_logit(num_partitions_list, eps_initial, eps_out,...
            iter_max_initial_in, iter_max_initial_out,...
            combine_principle_list, split_principle_list, random_number_list,...
            sample_size, row_size, col_size, x, y, disp_if,...
            beta_real, gamma_real,cv_number,tuning_start,tuning_end,tuning_number,if_fix);
        initial(local_i).beta0 = beta0;
        initial(local_i).gamma0 = gamma0;
        initial(local_i).partitions = partitions;
        initial(local_i).result = result;
    else
        initial_read = load(position);
        beta0 = cell2mat(initial_read.Result_table.beta_back(local_i));
        gamma0 = cell2mat(initial_read.Result_table.gamma_back(local_i));
        initial(local_i).beta0 = beta0;
        initial(local_i).gamma0 = gamma0;
    end
    %-----------------------------------------------------------------------------------------------------%
    %-----------------------------------------------------------------------------------------------------%
    y = y_real(:,local_i);%将第1次模拟中心化后的y抽出来记为y
    x = Data_x(:,:,:,local_i);%将第1次模拟的矩阵变量抽出来记为x(维度为p*q*n)
    beta = beta0;
    gamma = gamma0;
    v = zeros(sample_size,sample_size,row_size)*nan;
    w = zeros(sample_size,sample_size,col_size)*nan;
    for i = 1:(sample_size-1)
        for j = i+1:sample_size
            v(i,j,:) = beta(((i-1)*row_size+1):(i*row_size)) - beta(((j-1)*row_size+1):(j*row_size));
            w(i,j,:) = gamma(((i-1)*col_size+1):(i*col_size)) - gamma(((j-1)*col_size+1):(j*col_size));
        end
    end
    kesai = zeros(sample_size,sample_size,row_size);
    yita = zeros(sample_size,sample_size,col_size);
    v_vec = zeros(sample_size*(sample_size-1)*0.5*row_size,1);
    w_vec = zeros(sample_size*(sample_size-1)*0.5*col_size,1);
    v_vec_bar = zeros(sample_size*(sample_size-1)*0.5*row_size,1);
    w_vec_bar = zeros(sample_size*(sample_size-1)*0.5*col_size,1);
    u_vec = [v_vec;w_vec];
    u_vec_bar = [v_vec_bar;w_vec_bar];
    %v_vector中关于beta第ij系数差的范围(((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size)
    %w_vector中关于gamma第ij系数差的范围(((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size)
    for i = 1:(sample_size-1)
        for j = (i+1):(sample_size)
            v_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size)) = v(i,j,:);
            w_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size)) = w(i,j,:);
        end
    end
    kesai_vec = zeros((sample_size*(sample_size-1)*0.5*row_size),1);
    yita_vec = zeros((sample_size*(sample_size-1)*0.5*col_size),1);
    for i = 1:(sample_size-1)
        for j = (i+1):sample_size
            kesai_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size)) = kesai(i,j,:);
            yita_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size)) = yita(i,j,:);
        end
    end
    store_beta = zeros(row_size,sample_size);%%%%%%%%%%%%%%%
    store_gamma = zeros(col_size,sample_size);%%%%%%%%%%%%%%%%%
    %E中第((2*sample_size-i)*(i-1)/2)+(j-i))行是1*sample_size关于ij的指示向量
    E = zeros((sample_size*(sample_size-1)*0.5),sample_size);
    for i = 1:(sample_size-1)
        for j = (i+1):sample_size
            e_i = zeros(sample_size,1);
            e_i(i) = 1;
            e_j = zeros(sample_size,1);
            e_j(j) = 1;
            E((((2*sample_size-i)*(i-1)/2)+(j-i)),:) = (e_i - e_j)';
        end
    end
    %H_p维度为（组合数*p）*(样本数*p)
    %H_q维度为（组合数*q）*(样本数*q)
    H_p = kron(E,eye(row_size));
    H_q = kron(E,eye(col_size));
    %将sample_size个x[:,:,sample_size]拼成一个大的对角块矩阵X(np*nq)
    %先按照第三个维度转换成sample_size个元胞
    x_cell = mat2cell(x,row_size,col_size,ones(1,sample_size));
    X = blkdiag(x_cell{:});
    one_vec_sample = ones(sample_size,1);
    one_vec_row = ones(row_size,1);
    one_vec_col = ones(col_size,1);
    one_beta = kron(eye(sample_size),one_vec_row');
    one_gamma = kron(eye(sample_size),one_vec_col');
    D_gamma = one_gamma*diag(gamma);
    D_beta = one_beta*diag(beta);
    HH_p = H_p'*H_p;
    HH_q = H_q'*H_q;
    %-----------------------------------------------------------------------------------------------------%
    %-----------------------------------------------------------------------------------------------------%
    [DATA_struct,data,DATA_opt,data_opt] = admm_lambda_logit(ifauto,lambda_size,lambda_start_point,change_constant,log_change_constant,beta0,gamma0,sample_size,row_size,col_size,iter_max1,iter_max1_interval,...
        iter_max2,iter_max2_interval,iter_max3,iter_max3_interval,eps1,eps1_interval,eps2,eps2_interval,eps3,eps3_interval,...
        H_p,H_q,X,y,k,a,lambda_left,lambda_right,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,yita_vec,...
        store_beta,store_gamma,beta_real,gamma_real,min_class_num,one_beta,one_gamma,HH_p,HH_q,E);
    Results(local_i).DATA = DATA_struct;
    results(local_i).data = data;
    Results_opt(local_i).DATA = DATA_opt;
    results_opt(local_i).data = data_opt;
    fprintf('已完成第%.1f次的融合惩罚\n',local_i)
end
for i = 1:simulation_size
    Results_list_opt = [Results_list_opt;results_opt(i).data];
end
per = sum(Results_list_opt.per_if)/(simulation_size);
K_mean = mean(Results_list_opt.subgroup_number);
K_sd = std(Results_list_opt.subgroup_number);
SC_mean = mean(Results_list_opt.sc);
SC_sd = std(Results_list_opt.sc);
MSE_beta_mean = mean(Results_list_opt.mse_beta);
MSE_beta_sd = std(Results_list_opt.mse_beta);
MSE_gamma_mean = mean(Results_list_opt.mse_gamma);
MSE_gamma_sd = std(Results_list_opt.mse_gamma);
convergence_mean = mean(Results_list_opt.convergence);
convergence_sd = std(Results_list_opt.convergence);
Results_single_opt = [K_mean,K_sd,per,SC_mean,SC_sd,MSE_beta_mean,MSE_beta_sd,MSE_gamma_mean,MSE_gamma_sd,convergence_mean,convergence_sd];
Results_single_opt = array2table(Results_single_opt, 'VariableNames', {'K_mean','K_sd','per','SC_mean','SC_sd','MSE_beta_mean','MSE_beta_sd',...
    'MSE_gamma_mean','MSE_gamma_sd','convergence_mean','convergence_sd'});
save('D:\MATLAB_Document2\ADMM_BCD_new\多方法结果\PROPOSED\非平衡设计\mu=1\B2\RResults.mat','Results','results','Results_opt',...
    'results_opt','Results_list_opt','Results_single_opt')
end

