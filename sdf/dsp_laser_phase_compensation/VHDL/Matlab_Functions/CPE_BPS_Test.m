function [outDCf0,outDCf1,outDCf2,rest2] = CPE_BPS_Test(vect,NTPhase,Ntap,M)

%Ntap = 3;
phiInt = 1.5708;
b = 0:NTPhase-1;
TPhase = (b/NTPhase-1/2)*phiInt;
aux = exp(1j*TPhase);
rest0 = zeros(NTPhase,length(vect));
auxF = zeros(1,NTPhase);

for k=1:NTPhase
     [rest0(k,:),rest1(k,:),rest2(k,:),outDC(k,:)] = ErrorTPhase(vect,aux(k),Ntap,M);
end

[~,outIndex0] = min(rest0);
outVal0 = min(rest0);
[~,outIndex1] = min(rest1);
outVal1 = min(rest1);
[~,outIndex2] = min(rest2);
outVal2 = min(rest2);

% for l = 1:length(vect)
%     for k=1:NTPhase
%          [rest0(l,k),rest1(l,k),rest2(l,k),outDC(l,k),auxFDB] = ErrorTPhase(vect(l),aux(k),Ntap,auxF(k));
%           auxF(k) = auxFDB;
%     end
%     
%     [~,outIndex0(l)] = min(rest0(l,:));
%     outVal0(l) = min(rest0(l,:));
%     [~,outIndex1(l)] = min(rest1(l,:));
%     outVal1(l) = min(rest1(l,:));
%     [~,outIndex2(l)] = min(rest2(l,:));
%     outVal2(l) = min(rest2(l,:));
% end

for k=1:length(outVal0)
    temp =  outDC(:,k);
    outDCf0(k) = temp( outIndex0(k) );
    outDCf1(k) = temp( outIndex1(k) );
    outDCf2(k) = temp( outIndex2(k) );
end
% 
% [~,outIndex] = min(rest);
% outVal = min(rest);
