function [beta_part, gamma_part, lambda_best,...
    iter_initial_in, diff_loglikelihood] = logit_matrix_ridge_regression(x, y, n, row_size, col_size, cv_number, coefficients0,...
                                                                tuning_start, tuning_end, tuning_number, eps_initial, iter_max_initial_in, if_fix)
% [beta_part, gamma_part, lambda_best,...
% iter_initial_in, diff_loglikelihood] = logit_matrix_ridge_regression(x_part, y_part, n_part,...
%                                           row_size, col_size, [], [], [], [], [], [], [])
n_part = n;
x_part = x;
y_part = y;
if isempty(cv_number)
    cv_number = 5;
end
if isempty(coefficients0)
    beta0 = rand(row_size,1);
    gamma0 = (1/sqrt(col_size))*rand(col_size,1);
    gamma0(1)=sqrt(1-sum(gamma0.^2));
    coefficients0 = [beta0;gamma0];
end
if isempty(tuning_start)
    tuning_start = 0.1;
end
if isempty(tuning_number)
    tuning_number = 10;
end
if isempty(eps_initial)
    eps_initial = 1e-3;
end
if isempty(iter_max_initial_in)
     iter_max_initial_in = 200;
end
if isempty(if_fix)
     if_fix = 0;
end
if tuning_end == 0
    panduan = 0;
    tuning_end = 2*tuning_start;
else
    panduan = 1;
end
pai_gamma = zeros(row_size*col_size);
for i = 1:(row_size*col_size)
    if mod(i,row_size)~=0
        pai_gamma(((floor(i/row_size)+1)+(mod(i,row_size)-1)*col_size),i) = 1;
    else
        pai_gamma((floor(i/row_size)+(mod((i-1),row_size))*col_size),i) = 1;
    end
end
pai_gamma = pai_gamma';
beta0_part = coefficients0((1:row_size),1);
gamma0_part = coefficients0(((row_size+1):end),1);
beta_part = beta0_part;
gamma_part = gamma0_part;
while (panduan == 0)
tuning_end = 2*tuning_end;
tuning_choice = linspace(tuning_start,tuning_end,3);
tuning_matrix = zeros(length(tuning_choice),1);
beta_likelihood = kron(eye(n_part),beta_part');
x_likelihood = reshape(permute(x_part, [1,3,2]), row_size * n_part, col_size);
eta_likelihood = beta_likelihood*x_likelihood*gamma_part;
log_likelihood0 = -sum(y_part.*eta_likelihood-log(1+exp(eta_likelihood)))+...
                    0.5*tuning_choice(1)*(norm(beta_part).^2+norm(gamma_part).^2);
diff_loglikelihood = 1;
C2 = zeros(row_size,1);
C1 = zeros(col_size,1);
M2 = zeros(row_size,row_size);
M1 = zeros(col_size,col_size);
x_part_reshape = reshape(x_part,row_size*col_size,n_part);
for t = 1:length(tuning_choice)
    lambda_tuning = tuning_choice(t);
    batch_size = floor(n_part/cv_number);
    for u = 1:cv_number
        if u==cv_number
            n_test = n_part-(u-1)*batch_size;%n_batch为测试集样本数
            n_train = n_part - n_test;
            index = true(n_part,1);
            index((((u-1)*batch_size)+1):end)=false;
            x_test = x_part(:,:,(((u-1)*batch_size)+1):end);
            y_test = y_part((((u-1)*batch_size)+1):end);
            x_train = x_part(:,:,index);
            y_train = y_part(index);
        else
            n_test = batch_size;%n_batch为测试集样本数
            n_train = n_part - n_test;
            index = true(n_part,1);
            index((((u-1)*batch_size)+1):(u*batch_size))=false;
            x_test = x_part(:,:,(((u-1)*batch_size)+1):(u*batch_size));
            y_test = y_part((((u-1)*batch_size)+1):(u*batch_size));
            x_train = x_part(:,:,index);
            y_train = y_part(index);
        end
        beta_part = beta0_part;
        gamma_part = gamma0_part;
        beta_likelihood_train = kron(eye(n_train),beta_part');
        x_likelihood_train = reshape(permute(x_train, [1,3,2]), row_size * n_train, col_size);
        eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
        log_likelihood0 = -sum(y_train.*eta_likelihood_train-log(1+exp(eta_likelihood_train)))+...
            0.5*lambda_tuning*(norm(beta_part).^2+norm(gamma_part).^2);
        log_likelihood = log_likelihood0 + 1;
        diff_loglikelihood = 1;
        x_part_reshape_train = reshape(x_train,row_size*col_size,n_train);
        iter_initial_in = 0;
        while (diff_loglikelihood > eps_initial&&(iter_initial_in<=iter_max_initial_in))
            beta_likelihood_train = kron(eye(n_train),beta_part');
            eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
            eta_likelihood_mat_train = diag((1 + exp(beta_likelihood_train*x_likelihood_train*gamma_part)).^(-1));
            eta_likelihood_mat2_train = diag(sqrt(exp(beta_likelihood_train*x_likelihood_train*gamma_part)));
            C2 = kron(gamma_part',eye(row_size))*x_part_reshape_train*(((eta_likelihood_mat2_train.^2).*eta_likelihood_mat_train) - diag(y_train))*ones(n_train,1)...
                +lambda_tuning*beta_part;
            M2 = kron(gamma_part',eye(row_size))*(x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))*(x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))'*kron(gamma_part',eye(row_size))'...
                +lambda_tuning*eye(row_size);
            newton_train = pinv(M2)*C2;
            if norm(newton_train)>1
                newton_train = newton_train/norm(newton_train);
            end
            beta_part = beta_part - newton_train;
            beta_likelihood_train = kron(eye(n_train),beta_part');
            eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
            eta_likelihood_mat_train = diag((1 + exp(beta_likelihood_train*x_likelihood_train*gamma_part)).^(-1));
            eta_likelihood_mat2_train = diag(sqrt(exp(beta_likelihood_train*x_likelihood_train*gamma_part)));
            C1 = (kron(beta_part',eye(col_size))*pai_gamma')*x_part_reshape_train*(((eta_likelihood_mat2_train.^2).*eta_likelihood_mat_train) - diag(y_train))*ones(n_train,1)...
                +lambda_tuning*gamma_part;
            M1 = (kron(beta_part',eye(col_size))*pai_gamma')*(x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))*(x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))'*(kron(beta_part',eye(col_size))*pai_gamma')'...
                +lambda_tuning*eye(col_size);
            newton_train = pinv(M1)*C1;
            if norm(newton_train)>1
                newton_train = newton_train/norm(newton_train);
            end
            gamma_part = gamma_part - newton_train;
            guiyi = sign(gamma_part(1))*sqrt((sqrt(row_size)/sqrt(col_size))*(norm(gamma_part)/norm(beta_part)));
            gamma_part = gamma_part/guiyi;
            beta_part = beta_part*guiyi;
            beta_likelihood_train = kron(eye(n_train),beta_part');
            eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
            log_likelihood  = -sum(y_train.*eta_likelihood_train-log(1+exp(eta_likelihood_train)))+...
                0.5*lambda_tuning*(norm(beta_part).^2+norm(gamma_part).^2);
            diff_loglikelihood = abs(log_likelihood-log_likelihood0);
            log_likelihood0 = log_likelihood;
            iter_initial_in = iter_initial_in + 1;
            beta_part;
        end
        beta_likelihood_test = kron(eye(n_test),beta_part');
        x_likelihood_test = reshape(permute(x_test, [1,3,2]), row_size * n_test, col_size);
        eta_likelihood_test = beta_likelihood_test*x_likelihood_test*gamma_part;
        tuning_matrix(t,1) = tuning_matrix(t,1)-sum(y_test.*eta_likelihood_test-log(1+exp(eta_likelihood_test)));
    end
end
[~,index_min]=min(tuning_matrix);
if index_min ~= 3
    panduan = 1;
end
end
if if_fix == 0
tuning_choice = linspace(tuning_start,tuning_end,tuning_number);
tuning_matrix = zeros(length(tuning_choice),1);
beta_likelihood = kron(eye(n_part),beta_part');
x_likelihood = reshape(permute(x_part, [1,3,2]), row_size * n_part, col_size);
eta_likelihood = beta_likelihood*x_likelihood*gamma_part;
log_likelihood0 = -sum(y_part.*eta_likelihood-log(1+exp(eta_likelihood)))+...
                    0.5*tuning_choice(1)*(norm(beta_part).^2+norm(gamma_part).^2);
diff_loglikelihood = 1;
C2 = zeros(row_size,1);
C1 = zeros(col_size,1);
M2 = zeros(row_size,row_size);
M1 = zeros(col_size,col_size);
x_part_reshape = reshape(x_part,row_size*col_size,n_part);
for t = 1:length(tuning_choice)
    lambda_tuning = tuning_choice(t);
    batch_size = floor(n_part/cv_number);
    for u = 1:cv_number
        if u==cv_number
            n_test = n_part-(u-1)*batch_size;%n_batch为测试集样本数
            n_train = n_part - n_test;
            index = true(n_part,1);
            index((((u-1)*batch_size)+1):end)=false;
            x_test = x_part(:,:,(((u-1)*batch_size)+1):end);
            y_test = y_part((((u-1)*batch_size)+1):end);
            x_train = x_part(:,:,index);
            y_train = y_part(index);
        else
            n_test = batch_size;%n_batch为测试集样本数
            n_train = n_part - n_test;
            index = true(n_part,1);
            index((((u-1)*batch_size)+1):(u*batch_size))=false;
            x_test = x_part(:,:,(((u-1)*batch_size)+1):(u*batch_size));
            y_test = y_part((((u-1)*batch_size)+1):(u*batch_size));
            x_train = x_part(:,:,index);
            y_train = y_part(index);
        end
        beta_part = beta0_part;
        gamma_part = gamma0_part;
        beta_likelihood_train = kron(eye(n_train),beta_part');
        x_likelihood_train = reshape(permute(x_train, [1,3,2]), row_size * n_train, col_size);
        eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
        log_likelihood0 = -sum(y_train.*eta_likelihood_train-log(1+exp(eta_likelihood_train)))+...
            0.5*lambda_tuning*(norm(beta_part).^2+norm(gamma_part).^2);
        log_likelihood = log_likelihood0 + 1;
        diff_loglikelihood = 1;
        x_part_reshape_train = reshape(x_train,row_size*col_size,n_train);
        iter_initial_in = 0;
        while (diff_loglikelihood > eps_initial&&(iter_initial_in<=iter_max_initial_in))
            beta_likelihood_train = kron(eye(n_train),beta_part');
            eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
            eta_likelihood_mat_train = diag((1 + exp(beta_likelihood_train*x_likelihood_train*gamma_part)).^(-1));
            eta_likelihood_mat2_train = diag(sqrt(exp(beta_likelihood_train*x_likelihood_train*gamma_part)));
            C2 = kron(gamma_part',eye(row_size))*x_part_reshape_train*(((eta_likelihood_mat2_train.^2).*eta_likelihood_mat_train) - diag(y_train))*ones(n_train,1)...
                +lambda_tuning*beta_part;
            M2 = kron(gamma_part',eye(row_size))*(x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))*(x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))'*kron(gamma_part',eye(row_size))'...
                +lambda_tuning*eye(row_size);
            newton_train = pinv(M2)*C2;
            if norm(newton_train)>1
                newton_train = newton_train/norm(newton_train);
            end
            beta_part = beta_part - newton_train;
            beta_likelihood_train = kron(eye(n_train),beta_part');
            eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
            eta_likelihood_mat_train = diag((1 + exp(beta_likelihood_train*x_likelihood_train*gamma_part)).^(-1));
            eta_likelihood_mat2_train = diag(sqrt(exp(beta_likelihood_train*x_likelihood_train*gamma_part)));
            C1 = (kron(beta_part',eye(col_size))*pai_gamma')*x_part_reshape_train*(((eta_likelihood_mat2_train.^2).*eta_likelihood_mat_train) - diag(y_train))*ones(n_train,1)...
                +lambda_tuning*gamma_part;
            M1 = (kron(beta_part',eye(col_size))*pai_gamma')*(x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))*(x_part_reshape_train*(eta_likelihood_mat_train.*eta_likelihood_mat2_train))'*(kron(beta_part',eye(col_size))*pai_gamma')'...
                +lambda_tuning*eye(col_size);
            newton_train = pinv(M1)*C1;
            if norm(newton_train)>1
                newton_train = newton_train/norm(newton_train);
            end
            gamma_part = gamma_part - newton_train;
            guiyi = sign(gamma_part(1))*sqrt((sqrt(row_size)/sqrt(col_size))*(norm(gamma_part)/norm(beta_part)));
            gamma_part = gamma_part/guiyi;
            beta_part = beta_part*guiyi;
            beta_likelihood_train = kron(eye(n_train),beta_part');
            eta_likelihood_train = beta_likelihood_train*x_likelihood_train*gamma_part;
            log_likelihood  = -sum(y_train.*eta_likelihood_train-log(1+exp(eta_likelihood_train)))+...
                0.5*lambda_tuning*(norm(beta_part).^2+norm(gamma_part).^2);
            diff_loglikelihood = abs(log_likelihood-log_likelihood0);
            log_likelihood0 = log_likelihood;
            iter_initial_in = iter_initial_in + 1;
        end
        beta_likelihood_test = kron(eye(n_test),beta_part');
        x_likelihood_test = reshape(permute(x_test, [1,3,2]), row_size * n_test, col_size);
        eta_likelihood_test = beta_likelihood_test*x_likelihood_test*gamma_part;
        tuning_matrix(t,1) = tuning_matrix(t,1)-sum(y_test.*eta_likelihood_test-log(1+exp(eta_likelihood_test)));
    end
end


[~,index_min]=min(tuning_matrix);
lambda_best = tuning_choice(index_min);

else
    lambda_best = tuning_end;
end
iter_initial_in = 0;
beta_part = beta0_part;
gamma_part = gamma0_part;
beta_likelihood = kron(eye(n_part),beta_part');
x_likelihood = reshape(permute(x_part, [1,3,2]), row_size * n_part, col_size);
eta_likelihood = beta_likelihood*x_likelihood*gamma_part;
log_likelihood0 = -sum(y_part.*eta_likelihood-log(1+exp(eta_likelihood)))+...
                    0.5*lambda_best*(norm(beta_part).^2+norm(gamma_part).^2);
log_likelihood = log_likelihood0 + 1;
diff_loglikelihood = 1;
C2 = zeros(row_size,1);
C1 = zeros(col_size,1);
M2 = zeros(row_size,row_size);
M1 = zeros(col_size,col_size);
x_part_reshape = reshape(x_part,row_size*col_size,n_part);
while (diff_loglikelihood > eps_initial&&(iter_initial_in<=iter_max_initial_in))
    beta_likelihood = kron(eye(n_part),beta_part');
    eta_likelihood = beta_likelihood*x_likelihood*gamma_part;
    eta_likelihood_mat = diag((1 + exp(beta_likelihood*x_likelihood*gamma_part)).^(-1));
    eta_likelihood_mat2 = diag(sqrt(exp(beta_likelihood*x_likelihood*gamma_part)));
    C2 = kron(gamma_part',eye(row_size))*x_part_reshape*(((eta_likelihood_mat2.^2).*eta_likelihood_mat) - diag(y_part))*ones(n_part,1)...
        +lambda_best*beta_part;
    M2 = kron(gamma_part',eye(row_size))*(x_part_reshape*(eta_likelihood_mat.*eta_likelihood_mat2))*(x_part_reshape*(eta_likelihood_mat.*eta_likelihood_mat2))'*kron(gamma_part',eye(row_size))'...
        +lambda_best*eye(row_size);
    newton = pinv(M2)*C2;
    if norm(newton)>1
        newton = newton/norm(newton);
    end
    beta_part = beta_part - newton;
    beta_likelihood = kron(eye(n_part),beta_part');
    eta_likelihood = beta_likelihood*x_likelihood*gamma_part;
    eta_likelihood_mat = diag((1 + exp(beta_likelihood*x_likelihood*gamma_part)).^(-1));
    eta_likelihood_mat2 = diag(sqrt(exp(beta_likelihood*x_likelihood*gamma_part)));
    C1 = (kron(beta_part',eye(col_size))*pai_gamma')*x_part_reshape*(((eta_likelihood_mat2.^2).*eta_likelihood_mat) - diag(y_part))*ones(n_part,1)...
        +lambda_best*gamma_part;
    M1 = (kron(beta_part',eye(col_size))*pai_gamma')*(x_part_reshape*(eta_likelihood_mat.*eta_likelihood_mat2))*(x_part_reshape*(eta_likelihood_mat.*eta_likelihood_mat2))'*(kron(beta_part',eye(col_size))*pai_gamma')'...
        +lambda_best*eye(col_size);
    newton = pinv(M1)*C1;
    if norm(newton)>1
        newton = newton/norm(newton);
    end
    gamma_part = gamma_part - newton;
    guiyi = sign(gamma_part(1))*sqrt((sqrt(row_size)/sqrt(col_size))*(norm(gamma_part)/norm(beta_part)));
    gamma_part = gamma_part/guiyi;
    beta_part = beta_part*guiyi;
    beta_likelihood = kron(eye(n_part),beta_part');
    eta_likelihood = beta_likelihood*x_likelihood*gamma_part;
    log_likelihood  = -sum(y_part.*eta_likelihood-log(1+exp(eta_likelihood)))+...
        0.5*lambda_best*(norm(beta_part).^2+norm(gamma_part).^2);
    diff_loglikelihood = abs(log_likelihood-log_likelihood0);
    log_likelihood0 = log_likelihood;
    iter_initial_in = iter_initial_in + 1;
end
end