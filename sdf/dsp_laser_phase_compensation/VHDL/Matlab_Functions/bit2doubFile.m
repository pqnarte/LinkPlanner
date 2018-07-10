function [ result ] = bit2doubFile( nFracbit,nbit )

fileID1 = fopen('Output_re_bit.txt','r');

formatSpec = '%s\r\n';
s_1 = fscanf(fileID1,formatSpec);
L = length(s_1)/(2*nbit);
for k=1:L
    bit_in = s_1((k-1)*2*nbit+1:k*2*nbit);
    temp = [bit2doubValPar( bit_in(nbit+1:2*nbit),nFracbit,nbit ); bit2doubValPar( bit_in(1:nbit),nFracbit,nbit ) ];
    result(:,k) = temp;
end

end
