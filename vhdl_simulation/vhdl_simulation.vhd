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
	subtype myType is character; -- reads 1 byte
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
				variable char_buffer  : myType; -- bits received
				variable vector_buffer : std_logic_vector(7 downto 0);
				variable new_line_count : integer := 0; -- Counts the 4 newLine characters to ignore the HEADER
				
			begin
			
				file_open(file_input_signal, file_input_path, READ_MODE);
				file_open(file_output_signal, file_output_path, WRITE_MODE);
				
				while not endfile(file_input_signal) loop -- while there is information to be read
					-------------------------------------------
					-- Character Read
					-------------------------------------------
					-- Reads the input bits from the input file
					read(file_input_signal, char_buffer);
					-------------------------------------------
					-- HEADER Remover
					-------------------------------------------
					-- If /= 4 it's still reading the HEADER
					if(new_line_count /= 4) then
						-- If the current char is a new line character
						if(character'pos(char_buffer) = 10) then
						-- if new_line_count = 4, means HEADER is over
							new_line_count :=  new_line_count + 1;
						end if;
						next;
					end if;
					-------------------------------------------
					-- Computation
					-------------------------------------------
					vector_buffer := std_logic_vector(to_unsigned(character'pos(char_buffer),8));
					-- computation(vector_buffer); -- Signal Processing
					char_buffer := character'val(to_integer(unsigned(vector_buffer)));
					-------------------------------------------
					-- Write back
					-------------------------------------------
					-- Writes the output bits to the output file
					write(file_output_signal, char_buffer);
				end loop;
				
				file_close(file_input_signal);
				file_close(file_output_signal);
				
				wait;
			end process;
end Behavioral;