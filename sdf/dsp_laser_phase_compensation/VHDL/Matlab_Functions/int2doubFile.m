function [res_Pol1,res_Pol2] = int2doubFile()

% fileID1 = fopen('Output_reTestar.txt','r');
% fileID2 = fopen('Output_imgTestar.txt','r');

fileID1 = fopen('Output_re_Pol1.txt','r');
fileID2 = fopen('Output_img_Pol1.txt','r');
fileID3 = fopen('Output_re_Pol2.txt','r');
fileID4 = fopen('Output_img_Pol2.txt','r');

file_length = 4;
NTap = 5;
formatSpec = '%i';

s_real_Pol1 = fscanf(fileID1,formatSpec);
s_imag_Pol1 = fscanf(fileID2,formatSpec);
s_real_Pol2 = fscanf(fileID3,formatSpec);
s_imag_Pol2 = fscanf(fileID4,formatSpec);

%s_real = s_real(1:file_length-NTap+1);
%s_imag = s_imag(1:file_length-NTap+1);

res_Pol1=valConvert2dec(s_real_Pol1) + 1j*valConvert2dec(s_imag_Pol1);
res_Pol2=valConvert2dec(s_real_Pol2) + 1j*valConvert2dec(s_imag_Pol2);

end

