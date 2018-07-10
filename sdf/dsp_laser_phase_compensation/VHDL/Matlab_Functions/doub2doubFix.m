function result = doub2doubFix(val,nFracbit,bitLength)

v_re=doub2Nbit(real(val),nFracbit,bitLength);
v_im=doub2Nbit(imag(val),nFracbit,bitLength);

result = bit2doubValPar(v_re,nFracbit,bitLength)+ bit2doubValPar(v_im,nFracbit,bitLength)*i;