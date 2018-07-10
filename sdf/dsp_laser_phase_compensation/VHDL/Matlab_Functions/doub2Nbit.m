function [val_res]=doub2Nbit(S,nFracbit,nbits)

val_res = zeros(1,length(S));
for m=1:length(S)
    if (S<0 && round(((S*2^nFracbit)))<0)
        val_int = 2^nbits-round(abs((S*2^nFracbit)));
    else
        val_int = round(S*2^nFracbit);
    end 
    val_res = dec2bin(val_int,nbits);  
end