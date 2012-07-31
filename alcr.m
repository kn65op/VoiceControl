[N M] = size(raw_data);
wynik = zeros(N,1);

levels = zeros(50, 1);
levels(1) = 0.33;
levels(50) = 99.66;
levels(2) = 0.66;
levels(49) = 99.33;
levels(3) = 1;
levels(48) = 99;
for i=4:21
    levels(i) = i * 10 / 21;
    levels(50 - i + 1) = i * 10 /21 + 80; 
end

for i=22:1:29
    levels(i) = (i - 21) * 70 / 8 + 10;
end


for i=2:N
    for j=1:50
        if ((abs(raw_data(i)) - levels(j)) * (abs(raw_data(i-1)) - levels(j)) < 0)
            wynik(i) = wynik(i) + 1;
        end
    end
end

wynik2 = zeros(N,1);

for i=101:N-100
    wynik2(i) = mean(wynik(i-100:i+100));
end
