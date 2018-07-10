function res = int_to_doub(nFracbit,nbit)

fileID1 = fopen('Output_R0.txt','r');
fileID2 = fopen('Output_I0.txt','r');

formatSpec = '%i';
s_real = fscanf(fileID1,formatSpec);
s_imag = fscanf(fileID2,formatSpec);

s_real = s_real(1:end);
s_imag = s_imag(1:end);

%res=valConvert2decPar(s_real,nFracbit,nbit);
res=valConvert2decPar(s_real,nFracbit,nbit) + 1j*valConvert2decPar(s_imag,nFracbit,nbit);

