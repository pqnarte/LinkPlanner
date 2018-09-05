function [val_res]=doub2NbitVal(S,nFracbit,nBit)

%nFracbit = 6;
val_res = zeros(1,length(S));
bit_leng = 2^nBit;
for m=1:length(S)
    if (S(m)<0 && round(((S(m)*2^nFracbit)))<0)
        val_res(m) = bit_leng-round(abs((S(m)*2^nFracbit)));
    else
        val_res(m) = round(S(m)*2^nFracbit);
    end   
end