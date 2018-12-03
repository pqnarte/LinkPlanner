clear
clc

AverageOver=5;
NAlice=10^7; %Logical bits send by Alice to modulator
probd=0.10; %Probability of bit being a decoy
efficB=0.1; %Efficiency of Detetor from Bob
ProDarkCountBob=10^-5; %Probability of Dark count by Bob
ProDarkCountEve=0; %Probability of Dark count by Eve

for efficE=[-1 1 0.75 0.5 0.25 0.1]
    if efficE==-1
        IRAttack=0;
    else
        IRAttack=1;
    end
    TQBER=zeros(AverageOver,1);
    TKeyLength=zeros(AverageOver,1);
    for i=1:AverageOver
        
        %Alice Generate
        [SendA,DecoyTime]  = AliceGenerating(probd,NAlice);
        
        %Eve IR Attacks
        if IRAttack==1
            [SendA] = EveIRAttack(SendA,NAlice,ProDarkCountEve,efficE);
        end
        
        %Bob receives
        [ReceivedB,Dfired,DarkCounts]=BobReceiving(efficB,ProDarkCountBob,NAlice,SendA);
        
        %Calculate QBER
        [QBER,KeyLength,KeyPercent]=CalculateQBER(DecoyTime,ReceivedB,SendA,NAlice,Dfired);
        
        TQBER(i)=QBER;
        TKeyLength(i)=KeyLength;
    end
    if IRAttack==1
        TextoX=['With IR the attack, Average over ',num2str(i),' times, QBER=',num2str(mean(TQBER)),', R_B=',num2str(mean(TKeyLength)),' and Eve Efficency=',num2str(efficE)];
    else
        TextoX=['Without attacks, Average over ',num2str(i),' times, QBER=',num2str(mean(TQBER)),', R_B=',num2str(mean(TKeyLength))];
    end
    disp(TextoX)
end


%% Functions

function [SendAT,DecoyTime]  = AliceGenerating(probd,NAlice)
SendAinit=zeros(2*NAlice,1);
DecoyTime=zeros(2*NAlice,1);
RandomN=rand(NAlice,1);
for i=1:NAlice
    if RandomN(i,1)<=probd
        SendAinit(2*i-1)=1;
        SendAinit(2*i)=1;
        DecoyTime(2*i-1)=1;
        DecoyTime(2*i)=1;
    elseif RandomN(i,1)<=probd+(1-probd)/2
        SendAinit(2*i-1)=0;
        SendAinit(2*i)=1;
    else
        SendAinit(2*i-1)=1;
        SendAinit(2*i)=0;
    end
end
RandomN3=rand(NAlice*2,1);
SendAT=zeros(2*NAlice,1);
for j=1:NAlice*2
    if RandomN3(j,1)<=0.1
        if SendAinit(j)==1
            SendAT(j)=1;
        end
    end
end
end

function [SendAT] = EveIRAttack(SendA,NAlice,ProDarkCountEve,efficE)
RandomN3=rand(NAlice*2,3);
ReceivedE=zeros(2*NAlice,1);
SendAT=zeros(2*NAlice,1);
DarkCounts=0;
for j=1:NAlice*2
    if RandomN3(j,1)<=efficE
        if SendA(j)==1
            ReceivedE(j)=1;
            if RandomN3(j,3)<=0.1
                SendAT(j)=1;
            end
        end
    end
    
    %DarkCounts
    if SendAT(j)==0
        if RandomN3(j,2)<=ProDarkCountEve
            SendAT(j)=1;
            DarkCounts=DarkCounts+1;
        end
    end
end

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

function [QBER,KeyLength,KeyPercent]=CalculateQBER(DecoyTime,ReceivedB,SendA,NAlice,Dfired)
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
QBERTest=floor(sum(Dfired)*0.01);
QberAux=0;
Positions=randperm(sum(Dfired),QBERTest);
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
