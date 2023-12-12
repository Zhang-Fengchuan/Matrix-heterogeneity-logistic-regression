%%
%---------------------------------------------------------------------------------------------%
%----------------------------------------生成数据---------------------------------------------%
%---------------------------------------------------------------------------------------------%
rng(1234)%设置种子数为123
simulation_size = 5;%模拟总次数
sample_size = 200;%1次模拟的样本数　240
%col_size_del = 4;%矩阵变量x的列数　10
%row_size_del = 4;%矩阵变量的行数　 12
col_size  = 5;
row_size = 5;
rou = 0.6;%协方差自相关参数
sigma_col = zeros(col_size,col_size)*nan;%创建空的列协方差矩阵
sigma_row = zeros(row_size,row_size)*nan;%创建空的行协方差矩阵
%自相关方式创建列协方差阵
for i = 1:col_size
    for j = 1:col_size
        sigma_col(i,j) = rou^(abs(i-j));       
    end
end
%自相关方式创建行协方差阵
for i = 1:row_size
    for j = 1:row_size
        sigma_row(i,j) = rou^(abs(i-j));       
    end
end
% %带状结构创建列协方差阵B1
% sigma_col = zeros(col_size,col_size);%创建空的列协方差矩阵
% for i = 1:col_size
%     for j = 1:col_size
%         if i==j
%             sigma_col(i,j) = 1;
%         elseif abs(i-j)==1
%             sigma_col(i,j) = 0.25;
%         end
%     end
% end
% %带状结构创建行协方差阵B1
% sigma_row = zeros(row_size,row_size);%创建空的行协方差矩阵
% for i = 1:row_size
%     for j = 1:row_size
%         if i==j
%             sigma_row(i,j) = 1;
%         elseif abs(i-j)==1
%             sigma_row(i,j) = 0.25;
%         end
%     end
% end
% % % % % % % % % 
% % 带状结构创建列协方差阵B2
% sigma_col = zeros(col_size,col_size);%创建空的列协方差矩阵
% for i = 1:col_size
%     for j = 1:col_size
%         if i==j
%             sigma_col(i,j) = 1;
%         elseif abs(i-j)==1
%             sigma_col(i,j) = 0.5;%%%%%%%%%%%%%%%%%%
%         elseif abs(i-j) == 2
%             sigma_col(i,j) = 0.25;%%%%%%%%%%%%%%%%%%%%%%%%%
%         end
%     end
% end
% % 带状结构创建行协方差阵B2
% sigma_row = zeros(row_size,row_size);%创建空的行协方差矩阵
% for i = 1:row_size
%     for j = 1:row_size
%         if i==j
%             sigma_row(i,j) = 1;
%         elseif abs(i-j)==1
%             sigma_row(i,j) = 0.5;%%%%%%%%%%
%         elseif abs(i-j) == 2
%             sigma_row(i,j) = 0.25;%%%%%%%%%%%%%%%
%         end
%     end
% end
% 
sigma = kron(sigma_col,sigma_row);%求得矩阵变量的协方差阵（pq*pq）
[sigma_vec,sigma_value] = eig(sigma);%对协方差阵进行特征分解
sigma_sef = sigma_vec*sqrt(sigma_value);%将协方差阵分解成正交矩阵跟其转置的乘积
Data_x = zeros(row_size,col_size,sample_size,simulation_size)*nan;%创建矩阵x(100次模拟，每次模拟100个矩阵样本)
for j = 1:simulation_size
    for i = 1:sample_size
        Data_x(:,:,i,j) = reshape(sigma_sef*randn(col_size*row_size,1),row_size,col_size);
    end
end


mu = 1; 


beta_real = [beta_real_part1;beta_real_part2;beta_real_part3];
gamma_real = [gamma_real_part1;gamma_real_part2;gamma_real_part3];



epsilon = 0.5*randn(sample_size,simulation_size);%创建误差epsilon
y_real = zeros(sample_size,simulation_size)*nan;%创建真实的y_real
for i = 1:simulation_size
    for j = 1:sample_size
        y_real(j,i) = exp(beta_real(((j-1)*row_size+1):j*row_size)'*Data_x(:,:,j,i)*gamma_real(((j-1)*col_size+1):(j*col_size)))...
            /(1+exp(beta_real(((j-1)*row_size+1):j*row_size)'*Data_x(:,:,j,i)*gamma_real(((j-1)*col_size+1):(j*col_size))));
        y_real(j,i) = rand(1) < y_real(j,i);
        if y_real(j,i) >= 0.5
            y_real(j,i) = 1;
        else
            y_real(j,i) = 0;
        end
    end
end

yangbencishu = 1;%抽第i次
y = y_real(:,yangbencishu);%-mean(y_real(:,i));%将第1次模拟中心化后的y抽出来记为y
x = Data_x(:,:,:,yangbencishu);%将第1次模拟的矩阵变量抽出来记为x（维度为p*q*n）
beta_real;
gamma_real;


c1 = sign(gamma_real_part1(1))*sqrt((sqrt(row_size)/sqrt(col_size))*(norm(gamma_real_part1(1:col_size))/norm(beta_real_part1(1:row_size))));%gamma异质乘了符号
c2 = sign(gamma_real_part2(1))*sqrt((sqrt(row_size)/sqrt(col_size))*(norm(gamma_real_part2(1:col_size))/norm(beta_real_part2(1:row_size))));%gamma异质乘了符号
c3 = sign(gamma_real_part3(1))*sqrt((sqrt(row_size)/sqrt(col_size))*(norm(gamma_real_part3(1:col_size))/norm(beta_real_part3(1:row_size))));%gamma异质乘了符号
for i = 1:length(beta_real_part1)/row_size
beta_real_part1((i-1)*row_size+1:i*row_size) = beta_real_part1((i-1)*row_size+1:i*row_size)*c1;
gamma_real_part1((i-1)*col_size+1:i*col_size) = gamma_real_part1((i-1)*col_size+1:i*col_size)/c1;
end
for i = 1:length(beta_real_part2)/row_size
beta_real_part2((i-1)*row_size+1:i*row_size) = beta_real_part2((i-1)*row_size+1:i*row_size)*c2;
gamma_real_part2((i-1)*col_size+1:i*col_size) = gamma_real_part2((i-1)*col_size+1:i*col_size)/c2;
end
for i = 1:length(beta_real_part3)/row_size
beta_real_part3((i-1)*row_size+1:i*row_size) = beta_real_part3((i-1)*row_size+1:i*row_size)*c3;
gamma_real_part3((i-1)*col_size+1:i*col_size) = gamma_real_part3((i-1)*col_size+1:i*col_size)/c3;
end


beta_real = [beta_real_part1;beta_real_part2;beta_real_part3];
gamma_real = [gamma_real_part1;gamma_real_part2;gamma_real_part3];

yangbencishu = 1;%抽第i次
y = y_real(:,yangbencishu);%-mean(y_real(:,i));%将第1次模拟中心化后的y抽出来记为y
x = Data_x(:,:,:,yangbencishu);%将第1次模拟的矩阵变量抽出来记为x（维度为p*q*n）
beta_real;
gamma_real;