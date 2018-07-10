function [ val_out ] = bit2doubValPar( bit_in,nFracbit,nbit )

% nFracbit = 12;
% nbit = 14;

S=bin2dec(bit_in);

if S>((2^nbit)/2)
    val_out = (S-(2^nbit))/2^nFracbit;
else
    val_out = S/2^nFracbit;
end   
end
