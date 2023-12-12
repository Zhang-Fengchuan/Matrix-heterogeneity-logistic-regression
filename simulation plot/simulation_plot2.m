%% 画三维空间示意图
subplot(1,2,1)
for i = 1:sample_size
    [U,D,V]=svd(x(:,:,i));
    D = diag(D);
    xx(i,1) = D(1);
    yy(i,1) = D(2);
    zz(i,1) = D(3);
end
%取每个样本点的svd前三个特征值作为空间坐标，按照真实类别进行位置拉伸
xx(index_ori == 1) = 1*xx(index_ori == 1);
yy(index_ori == 1) = 1*yy(index_ori == 1);
zz(index_ori == 1) = 1*zz(index_ori == 1);
xx(index_ori == 2) = 2*xx(index_ori == 2);
yy(index_ori == 2) = 2*yy(index_ori == 2);
zz(index_ori == 2) = 2*zz(index_ori == 2);
xx(index_ori == 3) = 3*xx(index_ori == 3);
yy(index_ori == 3) = 3*yy(index_ori == 3);
zz(index_ori == 3) = 3*zz(index_ori == 3);
% 创建一个图形
subplot(1,4,1)
scatter3(xx(index_ori == 1), yy(index_ori == 1),zz(index_ori == 1),30,'filled');
hold on;
scatter3(xx(index_ori == 2), yy(index_ori == 2),zz(index_ori == 2),30,'filled');
scatter3(xx(index_ori == 3), yy(index_ori == 3), zz(index_ori == 3),30,'filled');
hold off
xlim([0, 30])
ylim([0, 25])
zlim([2, 16])
% 设置视图的方位角和仰角
az = 66; % 方位角，例如 45 度
el = 13; % 仰角，例如 30 度
view(az, el);
x = Data_x(:,:,:,yangbencishu);%将第1次模拟的矩阵变量抽出来记为x（维度为p*q*n）
subplot(1,4,2)
scatter3(xx(index_end2 == 1), yy(index_end2 == 1),zz(index_end2 == 1),30,'filled');
hold on;
scatter3(xx(index_end2 == 2), yy(index_end2 == 2),zz(index_end2 == 2),30,'filled');
scatter3(xx(index_end2 == 3), yy(index_end2 == 3), zz(index_end2 == 3),30,'filled');
scatter3(xx(index_end2 == 4), yy(index_end2 == 4), zz(index_end2 == 4),30,'filled');
scatter3(xx(index_end2 == 5), yy(index_end2 == 5), zz(index_end2 == 5),30,'filled');
hold off;
xlim([0, 30])
ylim([0, 25])
zlim([2, 16])
view(az, el);
subplot(1,4,3)
scatter3(xx(index_end3 == 1), yy(index_end3 == 1),zz(index_end3 == 1),30,'filled');
hold on;
scatter3(xx(index_end3 == 2), yy(index_end3 == 2),zz(index_end3 == 2),30,'filled');
scatter3(xx(index_end3 == 3), yy(index_end3 == 3), zz(index_end3 == 3),30,'filled');
scatter3(xx(index_end3 == 4), yy(index_end3 == 4), zz(index_end3 == 4),30,'filled');
scatter3(xx(index_end3 == 5), yy(index_end3 == 5), zz(index_end3 == 5),30,'filled');
hold off;
xlim([0, 30])
ylim([0, 25])
zlim([2, 16])
view(az, el);
subplot(1,4,4)
scatter3(xx(index_end4 == 1), yy(index_end4 == 1),zz(index_end4 == 1),30,'filled');
hold on;
scatter3(xx(index_end4 == 2), yy(index_end4 == 2),zz(index_end4 == 2),30,'filled');
scatter3(xx(index_end4 == 3), yy(index_end4 == 3), zz(index_end4 == 3),30,'filled');
hold off;
xlim([0, 30])
ylim([0, 25])
zlim([2, 16])
view(az, el);