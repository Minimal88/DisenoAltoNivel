
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Primera parte

% Vector de las componentes
figure
xa = [3.3      6.6     9.9    13.2    16.5    83.5    86.8    90.1    93.4    96.7   100];
ya = [5.5        4       3      2       1       1       2       3       4     5.0    5.5];

subplot(2, 1, 1);
stem(xa, ya, 'filled', '^', 'LineWidth', 1.25);

xlim([0 100]);
xL = xlim; 
yL = ylim; 
line(xL, [0 0],'color','k','linewidth',2) %x-axis 
line([0 0], yL,'color','k','linewidth',2) %y-axis


%set(gca,'XTick',[3.3      6.6     9.9    13.2    16.5    83.5    86.8    90.1    93.4    96.7   100] );
%set(gca,'XTickLabel',[3.3      6.6     9.9    13.2    16.5    83.5    86.8    90.1    93.4    96.7  100], 'FontSize',16);

set(gca,'YTickLabel',[]);

text(3.3, 5.4,'\leftarrow f_i en 3.3 MHz', 'FontSize', 18, 'FontWeight','bold');
text(6.6, 3.5,'\leftarrow 6.6 MHz', 'FontSize', 14);
text(9.9, 2.5,'\leftarrow 9.9 MHz', 'FontSize', 14);
text(13.2, 1.5,'\leftarrow 13.2 MHz', 'FontSize', 14);
text(16.5, 0.5,'\leftarrow 16.5 MHz', 'FontSize', 14);

text(76, 0.5,'83.5 MHz \rightarrow', 'FontSize', 14);
text(79.5, 1.5,'86.8 MHz \rightarrow', 'FontSize', 14);
text(83, 2.5,'90.1 MHz \rightarrow', 'FontSize', 14);
text(86.5, 3.5,'93.4 MHz \rightarrow', 'FontSize', 14);
text(89.75, 4.5,'96.7 MHz \rightarrow', 'FontSize', 14);
text(87, 5.4,'f_s en 100 MHz \rightarrow', 'FontSize', 18, 'FontWeight','bold');

xlabel('Frequency (MHz)','FontSize',20,'FontWeight','bold','Color','b');
ylabel('|A_s(\omega)|','FontSize',20,'FontWeight','bold','Color','b');

title('Frequencies and Harmonics for a 3.3 MHz signal, sampled at 100 MHz', 'FontSize', 18, 'FontWeight','bold');
grid on;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Segunda parte
xb = [0.1   3.2     3.3     3.4     3.5     6.5     6.6     6.7     6.8     9.9     10];
yb = [5.0   3.5     5.5     4.5     3.0     3.0     4.5     5.5     3.5     5       5.5];

subplot(2,1,2);
stem(xb, yb, 'filled', '^', 'LineWidth', 1.25);
xlim([0 10]);
xL = xlim; 
yL = ylim; 
line(xL, [0 0],'color','k','linewidth',2) %x-axis 
line([0 0], yL,'color','k','linewidth',2) %y-axis

set(gca,'YTickLabel',[]);

text(0.1, 3,'\leftarrow 0.1 MHz', 'FontSize', 14);
text(3.3, 5,'\leftarrow f_i en 3.3 MHz', 'FontSize', 18, 'FontWeight','bold');
text(3.4, 4,'\leftarrow 3.4 MHz', 'FontSize', 14);
text(3.5, 2.9,'\leftarrow 3.5 MHz', 'FontSize', 14);
text(2.55, 2.5,'3.2 MHz \rightarrow', 'FontSize', 14);

text(6.7, 5,'\leftarrow 6.6 MHz', 'FontSize', 18, 'FontWeight','bold');
%text(5.8, 3,'6.5 MHz \rightarrow', 'FontSize', 14);
%text(6.7, 2.5,'\leftarrow 6.7 MHz', 'FontSize', 14);

text(8.75, 5.4,'f_s en 10 MHz \rightarrow', 'FontSize', 18, 'FontWeight','bold');
text(9.2, 3,'9.9 MHz \rightarrow', 'FontSize', 14);


xlabel('Frequency (MHz)','FontSize',20,'FontWeight','bold','Color','b');
ylabel('|A_s(\omega)|','FontSize',20,'FontWeight','bold','Color','b');

title('Frequencies and Harmonics for a 3.3 MHz signal, sampled at 10 MHz', 'FontSize', 18, 'FontWeight','bold');
grid on;

