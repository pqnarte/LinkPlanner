function [ a,b ] = doub2bitValComplex( valcomplex )

v_real = real(valcomplex);
v_imag = imag(valcomplex);

a = doub2bitVal( v_real );
b = doub2bitVal( v_imag );

end

