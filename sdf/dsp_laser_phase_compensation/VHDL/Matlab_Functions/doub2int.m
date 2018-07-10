function doub2int(vect,nFracbit,bitLength)

formatSpec = '%i\r\n';

% nFracbit = 6;
% bitLength = 8;

vect_re=valConvertNbit(real(vect),nFracbit,bitLength);
vect_im=valConvertNbit(imag(vect),nFracbit,bitLength);
% vect_re=valConvert(real(vect),nFracbit,bitLength);
% vect_im=valConvert(imag(vect),nFracbit,bitLength);valConvertNbit

fid_x_real=fopen('IQMapQPSK0_re.txt','w');
fid_x_imag=fopen('IQMapQPSK0_im.txt','w');

for k=1:length(vect)
    fprintf(fid_x_real,formatSpec,vect_re(k));
    fprintf(fid_x_imag,formatSpec,vect_im(k));
end

fclose(fid_x_real);
fclose(fid_x_imag);
