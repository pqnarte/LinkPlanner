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
	file file_input_signal : text;
	file file_output_signal : text;

		
begin
	
	--------------------------------------------------------
	-- Instantiate and UUT
	--------------------------------------------------------
	--SOME_COMPONENT: generic_component
	--port map(rawSignalIn => s_simulated_signal,
	--	   modulatedOut => s_modulated_signal);
				
----------------------------------------------------------------------------------------------------------------
-- I/O HANDLER PROCESS
----------------------------------------------------------------------------------------------------------------
io_proc: process
	
				variable input_line  : line; -- pointer to string
				variable output_line : line;
				
			begin
				-- Reads content of file ficheiro_teste.txt and writes it to file output_teste.txt
				file_open(file_input_signal, "C:\bolsaIT\VHDL_IO\ficheiro_teste.txt", READ_MODE);
				file_open(file_output_signal, "C:\bolsaIT\VHDL_IO\output_teste.txt", WRITE_MODE);
				
				--Later it will read from a .sgn file and write to a .sgn file
				--file_open(file_input_signal, "C:\bolsaIT\VHDL_IO\S5.sgn", READ_MODE);
				--file_open(file_output_signal, "C:\bolsaIT\VHDL_IO\S5_OUT.sgn", WRITE_MODE);
				
				while not endfile(file_input_signal) loop -- Reads all the lines
					-- Reads each line from the input file
					readline(file_input_signal, input_line);
					-- Writes each line to the output file
					write(output_line, input_line.all); -- input_line.all returns the string it points to
					writeline(file_output_signal, output_line);
				end loop;
			
				file_close(file_input_signal);
				file_close(file_output_signal);
				
				wait;
			end process;
end Behavioral;