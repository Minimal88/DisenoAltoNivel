
rng default
Fs = 44000;
t = 0:1/Fs:4-1/Fs;
fc = 10000;
x_0 = [0    10000    20000   30000   40000   50000 ];
y_0 = [0    10       8       6       4       2     ];



subplot(2, 1, 1);
stem(x_0, y_0, 'filled', '^', 'LineWidth', 1.25);
grid on;
set(gca,'XTick',[0 5000 10000 15000 20000 25000 30000 35000 40000 45000 50000 55000 60000] );
set(gca,'XTickLabel',[0 5 10 15 20 25 30 35 40 45 50 55 60], 'FontSize',16);

set(gca,'YTickLabel',[]);
set(gca,'YTickLabel',[0 5 10 15], 'FontSize',16);

title('Harmonics for a 10kHz signal, sampled at 44 kHz', 'FontSize', 18, 'FontWeight','bold');
xlabel('Frequency (kHz)','FontSize',20,'FontWeight','bold','Color','b');
ylabel('|A_s(\omega)|','FontSize',20,'FontWeight','bold','Color','b');


x = cos(2*pi*fc*t) + sin(2*pi*2*fc*t) + sin(2*pi*3*fc*t) + sin(2*pi*4*fc*t) + sin(2*pi*5*fc*t) + randn(size(t));


N = length(x);
disp(N);
xdft = fft(x);
xdft = xdft(1:N);

psdx = (1/(Fs*N)) * abs(xdft).^2;
psdx(2:end-1) = 2*psdx(2:end-1);
freq = 0:Fs/N:Fs-Fs/N;


%plot(freq,10*log10(psdx))
subplot(2,1,2);
plot(freq,psdx);
xlim([0 55000]);

x_1 = [50000];
y_1 = [2];
hold on;
stem(x_1, y_1, 'Marker','none', 'Color','b');
grid on;

set(gca,'YTickLabel',[]);
set(gca,'XTick',[0 5000 10000 15000 20000 25000 30000 35000 40000 45000 50000] );
set(gca,'XTickLabel',[0 5 10 15 20 25 30 35 40 45 50], 'FontSize',16);

text(14000, 1.3,'harmonic 20 kHz \rightarrow', 'FontSize', 14);
text(24000, 1.3,'harmonic 30 kHz \rightarrow', 'FontSize', 14);
text(40000, 1.3,'\leftarrow harmonic 40 kHz', 'FontSize', 14);
text(50000, 1.3,'\leftarrow harmonic 50 kHz', 'FontSize', 14);

title('Power Spectral Density for a 10kHz signal, sampled at 44 kHz', 'FontSize', 18, 'FontWeight','bold');
xlabel('Frequency (kHz)','FontSize',20,'FontWeight','bold','Color','b');
ylabel('|PSD|','FontSize',20,'FontWeight','bold','Color','b');