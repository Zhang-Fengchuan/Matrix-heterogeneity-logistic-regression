%% Matrix_heterogenous_regression_logit里面
num_partitions_list = 6:8;%默认初值搜索分割组数区间4:8
eps_initial = 1e-3;%默认对数似然函数收敛条件1e-3
eps_out = 1e-3;%默认初值算法收敛条件1e-3
iter_max_initial_in = 200;%默认迭代最大步数10
iter_max_initial_out = 200;%默认迭代最大步数10
combine_principle_list = linspace(0.2, 0.4, 3)*sample_size;%默认合并机制阈值0.3*sample_size
split_principle_list = linspace(0.6, 0.6, 1)*sample_size;%默认分裂机制阈值0.6*sample_size
random_number_list = 1:25;%默认随机种子数列表1:100
ifauto = 1;%默认采取自动搜索区间 1
lambda_size = 25;%默认lambda因子个数 50
lambda_start_point = 0.3;%lambda因子搜索初始点为0.3
change_constant = 0.9;%lambda因子区间搜索变动系数为0.5
log_change_constant = 1;%lambda因子区间log-exp变换系数
iter_max1 = 50;%默认内部最小二乘迭代的最大步数为50
iter_max1_interval = 50;%默认区间搜索时内部最小二乘迭代的最大步数为50
iter_max2 = 50;%默认外部坐标下降的最大轮数为50
iter_max2_interval = 50;%默认区间搜索时外部坐标下降的最大轮数为50
iter_max3 = 50;%默认ADMM最大交替迭代步数为50
iter_max3_interval = 50;%默认区间搜索时ADMM最大交替迭代步数为50
eps1 = 1e-3;%默认内部最小二乘迭代时两步系数差的二范数的容差为1e-4
eps1_interval = 1e-3;%默认区间搜索时内部最小二乘迭代时两步系数差的二范数的容差为1e-4
eps2 = 1e-3;%默认外部坐标下降时两轮系数差的二范数的容差为1e-4
eps2_interval = 1e-3;%默认区间搜索时外部坐标下降时两轮系数差的二范数的容差为1e-4
eps3 = 5e-3;%默认ADMM原始残差二范数的容差为1e-3
eps3_interval = 5e-3;%默认区间搜索时ADMM原始残差二范数的容差为1e-3
beta_real = zeros(sample_size*row_size,1);%预测时不输入beta_real时默认的beta_real
gamma_real = zeros(sample_size*col_size,1);%预测时不输入gamma_real时默认的gamma_real
k = 10;%默认ADMM算法的惩罚参数为10
a = 3;%默认ADMM算法的惩罚参数为3
lambda_left = 0.005;%手动设置lambda左初始点0.005
lambda_right = 3;%手动设置lambda右初始点0.6
c = 5; %默认BIC准则第二部分的权重参数为5
min_class_num = 2;%默认lambda右端点对应的可接受的最小亚组数为2
cv_number = 3;%初值算法求解时最内层同质回归时岭回归选lambda的交叉验证折数
tuning_number = 3;%初值算法求解时最内层同质回归时岭回归交叉验证选lambda的备选个数
tuning_start = 0.1;%初值算法求解时最内层同质回归时岭回归交叉验证选lambda的最小lambda值
tuning_end = 5;%初值算法求解时最内层同质回归时岭回归交叉验证选lambda的最大lambda值
if_fix = 1;%初值算法求解时最内层同质回归时岭回归是否选用固定lambda值
disp_if = 1;%默认不显示过程信息
initial_if = 0; %1:不重新计算初值 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
local_i=1;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%第1次模拟
%% Matrix_heterogenous_regression_logit里面
if initial_if == 0
    y = y_real(:,local_i);%将第yangbencishu次模拟中心化后的y抽出来记为y
    x = Data_x(:,:,:,local_i);%将第yangbencishu次模拟的矩阵变量抽出来记为x（维度为p*q*n）
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
%% Matrix_heterogenous_regression_logit里面
y = y_real(:,local_i);%将第1次模拟中心化后的y抽出来记为y
x = Data_x(:,:,:,local_i);%将第1次模拟的矩阵变量抽出来记为x(维度为p*q*n)
beta = beta0;
gamma = gamma0;
%for i = 1:sample_size %按照可识别性条件对参数进行处理
%    identify = sign(gamma(((i-1)*col_size+1)))/sqrt(sum(gamma(((i-1)*col_size+1):(i*col_size)).^2));
%    beta(((i-1)*row_size+1):(i*row_size)) = beta(((i-1)*row_size+1):(i*row_size))/identify;
%    gamma(((i-1)*col_size+1):(i*col_size)) = gamma(((i-1)*col_size+1):(i*col_size))*identify;
%end
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
%% admm_lambda 区间模块
lambda_left_back = lambda_left;
lambda_right_back = lambda_right;
Lambda = linspace(lambda_left_back,lambda_right_back,lambda_size);%均分打开这一句
lambda = Lambda(20);
DATA = struct;
DATA(lambda_size).lambda = [];DATA(lambda_size).beta= [];DATA(lambda_size).gamma= [];DATA(lambda_size).class= [];DATA(lambda_size).index= [];
DATA(lambda_size).subgroup_number = [];DATA(lambda_size).convergence = [];DATA(lambda_size).BIC= [];DATA(lambda_size).iter = [];
DATA(lambda_size).per_if = [];DATA(lambda_size).mse_beta = [];DATA(lambda_size).mse_gamma = [];DATA(lambda_size).sc = [];DATA(lambda_size).Data = [];
%% admm4里面
beta = beta0;
gamma = gamma0;
iter = 0;
residual_primal = 1;
%f2 = 0;
v_vec_bar = zeros(sample_size*(sample_size-1)*0.5*row_size,1);
w_vec_bar = zeros(sample_size*(sample_size-1)*0.5*col_size,1);
per_if = 0;
sc_hat_store = zeros(sample_size,sample_size);
sc_real_store = zeros(sample_size,sample_size);
sc_store = zeros(sample_size,sample_size);
max_time = 60; % 设置最大执行时间为 60 秒
start_time = tic; % 开始计时
%% admm3 里面
pai_gamma = zeros(row_size*col_size);
for i = 1:(row_size*col_size)
    if mod(i,row_size)~=0
        pai_gamma(((floor(i/row_size)+1)+(mod(i,row_size)-1)*col_size),i) = 1;
    else
        pai_gamma((floor(i/row_size)+(mod((i-1),row_size))*col_size),i) = 1;
    end
end
pai_gamma = pai_gamma';
store_beta = zeros(row_size,sample_size);%%%%%%%%%%%%%%%
store_gamma = zeros(col_size,sample_size);%%%%%%%%%%%%%%%%%
for i = 1:sample_size
   if i==1
      for j = 2:sample_size
          store_beta(:,i) = store_beta(:,i)+(squeeze(v(i,j,:)-kesai(i,j,:)/k));
          store_gamma(:,i) = store_gamma(:,i)+(squeeze(w(i,j,:)-yita(i,j,:)/k));
      end
   elseif i==sample_size
       for j = 1:(sample_size-1)
           store_beta(:,i) = store_beta(:,i)+(squeeze((kesai(j,i,:)/k)-v(j,i,:)));
           store_gamma(:,i) = store_gamma(:,i)+(squeeze((yita(j,i,:)/k)-w(j,i,:)));
       end
   else
       for j = 1:(i-1)
       store_beta(:,i) = store_beta(:,i)+(squeeze((kesai(j,i,:)/k)-v(j,i,:)));
       store_gamma(:,i) = store_gamma(:,i)+(squeeze((yita(j,i,:)/k)-w(j,i,:)));
       end
       for j = (i+1):sample_size
           store_beta(:,i) = store_beta(:,i)+(squeeze(v(i,j,:)-kesai(i,j,:)/k));
           store_gamma(:,i) = store_gamma(:,i)+(squeeze(w(i,j,:)-yita(i,j,:)/k));
       end
   end  
end
beta_re = reshape(beta,row_size,sample_size);
gamma_re = reshape(gamma,col_size,sample_size);
iter_2 = 0;
coef_diff_sum = 1;
beta_re_old = beta_re;
gamma_re_old = gamma_re;
i=1; 
iter_1 = 0;
coef_diff_1 = 1;
e_i = ones(sample_size,1);
e_i(i) = 0;
beta_single_old = beta_re(:,i);
gamma_single_old = gamma_re(:,i);

C2 = zeros(row_size,1);
C1 = zeros(col_size,1);
M2 = zeros(row_size,row_size);
M1 = zeros(col_size,col_size);

%% MATLAB代码admm4_logit运行时间
tic
admm4_logit(sample_size,row_size,col_size,iter_max1,iter_max2,iter_max3,eps1,eps2,eps3,...
                                                                           beta0,gamma0,H_p,H_q,X,y,k,a,lambda,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                                           yita_vec,store_beta,store_gamma,beta_real,gamma_real,one_beta,one_gamma,HH_p,HH_q,E);
toc
%% C++代码admm4_logit运行时间
tic
admm4_logit_mex(sample_size,row_size,col_size,iter_max1,iter_max2,iter_max3,eps1,eps2,eps3,...
                                                                               beta0,gamma0,H_p,H_q,X,y,k,a,lambda_start_point,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                                               yita_vec,store_beta,store_gamma,beta_real,gamma_real,one_beta,one_gamma,HH_p,HH_q,E);
toc



















