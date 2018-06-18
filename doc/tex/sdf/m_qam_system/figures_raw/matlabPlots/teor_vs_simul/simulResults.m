function [simulations] = simulationResults()
%% Simulation results
% 64 Gsamples/s
% 200,000 bits
% RollOff 0.3

% Create structure for saving results
simulations.sampleRate = 64e9;
simulations.bandwidth= 64e9;
simulations.symbolRate ={};
simulations.ber = {};
simulations.berTop = {};
simulations.berBot = {};
simulations.teorSnr = {};
simulations.snr = {};
simulations.snrTop = {};
simulations.snrBot = {};
simulations.filtering = {};

%% 64 GBaud
idx64=[2,4,6,8,10];
snrTeor64=[-3, -2, 0, 1, 3, 4.00E+00, 7, 8 , 1.00E+01, 1.10E+01, 1.20E+01];
ber64=[0.237678, 0.211369, 0.15768, 0.129086, 0.0774424 , 5.53E-02, 0.0133721, 0.00642103, 1.01E-03, 1.30E-04 , 8.00E-05];
berTop64=[0.239544, 0.213159, 0.159279, 0.130557, 0.786161, 5.63E-02, 0.0138787, 0.00677435, 1.15E-03, 1.83E-04, 1.23E-04];
berBot64=[0.235807, 0.209575, 0.156079, 0.127613, 0.762681, 5.43E-02, 0.0128668, 0.00606918, 8.69E-04, 7.84E-05, 3.91E-05];
berTopConf64 = berTop64 - ber64;
berBotConf64 =  ber64 - berBot64;

simulations.symbolRate{end+1} = 64e9;
simulations.ber{end+1} = ber64(idx64);
simulations.berTop{end+1} = berTopConf64(idx64);
simulations.berBot{end+1} = berBotConf64(idx64);
simulations.teorSnr{end+1} = snrTeor64(idx64);
simulations.snr{end+1} = snrTeor64(idx64);
simulations.snrTop{end+1} = zeros(size(snrTeor64(idx64)));
simulations.snrBot{end+1} = zeros(size(snrTeor64(idx64)));
simulations.filtering{end+1} = true;

%% 32 GBaud
snrTeor32 = [-5, -2, 0, 3, 5, 8, 10];
ber32=[0.212858, 0.130132, 0.0794854, 0.0225072, 0.00591189, 0.00028009, 0.000010016];
berTop32=[0.215396, 0.13222, 0.0811666, 0.0234327, 0.00639361, 0.000390481, 2.71965E-05];
berBot32=[0.210311, 0.128039, 0.077803, 0.0215838, 0.00543317, 0.000173017, 1E-10];
snr32=[-4.91556, -1.81504, -0.043307, 3.0849, 5.00998, 7.96868, 10.0288];
snrTop32=[-4.69274, -1.65186, 0.0854328, 3.18507, 5.08217, 8.03808, 10.0698];
snrBot32=[-5.15044, -1.98458, -0.17598, 2.98237, 4.93656, 7.89816, 9.98747];
berTopConf32 = berTop32 - ber32;
berBotConf32 =  ber32 - berBot32;
snrTopConf32 = snrTop32 - snr32;
snrBotConf32 =  snr32 - snrBot32;

simulations.symbolRate{end+1} = 32e9;
simulations.ber{end+1} = ber32;
simulations.berTop{end+1} = berTopConf32;
simulations.berBot{end+1} = berBotConf32;
simulations.teorSnr{end+1} = snrTeor32;
simulations.snr{end+1} = snrTeor32;
simulations.snrTop{end+1} = snrTopConf32;
simulations.snrBot{end+1} = snrBotConf32;
simulations.filtering{end+1} = true;

%% 16 GBd
snrTeor16 = [-10, -6, -3, 0, 3, 6];
ber16=[0.264602, 0.15827, 0.0781475, 0.0225736, 0.0025004, 3.00048E-05];
berTop16=[0.266535, 0.159871, 0.0793261, 0.0232277, 0.00272259, 5.73463E-05];
berBot16=[0.262663, 0.156667, 0.0769683, 0.0219206, 0.00227981, 4.32939E-06];
snr16=[-10.1174, -6.01732, -2.97415, 0.0455119, 3.00786, 5.99801];
snrTop16=[-9.94014, -5.93226, -2.91362, 0.0878765, 3.03868, 6.02668];
snrBot16=[-10.3022, -6.10407, -3.03554, 0.00272985, 2.9783, 5.96916];
berTopConf16 = berTop16 - ber16;
berBotConf16 =  ber16 - berBot16;
snrTopConf16 = snrTop16 - snr16;
snrBotConf16 =  snr16 - snrBot16;

simulations.symbolRate{end+1} = 16e9;
simulations.ber{end+1} = ber16;
simulations.berTop{end+1} = berTopConf16;
simulations.berBot{end+1} = berBotConf16;
simulations.teorSnr{end+1} = snrTeor16;
simulations.snr{end+1} = snrTeor16;
simulations.snrTop{end+1} = snrTopConf16;
simulations.snrBot{end+1} = snrBotConf16;
simulations.filtering{end+1} = true;

% 4 GBd
snrTeor4 = [-12.5, -10, -7.5, -5, -2.5, 0];
ber4=[0.171852, 0.103957, 0.0455423, 0.012277, 0.00132521, 4.00064E-05];
berTop4=[0.173507, 0.105296, 0.0464588, 0.0127628, 0.00148798, 7.10616E-05];
berBot4=[0.170195, 0.102616, 0.446262, 0.0117925, 0.00116408, 1.06169E-05];
snr4=[-12.6201, -10.0274, -7.51103, -4.98434, -2.50846 , 0.016034];
snrTop4=[-12.5437, -9.97664, -7.47472, -4.95724, -2.48823, 0.032407];
snrBot4=[-12.6979, -10.0788, -7.54763, -5.01162, -2.52878, -0.000401634];
berTopConf4 = berTop4 - ber4;
berBotConf4 =  ber4 - berBot4;
snrTopConf4 = snrTop4 - snr4;
snrBotConf4 =  snr4 - snrBot4;

simulations.symbolRate{end+1} = 4e9;
simulations.ber{end+1} = ber4;
simulations.berTop{end+1} = berTopConf4;
simulations.berBot{end+1} = berBotConf4;
simulations.teorSnr{end+1} = snrTeor4;
simulations.snr{end+1} = snrTeor4;
simulations.snrTop{end+1} = snrTopConf4;
simulations.snrBot{end+1} = snrBotConf4;
simulations.filtering{end+1} = true;

% 64 GBd, no Matched Filter

idx64NoMF = [1,3,5,7,9,12];
snrTeor64NoMF=[-4, -3, -1, 0, 2, 3, 5, 7, 9.00E+00, 1.00E+01, 1.20E+01, 13];
ber64NoMF=[0.261776, 0.239829, 0.184035, 0.158588, 0.100468, 0.0789813, 0.036953, 0.012851, 2.19E-03, 7.20E-04, 1.50E-05, 0.00001];
berTop64NoMF=[0.263702, 0.2417, 0.185734, 0.16019, 0.101787 , 0.0801656, 0.0377826, 0.0133478, 2.39E-03, 8.41E-04 , 3.53E-05, 2.71943E-05];
berBot64NoMF=[0.259844, 0.237953, 0.182332, 0.1565983, 0.0991473, 0.0777964, 0.036124, 0.0123555, 1.98E-03, 6.01E-04, 1.00E-10, 1E-10];
berTopConf64NoMF = berTop64NoMF - ber64NoMF;
berBotConf64NoMF =  ber64NoMF - berBot64NoMF;

simulations.symbolRate{end+1} = 64e9;
simulations.ber{end+1} = ber64NoMF(idx64NoMF);
simulations.berTop{end+1} = berTopConf64NoMF(idx64NoMF);
simulations.berBot{end+1} = berBotConf64NoMF(idx64NoMF);
simulations.teorSnr{end+1} = snrTeor64NoMF(idx64NoMF);
simulations.snr{end+1} = snrTeor64NoMF(idx64NoMF);
simulations.snrTop{end+1} = zeros(size(snrTeor64NoMF(idx64NoMF)));
simulations.snrBot{end+1} = zeros(size(snrTeor64NoMF(idx64NoMF)));
simulations.filtering{end+1} = false;

% 32 GBd, no Matched Filter
snrTeor32NoMF=[-3, 0, 3, 7, 10, 12];
ber32NoMF=[0.239239, 0.157798, 0.0791413, 0.012551 , 0.000765061, 4.00032E-05];
berTop32NoMF=[0.241109, 0.159396, 0.0803267, 0.0130421, 0.000889564, 0.000071056];
berBot32NoMF=[0.237364, 0.156196, 0.0779553, 0.0120612, 0.000642203, 1.06161E-05];
snr32NoMF=[-3.38097, -0.297414, 2.69652, 6.68206, 9.66745, 11.6889];
snrTop32NoMF=[-3.25436, -0.211272, 2.75956, 6.73713 , 9.71127, 11.7411];
snrBot32NoMF=[-3.51138, -0.385299, 2.63255, 6.62628 , 9.62318, 11.6361];
berTopConf32NoMF = berTop32NoMF - ber32NoMF;
berBotConf32NoMF =  ber32NoMF - berBot32NoMF;
snrTopConf32NoMF = snrTop32NoMF - snr32NoMF;
snrBotConf32NoMF =  snr32NoMF - snrBot32NoMF;

simulations.symbolRate{end+1} = 32e9;
simulations.ber{end+1} = ber32NoMF;
simulations.berTop{end+1} = berTopConf32NoMF;
simulations.berBot{end+1} = berBotConf32NoMF;
simulations.teorSnr{end+1} = snrTeor32NoMF;
simulations.snr{end+1} = snrTeor32NoMF;
simulations.snrTop{end+1} = snrTopConf32NoMF;
simulations.snrBot{end+1} = snrBotConf32NoMF;
simulations.filtering{end+1} = false;


end
