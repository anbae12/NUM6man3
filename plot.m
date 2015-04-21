clear;
clc;
close all


%M=csvread('data.csv');



M=[2,3,4,5]
plot(M)

%{
hold on
plot([-50 length(M)+50],[Actual Actual],'r',[-50 length(M)+50],[MEAN_Measurement MEAN_Measurement],'g')
title('Test 4.1')
legend('Measured  distance','Distance','Sample mean','Location','southwest')
ylim([ylim_min-temp ylim_max+temp]) % tjek op på denne om alle data er vist.
xlim([-100 length(M)+100]) % tjek op på denne om alle data er vist.
xlabel('Sample')
ylabel('Altitude [cm]')
%print(gcf,'-depsc','-tiff','LIDARCal41.eps')
%}
