function [ res ] = val2bitvector2( vect )

%n=length(vect);
for n=1:length(vect)
     res((n-1)*8+1:n*8) = doub2bitVal(vect(n))
end

