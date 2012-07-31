[N M] = size(fourier);

wynik = zeros(N,N);

for i = 1:N
    for j=i:N
        for k = 1:M
            wynik(i,j) = wynik(i,j) + abs(fourier(i,k) - fourier(j,k));
        end
        wynik(j,i) = wynik(i,j);
    end
end


