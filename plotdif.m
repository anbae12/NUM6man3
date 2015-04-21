clear;
clc;
close all
M=csvread('data.csv');
%{
figure(1)
plot(M(:,1),'r')
hold on
plot(M(:,2),'b')
ylabel('[km]')
xlabel('Days')
legend('r1','r2','Location','northeast')
print(gcf,'-depsc','-tiff','Rapport/graphics/cross.eps')
figure(2)
plot(M(:,3),'m')
ylabel('[rad]')
xlabel('Days')
legend('delta angle','Location','northeast')
print(gcf,'-depsc','-tiff','Rapport/graphics/phase.eps')
%}
figure(3)
subplot(2,1,1)
plot(M(:,1),'r')
hold on
plot(M(:,2),'b')
ylabel('[km]')
xlabel('Days')
legend('r1','r2','Location','northeast')
subplot(2,1,2)
plot(M(:,3),'m')
ylabel('[rad]')
xlabel('Days')
legend('delta angle','Location','northeast')
print(gcf,'-depsc','-tiff','Rapport/graphics/subplot.eps')