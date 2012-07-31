[N M] = size(after);

for i=1:N
    after(i,:) = after(i,:) ./ max(after(i,:));
end
