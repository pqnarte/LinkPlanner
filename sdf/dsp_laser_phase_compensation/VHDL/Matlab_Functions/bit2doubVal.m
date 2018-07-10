function [ val_out ] = bit2doubVal( bit_in )

nFracbit = 10;
nbit = 12;

S=bin2dec(bit_in);

if S>((2^nbit)/2)
    val_out = (S-(2^nbit))/2^nFracbit;
else
    val_out = S/2^nFracbit;
end   
end

