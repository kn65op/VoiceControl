[N N] = size(wynik);

for i=1:N
    for j=1:N
        wynik2(i,j) = wynik(i,j) > 10;
    end
end

