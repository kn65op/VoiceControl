close all
load ALCR.dat
load raw_data.dat
load segments.dat

hold on
plot(ALCR, 'r')
plot(raw_data)
plot(segments, 15, '.')
hold off
