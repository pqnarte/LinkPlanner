--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:30:03 04/11/2018
-- Design Name:   
-- Module Name:   C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/SymbolDecision/SymbolDecision_tb.vhd
-- Project Name:  SymbolDecision
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: SymbolDecision
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use std.textio.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;
use ieee.math_real.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY SymbolDecision_tb IS
GENERIC( 
      Input_int   	: integer := 4;
	  Input_frac  	: integer := 4;
	  Output_int  	: integer := 4;
	  Output_frac 	: integer := 4
   );
END SymbolDecision_tb;
 
ARCHITECTURE behavior OF SymbolDecision_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT SymbolDecision
    PORT(
         clk : IN  std_logic;
         clk_en : IN  std_logic;
         Input_I : IN  std_logic_vector((Input_int+Input_frac)-1 downto 0);
         Input_R : IN  std_logic_vector((Input_int+Input_frac)-1 downto 0);
         Input_I_Ref : IN  std_logic_vector((Input_int+Input_frac)-1 downto 0);
         Input_R_Ref : IN  std_logic_vector((Input_int+Input_frac)-1 downto 0);
         Output : OUT  std_logic_vector(Output_int+Output_frac-1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal clk_en : std_logic := '1';
   signal Input_I : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
   signal Input_R : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
   signal Input_I_Ref : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
   signal Input_R_Ref : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');

 	--Outputs
   signal Output : std_logic_vector(Output_int+Output_frac-1 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
   --constant clk_en_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: SymbolDecision PORT MAP (
          clk => clk,
          clk_en => clk_en,
          Input_I => Input_I,
          Input_R => Input_R,
          Input_I_Ref => Input_I_Ref,
          Input_R_Ref => Input_R_Ref,
          Output => Output
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 
 

   -- Stimulus process
   process
		--begin		
      -- hold reset state for 100 ns.
--      wait for 100 ns;	
--
--      Input_I <= "00110000";
--		Input_R <= "00110000";
--		Input_I_Ref <= "00010000";
--		Input_R_Ref <= "00100000";
--		
--      wait;
--		
		--ficheiros com as componentes
		file file_pointer_Input_re, file_pointer_Input_img, file_pointer_Output_re, file_pointer_Output_img, file_pointer_Output_re_bit : text; 
			
		--ponteiros de linha
		variable line_pointer_Input_re, line_pointer_Input_img: line;
		variable line_pointer_Output_re, line_pointer_Output_img: line;	
		variable line_pointer_Output_re_bit: line;
		--informação retirada da linha
		variable var_input_re, var_input_img : integer := 0;

		
		--variáveis
		variable var_Inputs_Real, var_Inputs_Imag	: std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
		variable var_Outputs_Real, var_Outputs_Imag	: integer := 0;
		--variable var_Outputs_Real_bit  :	bit_vector((Nsample+NtapCPE-1)*(Dist_int+Dist_frac)-1 downto 0);
		
		Variable Count : Integer := 0;		
		constant file_length : real := 6.0;
		--variable loop_cout : integer := integer(ceil((file_length/real(Nsample))))+1;
	begin
	
	-- hold reset state for 100 ns.
		--wait for 60 ns;	
		
		--abrir vectores com as componentes dos sinais X e Y canais para leitura
		file_open(file_pointer_Input_re, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Input_R.txt"), READ_MODE);
		file_open(file_pointer_Input_img, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Input_I.txt"), READ_MODE);
						
		--abrir vectores de escrita
		file_open(file_pointer_Output_re, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_R.txt"), WRITE_MODE);
		--file_open(file_pointer_Output_img, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_I.txt"), WRITE_MODE);
		
		file_open(file_pointer_Output_re_bit, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_re_bit.txt"), WRITE_MODE);
				
		--fazer o loop e gravar a informação agora
		for i in 0 to 6-1 loop		
		
			for counter in 0 to 1-1 loop	
			
				--if(not endfile(file_pointer_Input_re)) then
					
					readline(file_pointer_Input_re,line_pointer_Input_re);
					readline(file_pointer_Input_img,line_pointer_Input_img);
					read(line_pointer_Input_re, var_input_re);
					read(line_pointer_Input_img, var_input_img);
															
					var_Inputs_Real((counter+1) * (Input_int+Input_frac)-1 downto counter * (Input_int+Input_frac)) := std_logic_vector(to_signed(var_input_re, (Input_int+Input_frac)));
					var_Inputs_Imag((counter+1) * (Input_int+Input_frac)-1 downto counter * (Input_int+Input_frac)) := std_logic_vector(to_signed(var_input_img, (Input_int+Input_frac)));
												
				 --end if;
			  end loop;			
			
			--atribuir as entradas
--			Input_R_tb <= var_Inputs_Real;
--			Input_I_tb <= var_Inputs_Imag;
			
			Input_I <= var_Inputs_Real;
			Input_R <= var_Inputs_Imag;
			Input_I_Ref <= "00010000";
			Input_R_Ref <= "00100000";
			
			-- esperar por 1 período de clock
			wait for 3*clk_period;
			
			for counter in 0 to 1-1 loop

				--if Count >= (((Ntap-1)/NSig)+2)+1+2 then
				
					--retirar as saídas e armazenar num ficheiro
				
				var_Outputs_Real := conv_integer(Output((counter+1) * (Output_int+Output_frac)-1 downto counter * (Output_int+Output_frac)));
				--var_Outputs_Real := conv_integer(var_Inputs_Real((counter+1) * (Input_int+Input_frac)-1 downto counter * (Input_int+Input_frac)));
				write(line_pointer_Output_re, var_Outputs_Real);
				writeline(file_pointer_Output_re, line_pointer_Output_re);
										
				--end if;	
			END LOOP;
			
--			var_Outputs_Real_bit := to_bitvector(Output_dist_tb);
--			
--			write(line_pointer_Output_re_bit, var_Outputs_Real_bit);
--			writeline(file_pointer_Output_re_bit, line_pointer_Output_re_bit);
--			
			 --Count := Count + 1;
			
		 end loop;
		
		wait;
   end process;

END;
