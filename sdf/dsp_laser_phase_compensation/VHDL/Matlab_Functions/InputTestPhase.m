function res = InputTestPhase(NTPhase,q)

b=0:NTPhase-1;
phiInt = 1.5708;
TPhase = (b/NTPhase-1/2)*phiInt;
if (q==0)
    Tvet = exp(1j*TPhase);
    doub2intFile(Tvet,6,8,'TPhaseExp_cos.txt','TPhaseExp_sin.txt')
end
if (q==1)
    Tvet = exp(-1j*TPhase);
    doub2intFile(Tvet,6,8,'PhaseEstExp_re.txt','PhaseEstExp_im.txt')
end
res = Tvet;