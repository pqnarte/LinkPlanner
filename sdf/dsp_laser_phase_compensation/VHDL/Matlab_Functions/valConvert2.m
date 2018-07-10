function [val_res]=valConvert2(S,nFracbit,bitLength)

val_res = zeros(1,length(S));
for m=1:length(S)
        aux = fi(S(m),1 ,bitLength, nFracbit);
        %aux_bin = bin(num2str(aux));
        val_res(m) = bin2dec(bin(aux));  
end