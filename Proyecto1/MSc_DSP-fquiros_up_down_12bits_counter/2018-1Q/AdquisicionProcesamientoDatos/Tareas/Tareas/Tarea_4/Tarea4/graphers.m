% Tarea 4

A = table2array(putty50HZblackman);

[n,p] = size(putty50HZblackman);

x = 1:n;

plot(x, A);

axis([0 2000 35 50]);

xlabel('Time (samples)','FontSize',20,'FontWeight','bold','Color','b');
ylabel('Output Voltage of the VADC8','FontSize',20,'FontWeight','bold','Color','b');

title('Output of the System with 50Hz, Blackman filter', 'FontSize', 18, 'FontWeight','bold');
grid on;