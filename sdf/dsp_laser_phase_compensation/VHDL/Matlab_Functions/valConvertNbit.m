function [val_res]=valConvertNbit(S,nFracbit,N)

%nFracbit = 6;
val_res = zeros(1,length(S));
shift = 0;
%N=8;
for m=1:length(S)
    if (S(m)<0 && round(((S(m)*2^nFracbit)))<0)
        val_res(m) = 2^N-round(abs((S(m)*2^nFracbit)));
        if(val_res(m)>(2^N/2)+shift)
            val_res(m)=val_res(m)-shift;
        end
    else
        val_res(m) = round(S(m)*2^nFracbit);
        if(val_res(m)<(2^N/2)-shift)
            val_res(m)=val_res(m)+shift;
        end
    end   
end