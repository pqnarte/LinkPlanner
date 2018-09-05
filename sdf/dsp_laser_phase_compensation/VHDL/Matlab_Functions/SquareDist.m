function result = SquareDist(vect,TPhase)

aux0 = vect*TPhase;
outDC = decisionCircuit( aux0 );
aux1 = aux0-outDC;
result = abs(aux1).^2;


