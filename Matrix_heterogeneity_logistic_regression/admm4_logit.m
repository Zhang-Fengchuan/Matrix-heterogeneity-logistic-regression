function [beta_back,gamma_back,class_back,index_back,subgroup_number,...
               per_if,mse_beta,mse_gamma,sc,BIC_back,BIC_part2_back,wucha_back,convergence,iter_back,Data] = admm4_logit(sample_size,row_size,col_size,iter_max1,iter_max2,iter_max3,eps1,eps2,eps3,...
                                                                           beta0,gamma0,H_p,H_q,X,y,k,a,lambda,c,v,w,kesai,yita,v_vec,w_vec,kesai_vec,...
                                                                           yita_vec,store_beta,store_gamma,beta_real,gamma_real,one_beta,one_gamma,HH_p,HH_q,E)
%-------------------------------------------函数功能-----------------------------------------------%
% 使用ADMM算法求解单个lambda对应的目标函数
%----------------------------------------需要的前置函数---------------------------------------------%
% MATLAB Function:      admm3
%-----------------------------------------输出变量说明---------------------------------------------%
% beta_back             返回估计出的参数beta  [row_size*sample_size] matrix
% gamma_back            返回估计出的参数gamma [col_size*sample_size] matrix
% class_back            返回亚组划分的结果，每一行代表一个组，这一行为这一组的原始索引值
% index_back            返回亚组划分的结果，每一行的第一列代表样本索引，第二列代表组号
% subgroup_number       返回识别的亚族数
% per_if                返回亚组数准确识别标记，若为1则为亚组数识别准确，为0则不准确
% mse_beta              估计出的beta的均方误差
% mse_gamma             估计出的gamma的均方误差
% sc                    估计出的一致性指数
% BIC_back              返回BIC值
% BIC_part2_back        BIC值的第二部分
% wucha_back            BIC值的第一部分
% convergence           第 n 步与第 n-1 步ADMM交替求解的原始残差的二范数（考虑维度平均意义下的差值二范数）
% iter_back             ADMM迭代步数
% Data                  返回的估计详细信息结构体
%-----------------------------------------输入变量说明---------------------------------------------%
% sample_size           样本量
% row_size              行向量维数
% col_size              列向量维数
% iter_max1             内部最小二乘迭代的最大步数
% iter_max2             外部坐标下降的最大轮数
% iter_max3             ADMM最大交替迭代步数
% eps1                  内部最小二乘迭代时两步系数差的二范数的容差
% eps2                  外部坐标下降时两轮系数差的二范数的容差
% eps3                  ADMM原始残差二范数的容差
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
% lambda                惩罚调节参数
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
beta = beta0;
gamma = gamma0;
iter = 0;
residual_primal = 1;
v_vec_bar = zeros(sample_size*(sample_size-1)*0.5*row_size,1);
w_vec_bar = zeros(sample_size*(sample_size-1)*0.5*col_size,1);
per_if = 0;
sc_hat_store = zeros(sample_size,sample_size);
sc_real_store = zeros(sample_size,sample_size);
sc_store = zeros(sample_size,sample_size);
max_time = 60; % 设置最大执行时间为 60 秒
start_time = tic; % 开始计时
while ((residual_primal > eps3)&&(iter<=iter_max3))
%---------------------------------------------------------------------------------------------%
%----------------------------------------ADMM第一步-------------------------------------------%
%---------------------------------------------------------------------------------------------%
[beta,gamma,~] = admm3_logit(sample_size,row_size,col_size,iter_max1,iter_max2,eps1,eps2,beta,gamma,H_p,H_q,X,y,k,v,...
                                              w,kesai,yita,v_vec,w_vec,kesai_vec,yita_vec,store_beta,store_gamma);
%---------------------------------------------------------------------------------------------%
%----------------------------------------ADMM第二步-------------------------------------------%
%---------------------------------------------------------------------------------------------%
for i = 1:(sample_size-1)
    for j = (i+1):sample_size
        v_vec_bar((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size))=...
                                      beta(((i-1)*row_size+1):(i*row_size))-beta(((j-1)*row_size+1):(j*row_size))+...
                                      +kesai_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size))/k;
        w_vec_bar((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size))=...
                                      gamma(((i-1)*col_size+1):(i*col_size))-gamma(((j-1)*col_size+1):(j*col_size))+...
                                      yita_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size))/k;
        u_bar_norm = norm([v_vec_bar((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size));...
                      w_vec_bar((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size))]);
        if u_bar_norm>(a*lambda)
            v_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size))=...
                      v_vec_bar((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size));
            w_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size))=...
                      w_vec_bar((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size));
        else
            v_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size))=...
                (max((1-lambda/(k*u_bar_norm)),0)/(1-1/(a*k)))*v_vec_bar((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size));
            w_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size))=...
                (max((1-lambda/(k*u_bar_norm)),0)/(1-1/(a*k)))*w_vec_bar((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size));
        end
        kesai_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size))=...
            kesai_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size))+...
            k*(beta(((i-1)*row_size+1):(i*row_size))-beta(((j-1)*row_size+1):(j*row_size))-v_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size)));
        yita_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size))=...
            yita_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size))+...
            k*(gamma(((i-1)*col_size+1):(i*col_size))-gamma(((j-1)*col_size+1):(j*col_size))-w_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size)));
            
    end
end
%--------------------------------------------更新v,w,kesai,yita---------------------------------------------%
for i = 1:(sample_size-1)
    v(i,i,:) = 0;
    w(i,i,:) = 0;
    for j = (i+1):(sample_size)
        v(i,j,:) = v_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size));
        w(i,j,:) = w_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size));
        kesai(i,j,:) = kesai_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size));
        yita(i,j,:) = yita_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*col_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*col_size));
        v(j,i,:) = v(i,j,:);
        w(j,i,:) = w(i,j,:);
    end
end
%--------------------------------------------目标函数值计算----------------------------------------------------%
% D_beta = one_beta*diag(beta);
% D_gamma = one_gamma*diag(gamma);
% mcp_value = zeros(sample_size*sample_size,1);
% mcp = 0;
% for i = 1:(sample_size-1)
%    for j = (i+1):sample_size
%        mcp(i,j) = sqrt(sum(v_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size)).^2)+...
%                       sum(w_vec((((((2*sample_size-i)*(i-1)/2+(j-i))-1)*row_size)+1):((((2*sample_size-i)*(i-1)/2)+(j-i))*row_size)).^2));
%        if mcp(i,j)<=(a*lambda)
%            mcp(i,j) = lambda*mcp(i,j)-mcp(i,j).^2/(2*a);
%        else
%            mcp(i,j) = 0.5*a*lambda.^2;
%        end
%    end
% end
% f2 = 0.5*sum((y-D_beta*X*gamma).^2)+0.5*k*sum((H_p*beta-v_vec).^2)+0.5*k*sum((H_q*gamma-w_vec).^2)+...
%                                   kesai_vec'*(H_p*beta-v_vec)+yita_vec'*(H_q*gamma-w_vec)+sum(sum(mcp))
%--------------------------------------------系数差和原始残差计算-----------------------------------------------%              
residual_primal = norm(([H_p*beta;H_q*gamma]-[v_vec;w_vec])/sqrt(0.5*sample_size*(sample_size-1)*(row_size+col_size)));
iter = iter+1;
%-------------------------自适应步长---------------------------------%
elapsed_time = toc(start_time);
    if elapsed_time > max_time
        %disp('超过给定时间，跳出循环。');
        break;
    end
end
%----------------------------------------------亚组结构识别-------------------------------------------------%
class_matrix = squeeze(v(:,:,1));
class_matrix(sample_size,sample_size) = 0;
for i = 1:(sample_size-1)
    for j = (i+1):sample_size
        if class_matrix(i,j)~= 0
            class_matrix(i,j) = 1;
            class_matrix(j,i) = 1;
        end
    end
end
[v_class,Iv,~] = unique(class_matrix,'rows');
class_store = zeros(length(Iv),sample_size);
for i = 1:length(Iv)
   store_tem = [];
   for j = 1:sample_size
       if class_matrix(j,:)==v_class(i,:)
           store_tem = [store_tem,j];
       end
   end
   class_store(i,(1:length(store_tem))) = store_tem;
end
class_store(class_store==0)= nan;
index_store = [(1:sample_size)',zeros(sample_size,1)];
for i = 1:sample_size
   for j = 1:length(Iv)
      if class_matrix(i,:) == v_class(j,:)
         index_store(i,2)= j;
         break
      end
   end
end
%class_store %存储每组下的原始序号（每一行代表一组，元素为原始序号）
%index_store %存储原始序号对应的组标签（第一列为原始序号，第二列为对应的组标签）
%----------------------------------------\hat{k}_number是否等于k_real_number--------------------------------------%
theta_real_re = [reshape(beta_real,row_size,sample_size);reshape(gamma_real,col_size,sample_size)];
[~,Itheta,~] = unique(theta_real_re','rows');
k_real_number = length(Itheta);
k_hat_number = length(Iv);%为估计出的亚组数
if k_hat_number == k_real_number
    per_if = 1;%判定估计出的亚组数与真实系数亚组数是否相等
end
%------------------------------------------真实亚组结构识别-------------------------------------------------------%
v_real = zeros(sample_size,sample_size,(row_size+col_size));
for i = 1:(sample_size-1)
    for j = (i+1):sample_size
        v_real(i,j,:) = abs(theta_real_re(:,i)-theta_real_re(:,j));
    end
end
class_real_matrix = squeeze(sum(abs(v_real(:,:,:)),3));
class_real_matrix(sample_size,sample_size) = 0;
for i = 1:(sample_size-1)
    for j = (i+1):sample_size
        if class_real_matrix(i,j)~= 0
            class_real_matrix(i,j) = 1;
            class_real_matrix(j,i) = 1;
        end
    end
end
[v_real_class,Ireal,~] = unique(class_real_matrix,'rows');
index_real_store = [(1:sample_size)',zeros(sample_size,1)];
for i = 1:sample_size
   for j = 1:length(Ireal)
      if class_real_matrix(i,:) == v_real_class(j,:)
         index_real_store(i,2)= j;
         break
      end
   end
end
%------------------------------------------------计算估计参数的mse------------------------------------------------%
mse_beta = sum((beta-beta_real).^2)/(sample_size*row_size);
mse_gamma = sum((gamma-gamma_real).^2)/(sample_size*col_size);
%-----------------------------------------------计算亚组划分一致性------------------------------------------------%
for i = 1:(sample_size-1)
    for j = (i+1):sample_size
        if index_store(i,2)==index_store(j,2)
            sc_hat_store(i,j)=1;
        end
    end
end
for i = 1:(sample_size-1)
    for j = (i+1):sample_size
        if index_real_store(i,2)==index_real_store(j,2)
            sc_real_store(i,j)=1;
        end
    end
end
for i = 1:(sample_size-1)
    for j = (i+1):sample_size
        if sc_hat_store(i,j)==sc_real_store(i,j)
            sc_store(i,j)=1;
        end        
    end
end
sc = sum(sum(sc_store))/nchoosek(sample_size,2);
%-----------------------------------------------计算预测误差值---------------------------------------------------%
eta_likelihood = kron(eye(sample_size),ones(row_size,1)')*diag(beta)*X*gamma; 
wucha = -2*log(exp(sum(y.*eta_likelihood-log(1+exp(eta_likelihood)))));
%------------------------------------------------计算BIC值---------------------------------------------------%
bic = wucha+c*log(log(sample_size*(row_size+col_size)))*(log(sample_size)/sample_size)*(k_hat_number);
%-----------------------------------------------计算预测BIC第二项---------------------------------------------------%
BIC_part2 = c*log(log(sample_size*(row_size+col_size)))*(log(sample_size)/sample_size)*(k_hat_number);
%------------------------------------------------函数输出---------------------------------------------------%
BIC_part2_back = BIC_part2;
beta_back = beta;
gamma_back = gamma;
class_back = class_store;
index_back = index_store;
subgroup_number = k_hat_number;
convergence = residual_primal;
BIC_back = bic;
wucha_back = wucha;
iter_back = iter-1;
Data.beta = beta_back;
Data.gamma = gamma_back;
Data.class = class_back;
Data.index = index_back;
Data.subgroup_number = subgroup_number;
Data.convergence = convergence;
Data.BIC = BIC_back;
Data.iter = iter_back;
Data.wucha = wucha_back;
Data.BIC_part2 = BIC_part2;
end