[N M] = size(wektor);

wynik = zeros(N,N);

for i = 1:N
    for j=i:N
        for k = 1:M
            wynik(i,j) = wynik(i,j) + abs(wektor(i,k) - wektor(j,k));
        end
        wynik(j,i) = wynik(i,j);
    end
end


