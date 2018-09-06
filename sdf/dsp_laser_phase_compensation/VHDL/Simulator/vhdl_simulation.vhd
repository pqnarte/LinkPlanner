library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_TEXTIO.all;
use IEEE.NUMERIC_STD.all;
use STD.TEXTIO.all;

entity vhdl_simulation is
	generic(INPUT_FILENAME_1 : string := "S19.sgn";
			  INPUT_FILENAME_2 : string := "S20.sgn";
			  OUTPUT_FILENAME_1: string := "sim_out_1.sgn";
			  OUTPUT_FILENAME_2: string := "sim_out_2.sgn";
			  CLK_PERIOD : integer := 1); -- in ns
end vhdl_simulation;

architecture Behavioral of vhdl_simulation is

	--------------------------------------------------------
	-- TestBench Internal Signals	--
	--------------------------------------------------------
	subtype myType is character; -- reads 1 byte
	type FileType is file of myType;
	file file_input_signal_1 : FileType; -- Pointer to the input .sgn file 1
	file file_input_signal_2 : FileType; -- Pointer to the input .sgn file 2
	file file_output_signal_1 : FileType; -- Pointer to the output .sgn file 1
	file file_output_signal_2 : FileType; -- Pointer to the output .sgn file 2
	
	signal vector_buffer_in_1  : std_logic_vector(7 downto 0);
	signal vector_buffer_in_2  : std_logic_vector(7 downto 0);
	signal vector_buffer_out_1 : std_logic_vector(7 downto 0);
	signal vector_buffer_out_2 : std_logic_vector(7 downto 0);

	--------------------------------------------------------
	-- Unit Under Test Declaration
	--------------------------------------------------------
	component CpeBPS is
	GENERIC( 
		Input_int   		: integer := 2;
		Input_frac  		: integer := 6;
		Dist_int   			: integer := 2;
		Dist_frac  			: integer := 14;
		Output_int  		: integer := 2;
		Output_frac 		: integer := 6;
		data_lut_width		: integer := 8;
		--AdrrWidth  			: integer := 4;
		Nsig  				: integer := 1;
		NTphase				: integer := 2;
		Ntap				 	: integer := 1
   );
	PORT(
		Input_re    		: IN     std_logic_vector (Nsig*(Input_int+Input_frac)-1 DOWNTO 0);	  
	   Input_im	    		: IN     std_logic_vector (Nsig*(Input_int+Input_frac)-1 DOWNTO 0);
      clk              	: IN     std_logic;
      clk_en          	: IN     std_logic;      		
      Output_re    	   : OUT    std_logic_vector (Nsig*(Output_int+Output_frac)-1 DOWNTO 0);
	   Output_im   	   : OUT    std_logic_vector (Nsig*(Output_int+Output_frac)-1 DOWNTO 0)
	);
	end component;
	--------------------------------------------------------
	-- UUT Input Parameters
	--------------------------------------------------------
	signal s_clk : std_logic := '0';
	signal s_clk_en : std_logic := '1'; -- enabled by default
	constant CLK_PER : time := CLK_PERIOD * 1 ns;
		
begin
	--------------------------------------------------------
	-- UUT Initialization
	--------------------------------------------------------
	uut: CpeBPS port map(
		Input_re => vector_buffer_in_1,
		Input_im => vector_buffer_in_2,
		clk => s_clk,
		clk_en => s_clk_en,
		Output_re => vector_buffer_out_1,
		Output_im => vector_buffer_out_2
	);

	--------------------------------------------------------
	-- I/O HANDLER PROCESS
	--------------------------------------------------------
	
io_proc: process
		
	variable char_buffer_in_1    : myType; -- character received 1
	variable char_buffer_in_2    : myType; -- character received 2
	variable char_buffer_out_1   : myType; -- character output 1
	variable char_buffer_out_2   : myType; -- character output 2
	variable new_line_count      : integer := 0; -- Counts the 4 newLine characters to ignore the HEADER
	
begin

	-- The simulation must be executed in the directory \Simulator\
	file_open(file_input_signal_1, ".\..\..\signals\" & INPUT_FILENAME_1, READ_MODE);
	file_open(file_input_signal_2, ".\..\..\signals\" & INPUT_FILENAME_2, READ_MODE);
	file_open(file_output_signal_1, ".\..\..\signals\" & OUTPUT_FILENAME_1, WRITE_MODE);
	file_open(file_output_signal_2, ".\..\..\signals\" & OUTPUT_FILENAME_2, WRITE_MODE);
	
	while not endfile(file_input_signal_1) and not endfile(file_input_signal_2) loop -- while there is information to be read. The input files have the same length
		-------------------------------------------
		-- Character Read
		-------------------------------------------
		-- Reads the input bits from the input file
		read(file_input_signal_1, char_buffer_in_1);
		read(file_input_signal_2, char_buffer_in_2);
		-------------------------------------------
		-- HEADER Remover
		-------------------------------------------
		-- If /= 4 it's still reading the HEADER
		if(new_line_count /= 4) then
			-- If the current char is a new line character
			if(character'pos(char_buffer_in_1) = 10) then
			-- if new_line_count = 4, means HEADER is over
				new_line_count :=  new_line_count + 1;
			end if;
			write(file_output_signal_1, char_buffer_in_1); -- writes the header in output file 1
			write(file_output_signal_2, char_buffer_in_2); -- writes the header in output file 2
			next;
		end if;
		-------------------------------------------
		-- Computation
		-------------------------------------------
		vector_buffer_in_1 <= std_logic_vector(to_unsigned(character'pos(char_buffer_in_1),8));
		vector_buffer_in_2 <= std_logic_vector(to_unsigned(character'pos(char_buffer_in_2),8));
		wait until s_clk'event and s_clk='1' and s_clk_en='1';
		char_buffer_out_1 := character'val(to_integer(unsigned(vector_buffer_out_1)));
		char_buffer_out_2 := character'val(to_integer(unsigned(vector_buffer_out_2)));
		-------------------------------------------
		-- Write back
		-------------------------------------------
		-- Writes the output bits to the output file
		write(file_output_signal_1, char_buffer_out_1);
		write(file_output_signal_2, char_buffer_out_2);
	end loop;
	
	file_close(file_input_signal_1);
	file_close(file_input_signal_2);
	file_close(file_output_signal_1);
	file_close(file_output_signal_2);
	report "-------------- Simulation complete! ------------------"  severity failure ;
	wait;
end process;

-------------------------------------------
-- Clock process
-------------------------------------------
	
clk_process: process
begin

		s_clk <= '0';
		wait for CLK_PER/2;
		s_clk <= '1';
		wait for CLK_PER/2;
			
end process;

-------------------------------------------
-- TB Stimulus
-------------------------------------------

stim_proc: process
begin
	
	-- Used to enable or disable clk
	s_clk_en <= '1'; -- In this case the clock is always enabled
	wait for 50 ns;
	------ Example ---------
	-- wait for 50 ns;
	-- s_clk_en <= '0';
		
end process;

end Behavioral;