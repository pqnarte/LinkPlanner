function [ res ] = val2bitvector()

formatSpec = '%i';
fileID1 = fopen('Input_Test.txt','r');
s_real = fscanf(fileID1,formatSpec);
vect = valConvert2dec(s_real);
n=length(vect);
for i=1:length(vect)
     res((n-1)*8+1:n*8) = doub2bitVal(vect(i));
     n=n-1;
end

