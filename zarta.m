[N m] = size(kor);

tdomain = zeros(N,N);
ffts = zeros(N,N);

for i=1:N
    tdomain(i,i) = kor(i);
    ffts(i,:) = abs(fft(tdomain(i,:)));
end

wynik = zeros(N,1);

for i=1:N
    wynik(i) = sum(ffts(:,i));
end
