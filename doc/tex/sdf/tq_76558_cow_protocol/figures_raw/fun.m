function [Pulses]  = AliceGenerating(probd,PoissonA,Units)
i=1;
Pulses=zeros(2*Units,3);
for k=1:1000
    RandomPulseNumber=poissrnd(PoissonA,Units,1);
    RandomNumber=rand(Units,1);
    for j=1:Units-1
        if RandomPulseNumber(j)>=1
            if RandomNumber(j,1)<=probd
                if RandomPulseNumber(j+1)>=1
                    Pulses(2*i-1,1)=1;
                    Pulses(2*i-1,2)=RandomPulseNumber(j);
                    Pulses(2*i-1,3)=2;
                    Pulses(2*i,1)=1;
                    Pulses(2*i,2)=RandomPulseNumber(j);
                    Pulses(2*i,3)=2;
                else
                    if RandomNumber(j+1,1)<=0.5
                        Pulses(2*i-1,1)=1;
                        Pulses(2*i-1,2)=RandomPulseNumber(j);
                    elseif RandomNumber(j+1,1)>=0.5
                        Pulses(2*i,1)=1;
                        Pulses(2*i,2)=RandomPulseNumber(j);
                    end
                end
                i=1+i;
            elseif RandomNumber(j,1)<probd+(1-probd)/2
                Pulses(2*i-1,1)=0;
                Pulses(2*i,1)=1;
                Pulses(2*i,2)=RandomPulseNumber(j);
                Pulses(2*i,3)=0;
                Pulses(2*i-1,3)=0;
            else
                Pulses(2*i-1,1)=1;
                Pulses(2*i-1,2)=RandomPulseNumber(j);
                Pulses(2*i,1)=0;
                Pulses(2*i-1,3)=1;
                Pulses(2*i,3)=1;
            end
            i=1+i;
            
        end
        if i>=Units+1
            break
        end
    end
    if i>=Units+1
        break
    end
end
end

function [Pulses,ReceivedE,DarkCountsE] = EveIRAttack(Pulses,Units,ProDarkCountEve,efficE,PoissonE)
RandomNumber=rand(Units*2,2);
RandomPulseNumber=poissrnd(PoissonE,Units*2,1);
ReceivedE=zeros(2*Units,1);
SendAT=zeros(2*Units,3);

for j=1:Units*2
    for i=1:Pulses(j,2)
        if RandomNumber(i,1)<=efficE
            if Pulses(j,1)==1
                ReceivedE(j)=1;
                if RandomPulseNumber(j,1)>=1
                    SendAT(j,1)=1;
                    SendAT(j,2)=RandomPulseNumber(j,1);
                end
            end
        end
    end
    %DarkCounts
    if ReceivedE(j)==0
        if RandomNumber(j,2)<=ProDarkCountEve
            ReceivedE(j)=1;
            DarkCountsE=DarkCountsE+1;
        end
    end
end
SendAT(:,3)=Pulses(:,3);
Pulses=SendAT;

end

function [ReceivedB,Dfired,DarkCounts,DM1fired,DM2fired]= BobReceiving(efficB,ProDarkCountBob,Units,Pulses)
RandomNumbers=rand(Units*2,3);
LatePulses=zeros(Units*2,1);
DarkCounts=0;
DM1fired=0;
DM2fired=0;
ReceivedB=zeros(2*Units,1);
Dfired=zeros(2*Units,1);
for j=1:Units*2
    if Pulses(j,1)==1
        for i=1:Pulses(j,2)
            if i>1
                l=randi(2*Units);
            elseif i==1
                l=j;
            end
            %Monotiring Line
            if RandomNumbers(l,1)<=0.1
                %Late Pulses
                %0- No pulses
                %1- Only 1st Pulse
                %2- Two Pulses
                %3- Only 2nd Pulse
                if RandomNumbers(l,2)<=efficB+ProDarkCountBob
                    if RandomNumbers(l,3)<=0.5
                        %Coherent with late pulse
                        if LatePulses(j,1)==1
                            LatePulses(j,1)=2;
                            DM1fired=DM1fired-1;
                            DM2fired=DM2fired+1;
                        elseif LatePulses(j,1)==0
                            LatePulses(j,1)=3;
                            DM1fired=DM1fired+1;
                        end
                    elseif RandomNumbers(l,3)>0.5
                        %Edit Late pulse
                        if j<Units*2
                            if LatePulses(j+1,1)==0
                                LatePulses(j+1,1)=1;
                                DM1fired=DM1fired+1;
                            end
                        end
                    end
                end
                %Data Line
            elseif RandomNumbers(l,1)>0.1
                if RandomNumbers(l,2)<=efficB
                    ReceivedB(j)=1;
                    Dfired(j)=1;
                end
            end
            
        end
    end
    %DarkCounts
    if ReceivedB(j)==0
        if RandomNumbers(j,2)<=ProDarkCountBob
            Dfired(j)=1;
            ReceivedB(j)=1;
            DarkCounts=DarkCounts+1;
        end
    end
end
end

function [QBER,KeyLength,ReceivedE,ReceivedB,Pulses]=CalculateQBER(ReceivedB,Pulses,Units,Dfired,ReceivedE)
%Remove Decoy
for i=1:Units*2
    if Pulses(i,3)==2
        ReceivedB(i)=0;
        ReceivedE(i)=0;
        Dfired(i)=0;
        Pulses(i,1)=0;
    end
end

%Times that Dm clicked
FinalA=zeros(2*Units,1);
FinalB=zeros(2*Units,1);
for j=1:Units*2
    if Dfired(j)==1
        FinalA(j)=Pulses(j,1);
        FinalB(j)=ReceivedB(j);
    end
end

%Calculate QBER
QBERTest=floor(sum(Dfired)*0.5);
QberAux=0;
Positions=randperm(sum(Dfired),QBERTest);
DfiredTimes=find(Dfired==1);
for j=1:QBERTest
    i=DfiredTimes(Positions(j));
    if i>1
        if FinalA(i)==FinalB(i)
            if FinalA(i-1)==FinalB(i-1)
                QberAux=QberAux+1;
            end
        end
    end
end
KeyLength=sum(Dfired)-QBERTest;
QBER=1-QberAux/QBERTest;
end
