library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_TEXTIO.all;
use IEEE.NUMERIC_STD.all;
use STD.TEXTIO.all;

entity VHDL_IO is
end VHDL_IO;

architecture Behavioral of VHDL_IO is
	
	--------------------------------------------------------
	-- Component Under Test	--
	--------------------------------------------------------
	--component generic_component is
	--	port( rawSignalIn  : std_logic_vector(3 downto 0);
	--	      modulatedOut : std_logic_vector(3 downto 0));
	--end component generic_component;
	
	--------------------------------------------------------
	-- TestBench Internal Signals	--
	--------------------------------------------------------
	type CHARF is file of character;
	file file_input_signal : CHARF; -- Pointer to the input .sgn file
	file file_output_signal : CHARF;-- Pointer to the output .sgn file

		
begin
	
	--------------------------------------------------------
	-- Instantiate and UUT
	--------------------------------------------------------
	--SOME_COMPONENT: generic_component
	--port map(rawSignalIn => s_simulated_signal,
	--	   modulatedOut => s_modulated_signal);
				
	--------------------------------------------------------
	-- I/O HANDLER PROCESS
	--------------------------------------------------------
io_proc: process
	
				variable input_line  : character; -- pointer to char buffer
				variable output_line : character;
				constant input_file_path : string := "C:\bolsaIT\LinkPlanner\vhdl_io\input_files\S5.sgn";
				constant output_file_path : string := "C:\bolsaIT\LinkPlanner\vhdl_io\output_files\S5.sgn";
				
			begin
			
				file_open(file_input_signal, input_file_path, READ_MODE);
				file_open(file_output_signal, output_file_path, WRITE_MODE);
				
				while not endfile(file_input_signal) loop -- Reads all the lines
					-- Reads each line from the input file
					read(file_input_signal, input_line);
					-----------------
					-- Computation --
					-----------------
					-- ... 
					
					
					-- Writes each line to the output file
					write(file_output_signal, input_line);
				end loop;
			
				file_close(file_input_signal);
				file_close(file_output_signal);
				
				wait;
			end process;
end Behavioral;