function doub2intNew(xin)

formatSpec = '%i\r\n';

xin_conv_r=valConvert2(real(xin));
xin_conv_i=valConvert2(imag(xin));

% coef_conv_r=valConvert2(real(coef));
% coef_conv_i=valConvert2(imag(coef));

% fid_x_real=fopen('Coef_re_16bit_301Tap.txt','w');
% fid_x_imag=fopen('Coef_img_16bit_301Tap.txt','w');

fid_x_real=fopen('Coef_re_18bit_301Tap.txt','w');
fid_x_imag=fopen('Coef_img_18bit_301Tap.txt','w');


% fid_c_real=fopen('Coef_re_ex.txt','w');
% fid_c_imag=fopen('Coef_img_ex.txt','w');

for k=1:(length(xin)-1)/2+1
    fprintf(fid_x_real,formatSpec,xin_conv_r(k));
    fprintf(fid_x_imag,formatSpec,xin_conv_i(k));
end

% for k=1:(length(xin)-1)/2+1
%     fprintf(fid_x_real,formatSpec,xin_conv_r(k));
%     fprintf(fid_x_imag,formatSpec,xin_conv_i(k));
% end
 % for k=1:(length(coef)-1)/2+1
%     fprintf(fid_c_real,formatSpec,coef_conv_r(k));
%     fprintf(fid_c_imag,formatSpec,coef_conv_i(k));
% end

fclose(fid_x_real);
fclose(fid_x_imag);
% fclose(fid_c_real);
% fclose(fid_c_imag);