%%
near_out_duiqi = readtable("D:/MATLAB_Document/ADMM_BCD_new/实际数据/near_out_duiqi.csv");
snp_duiqi = readtable("D:/MATLAB_Document/ADMM_BCD_new/实际数据/snp_duiqi.csv");
y_duiqi = readtable("D:/MATLAB_Document/ADMM_BCD_new/实际数据/y_duiqi.csv");
snp = table2array([snp_duiqi(:,2:26)]);
y = [y_duiqi.RA_2, y_duiqi.AL_2, y_duiqi.VCD_2, y_duiqi.Kavg_2, y_duiqi.LLTT_2,...
     y_duiqi.AD_2, y_duiqi.White_to_White_2, y_duiqi.CCT_2, y_duiqi.Pupill_2, y_duiqi.OPP_2,...
     y_duiqi.RASPH_2, y_duiqi.RACYL_2, y_duiqi.DBLOPRE_2, y_duiqi.SBLOPRE_2, y_duiqi.RPR_2,...
     y_duiqi.JTR_2, y_duiqi.YTR_2];
environment = [y_duiqi.GENDER, y_duiqi.AGE_2, near_out_duiqi.JG_2, near_out_duiqi.YW_2, snp_duiqi.myopia, snp_duiqi.HEIGHT];%身高是初一的
save("D:/MATLAB_Document/ADMM_BCD_new/实际数据/y_new.mat",'y');
save("D:/MATLAB_Document/ADMM_BCD_new/实际数据/environment_new.mat",'environment');
save("D:/MATLAB_Document/ADMM_BCD_new/实际数据/snp_new.mat",'snp');

%%
%真实数据载入
environment = load("D:/MATLAB_Document/ADMM_BCD_new/实际数据/environment_new.mat").environment;%.matrix_data;
snp = load("D:/MATLAB_Document/ADMM_BCD_new/实际数据/snp_new.mat").snp;%.matrix_data;
y = load("D:/MATLAB_Document/ADMM_BCD_new/实际数据/y_new.mat").y;%.matrix_data;
[row,~] = find(isnan([y,environment])); row = unique(row); [row_num,~]=size(snp);
snp_choose = [2:11,13:17,19:21,23:25]; %选多少个基因
snp = snp(setdiff((1:row_num),row),snp_choose);%剔除样本编号中有缺失值的编号，row是缺失值的编号集合
environment = environment(setdiff((1:row_num),row),:);%包括基本环境变量和身高加0-1变量
y = y(setdiff((1:row_num),row),:);% y包括各种临床眼部参数
index_gender_0 = find(environment(:,1)==1);%性别为0的索引集
index_gender_1 = find(environment(:,1)==2);%%性别为1的索引集
y_0 = y(index_gender_0,:);%性别为0的样本的眼部参数
y_1 = y(index_gender_1,:);%性别为1的样本的眼部参数
snp_0 = snp(index_gender_0,:);%性别为0的样本的眼部参数 
snp_1 = snp(index_gender_1,:);%性别为1的样本的眼部参数
environment_0 = environment(index_gender_0,:);%性别为0的样本的环境变量
environment_1 = environment(index_gender_1,:);%性别为1的样本的环境变量
num_seed = 12;
num_choose = 100:length(y_0);%length(要研究的y)
p_value_store = zeros(length(num_seed),length(num_choose));
h_value_store = zeros(length(num_seed),length(num_choose));
for j = 1:length(num_seed)
for i = 1:length(num_choose) 
    rng(num_seed(j));
    sampling_size = num_choose(i);
    index = randperm(length(snp_0));index = sort(index(1:sampling_size));
    snp_0_h = snp_0(index,:);
    snp_1_h = snp_1(index,:);
    environment_0_h = environment_0(index,:);
    environment_1_h = environment_1(index,:);
    y_0_h = y_0(index,:);
    y_1_h = y_1(index,:);
    y_y_h = y_0_h;
    [h, p] = jbtest(y_y_h(:,1));%用哪个眼部参数来做正态性检验
    p_value_store(j, i) = p;
    h_value_store(j, i) = h;
end
end
[m,n] = find(p_value_store > 0.05);
sampling_size = num_choose(max(n));

rng(12); %随机种子数
index = randperm(length(snp_0));index = sort(index(1:sampling_size));
snp_0 = snp_0(index,:);
snp_1 = snp_1(index,:);
environment_0 = environment_0(index,:);
environment_1 = environment_1(index,:);
y_0 = y_0(index,:);
y_1 = y_1(index,:);
y_y = y_0;
%%
%将预处理后的实际数据转化为标准的输入形式
if_add_1 = 0; %如果考虑主效应
simulation_size = 1;
[sample_size,col_size] = size(snp_0);
row_size = 3;%年龄、近距离工作时间、户外工作时间
[~,col_size] = size(snp_0);
Data_x = zeros((row_size+if_add_1),(col_size+if_add_1),sample_size,simulation_size)*nan;%创建矩阵x(实际1次模拟，每次模拟n个矩阵样本)
for j = 1:simulation_size
    for i = 1:sample_size
        if if_add_1 == 1
            Data_x(:,:,i,j) = [1,environment_0(i,2:4)]'*[1,snp_0(i,:)];
        else
             Data_x(:,:,i,j) = environment_0(i,2:4)'*snp_0(i,:);
        end
    end
end

%对基因环境交互作用生成的matrix-variate进行标准化处理
MEAN = mean(Data_x,3);
STD = zeros((row_size+if_add_1),(col_size+if_add_1));
for i = 1:(row_size+if_add_1)
    for j = 1:(col_size+if_add_1)
        STD(i,j) = std(Data_x(i,j,:));
    end
end
for i = 1:(row_size+if_add_1)
    for j = 1:(col_size+if_add_1)
        for k = 1:sample_size
            Data_x(i,j,k) = (Data_x(i,j,k)-MEAN(i,j))/STD(i,j);   
        end
    end
end
if if_add_1 == 1
    Data_x(1,1,:) = 1;
end
x = Data_x;

y = y_y(:,1);%因变量不标准化

beta_real = zeros((sample_size*(row_size+if_add_1)),1);
gamma_real = zeros((sample_size*(col_size+if_add_1)),1);
%%
% 执行Jarque-Bera正态性检验
[h, p] = jbtest(y);

% 输出检验结果
if h == 0
    disp('数据符合正态分布');
else
    disp('数据不符合正态分布');
end

disp(['p-value: ', num2str(p)]);

%%
% 生成示例数据，可以将您的数据替换为实际数据
data = randn(1000, 1); % 这里生成1000个符合标准正态分布的随机数
% 设置bin的个数
numBins = 50;
% 使用histogram函数绘制频数直方图并计算概率密度值
histogramValues = histogram(y, numBins, 'Normalization', 'probability', 'FaceAlpha', 0.7);
% 显示网格线
grid on;
% 调整整个图形的透明度
alpha(0.7);
% 计算每个bin的中心值
%binCenters = (histogramValues.BinEdges(1:end-1) + histogramValues.BinEdges(2:end)) / 2;
% 使用bar函数绘制概率密度直方图
%bar(binCenters, histogramValues.Values);
% 添加标签和标题
xlabel('Diopter');
ylabel('Density');
title('Histogram of the responses (Diopter)');
%%
[sample_size,~] = size(snp_0);
k = 10;%ADMM中的惩罚参数
lambda = 0.38;%MCP中的惩罚参数0.4一致
a = 3;%MCP中的惩罚参数
%num_partitions = 6;%随机分成多少组
eps_initial = 1e-3;%对数似然函数收敛条件1e-5
eps_out = 1e-3;%初值算法收敛条件1e-8
iter_max_initial_in = 200;%迭代最大步数500
iter_max_initial_out = 200;%迭代最大步数500
%combine_principle = 0.2*sample_size;%最小元素个数组合并准则
%combine_principle_list = (linspace(0.25*sample_size,0.35*sample_size,5));%(linspace(0.2*sample_size,0.3*sample_size,5));
num_partitions_list = 6:8;%(4:10)(3:8)
combine_principle_list = linspace(0.2,0.4,3)*sample_size;%0.3
split_principle_list = 0.6*sample_size;%0.6
random_number_list = 1:25;
[beta0, gamma0, partitions, result] = k_means_regression_initial(num_partitions_list,eps_initial,eps_out,iter_max_initial_in,...
                                                iter_max_initial_out,combine_principle_list,split_principle_list,random_number_list,sample_size,row_size,col_size,x,y,1,beta_real,gamma_real);
%%
%[Results,results,Results_opt,results_opt,Partitions,initial] = Matrix_heterogeneous_regression(simulation_size,Data_x,y,sample_size,row_size,col_size,beta_real,gamma_real,...
%                                                             [],[],[],[],[],
%                                                             [],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],1);
[Results,results,Results_opt,results_opt,...
  initial,Results_list_opt,Results_single_opt] = Matrix_heterogeneous_regression(simulation_size,Data_x,y,sample_size,(row_size+if_add_1),(col_size+if_add_1),beta_real,gamma_real,...
                                                               [],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],1,[],[]);
%%
[row, col] = size(Results_opt.DATA.class);%row为组数
class = cell(1, row);
for i = 1:row
   class{1,i} = Results_opt.DATA.class(i,~isnan(Results_opt.DATA.class(i,:))); 
end
B = zeros((row_size+if_add_1), (col_size+if_add_1), row);
for i = 1:row
    %Results_opt.DATA.class(i,1) 每个类第一个元素指标
    B(:, :, i) = Results_opt.DATA.beta(((Results_opt.DATA.class(i,1)-1)*(row_size+if_add_1)+1):(Results_opt.DATA.class(i,1)*(row_size+if_add_1)),1)*...
                 (Results_opt.DATA.gamma(((Results_opt.DATA.class(i,1)-1)*(col_size+if_add_1)+1):(Results_opt.DATA.class(i,1)*(col_size+if_add_1)),1))';
end
for i = 1:row
subplot(row, 1, i);
h = heatmap(B(:, :, i));
% 设置坐标轴标签
h.XLabel = 'Genetic variables';
h.YLabel = 'Environmental variables';
% 设置坐标轴刻度
h.XDisplayLabels = {'rs2564978', 'rs2114039', 'rs6554163', 'rs35597368', 'rs1048201', 'rs3735520','rs885863',...
                    'rs2730220','rs2071623','rs2239182','rs1034762','rs3803183','rs12423791','rs5742612','rs17859821','rs2287074',...
                    'rs2075555','rs2269336','rs1049007','rs235768','rs3178250'};
h.YDisplayLabels = {'Age', 'Near', 'Outdoor'};
% 设置坐标轴显示方向
%h.XDisplayOrientation = 'horizontal';
%h.YDisplayOrientation = 'horizontal';
end
%%
subplot(2, 3, 1);%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%箱线图画成子图
variable = 1;%临床变量所在y_y中的列数 选择哪个临床变量
[row,col] = size(Results_opt.DATA.class);%row为组数
class = cell(1,row);
for i = 1:row
   class{1,i} = Results_opt.DATA.class(i,~isnan(Results_opt.DATA.class(i,:))); 
end
box_store = cell(1,((row-1)*row));
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)       %%index_j(j)
        match_distance = zeros(numel(class{1,i}),numel(class{1,index_j(j)}));
        for z = 1:numel(class{1,i})
            for d = 1:numel(class{1,index_j(j)})
                match_distance(z,d) =  sum(sum((Data_x(:,:,class{1,i}(z))-Data_x(:,:,class{1,(index_j(j))}(d))).^2)) ;
            end
        end
        [~, match_distance_index] = min(match_distance, [], 2);
        difference = zeros(numel(class{1,i}),1);
        for z = 1:numel(class{1,i})
            difference(z,1) = abs(y_y(class{1,i}(z),variable)-y_y(class{1,index_j(j)}(match_distance_index(z,1)),variable))/abs(y_y(class{1,i}(z),variable));
        end
        box_store{1,((i-1)*(row-1)+j)} =  difference;
    end
end
% 将所有数据连接到一个长向量中
allData = [];
groups = [];
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)
        allData = [allData,100*box_store{1,((i-1)*(row-1)+j)}'];
        groups = [groups,((i-1)*(row-1)+j)*ones(1,numel(box_store{1,((i-1)*(row-1)+j)}))];
    end
end
allData
groups
% 填充颜色
C5=[77,186,216;77,186,216;235,75,55;235,75,55;2,162,136;2,162,136]./255;
colorList = C5;
% 绘图
boxplot(allData, groups,'Symbol','o','OutlierSize',3,'Colors',C5);
ylim([-20 550]); 
% 坐标区域属性设置
ax=gca;hold on; 
ax.LineWidth=1.1;
ax.FontSize=11;
ax.FontName='Arial';
ax.XTickLabel={'1&2','2&1','2&1','2&3','3&1','3&2'};
%ax.XTickLabel={'1&2','1&3','2&1','2&3','3&1','3&2'};
ax.Title.String='RA';
ax.Title.FontSize=13;
ax.YLabel.String='Relative Differences (%)';
% 修改线条粗细
lineObj=findobj(gca,'Type','Line');
for i=1:length(lineObj)
    lineObj(i).LineWidth=1;
    lineObj(i).MarkerFaceColor=[1,1,1].*.3;
    lineObj(i).MarkerEdgeColor=[1,1,1].*.3;
end
% 为箱线图的框上色
boxObj=findobj(gca,'Tag','Box');
for i=1:length(boxObj)
    patch(boxObj(i).XData,boxObj(i).YData,colorList(length(boxObj)+1-i,:),'FaceAlpha',0.5,...
        'LineWidth',1.1);
end
%%
subplot(2, 3, 2);%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%箱线图画成子图
variable = 11;%临床变量所在y_y中的列数 选择哪个临床变量
[row,col] = size(Results_opt.DATA.class);%row为组数
class = cell(1,row);
for i = 1:row
   class{1,i} = Results_opt.DATA.class(i,~isnan(Results_opt.DATA.class(i,:))); 
end
box_store = cell(1,((row-1)*row));
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)       %%index_j(j)
        match_distance = zeros(numel(class{1,i}),numel(class{1,index_j(j)}));
        for z = 1:numel(class{1,i})
            for d = 1:numel(class{1,index_j(j)})
                match_distance(z,d) =  sum(sum((Data_x(:,:,class{1,i}(z))-Data_x(:,:,class{1,(index_j(j))}(d))).^2)) ;
            end
        end
        [~, match_distance_index] = min(match_distance, [], 2);
        difference = zeros(numel(class{1,i}),1);
        for z = 1:numel(class{1,i})
            difference(z,1) = abs(y_y(class{1,i}(z),variable)-y_y(class{1,index_j(j)}(match_distance_index(z,1)),variable))/abs(y_y(class{1,i}(z),variable));
        end
        box_store{1,((i-1)*(row-1)+j)} =  difference;
    end
end
% 将所有数据连接到一个长向量中
allData = [];
groups = [];
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)
        allData = [allData,100*box_store{1,((i-1)*(row-1)+j)}'];
        groups = [groups,((i-1)*(row-1)+j)*ones(1,numel(box_store{1,((i-1)*(row-1)+j)}))];
    end
end
allData
groups
% 填充颜色
C5=[77,186,216;77,186,216;235,75,55;235,75,55;2,162,136;2,162,136]./255;
colorList = C5;
% 绘图
boxplot(allData, groups,'Symbol','o','OutlierSize',3,'Colors',C5);
ylim([-20 550]); 
% 坐标区域属性设置
ax=gca;hold on; 
ax.LineWidth=1.1;
ax.FontSize=11;
ax.FontName='Arial';
ax.XTickLabel={'1&2','2&1','2&1','2&3','3&1','3&2'};
ax.Title.String='RASPH';
ax.Title.FontSize=13;
ax.YLabel.String='Relative Differences (%)';
% 修改线条粗细
lineObj=findobj(gca,'Type','Line');
for i=1:length(lineObj)
    lineObj(i).LineWidth=1;
    lineObj(i).MarkerFaceColor=[1,1,1].*.3;
    lineObj(i).MarkerEdgeColor=[1,1,1].*.3;
end
% 为箱线图的框上色
boxObj=findobj(gca,'Tag','Box');
for i=1:length(boxObj)
    patch(boxObj(i).XData,boxObj(i).YData,colorList(length(boxObj)+1-i,:),'FaceAlpha',0.5,...
        'LineWidth',1.1);
end
%%
subplot(2, 3, 3);%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%箱线图画成子图
variable = 12;%临床变量所在y_y中的列数 选择哪个临床变量
y_y(y_y(:,12)==0,12)=1e-8;
[row,col] = size(Results_opt.DATA.class);%row为组数
class = cell(1,row);
for i = 1:row
   class{1,i} = Results_opt.DATA.class(i,~isnan(Results_opt.DATA.class(i,:))); 
end
box_store = cell(1,((row-1)*row));
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)       %%index_j(j)
        match_distance = zeros(numel(class{1,i}),numel(class{1,index_j(j)}));
        for z = 1:numel(class{1,i})
            for d = 1:numel(class{1,index_j(j)})
                match_distance(z,d) =  sum(sum((Data_x(:,:,class{1,i}(z))-Data_x(:,:,class{1,(index_j(j))}(d))).^2)) ;
            end
        end
        [~, match_distance_index] = min(match_distance, [], 2);
        difference = zeros(numel(class{1,i}),1);
        for z = 1:numel(class{1,i})
            difference(z,1) = abs(y_y(class{1,i}(z),variable)-y_y(class{1,index_j(j)}(match_distance_index(z,1)),variable))/abs(y_y(class{1,i}(z),variable));
        end
        box_store{1,((i-1)*(row-1)+j)} =  difference;
    end
end
% 将所有数据连接到一个长向量中
allData = [];
groups = [];
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)
        allData = [allData,100*box_store{1,((i-1)*(row-1)+j)}'];
        groups = [groups,((i-1)*(row-1)+j)*ones(1,numel(box_store{1,((i-1)*(row-1)+j)}))];
    end
end
allData
groups
% 填充颜色
C5=[77,186,216;77,186,216;235,75,55;235,75,55;2,162,136;2,162,136]./255;
colorList = C5;
% 绘图
boxplot(allData, groups,'Symbol','o','OutlierSize',3,'Colors',C5,'Whisker',2);
ylim([-20 550]); 
% 坐标区域属性设置
ax=gca;hold on; 
ax.LineWidth=1.1;
ax.FontSize=11;
ax.FontName='Arial';
ax.XTickLabel={'1&2','2&1','2&1','2&3','3&1','3&2'};
ax.Title.String='RACYL';
ax.Title.FontSize=13;
ax.YLabel.String='Relative Differences (%)'; 
% 修改线条粗细
lineObj=findobj(gca,'Type','Line');
for i=1:length(lineObj)
    lineObj(i).LineWidth=1;
    lineObj(i).MarkerFaceColor=[1,1,1].*.3;
    lineObj(i).MarkerEdgeColor=[1,1,1].*.3;
end
% 为箱线图的框上色
boxObj=findobj(gca,'Tag','Box');
for i=1:length(boxObj)
    patch(boxObj(i).XData,boxObj(i).YData,colorList(length(boxObj)+1-i,:),'FaceAlpha',0.5,...
        'LineWidth',1.1);
end
%%
subplot(2, 3, 4);%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%箱线图画成子图
variable = 15;%临床变量所在y_y中的列数 选择哪个临床变量
[row,col] = size(Results_opt.DATA.class);%row为组数
class = cell(1,row);
for i = 1:row
   class{1,i} = Results_opt.DATA.class(i,~isnan(Results_opt.DATA.class(i,:))); 
end
box_store = cell(1,((row-1)*row));
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)       %%index_j(j)
        match_distance = zeros(numel(class{1,i}),numel(class{1,index_j(j)}));
        for z = 1:numel(class{1,i})
            for d = 1:numel(class{1,index_j(j)})
                match_distance(z,d) =  sum(sum((Data_x(:,:,class{1,i}(z))-Data_x(:,:,class{1,(index_j(j))}(d))).^2)) ;
            end
        end
        [~, match_distance_index] = min(match_distance, [], 2);
        difference = zeros(numel(class{1,i}),1);
        for z = 1:numel(class{1,i})
            difference(z,1) = abs(y_y(class{1,i}(z),variable)-y_y(class{1,index_j(j)}(match_distance_index(z,1)),variable))/abs(y_y(class{1,i}(z),variable));
        end
        box_store{1,((i-1)*(row-1)+j)} =  difference;
    end
end
% 将所有数据连接到一个长向量中
allData = [];
groups = [];
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)
        allData = [allData,100*box_store{1,((i-1)*(row-1)+j)}'];
        groups = [groups,((i-1)*(row-1)+j)*ones(1,numel(box_store{1,((i-1)*(row-1)+j)}))];
    end
end
allData
groups
% 填充颜色
C5=[77,186,216;77,186,216;235,75,55;235,75,55;2,162,136;2,162,136]./255;
colorList = C5;
% 绘图
boxplot(allData, groups,'Symbol','o','OutlierSize',3,'Colors',C5);
ylim([-20 550]); 
% 坐标区域属性设置
ax=gca;hold on; 
ax.LineWidth=1.1;
ax.FontSize=11;
ax.FontName='Arial';
ax.XTickLabel={'1&2','2&1','2&1','2&3','3&1','3&2'};
ax.Title.String='RPR';
ax.Title.FontSize=13;
ax.YLabel.String='Relative Differences (%)';
% 修改线条粗细
lineObj=findobj(gca,'Type','Line');
for i=1:length(lineObj)
    lineObj(i).LineWidth=1;
    lineObj(i).MarkerFaceColor=[1,1,1].*.3;
    lineObj(i).MarkerEdgeColor=[1,1,1].*.3;
end
% 为箱线图的框上色
boxObj=findobj(gca,'Tag','Box');
for i=1:length(boxObj)
    patch(boxObj(i).XData,boxObj(i).YData,colorList(length(boxObj)+1-i,:),'FaceAlpha',0.5,...
        'LineWidth',1.1);
end
%%
subplot(2, 3, 5);%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%箱线图画成子图
variable = 16;%临床变量所在y_y中的列数 选择哪个临床变量
[row,col] = size(Results_opt.DATA.class);%row为组数
class = cell(1,row);
for i = 1:row
   class{1,i} = Results_opt.DATA.class(i,~isnan(Results_opt.DATA.class(i,:))); 
end
box_store = cell(1,((row-1)*row));
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)       %%index_j(j)
        match_distance = zeros(numel(class{1,i}),numel(class{1,index_j(j)}));
        for z = 1:numel(class{1,i})
            for d = 1:numel(class{1,index_j(j)})
                match_distance(z,d) =  sum(sum((Data_x(:,:,class{1,i}(z))-Data_x(:,:,class{1,(index_j(j))}(d))).^2)) ;
            end
        end
        [~, match_distance_index] = min(match_distance, [], 2);
        difference = zeros(numel(class{1,i}),1);
        for z = 1:numel(class{1,i})
            difference(z,1) = abs(y_y(class{1,i}(z),variable)-y_y(class{1,index_j(j)}(match_distance_index(z,1)),variable))/abs(y_y(class{1,i}(z),variable));
        end
        box_store{1,((i-1)*(row-1)+j)} =  difference;
    end
end
% 将所有数据连接到一个长向量中
allData = [];
groups = [];
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)
        allData = [allData,100*box_store{1,((i-1)*(row-1)+j)}'];
        groups = [groups,((i-1)*(row-1)+j)*ones(1,numel(box_store{1,((i-1)*(row-1)+j)}))];
    end
end
allData
groups
% 填充颜色
C5=[77,186,216;77,186,216;235,75,55;235,75,55;2,162,136;2,162,136]./255;
colorList = C5;
% 绘图
boxplot(allData, groups,'Symbol','o','OutlierSize',3,'Colors',C5);
ylim([-20 550]); 
% 坐标区域属性设置
ax=gca;hold on; 
ax.LineWidth=1.1;
ax.FontSize=11;
ax.FontName='Arial';
ax.XTickLabel={'1&2','2&1','2&1','2&3','3&1','3&2'};
ax.Title.String='JTR';
ax.Title.FontSize=13;
ax.YLabel.String='Relative Differences (%)';
% 修改线条粗细
lineObj=findobj(gca,'Type','Line');
for i=1:length(lineObj)
    lineObj(i).LineWidth=1;
    lineObj(i).MarkerFaceColor=[1,1,1].*.3;
    lineObj(i).MarkerEdgeColor=[1,1,1].*.3;
end
% 为箱线图的框上色
boxObj=findobj(gca,'Tag','Box');
for i=1:length(boxObj)
    patch(boxObj(i).XData,boxObj(i).YData,colorList(length(boxObj)+1-i,:),'FaceAlpha',0.5,...
        'LineWidth',1.1);
end
%%
subplot(2, 3, 6);%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%箱线图画成子图
variable = 17;%临床变量所在y_y中的列数 选择哪个临床变量
[row,col] = size(Results_opt.DATA.class);%row为组数
class = cell(1,row);
for i = 1:row
   class{1,i} = Results_opt.DATA.class(i,~isnan(Results_opt.DATA.class(i,:))); 
end
box_store = cell(1,((row-1)*row));
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)       %%index_j(j)
        match_distance = zeros(numel(class{1,i}),numel(class{1,index_j(j)}));
        for z = 1:numel(class{1,i})
            for d = 1:numel(class{1,index_j(j)})
                match_distance(z,d) =  sum(sum((Data_x(:,:,class{1,i}(z))-Data_x(:,:,class{1,(index_j(j))}(d))).^2)) ;
            end
        end
        [~, match_distance_index] = min(match_distance, [], 2);
        difference = zeros(numel(class{1,i}),1);
        for z = 1:numel(class{1,i})
            difference(z,1) = abs(y_y(class{1,i}(z),variable)-y_y(class{1,index_j(j)}(match_distance_index(z,1)),variable))/abs(y_y(class{1,i}(z),variable));
        end
        box_store{1,((i-1)*(row-1)+j)} =  difference;
    end
end
% 将所有数据连接到一个长向量中
allData = [];
groups = [];
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)
        allData = [allData,100*box_store{1,((i-1)*(row-1)+j)}'];
        groups = [groups,((i-1)*(row-1)+j)*ones(1,numel(box_store{1,((i-1)*(row-1)+j)}))];
    end
end
allData
groups
% 填充颜色
C5=[77,186,216;77,186,216;235,75,55;235,75,55;2,162,136;2,162,136]./255;
colorList = C5;
% 绘图
boxplot(allData, groups,'Symbol','o','OutlierSize',3,'Colors',C5);
ylim([-20 550]); 
% 坐标区域属性设置
ax=gca;hold on; 
ax.LineWidth=1.1;
ax.FontSize=11;
ax.FontName='Arial';
ax.XTickLabel={'1&2','2&1','2&1','2&3','3&1','3&2'};
ax.Title.String='YTR';
ax.Title.FontSize=13;
ax.YLabel.String='Relative Differences (%)';
% 修改线条粗细
lineObj=findobj(gca,'Type','Line');
for i=1:length(lineObj)
    lineObj(i).LineWidth=1;
    lineObj(i).MarkerFaceColor=[1,1,1].*.3;
    lineObj(i).MarkerEdgeColor=[1,1,1].*.3;
end
% 为箱线图的框上色
boxObj=findobj(gca,'Tag','Box');
for i=1:length(boxObj)
    patch(boxObj(i).XData,boxObj(i).YData,colorList(length(boxObj)+1-i,:),'FaceAlpha',0.5,...
        'LineWidth',1.1);
end
%%
%方差齐性检验和KS检验
[~,col_y] = size(y_y);
hh_var = Inf*ones((row*(row-1)),col_y);
pp_var = Inf*ones((row*(row-1)),col_y);
pp_ks = Inf*ones((row*(row-1)),col_y);
for i = 1:col_y
    for t = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==t));
    for j = 1:length(index_j)  
        sample1 = y_y(Results_opt.DATA.class(t,~isnan(Results_opt.DATA.class(t,:))),i);
        sample2 = y_y(Results_opt.DATA.class(index_j(j),~isnan(Results_opt.DATA.class(index_j(j),:))),i);
    % 使用vartest2函数进行方差检验
    [h, p] = vartest2(sample1, sample2);
    hh_var(((t-1)*(row-1)+j),i) = h;
    pp_var(((t-1)*(row-1)+j),i) = p;
    % 使用kstest2函数进行双样本KS检验
    [h, p] = kstest2(sample1, sample2);
    hh_ks(((t-1)*(row-1)+j),i) = h;
    pp_ks(((t-1)*(row-1)+j),i) = p;
    end
    end
end
hh_var
hh_ks
pp_var
pp_ks
%% 画不同亚组的概率密度曲线直方图
for i = 1:row
zhibiao = 1;%y_y中第几列是要绘制的变量，第1列屈光度%%%%%%%%%%%%%%%%%可以更换
numBins = 25;%概率密度分多少个格子
%subplot(1, row, i);
%Color = [0.298, 0.447, 0.290];
%color = Color(i,:);
hhh = y_y(Results_opt.DATA.class(i,(Results_opt.DATA.class(i,:)>0)),zhibiao);
histogramValues = histogram(hhh, numBins, 'Normalization', 'probability', 'FaceAlpha', 0.7);
hold on;
% 使用ksdensity函数估计概率密度曲线
[x, f] = ksdensity(hhh);
% 绘制概率密度曲线3
plot(f, x, 'LineWidth', 1);
% 显示网格线
grid on;
% 调整整个图形的透明度
alpha(0.7);
% 计算每个bin的中心值
%binCenters = (histogramValues.BinEdges(1:end-1) + histogramValues.BinEdges(2:end)) / 2;
% 使用bar函数绘制概率密度直方图
%bar(binCenters, histogramValues.Values);
% 添加标签和标题
xlabel('Diopter');
ylabel('Density');
title('Histogram of the responses (Diopter)');
hold on
end
%%
% 基因
subplot(2, 3, 6);%箱线图画成子图
variable = 6;%临床变量所在y_y中的列数 选择哪个临床变量
[row,col] = size(Results_opt.DATA.class);%row为组数
class = cell(1,row);
for i = 1:row
   class{1,i} = Results_opt.DATA.class(i,~isnan(Results_opt.DATA.class(i,:))); 
end
box_store = cell(1,((row-1)*row));
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)
        match_distance = zeros(numel(class{1,i}),numel(class{1,index_j(j)}));
        for z = 1:numel(class{1,i})
            for d = 1:numel(class{1,index_j(j)})
                match_distance(z,d) =  sum(sum((Data_x(:,:,class{1,i}(z))-Data_x(:,:,class{1,(index_j(j))}(d))).^2)) ;
            end
        end
        [~, match_distance_index] = min(match_distance, [], 2);
        difference = zeros(numel(class{1,i}),1);
        for z = 1:numel(class{1,i})
            difference(z,1) = abs(environment_0(class{1,i}(z),variable)-environment_0(class{1,index_j(j)}(match_distance_index(z,1)),variable))/abs(environment_0(class{1,i}(z),variable));
        end
        box_store{1,((i-1)*(row-1)+j)} =  difference;
    end
end
% 将所有数据连接到一个长向量中
allData = [];
groups = [];
for i = 1:row
    index_j = 1:row;
    index_j = index_j(~(index_j==i));
    for j = 1:length(index_j)
        allData = [allData,100*box_store{1,((i-1)*(row-1)+j)}'];
        groups = [groups,((i-1)*(row-1)+j)*ones(1,numel(box_store{1,((i-1)*(row-1)+j)}))];
    end
end
allData
groups
% 填充颜色
C5=[77,186,216;77,186,216;235,75,55;235,75,55;2,162,136;2,162,136]./255;
colorList = C5;
% 绘图
boxplot(allData, groups,'Symbol','o','OutlierSize',3,'Colors',C5);
ylim([-20 550]); 
% 坐标区域属性设置
ax=gca;hold on; 
ax.LineWidth=1.1;
ax.FontSize=11;
ax.FontName='Arial';
ax.XTickLabel={'1&2','1&3','2&1','2&3','3&1','3&2'};
ax.Title.String='YTR';
ax.Title.FontSize=13;
ax.YLabel.String='Relative Differences (%)';
% 修改线条粗细
lineObj=findobj(gca,'Type','Line');
for i=1:length(lineObj)
    lineObj(i).LineWidth=1;
    lineObj(i).MarkerFaceColor=[1,1,1].*.3;
    lineObj(i).MarkerEdgeColor=[1,1,1].*.3;
end
% 为箱线图的框上色
boxObj=findobj(gca,'Tag','Box');
for i=1:length(boxObj)
    patch(boxObj(i).XData,boxObj(i).YData,colorList(length(boxObj)+1-i,:),'FaceAlpha',0.5,...
        'LineWidth',1.1);
end