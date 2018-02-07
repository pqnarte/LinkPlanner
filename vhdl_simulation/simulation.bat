ghdl -a --std=08 SignalProcessing.vhd
ghdl -a --std=08 vhdl_simulation.vhd
ghdl -e --std=08 vhdl_simulation
ghdl -r --std=08 vhdl_simulation
del *.cf