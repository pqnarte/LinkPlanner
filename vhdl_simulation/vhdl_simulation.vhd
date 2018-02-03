library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_TEXTIO.all;
use IEEE.NUMERIC_STD.all;
use STD.TEXTIO.all;

entity vhdl_simulation is
	generic(FILENAME : string := "S5.sgn");
end vhdl_simulation;

architecture Behavioral of vhdl_simulation is

	--------------------------------------------------------
	-- TestBench Internal Signals	--
	--------------------------------------------------------
	subtype myType is bit; -- reads 1 byte
	type FileType is file of myType;
	file file_input_signal : FileType; -- Pointer to the input .sgn file
	file file_output_signal : FileType; -- Pointer to the output .sgn file

		
begin
				
	--------------------------------------------------------
	-- I/O HANDLER PROCESS
	--------------------------------------------------------
	
io_proc: process
				
				-- The simulation must be executed in the directory \vhdl_simulation\
				constant file_input_path : string := ".\input_files\" & FILENAME;
				constant file_output_path : string := ".\output_files\" & FILENAME;
				variable input_bits  : myType; -- bits received
				variable output_bits : myType; -- output bits after computation
				
			begin
			
				file_open(file_input_signal, file_input_path, READ_MODE);
				file_open(file_output_signal, file_output_path, WRITE_MODE);
				
				while not endfile(file_input_signal) loop -- while there is information to be read
					-- Reads the input bits from the input file
					read(file_input_signal, input_bits);
					-----------------
					-- Computation --
					-----------------
					-- computation(input_bits,output_bits)
					
					-- Writes the output bits to the output file
					write(file_output_signal, input_bits);
				end loop;
				
				file_close(file_input_signal);
				file_close(file_output_signal);
				
				wait;
			end process;
end Behavioral;