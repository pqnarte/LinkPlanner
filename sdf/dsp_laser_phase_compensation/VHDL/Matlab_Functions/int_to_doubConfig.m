function res = int_to_doubConfig(nFracbit,nbit,nTap,L)

res0 = int_to_doub(nFracbit,nbit);
st = 7;
strt = st+1+(nTap-1)/2;
res = res0(strt:strt+L-1);
