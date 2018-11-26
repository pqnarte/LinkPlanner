clc
clear
X=0:0.02:1;

TQBER=zeros(length(X),1);
TKeyLength=zeros(length(X),1);
TKeyPercent=zeros(length(X),1);
i=1;
%for efficE=X*0.1

NAlice=10^6; %Logical bits send by Alice
probd=0.10; %Probability of bit being a decoy
efficB=0.1*0.1*0.9; %Efficiency of Detetor from Bob
ProDarkCountBob=10^-5; %Probability of Dark count by Bob
ProDarkCountEve=0; %Probability of Dark count by Eve
QBERTest=10^3; %Amount of bits compared for QBER Test, in this simulation
%they can use the same bit more than once

%Alice Generate
[SendA,DecoyTime]  = AliceGenerating(probd,NAlice);

%Eve IR Attacks
%[SendA] = EveIRAttack(SendA,NAlice,ProDarkCountEve,efficE);

%Bob receives
[ReceivedB,Dfired,DarkCounts]=BobReceiving(efficB,ProDarkCountBob,NAlice,SendA);

%Calculate QBER
[QBER,KeyLength,KeyPercent]=CalculateQBER(DecoyTime,ReceivedB,SendA,NAlice,QBERTest,Dfired);

X=['Without the attack, QBER=',num2str(QBER),', Key Length=',num2str(KeyLength),' and KeyPercent=',num2str(KeyPercent)];
disp(X)
%TQBER(i)=QBER;
%TKeyLength(i)=KeyLength;
%TKeyPercent(i)=KeyPercent;
%i=i+1;
%end

subplot(3,1,1)
plot(X,TQBER)
xlabel ('Eve Efficency')
ylabel ('QBER')
subplot(3,1,2)
plot(X,TKeyLength)
xlabel ('Eve Efficency')
ylabel ('Key Length after QBER')
subplot(3,1,3)
plot(X,TKeyPercent)
xlabel ('Eve Efficency')
ylabel ('Key Percentage of the Alice Data')
%% Functions

function [SendA,DecoyTime]  = AliceGenerating(probd,NAlice)
SendA=zeros(2*NAlice,1);
DecoyTime=SendA;
RandomN=rand(NAlice,1);
for i=1:NAlice
    if RandomN(i,1)<=probd
        SendA(2*i-1)=1;
        SendA(2*i)=1;
        DecoyTime(2*i-1)=1;
        DecoyTime(2*i)=1;
    elseif RandomN(i,1)<=probd+(1-probd)/2
        SendA(2*i-1)=0;
        SendA(2*i)=1;
    else
        SendA(2*i-1)=1;
        SendA(2*i)=0;
    end
end
end

function [SendA] = EveIRAttack(SendA,NAlice,ProDarkCountEve,efficE)
RandomN3=rand(NAlice*2,2);
ReceivedE=zeros(2*NAlice,1);
DarkCounts=0;
for j=1:NAlice*2
    if RandomN3(j,1)<=efficE
        if SendA(j)==1
            ReceivedE(j)=1;
        end
    end
    
    %DarkCounts
    if ReceivedE(j)==0
        if RandomN3(j,2)<=ProDarkCountEve
            ReceivedE(j)=1;
            DarkCounts=DarkCounts+1;
        end
    end
end
SendA=ReceivedE;

end


function [ReceivedB,Dfired,DarkCounts]= BobReceiving(efficB,ProDarkCountBob,NAlice,SendA)
RandomN3=rand(NAlice*2,2);
ReceivedB=zeros(2*NAlice,1);
Dfired=zeros(2*NAlice,1);
DarkCounts=0;
for j=1:NAlice*2
    if RandomN3(j,1)<=efficB
        if SendA(j)==1
            ReceivedB(j)=1;
            Dfired(j)=1;
        end
    end
    
    %DarkCounts
    if ReceivedB(j)==0
        if RandomN3(j,2)<=ProDarkCountBob
            Dfired(j)=1;
            ReceivedB(j)=1;
            DarkCounts=DarkCounts+1;
        end
    end
end
end

function [QBER,KeyLength,KeyPercent]=CalculateQBER(DecoyTime,ReceivedB,SendA,NAlice,QBERTest,Dfired)
%Remove Decoy
for i=1:NAlice*2
    if DecoyTime(i)==1
        ReceivedB(i)=0;
        SendA(i)=0;
        Dfired(i)=0;
    end
end

%Times that Dm clicked
FinalA=zeros(2*NAlice,1);
FinalB=zeros(2*NAlice,1);
for j=1:NAlice*2
    if Dfired(j)==1
        FinalA(j)=SendA(j);
        FinalB(j)=ReceivedB(j);
    end
end

%Calculate QBER
QberAux=0;
Positions=randi(sum(Dfired),QBERTest,1);
DfiredTimes=find(Dfired==1);
for j=1:QBERTest
    i=DfiredTimes(Positions(j));
    if rem (i,2)
        i=i-1;
    end
    if FinalA(i)==FinalB(i)
        if FinalA(i-1)==FinalB(i-1)
            QberAux=QberAux+1;
        end
    end
end
KeyPercent=(sum(Dfired)*2)/(2*NAlice);
KeyLength=sum(Dfired)*2-QBERTest;
QBER=1-QberAux/QBERTest;

end
