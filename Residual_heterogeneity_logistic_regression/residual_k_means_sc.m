function [class, k_best] = residual_k_means_sc(y, k_min, k_max, num_time, sample_size)
k_store = zeros((k_max-k_min+1), 1);
for i = k_min:k_max
    a = 0;
    for j = 1:num_time
        rng(j);
        clust = kmeans(y, i, 'Distance','sqeuclidean');
        a = a + mean(silhouette(y, clust, "Euclidean"));
    end
    a = a/num_time;
    k_store(i, 1) = a;
end
panding = 0;
while panding < 1
k_best = k_min + find(k_store == max(k_store)) - 1;
class = kmeans(y, k_best);

index_store = cell(k_best, 1);
length_min = zeros(k_best, 1);
for i = 1: k_best
    index_store{i,1} = find(class==i);
    length_min(i,1) = length(index_store{i});
end
if min(length_min) < (0.05*sample_size)
    k_store(find(k_store == max(k_store)), 1) = 0;
else
    panding = panding + 1;
end
end
end