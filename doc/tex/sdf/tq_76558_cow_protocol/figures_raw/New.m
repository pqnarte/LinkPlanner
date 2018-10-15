%% Step 1
x = 0:0.01:1;
subplot(1,3,1)
y = gaussmf(x,[0.075 0.25]);
plot(x,y,    'LineWidth',5)
grid on
title ('|0\rangle')
ax = gca; % current axes
ax.FontSize = 20;
ylim([0 1])
subplot(1,3,2)
y = gaussmf(x,[0.075 0.25+0.5]);
plot(x,y,    'LineWidth',5)
grid on
title ('|1\rangle')
ax = gca; % current axes
ax.FontSize = 20;
xlabel('Time(ns)')
ylim([0 1])
subplot(1,3,3)
y = gaussmf(x,[0.075 0.25]);
y2 = gaussmf(x,[0.075 0.25+0.5]);
plot(x,y+y2,    'LineWidth',5)
grid on
title ('|d\rangle')
ax = gca; % current axes
ax.FontSize = 20;
ylim([0 1])
%% Step 2
%figure('units','normalized','outerposition',[0 0 1 0.5])
x = 0:0.01:10;
subplot(2,1,1)

y = gaussmf(x,[0.075 0.25+1])+...
    gaussmf(x,[0.075 0.25+0.5+2])+...
    gaussmf(x,[0.075 0.25+3])+...
    gaussmf(x,[0.075 0.25+4])+...
    gaussmf(x,[0.075 0.25+5])+...
    gaussmf(x,[0.075 0.25+5+0.5])+...
    gaussmf(x,[0.075 0.25+6])+...
    gaussmf(x,[0.075 0.25+7])+...
    gaussmf(x,[0.075 0.25+7+0.5])+...
    gaussmf(x,[0.075 0.25+8+0.5])+...
    gaussmf(x,[0.075 0.25+9+0.5]);

plot(x,y,'LineWidth',5)
grid on
title ('Measured before UZMI')
ax = gca; % current axes
ax.FontSize = 10;
xlabel('Time(ns)')

subplot(2,1,2)

y = gaussmf(x,[0.075 0.25+1])+...
    gaussmf(x,[0.075 0.25+1+0.5])+...
    gaussmf(x,[0.075 0.25+2+0.5])+...
    gaussmf(x,[0.075 0.25+3+0.5])+...
    gaussmf(x,[0.075 0.25+4])+...
    gaussmf(x,[0.075 0.25+4+0.5])+...
    gaussmf(x,[0.075 0.25+5])+...
    gaussmf(x,[0.075 0.25+6+0.5])+...
    gaussmf(x,[0.075 0.25+7])+...
    gaussmf(x,[0.075 0.25+8])+...
    gaussmf(x,[0.075 0.25+8+0.5])+...
    gaussmf(x,[0.075 0.25+9])+...
    gaussmf(x,[0.075 0.25+9+0.5]);

plot(x,y,'LineWidth',5)
grid on
title ('Measured in SPD_2')
ax = gca; % current axes
ax.FontSize = 10;
xlabel('Time(ns)')
