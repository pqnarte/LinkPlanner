function [resPol1,resPol2] = int_to_doub2Pol()

% fileID1 = fopen('Output_re_Pol1.txt','r');
% fileID2 = fopen('Output_img_Pol1.txt','r');

% fileID1 = fopen('Output_reNLC2_Pol1.txt','r');
% fileID2 = fopen('Output_imgNLC2_Pol1.txt','r');
% 
% fileID3 = fopen('Output_reNLC2_Pol2.txt','r');
% fileID4 = fopen('Output_imgNLC2_Pol2.txt','r');

fileID1 = fopen('Output_reT_1Step16_Lut12bits_Pol1.txt','r');
fileID2 = fopen('Output_imgT_1Step16_Lut12bits_Pol1.txt','r');

fileID3 = fopen('Output_reT_1Step16_Lut12bits_Pol2.txt','r');
fileID4 = fopen('Output_imgT_1Step16_Lut12bits_Pol2.txt','r');

%file_length = 32768;

%file_length = 65536;
file_length = 1000;
NTap = 21;
st=7;
st2=6;
% st=32;
% st2=31;

formatSpec = '%i';
s_real_Pol1 = fscanf(fileID1,formatSpec);
s_imag_Pol1 = fscanf(fileID2,formatSpec);
s_real_Pol2 = fscanf(fileID3,formatSpec);
s_imag_Pol2 = fscanf(fileID4,formatSpec);

% s_real_Pol1 = s_real_Pol1(st2:end);
% s_imag_Pol1 = s_imag_Pol1(st2:end);
% s_real_Pol2 = s_real_Pol2(st2:end);
% s_imag_Pol2 = s_imag_Pol2(st2:end);

s_real_Pol1 = s_real_Pol1(st:file_length+st2);
s_imag_Pol1 = s_imag_Pol1(st:file_length+st2);
s_real_Pol2 = s_real_Pol2(st:file_length+st2);
s_imag_Pol2 = s_imag_Pol2(st:file_length+st2);

% s_real = s_real(1:file_length-NTap+1);
% s_imag = s_imag(1:file_length-NTap+1);

resPol1=valConvert2dec(s_real_Pol1) + 1j*valConvert2dec(s_imag_Pol1);
resPol2=valConvert2dec(s_real_Pol2) + 1j*valConvert2dec(s_imag_Pol2);

