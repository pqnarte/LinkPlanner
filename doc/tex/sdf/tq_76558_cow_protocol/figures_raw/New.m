
%% Step 1
figure('units','normalized','outerposition',[0 0 0.5 1])
x = 0:0.01:1;
subplot(3,1,1)
y = gaussmf(x,[0.005 0.25]);
plot(x,y,    'LineWidth',5)
grid on
title ('|0\rangle')
ylim([0 1])
ax = gca; % current axes
ax.FontSize = 25;

subplot(3,1,2)
y = gaussmf(x,[0.005 0.25+0.5]);
plot(x,y,    'LineWidth',5)
grid on
title ('|1\rangle')
xlabel('Time(ns)')
ylim([0 1])
ax = gca; % current axes
ax.FontSize = 25;

subplot(3,1,3)
y = gaussmf(x,[0.005 0.25]);
y2 = gaussmf(x,[0.005 0.25+0.5]);
plot(x,y+y2,    'LineWidth',5)
grid on
title ('|d\rangle')
ylim([0 1])
ax = gca; % current axes
ax.FontSize = 25;
%% Step 2
figure('units','normalized','outerposition',[0 0 1 1])
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
%% COW Protocol
figure('units','normalized','outerposition',[0 0 0.5 1])
x = 0:0.01:2;

subplot(2,1,1)
y = gaussmf(x,[0.005 0.25+1]);
y2 = gaussmf(x,[0.005 0.25+0.5]);
plot(x,y+y2,'LineWidth',5)
grid on
title ('|1\rangle:|0\rangle')
ylim([0 1])
xlim([0 2])
ax = gca; % current axes
ax.FontSize = 25;

subplot(2,1,2)
x = 0:0.01:2;
y = gaussmf(x,[0.005 0.25+1]);
y2 = gaussmf(x,[0.005 0.25+0.5+1]);
plot(x,y+y2,'LineWidth',5)
grid on
title ('|d\rangle')
ylim([0 1])
xlim([0 2])
ax = gca; % current axes
ax.FontSize = 25;
%% Dm3
figure('units','normalized','outerposition',[0 0 0.82 1])
p=0.1;
size=10;
x=0:0.01:size;
%A=rand(size,1);
A=[0.6 0.6 0.4 0 0.6 0.4 0.6 0.4 0 0.4];
Bdata=zeros(size,1);
DM=zeros(2*size,1);
DM1=zeros(2*size,1);
DM2=zeros(2*size,1);
j=1;


for i=1:size
    if A(i)<p
        Bdata(i)=2;
        DM(j)=1;
        DM(j+1)=1;
    elseif A(i)<(1-p)/2+p
        Bdata(i)=1;
        DM(j)=1;
        DM(j+1)=0;
    else
        Bdata(i)=0;
        DM(j)=0;
        DM(j+1)=1;
    end
    j=j+2;
end

for i=2:2*size
   if DM(i)+DM(i-1)==2
       DM1(i)=0;
       DM2(i)=1;
   elseif DM(i)+DM(i-1)==1
       DM1(i)=1;
       DM2(i)=0;
   else
       DM1(i)=0;
       DM2(i)=0;
   end
end

yDM=0;
yDM1=0;
yDM2=0;


for j=1:2*size
    if DM(j)==1
    yDM = yDM + gaussmf(x,[0.005 j/2-0.25]);
    end
    if DM2(j)==1
    yDM2 = yDM2 + gaussmf(x,[0.005 j/2-0.25]);
    end
    if DM1(j)==1
    yDM1 = yDM1 + gaussmf(x,[0.005 j/2-0.25]);
    end
end

subplot(3,1,1)
plot(x,yDM,'LineWidth',5)
grid on
xlabel('Time(ns)')
ylabel('DM')
title('0          0          1          d          0          1          0          1          d          1')
ax = gca; % current axes
ax.FontSize = 25;
subplot(3,1,3)

plot(x,yDM1,'k','LineWidth',5)
grid on
xlabel('Time(ns)')
ylabel('DM1')
ax = gca; % current axes
ax.FontSize = 25;
subplot(3,1,2)
plot(x,yDM2,'r','LineWidth',5)
grid on
xlabel('Time(ns)')
ylabel('DM2')
ax = gca; % current axes
ax.FontSize = 25;