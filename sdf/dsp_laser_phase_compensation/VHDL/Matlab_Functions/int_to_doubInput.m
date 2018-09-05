function res = int_to_doubInput()

fileID1 = fopen('Output_re_fir.txt','r');
fileID2 = fopen('Output_img_fir.txt','r');

file_length = 32768;
Ntap = 21;
NSig = 1;
formatSpec = '%i';

s_real = fscanf(fileID1,formatSpec);
s_imag = fscanf(fileID2,formatSpec);

% s_real = s_real(823:822+file_length-Ntap+1);
% s_imag = s_imag(823:822+file_length-Ntap+1);
s_real = s_real(1:file_length-Ntap+1);
s_imag = s_imag(1:file_length-Ntap+1);
%s_real = s_real;
%s_imag = s_imag;

res=valConvert2dec(s_real) + 1j*valConvert2dec(s_imag);

%res_r=valConvert2dec(s_real);
%res_i=valConvert2dec(s_imag);
