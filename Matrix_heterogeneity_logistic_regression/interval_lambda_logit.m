function [lambda_left_back,lambda_right_back] = interval_lambda_logit(lambda_start_point,change_constant,sample_size,row_size,col_size,iter_max1_interval,iter_max2_interval,iter_max3_interval,...
                                                      eps1_interval,eps2_interval,eps3_interval,beta0,gamma0,H_p,H_q,X,y,k,a,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                      yita_vec,store_beta,store_gamma,beta_real,gamma_real,min_class_num,one_beta,one_gamma,HH_p,HH_q,E)
%-------------------------------------------函数功能-----------------------------------------------%
% 使用admm4_mex求解正则化路径的lambda左右端点
%----------------------------------------需要的前置函数---------------------------------------------%
% MATLAB Function:      admm3、admm4
% C++ Function:         admm4_mex
%-----------------------------------------输出变量说明---------------------------------------------%
% lambda_left_back      惩罚因子区间左端点 double
% lambda_right_back     惩罚因子区间右端点 double
%-----------------------------------------输入变量说明---------------------------------------------%
% lambda_start_point    lambda搜索起始点
% change_constant       lambda因子变动系数
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
lambda_left = lambda_start_point;
lambda_right = lambda_start_point;
iter_max1 = iter_max1_interval;
iter_max2 = iter_max2_interval;
iter_max3 = iter_max3_interval;
eps1 = eps1_interval;
eps2 = eps2_interval;
eps3 = eps3_interval;
[~,~,~,~,subgroup_number_start,~,~,~,~,~,~,~,~,~,~] = admm4_logit_mex(sample_size,row_size,col_size,iter_max1,iter_max2,iter_max3,eps1,eps2,eps3,...
                                                                               beta0,gamma0,H_p,H_q,X,y,k,a,lambda_start_point,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                                               yita_vec,store_beta,store_gamma,beta_real,gamma_real,one_beta,one_gamma,HH_p,HH_q,E);
subgroup_number_left = subgroup_number_start;
subgroup_number_right = subgroup_number_start;
while subgroup_number_left==sample_size
    lambda_left = lambda_left/change_constant;
    [~,~,~,~,subgroup_number_left,~,~,~,~,~,~,~,convergence,iter_back,DATA] = admm4_logit_mex(sample_size,row_size,col_size,iter_max1,iter_max2,iter_max3,eps1,eps2,eps3,...
                                                                               beta0,gamma0,H_p,H_q,X,y,k,a,lambda_left,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                                               yita_vec,store_beta,store_gamma,beta_real,gamma_real,one_beta,one_gamma,HH_p,HH_q,E);
end
lambda_left = lambda_left*change_constant;
while subgroup_number_right == 1
    lambda_right = lambda_right*change_constant;
    [~,~,~,~,subgroup_number_right,~,~,~,~,~,~,~,~,~,~] = admm4_logit_mex(sample_size,row_size,col_size,iter_max1,iter_max2,iter_max3,eps1,eps2,eps3,...
                                                                               beta0,gamma0,H_p,H_q,X,y,k,a,lambda_right,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                                               yita_vec,store_beta,store_gamma,beta_real,gamma_real,one_beta,one_gamma,HH_p,HH_q,E);
end
lambda_right = lambda_right/change_constant;    

while subgroup_number_left < (sample_size*0.2) 
lambda_left = lambda_left*change_constant;
[~,~,~,~,subgroup_number_left,~,~,~,~,~,~,~,~,~,~] = admm4_logit_mex(sample_size,row_size,col_size,iter_max1,iter_max2,iter_max3,eps1,eps2,eps3,...
                                                                               beta0,gamma0,H_p,H_q,X,y,k,a,lambda_left,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                                               yita_vec,store_beta,store_gamma,beta_real,gamma_real,one_beta,one_gamma,HH_p,HH_q,E);
end
while subgroup_number_right > min_class_num
lambda_right = lambda_right/change_constant;
[~,~,~,~,subgroup_number_right,~,~,~,~,~,~,~,~,~,~] = admm4_logit_mex(sample_size,row_size,col_size,iter_max1,iter_max2,iter_max3,eps1,eps2,eps3,...
                                                                               beta0,gamma0,H_p,H_q,X,y,k,a,lambda_right,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                                               yita_vec,store_beta,store_gamma,beta_real,gamma_real,one_beta,one_gamma,HH_p,HH_q,E);
end
lambda_left_back = lambda_left;
lambda_right_back = lambda_right;
end
