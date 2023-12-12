function [DATA_struct,data,DATA_opt,data_opt] = admm_lambda_logit(ifauto,lambda_size,lambda_start_point,change_constant,log_change_constant,beta0,gamma0,sample_size,row_size,col_size,iter_max1,iter_max1_interval,iter_max2,iter_max2_interval,iter_max3,iter_max3_interval,...
                                                                  eps1,eps1_interval,eps2,eps2_interval,eps3,eps3_interval,H_p,H_q,X,y,k,a,lambda_left,lambda_right,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,yita_vec,...
                                                                  store_beta,store_gamma,beta_real,gamma_real,min_class_num,one_beta,one_gamma,HH_p,HH_q,E)
%-------------------------------------------函数功能-----------------------------------------------%
% 使用interval_lambda、admm4_mex求解一次模拟中最优lambda对应的估计信息
%----------------------------------------需要的前置函数---------------------------------------------%
% MATLAB Function:      admm3、admm4、interval_lambda
% C++ Function:         admm4_mex
%-----------------------------------------输出变量说明---------------------------------------------%
% DATA_struct      　　　一次模拟中每个lambda对应的详细估计信息
% data                  一次模拟中每个lambda对应的简略估计信息
% DATA_opt              一次模拟中最优lambda对应的详细估计信息
% data_opt              一次模拟中最优lambda对应的简略估计信息
%-----------------------------------------输入变量说明---------------------------------------------%
% ifauto                是否使用interval_lambda自动搜索lambda,1为使用，0为不使用
% lambda_left           手动输入lambda区间左端点
% lambda_right          手动输入lambda区间右端点
% lambda_start_point    lambda搜索起始点
% change_constant       lambda因子变动系数
% log_change_constant   lambda区间对数变换系数
% sample_size           样本量
% row_size              行向量维数
% col_size              列向量维数
% iter_max1_interval    区间搜索时内部最小二乘迭代的最大步数
% iter_max2_interval    区间搜索时外部坐标下降的最大轮数
% iter_max3_interval    区间搜索时ADMM最大交替迭代步数
% eps1_interval         区间搜索时内部最小二乘迭代时两步系数差的二范数的容差
% eps2_interval         区间搜索时外部坐标下降时两轮系数差的二范数的容差
% eps3_interval         区间搜索时ADMM原始残差二范数的容差
% beta0                 初值beta0
% gamma0                初值gamma0
% H_p                   H_p维度为（组合数*p）*(样本数*p) matrix
% H_q                   H_q维度为（组合数*q）*(样本数*q) matrix
% X                     解释变量数据 （样本数*p）*(样本数*q) matrix
% y                     连续相应变量 （样本数*1）matrix
% a                     MCP惩罚函数里的控制凹凸性的参数
% k                     ADMM算法的惩罚参数
% v                     beta组合差信息储存矩阵（对偶变量）
% w                     gamma组合差信息储存矩阵（对偶变量）
% c                     BIC准则第二部分的权重参数
% kesai　　　　　　　　　关于beta的增广lagrange乘子
% yita                  关于gamma的增广lagrange乘子
% v_vec                 beta组合差信息储存矩阵（对偶变量）按组合顺序拉成向量
% w_vec                 gamma组合差信息储存矩阵（对偶变量）按组合顺序拉成向量
% kesai_vec             beta的增广lagrange乘子按组合顺序拉成向量
% yita_vec              gamma的增广lagrange乘子按组合顺序拉成向量
% store_beta            内部最小二乘迭代时更新beta时用到的信息
% store_gamma           内部最小二乘迭代时更新gamma时用到的信息
% beta_real             真实的beta
% gamma_real            真实的gamma
% one_beta              kron(eye(sample_size),one_vec_row')
% one_gamma             kron(eye(sample_size),one_vec_col')
% HH_p                  H_p'*H_p
% HH_q                  H_q'*H_q
% min_class_num         lambda右端点对应的可接受的最小亚组数

%----------------------------------------是否选择使用自动搜索lambda区间-------------------------------------------%   
if log_change_constant == '~'
   log_change_constant = 1;
end
if ifauto == 1
    
    [lambda_left_back,lambda_right_back] = interval_lambda_logit(lambda_start_point,change_constant,sample_size,row_size,col_size,iter_max1_interval,iter_max2_interval,iter_max3_interval,...
                                                               eps1_interval,eps2_interval,eps3_interval,beta0,gamma0,H_p,H_q,X,y,k,a,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                               yita_vec,store_beta,store_gamma,beta_real,gamma_real,min_class_num,one_beta,one_gamma,HH_p,HH_q,E);
    Lambda = lambda_right_back*log(linspace(exp(lambda_left_back/lambda_right_back),exp(1),lambda_size));
    Lambda = linspace(lambda_left_back,lambda_right_back,lambda_size);
else
    lambda_left_back = lambda_left;
    lambda_right_back = lambda_right;
    Lambda = lambda_right_back*log(linspace(exp(lambda_left_back/lambda_right_back),exp(1),lambda_size));
    Lambda = linspace(lambda_left_back,lambda_right_back,lambda_size);
end
disp("lambda区间搜索完成")
%----------------------------------------设置结构体储存每个lambda对应的结果----------------------------------------%
DATA = struct;
DATA(lambda_size).lambda = [];DATA(lambda_size).beta= [];DATA(lambda_size).gamma= [];DATA(lambda_size).class= [];DATA(lambda_size).index= [];
DATA(lambda_size).subgroup_number = [];DATA(lambda_size).convergence = [];DATA(lambda_size).BIC= [];DATA(lambda_size).iter = [];
DATA(lambda_size).per_if = [];DATA(lambda_size).mse_beta = [];DATA(lambda_size).mse_gamma = [];DATA(lambda_size).sc = [];DATA(lambda_size).Data = [];
for i = 1:length(Lambda)
[beta_back,gamma_back,class_back,index_back,subgroup_number,...
               per_if,mse_beta,mse_gamma,sc,BIC_back,BIC_part2_back,wucha_back,convergence,iter_back,Data] = admm4_logit_mex(sample_size,row_size,col_size,iter_max1,iter_max2,iter_max3,eps1,eps2,eps3,...
                                                                               beta0,gamma0,H_p,H_q,X,y,k,a,Lambda(i),c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                                               yita_vec,store_beta,store_gamma,beta_real,gamma_real,one_beta,one_gamma,HH_p,HH_q,E);
                                                                           
DATA(i).lambda = Lambda;
DATA(i).beta= beta_back;
DATA(i).gamma = gamma_back;
DATA(i).class= class_back;
DATA(i).index= index_back;
DATA(i).subgroup_number = subgroup_number;
DATA(i).per_if = per_if;
DATA(i).mse_beta = mse_beta;
DATA(i).mse_gamma = mse_gamma;
DATA(i).sc = sc;
DATA(i).convergence = convergence;
DATA(i).iter = iter_back;
DATA(i).BIC= BIC_back;
DATA(i).Data = Data;
DATA(i).wucha = wucha_back;
DATA(i).BIC_part2 = BIC_part2_back;
fprintf('已完成一次模拟中 %.1f%% 的融合惩罚\n',(100*i/lambda_size))
end
%------------------------------------每次模拟的详细信息在DATA_struct中--------------------------------%
DATA_struct = DATA;
%------------------------------------每次模拟的简略信息在data中---------------------------------------%
lambda = [DATA_struct(1).lambda];
BIC = [DATA_struct.BIC];
wucha = [DATA_struct.wucha];
BIC_part2 = [DATA_struct.BIC_part2];
mse_beta = [DATA_struct.mse_beta];
mse_gamma = [DATA_struct.mse_gamma];
subgroup_number = [DATA_struct.subgroup_number];
per_if =[DATA_struct.per_if];
sc = [DATA_struct.sc];
convergence =[DATA_struct.convergence];
iter = [DATA_struct.iter];
data = [lambda',BIC',wucha',BIC_part2',mse_beta',mse_gamma',subgroup_number',per_if',sc',convergence',iter'];
data = array2table(data, 'VariableNames', {'lambda','BIC','wucha','BIC_part2','mse_beta','mse_gamma','subgroup_number','per_if','sc','convergence','iter'});
DATA_opt = DATA_struct(min(find(BIC == min(BIC))));
lambda_opt = [DATA_opt.lambda(min(find(BIC == min(BIC))))];
BIC_opt = [DATA_opt.BIC];
wucha_opt = [DATA_opt.wucha];
BIC_part2_opt = [DATA_opt.BIC_part2];
mse_beta_opt = [DATA_opt.mse_beta];
mse_gamma_opt = [DATA_opt.mse_gamma];
subgroup_number_opt = [DATA_opt.subgroup_number];
per_if_opt =[DATA_opt.per_if];
sc_opt = [DATA_opt.sc];
convergence_opt =[DATA_opt.convergence];
iter_opt = [DATA_opt.iter];

data_opt = [lambda_opt,BIC_opt,wucha_opt,BIC_part2_opt,mse_beta_opt,mse_gamma_opt,...
            subgroup_number_opt,per_if_opt,sc_opt,convergence_opt,iter_opt];
data_opt = array2table(data_opt, 'VariableNames', {'lambda','BIC','wucha','BIC_part2','mse_beta','mse_gamma','subgroup_number','per_if','sc','convergence','iter'});
end