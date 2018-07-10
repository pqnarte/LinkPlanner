function out = decisionCircuit( samp, M )
if (M==4)
    constMap = load('C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\ConstellationMapQPSK');
end
if (M==16)
    constMap = load('C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\ConstellationMap');
end
aux = abs(constMap.Const-samp);
[~,I] = min(aux);
out = constMap.Const(I);
end

