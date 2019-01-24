clear
clc

Units=10^7;     %Charachters that Alice tries to transfer
AverageOver=200; %Run X times
PoissonA=0.1; %Num. Aver. Phothons by Impulse of Alice
probd=0.1; %Probability of bit being a decoy
efficB=0.1; %Efficiency of Detetor from Bob
ProDarkCountBob=10^-5; %Probability of Dark count by Bob
ProDarkCountEve=0; %Probability of Dark count by Eve

for a=[-1 0.1 0.5 0.9 1 1.0001 1.1 1.2 1.5]
    if a==-1
        IRAttack=0;
        efficE=a;
        PoissonE=0.1;
    elseif a<=1
        PoissonE=0.1;
        IRAttack=1;
        efficE=a;
  elseif a>1
       PoissonE=a;
       IRAttack=1;
       efficE=1;
    end
    TQBER=zeros(AverageOver,1);
    TKeyLength=zeros(AverageOver,1);
    TDarkCounts=zeros(AverageOver,1);
    TDM1fired=zeros(AverageOver,1);
    TDM2fired=zeros(AverageOver,1);
    TDMfired=zeros(AverageOver,1);
    ReceivedE=zeros(2*Units,1);
    for i=1:AverageOver
        
        %Alice Generate
        [Pulses]  = AliceGenerating(probd,PoissonA,Units);
        
        %Eve IR Attacks
        if IRAttack==1
            [Pulses,ReceivedE] = EveIRAttack(Pulses,Units,ProDarkCountEve,efficE,PoissonE);
        end
        
        %Bob receives
        [ReceivedB,Dfired,DarkCounts,DM1fired,DM2fired]= BobReceiving(efficB,ProDarkCountBob,Units,Pulses);
        
        %Calculate QBER
        [QBER,KeyLength,ReceivedE,ReceivedB,Pulses]=CalculateQBER(ReceivedB,Pulses,Units,Dfired,ReceivedE);
        
        TQBER(i)=QBER;
        TKeyLength(i)=KeyLength;
        TDarkCounts(i)=DarkCounts;
        TDM1fired(i)=DM1fired;
        TDM2fired(i)=DM2fired;
        TDMfired(i)=sum(Dfired);
        clear DM2fired DarkCounts KeyLength QBER
    end
    %Obtain mean and std for every variable
    pd1 = fitdist(TQBER,'Normal');
    pd2 = fitdist(TKeyLength,'Normal');
    pd3 = fitdist(TDM1fired,'Normal');
    pd4 = fitdist(TDM2fired,'Normal');
    %Save eveyrthing
    TextX=['file',num2str((efficE)),'PE',num2str(PoissonE),'.mat'];
    save(TextX,'pd1','pd2','pd3','pd4')
end
