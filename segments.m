[N, M] = size (wynik2);

ok = 0;
mins = 1;
i = 1000;

while i < 40000
    if (wynik2(i) == min(wynik2(i - 160: i + 160)))
        mini(mins) = i;
        mins = mins + 1;
        ok = 0;
        i = i + 192 - 160;
    end
    i  = i + 1;
end
