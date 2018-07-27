%Tarea 3%

A = table2array(putty);

[n,p] = size(puttyDone);

x = 1:n;

%plot(x,puttyDone);

%xlabel('Time(s)','FontSize',20,'FontWeight','bold','Color','b');
%ylabel('Amplitude','FontSize',20,'FontWeight','bold','Color','b');

xdft = fft(puttyDone);

Fs = 2000;

psdx = (1/(Fs*n)) * abs(xdft).^2;
psdx(2:end-1) = 2*psdx(2:end-1);
freq = 0:Fs/length(x):Fs/2;

plot(x,10*log10(psdx))
grid on

title('Power Spectral Density','FontSize',20,'FontWeight','bold','Color','black');

xlabel('Frecuency (Hz)','FontSize',20,'FontWeight','bold','Color','b');
ylabel('Spectral Density (dB/Hz)','FontSize',20,'FontWeight','bold','Color','b');


