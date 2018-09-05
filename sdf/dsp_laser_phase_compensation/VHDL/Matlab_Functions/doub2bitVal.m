function [ val_bit ] = doub2bitVal( val )

nFracbit = 10;
bitLength = 12;
%val_res = zeros(1,length(S));

aux = fi(val,1 ,bitLength, nFracbit);
%aux_bin = bin(num2str(aux));
val_bit = bin(aux);  


end

