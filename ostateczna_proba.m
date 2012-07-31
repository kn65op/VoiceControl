[N M] = size(signal);

okno = signal .* hamming(N);

kor = xcorr(okno);

fo = abs(fft(kor));

lo = log(fo ./ max(fo));


