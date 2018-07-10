function doub2intFile(vect,nFracbit,bitLength,filename1,filename2)

formatSpec = '%i\r\n';

fid1 = fopen(filename1,'w');
fid2 = fopen(filename2,'w');

vect_re=valConvertNbit(real(vect),nFracbit,bitLength);
vect_im=valConvertNbit(imag(vect),nFracbit,bitLength);

for k=1:length(vect)
    fprintf(fid1,formatSpec,vect_re(k));
    fprintf(fid2,formatSpec,vect_im(k));
end

fclose(fid1);
fclose(fid2);
