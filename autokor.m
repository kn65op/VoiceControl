[m N] = size(mini);

res = zeros(N,1024);

for i=1:N-1
    r = fft(xcorr(raw_data(mini(i):mini(i+1))), 1024);
    res(i, :) = abs(r);
end
