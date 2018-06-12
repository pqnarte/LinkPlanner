% Plot of simulated BER vs theoretical BER
simulations = simulResults;
teorCurves = {};
simulPoints = {};
legendStrings ={};
mf = 0;

for i = 1:length(simulations.symbolRate)
	% Plot theoretical curve
	if simulations.filtering{i}
		[teorCurves{end+1}]=getBERCurve2(modulationType.QPSK, ...
		linspace(-15,25,100), 4, simulations.symbolRate{i}, simulations.bandwidth, true,1e-6);
		hold on
		legendStrings{end+1} = [ 'Theoretical QPSK (' ...
		num2str(simulations.symbolRate{i}/1e9) ' GBd)' ];
	elseif mf == 0
		[teorCurves{end+1}]=getBERCurve2(modulationType.QPSK, ...
		linspace(-15,15,100), 4, simulations.symbolRate{i}, ...
		simulations.bandwidth, false,1e-6);
		hold on
		legendStrings{end+1} =['Theoretical QPSK without MF)'];
		teorCurves{end}.LineStyle = '--';	
		teorCurves{end}.Color= 'k';	
		mf = 1;
	end

	% Plot simulation results
%	simulations.berBot{i}(simulations.ber{i}-simulations.berBot{i}<1e-6) = ...
%	simulations.ber{i}(simulations.ber{i}-simulations.berBot{i}<1e-6)-0.99e-6;
	if i == 1
		simulPoints{end+1} = errorbar(simulations.snr{i}, ...
	    simulations.ber{i}, simulations.berBot{i}, simulations.berTop{i},'.');
    			legendStrings{end+1} =['Simulated QPSK (' ... 
			num2str(simulations.symbolRate{i}/1e9) ' GBd)'];
	else
		if simulations.filtering{i}
			simulPoints{end+1} = errorbar(simulations.snr{i}, ...
		    simulations.ber{i}, simulations.berBot{i}, simulations.berTop{i}, ...
			simulations.snrBot{i}, simulations.snrTop{i}, '.');
			legendStrings{end+1} =['Simulated QPSK (' ... 
			num2str(simulations.symbolRate{i}/1e9) ' GBd)'];
        else
            simulPoints{end+1} = errorbar(simulations.snr{i}, ...
		    simulations.ber{i}, simulations.berBot{i}, simulations.berTop{i}, ...
			simulations.snrBot{i}, simulations.snrTop{i}, 'o');
			legendStrings{end+1} =['Simulated QPSK (' ... 
			num2str(simulations.symbolRate{i}/1e9) ' GBd, without MF)'];
		end
	end

end

legend(legendStrings,'Location','SouthWest')
%title({'M=4, Root-Raised-Cosine Matched filter,',['Bandwidth = ' num2str(bw/1e9) ' GHz']})
