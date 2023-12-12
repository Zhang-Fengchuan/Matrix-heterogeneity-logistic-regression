%% 模拟结果绘图 BALANCED MU=0.5
% AR0.2
dataset11 = [0.39; 0.37; 0.87];% Per
se11 = [0;0;0]; % 误差长度

dataset12 = [0.552; 0.556; 0.853];% SC
se12 = [0.037;0.039;0.090]; % 误差长度

dataset13 = [3.30; 3.38; 2.87];% K
se13 = [1.16;1.24;0.34]; % 误差长度

dataset14 = [0.616; 0.714; 0.108];% MSE_beta
se14 = [0.051;0.099;0.123]; % 误差长度

dataset15 = [0.460; 0.583; 0.016];% MSE_gamma
se15 = [0.120;0.232;0.051]; % 误差长度
% AR0.6
dataset21 = [0.44; 0.39; 0.88];% Per
se21 = [0;0;0]; % 误差长度

dataset22 = [0.563; 0.552; 0.910];% SC
se22 = [0.035;0.038;0.140]; % 误差长度

dataset23 = [3.56; 3.31; 2.97];% K
se23 = [1.23;1.22;0.46]; % 误差长度

dataset24 = [1.192; 1.619; 0.070];% MSE_beta
se24 = [0.178;0.328;0.150]; % 误差长度

dataset25 = [1.049; 1.502; 0.011];% MSE_gamma
se25 = [0.255;0.407;0.055]; % 误差长度
% B1
dataset31 = [0.40; 0.42; 0.89];% Per
se31 = [0;0;0]; % 误差长度

dataset32 = [0.551; 0.555; 0.856];% SC
se32 = [0.036;0.036;0.081]; % 误差长度

dataset33 = [3.26; 3.34; 2.89];% K
se33 = [1.08;1.11;0.31]; % 误差长度

dataset34 = [0.626; 0.712; 0.105];% MSE_beta
se34 = [0.063;0.100;0.116]; % 误差长度

dataset35 = [0.479; 0.556; 0.015];% MSE_gamma
se35 = [0.146;0.206;0.058]; % 误差长度
% B2
dataset41 = [0.40; 0.37; 0.94];% Per
se41 = [0;0;0]; % 误差长度

dataset42 = [0.563; 0.554; 0.902];% SC
se42 = [0.033;0.038;0.077]; % 误差长度

dataset43 = [3.53; 3.41; 2.94];% K
se43 = [1.10;1.22;0.24]; % 误差长度

dataset44 = [0.944; 1.142; 0.072];% MSE_beta
se44 = [0.542;0.244;0.120]; % 误差长度

dataset45 = [0.789; 0.992; 0.025];% MSE_gamma
se45 = [0.506;0.341;0.122]; % 误差长度


% 颜色定义
C1 = [253;185;106]/255;
C2 = [245;251;177]/255;
C3 = [203;233;157]/255;
C4 = [70;158;180]/255;
gca_color = [.96 .96 .96];%图内背景颜色灰
gcf_color = [1 1 1];%背景颜色白
X_Color = [0 0 0];%轴线刻度颜色黑
Y_Color = [0 0 0];%轴线刻度颜色黑
Cap_Size = 7;%误差线端盖宽度
Cap_LineWidth = 0.5;%误差线粗细
Font_Size = 4;%文本字体大小
y_lable_size = 10; %y轴标签字体大小
y_start = -0.05;
y_start_top = 0.05;
%%
subplot(4,5,1)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset11,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75,0.08,0.2] )
%% 
subplot(4,5,2)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset12,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset12);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset12, se12, se12,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,3)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset13,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset13);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset13, se13, se13,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,4)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset14,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset14);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset14, se14, se14,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset14));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,5)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset15,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset15);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset15, se15, se15,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset15));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,6)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset21,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23,0.08,0.2] )
%% 
subplot(4,5,7)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset22,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset12);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset22, se22, se22,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,8)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset23,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset23);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset23, se23, se23,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,9)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset24,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset24);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset24, se24, se24,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset24));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,10)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset25,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset25);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset25, se25, se25,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset25));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,11)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset31,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23-0.23,0.08,0.2] )

%% 
subplot(4,5,12)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset32,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset32);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset32, se32, se32,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,13)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset33,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset33);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset33, se33, se33,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,14)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset34,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset34);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset34, se34, se34,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset34));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,15)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset35,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset35);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset35, se35, se35,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset35));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,16)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset41,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23-0.23-0.23,0.08,0.2] )
%% 
subplot(4,5,17)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset42,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset42);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset42, se42, se42,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,18)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset43,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset43);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset43, se43, se43,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,19)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset44,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset44);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset44, se44, se44,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset44));
y_max = 2;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,20)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset45,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset45);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset45, se45, se45,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset45));
y_max = 2;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%% 模拟结果绘图 UNBALANCED MU=0.5
% 
% AR0.2
dataset11 = [0.42; 0.59; 0.80];% Per
se11 = [0;0;0]; % 误差长度

dataset12 = [0.530; 0.540; 0.780];% SC
se12 = [0.025;0.026;0.126]; % 误差长度

dataset13 = [3.16; 3.19; 2.80];% K
se13 = [0.98;0.86;0.40]; % 误差长度

dataset14 = [0.591; 0.554; 0.224];% MSE_beta
se14 = [0.066;0.088;0.254]; % 误差长度

dataset15 = [0.432; 0.336; 0.101];% MSE_gamma
se15 = [0.133;0.168;0.203]; % 误差长度
% AR0.6
dataset21 = [0.43; 0.71; 0.75];% Per
se21 = [0;0;0]; % 误差长度

dataset22 = [0.537; 0.541; 0.826];% SC
se22 = [0.023;0.026;0.218]; % 误差长度

dataset23 = [3.45; 3.19; 2.86];% K
se23 = [1.19;0.83;1.20]; % 误差长度

dataset24 = [1.183; 1.083; 0.153];% MSE_beta
se24 = [0.191;0.234;0.233]; % 误差长度

dataset25 = [1.017; 0.899; 0.042];% MSE_gamma
se25 = [0.260;0.350;0.106]; % 误差长度
% B1
dataset31 = [0.36; 0.66; 0.82];% Per
se31 = [0;0;0]; % 误差长度

dataset32 = [0.532; 0.544; 0.789];% SC
se32 = [0.025;0.023;0.121]; % 误差长度

dataset33 = [3.26; 3.26; 2.82];% K
se33 = [1.12;0.84;0.39]; % 误差长度

dataset34 = [0.617; 0.564; 0.192];% MSE_beta
se34 = [0.070;0.105;0.203]; % 误差长度

dataset35 = [0.478; 0.326; 0.084];% MSE_gamma
se35 = [0.143;0.191;0.169]; % 误差长度
% B2
dataset41 = [0.46; 0.69; 0.94];% Per
se41 = [0;0;0]; % 误差长度

dataset42 = [0.535; 0.539; 0.867];% SC
se42 = [0.025;0.025;0.106]; % 误差长度

dataset43 = [3.37; 3.16; 2.94];% K
se43 = [1.13;0.56;0.24]; % 误差长度

dataset44 = [0.866; 0.810; 0.154];% MSE_beta
se44 = [0.124;0.158;0.307]; % 误差长度

dataset45 = [0.719; 0.578; 0.087];% MSE_gamma
se45 = [0.198;0.217;0.273]; % 误差长度


% 颜色定义
C1 = [253;185;106]/255;
C2 = [245;251;177]/255;
C3 = [203;233;157]/255;
C4 = [70;158;180]/255;
gca_color = [.96 .96 .96];%图内背景颜色灰
gcf_color = [1 1 1];%背景颜色白
X_Color = [0 0 0];%轴线刻度颜色黑
Y_Color = [0 0 0];%轴线刻度颜色黑
Cap_Size = 7;%误差线端盖宽度
Cap_LineWidth = 0.5;%误差线粗细
Font_Size = 4;%文本字体大小
y_lable_size = 10; %y轴标签字体大小
y_start = -0.05;
y_start_top = 0.05;
%%
subplot(4,5,1)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset11,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75,0.08,0.2] )
%% 
subplot(4,5,2)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset12,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset12);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % 
end
errorbar(xpos, dataset12, se12, se12,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,3)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset13,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset13);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset13, se13, se13,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,4)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset14,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset14);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset14, se14, se14,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset14));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,5)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset15,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset15);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset15, se15, se15,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset15));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,6)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset21,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% % 添加误差棒
% [M,N] = size(dataset11);
% xpos = zeros(M,N);
% for i = 1:M
%     xpos(i) = GO.XEndPoints(i); % v2019b
% end
% errorbar(xpos, dataset11, se11, se11,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23,0.08,0.2] )
%% 
subplot(4,5,7)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset22,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset12);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset22, se22, se22,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,8)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset23,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset23);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset23, se23, se23,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,9)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset24,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset24);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset24, se24, se24,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset24));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,10)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset25,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset25);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset25, se25, se25,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset25));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23,0.08,0.2] )


%%
subplot(4,5,11)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset31,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23-0.23,0.08,0.2] )

%% 
subplot(4,5,12)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset32,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset32);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset32, se32, se32,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                    % 边框
    'XGrid', 'on', 'YGrid', 'on',...                          % 网格
    'TickDir', 'none', ...                                    % 刻度
    'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
    'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
    'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
    'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
    'Xticklabel',{},...                                       % X坐标轴刻度标签
    'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,13)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset33,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset33);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset33, se33, se33,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                    % 边框
    'XGrid', 'on', 'YGrid', 'on',...                          % 网格
    'TickDir', 'none', ...                                    % 刻度
    'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
    'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
    'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
    'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
    'Xticklabel',{},...                                       % X坐标轴刻度标签
    'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,14)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset34,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset34);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset34, se34, se34,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset34));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,15)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset35,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset35);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset35, se35, se35,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset35));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,16)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset41,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% % 添加误差棒
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23-0.23-0.23,0.08,0.2] )
%% 
subplot(4,5,17)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset42,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset42);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset42, se42, se42,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,18)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset43,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset43);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset43, se43, se43,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,19)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset44,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset44);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset44, se44, se44,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset44));
y_max = 2;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,20)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset45,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset45);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset45, se45, se45,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset45));
y_max = 2;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%% 模拟结果绘图 BALANCED MU=1
% AR0.2
dataset11 = [0.39; 0.41; 0.65];% Per
se11 = [0;0;0]; % 误差长度

dataset12 = [0.550; 0.557; 0.921];% SC
se12 = [0.037;0.036;0.086]; % 误差长度

dataset13 = [3.21; 3.36; 3.26];% K
se13 = [1.13;1.14;0.61]; % 误差长度

dataset14 = [1.223; 1.407; 0.111];% MSE_beta
se14 = [0.107;0.178;0.168]; % 误差长度

dataset15 = [0.914; 1.201; 0.025];% MSE_gamma
se15 = [0.288;0.449;0.110]; % 误差长度
% AR0.6
dataset21 = [0.44; 0.37; 0.45];% Per
se21 = [0;0;0]; % 误差长度

dataset22 = [0.557; 0.557; 0.833];% SC
se22 = [0.033;0.039;0.260]; % 误差长度

dataset23 = [3.39; 3.51; 3.78];% K
se23 = [1.15;1.35;2.97]; % 误差长度

dataset24 = [2.408; 3.203; 0.279];% MSE_beta
se24 = [0.365;0.708;0.483]; % 误差长度

dataset25 = [2.114; 2.958; 0.100];% MSE_gamma
se25 = [0.525;0.902;0.224]; % 误差长度
% B1
dataset31 = [0.42; 0.46; 0.67];% Per
se31 = [0;0;0]; % 误差长度

dataset32 = [0.556; 0.554; 0.925];% SC
se32 = [0.036;0.034;0.060]; % 误差长度

dataset33 = [3.46; 3.27; 3.30];% K
se33 = [1.33;0.99;0.64]; % 误差长度

dataset34 = [1.245; 1.436; 0.089];% MSE_beta
se34 = [0.105;0.187;0.068]; % 误差长度

dataset35 = [0.902; 1.130; 0.009];% MSE_gamma
se35 = [0.260;0.414;0.017]; % 误差长度
% B2
dataset41 = [0.39; 0.43; 0.78];% Per
se41 = [0;0;0]; % 误差长度

dataset42 = [0.562; 0.558; 0.917];% SC
se42 = [0.033;0.037;0.162]; % 误差长度

dataset43 = [3.51; 3.51; 3.23];% K
se43 = [1.04;1.31;1.59]; % 误差长度

dataset44 = [1.757; 2.249; 0.118];% MSE_beta
se44 = [0.224;0.456;0.267]; % 误差长度

dataset45 = [1.457; 1.958; 0.028];% MSE_gamma
se45 = [0.391;0.639;0.102]; % 误差长度


% 颜色定义
C1 = [253;185;106]/255;
C2 = [245;251;177]/255;
C3 = [203;233;157]/255;
C4 = [70;158;180]/255;
gca_color = [.96 .96 .96];%图内背景颜色灰
gcf_color = [1 1 1];%背景颜色白
X_Color = [0 0 0];%轴线刻度颜色黑
Y_Color = [0 0 0];%轴线刻度颜色黑
Cap_Size = 7;%误差线端盖宽度
Cap_LineWidth = 0.5;%误差线粗细
Font_Size = 4;%文本字体大小
y_lable_size = 10; %y轴标签字体大小
y_start = -0.1;
y_start_top = 0.1;
%%
subplot(4,5,1)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset11,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% % 添加误差棒
% [M,N] = size(dataset11);
% xpos = zeros(M,N);
% for i = 1:M
%     xpos(i) = GO.XEndPoints(i); % v2019b
% end
% errorbar(xpos, dataset11, se11, se11,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75,0.08,0.2] )
%% 
subplot(4,5,2)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset12,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset12);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset12, se12, se12,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,3)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset13,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset13);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset13, se13, se13,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,4)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset14,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset14);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset14, se14, se14,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset14));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,5)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset15,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset15);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset15, se15, se15,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset15));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,6)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset21,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% % 添加误差棒
% [M,N] = size(dataset11);
% xpos = zeros(M,N);
% for i = 1:M
%     xpos(i) = GO.XEndPoints(i); % v2019b
% end
% errorbar(xpos, dataset11, se11, se11,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23,0.08,0.2] )
%% 
subplot(4,5,7)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset22,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset12);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset22, se22, se22,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,8)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset23,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset23);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset23, se23, se23,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.7:7,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*7 7+y_start_top*7], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.7:7})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,9)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset24,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset24);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset24, se24, se24,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset24));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,10)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset25,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset25);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset25, se25, se25,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset25));
y_max = 4;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,11)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset31,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23-0.23,0.08,0.2] )

%% 
subplot(4,5,12)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset32,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset32);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset32, se32, se32,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,13)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset33,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset33);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset33, se33, se33,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,14)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset34,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset34);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset34, se34, se34,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset34));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,15)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset35,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset35);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset35, se35, se35,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset35));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,16)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset41,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23-0.23-0.23,0.08,0.2] )
%% 
subplot(4,5,17)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset42,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset42);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset42, se42, se42,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,18)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset43,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset43);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset43, se43, se43,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,19)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset44,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset44);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset44, se44, se44,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset44));
%y_max = 2;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,20)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset45,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset45);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset45, se45, se45,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset45));
y_max = 3;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )

%% 模拟结果绘图 UNBALANCED MU=1
% 
% AR0.2
dataset11 = [0.41; 0.60; 0.83];% Per
se11 = [0;0;0]; % 误差长度

dataset12 = [0.534; 0.542; 0.849];% SC
se12 = [0.026;0.024;0.143]; % 误差长度

dataset13 = [3.32; 3.27; 2.83];% K
se13 = [1.13;0.75;0.38]; % 误差长度

dataset14 = [1.226; 1.107; 0.296];% MSE_beta
se14 = [0.494;0.194;0.405]; % 误差长度

dataset15 = [0.912; 0.668; 0.143];% MSE_gamma
se15 = [0.501;0.353;0.324]; % 误差长度
% AR0.6
dataset21 = [0.47; 0.67; 0.68];% Per
se21 = [0;0;0]; % 误差长度

dataset22 = [0.536; 0.542; 0.821];% SC
se22 = [0.023;0.025;0.247]; % 误差长度

dataset23 = [3.36; 3.27; 3.09];% K
se23 = [1.05;0.92;1.66]; % 误差长度

dataset24 = [2.395; 2.221; 0.304];% MSE_beta
se24 = [0.373;0.498;0.453]; % 误差长度

dataset25 = [2.090; 1.868; 0.112];% MSE_gamma
se25 = [0.506;0.730;0.241]; % 误差长度
% B1
dataset31 = [0.37; 0.72; 0.89];% Per
se31 = [0;0;0]; % 误差长度

dataset32 = [0.532; 0.544; 0.867];% SC
se32 = [0.024;0.019;0.129]; % 误差长度

dataset33 = [3.21; 3.23; 2.91];% K
se33 = [1.08;0.65;0.32]; % 误差长度

dataset34 = [1.223; 1.117; 0.249];% MSE_beta
se34 = [0.139;0.202;0.386]; % 误差长度

dataset35 = [0.918; 0.647; 0.099];% MSE_gamma
se35 = [0.288;0.395;0.253]; % 误差长度
% B2
dataset41 = [0.43; 0.69; 0.84];% Per
se41 = [0;0;0]; % 误差长度

dataset42 = [0.537; 0.541; 0.872];% SC
se42 = [0.026;0.023;0.181]; % 误差长度

dataset43 = [3.52; 3.24; 3.15];% K
se43 = [1.30;0.68;1.74]; % 误差长度

dataset44 = [1.738; 1.644; 0.249];% MSE_beta
se44 = [0.240;0.363;0.454]; % 误差长度

dataset45 = [1.440; 1.169; 0.249];% MSE_gamma
se45 = [0.354;0.459;0.310]; % 误差长度


% 颜色定义
C1 = [253;185;106]/255;
C2 = [245;251;177]/255;
C3 = [203;233;157]/255;
C4 = [70;158;180]/255;
gca_color = [.96 .96 .96];%图内背景颜色灰
gcf_color = [1 1 1];%背景颜色白
X_Color = [0 0 0];%轴线刻度颜色黑
Y_Color = [0 0 0];%轴线刻度颜色黑
Cap_Size = 7;%误差线端盖宽度
Cap_LineWidth = 0.5;%误差线粗细
Font_Size = 4;%文本字体大小
y_lable_size = 10; %y轴标签字体大小
y_start = -0.1;
y_start_top = 0.1;
%%
subplot(4,5,1)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset11,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% % 添加误差棒
% [M,N] = size(dataset11);
% xpos = zeros(M,N);
% for i = 1:M
%     xpos(i) = GO.XEndPoints(i); % v2019b
% end
% errorbar(xpos, dataset11, se11, se11,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75,0.08,0.2] )
%% 
subplot(4,5,2)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset12,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset12);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset12, se12, se12,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,3)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset13,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset13);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset13, se13, se13,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,4)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset14,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset14);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset14, se14, se14,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset14));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,5)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset15,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset15);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset15, se15, se15,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset15));
y_max = 2;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75,0.08,0.2] )
%%
subplot(4,5,6)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset21,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% % 添加误差棒
% [M,N] = size(dataset11);
% xpos = zeros(M,N);
% for i = 1:M
%     xpos(i) = GO.XEndPoints(i); % v2019b
% end
% errorbar(xpos, dataset11, se11, se11,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23,0.08,0.2] )
%% 
subplot(4,5,7)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset22,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset12);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset22, se22, se22,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,8)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset23,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset23);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset23, se23, se23,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,9)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset24,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset24);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset24, se24, se24,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset24));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,10)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset25,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset25);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset25, se25, se25,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset25));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23,0.08,0.2] )
%%
subplot(4,5,11)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset31,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% % 添加误差棒
% [M,N] = size(dataset11);
% xpos = zeros(M,N);
% for i = 1:M
%     xpos(i) = GO.XEndPoints(i); % v2019b
% end
% errorbar(xpos, dataset11, se11, se11,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23-0.23,0.08,0.2] )
%% 
subplot(4,5,12)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset32,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset32);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset32, se32, se32,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,13)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset33,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset33);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset33, se33, se33,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,14)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset34,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset34);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset34, se34, se34,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset34));
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,15)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset35,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset35);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset35, se35, se35,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset35));
y_max = 2;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,16)
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset41,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% % 添加误差棒
% [M,N] = size(dataset11);
% xpos = zeros(M,N);
% for i = 1:M
%     xpos(i) = GO.XEndPoints(i); % v2019b
% end
% errorbar(xpos, dataset11, se11, se11,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Per', 'FontSize', y_lable_size);
set (gca,'position',[0.15,0.75-0.23-0.23-0.23,0.08,0.2] )
%% 
subplot(4,5,17)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset42,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset42);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset42, se42, se42,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.1:1,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*1, 1+y_start_top*1], ...                % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.1:1})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('SC', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,18)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset43,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset43);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset43, se43, se43,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';

% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', 0:0.5:5,...                                      % 刻度位置、间隔
         'Ylim' , [y_start*5 5+y_start_top*5], ...                 % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{0:0.5:5})                                   % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('Number of subgroups', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,19)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset44,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset44);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset44, se44, se44,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset44));
y_max = 2;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \beta', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )
%%
subplot(4,5,20)
% 颜色定义
C = [C1,C2,C3]';
% 绘制初始柱状图
GO = bar(dataset45,"LineStyle",'none','FaceColor','flat','CData', C,'EdgeColor','flat');
hold on
a = axis;
plot([a(1) a(2)],[a(3) a(3)],'w','linewidth',1.5);
plot([a(1) a(1)],[a(3) a(4)],'w','linewidth',1.5);
set(gca,'layer','bottom')
hold on
% 添加误差棒
[M,N] = size(dataset45);
xpos = zeros(M,N);
for i = 1:M
    xpos(i) = GO.XEndPoints(i); % v2019b
end
errorbar(xpos, dataset45, se45, se45,'LineStyle', 'none', 'Color', 'k', 'LineWidth', Cap_LineWidth,'CapSize',Cap_Size);
hAxes = gca;
hAxes.XRuler.Axle.LineStyle = 'none';
hAxes.YRuler.Axle.LineStyle = 'none';
y_max = ceil(max(dataset45));
y_max = 2;
% 坐标区调整
set(gca, 'box', 'off', ...                                         % 边框
         'XGrid', 'on', 'YGrid', 'on',...                          % 网格
         'TickDir', 'none', ...                                    % 刻度
         'XMinorTick', 'off', 'YMinorTick', 'off', ...             % 小刻度
         'XColor',X_Color,  'YColor', Y_Color,...                  % 坐标轴颜色
         'YTick', linspace(0,y_max,11),...                         % 刻度位置、间隔
         'Ylim' , [y_start*y_max y_max+y_start_top*y_max], ...     % 坐标轴范围
         'Xticklabel',{},...                                       % X坐标轴刻度标签
         'Yticklabel',{linspace(0,y_max,11)})                      % Y坐标轴刻度标签
% 背景颜色
set(gca,'Color',gca_color)
set(gcf,'Color',gcf_color)
set(gca, 'FontSize', Font_Size);
ylabel('MSE of \gamma', 'FontSize', y_lable_size);
set (gca,'position',[0.15+0.1+0.1+0.1+0.1,0.75-0.23-0.23-0.23,0.08,0.2] )