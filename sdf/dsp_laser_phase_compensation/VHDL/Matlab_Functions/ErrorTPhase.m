function [rest0,rest1,rest2,outDC] = ErrorTPhase(vect,TPhase,Ntap,M)

Ntap2 = (Ntap-1)/2;
aux0 = vect*TPhase;
outDC = zeros(1,length(aux0));
for k=1:length(aux0)
    outDC(k) = decisionCircuit( aux0(k),M );
end
aux1 = aux0-outDC;
aux2 = abs(aux1).^2;
%aux3 = [0.1110,aux2,0.0515];
if (Ntap>1)
    aux3 = [zeros(1,Ntap2-1),0.1110,aux2,zeros(1,Ntap2)];
else
    aux3=aux2;
end
for k=1:length(aux0)
    temp = aux3(k:Ntap+k-1);
    rest0(k) = mean(temp);
    rest2(k) = sum(temp);
end
rest1 = movmean(aux2,Ntap);



