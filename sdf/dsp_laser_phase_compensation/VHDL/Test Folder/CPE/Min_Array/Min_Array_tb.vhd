--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:40:16 04/10/2018
-- Design Name:   
-- Module Name:   C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/Min_Array/Min_Array_tb.vhd
-- Project Name:  Min_Array
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: MinArray
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
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY Min_Array_tb IS
GENERIC( 
			DataWidth_in		: integer := 16;
		   IndexWidth		: integer := 1;
			Nsig 		: integer := 2
  );
END Min_Array_tb;
 
ARCHITECTURE behavior OF Min_Array_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT MinArray
    PORT(
			clk : IN  std_logic;
         clk_en : IN  std_logic;
         A : IN  std_logic_vector(Nsig*DataWidth_in-1 downto 0);
         Y : OUT  std_logic_vector(IndexWidth-1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal Atb : std_logic_vector(Nsig*DataWidth_in-1 downto 0) := (others => '0');

 	--Outputs
   signal Ytb : std_logic_vector(IndexWidth-1 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
	
	signal Clk_tb : std_logic := '0';
   signal clk_en_tb : std_logic := '1';
   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: MinArray PORT MAP (
			 clk => clk_tb,
          clk_en => clk_en_tb,
          A => Atb,
          Y => Ytb
        );

   -- Clock process definitions
		clk_process :process
		begin
			Clk_tb <= '0';
			wait for clk_period/2;
			Clk_tb <= '1';
			wait for clk_period/2;
		end process;


   -- Stimulus process
   stim_proc: process
	
	file file_pointer_w,file_pointer_r : text;
	variable line_pointer_w,line_pointer_r: line;
	variable var_aux_r  :	bit_vector(Nsig*DataWidth_in-1 DOWNTO 0);
	variable var_aux_w :	bit_vector(IndexWidth-1 DOWNTO 0);
	variable var_Aux_STD : std_logic_vector(Nsig*DataWidth_in-1 downto 0) := (others => '0');
	
   begin		
		
		file_open(file_pointer_r, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Min_read.txt"), READ_MODE);
      file_open(file_pointer_w, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Min_wrte.txt"), WRITE_MODE);
		
		for i in 0 to 3 loop
		
			readline(file_pointer_r,line_pointer_r);
			read(line_pointer_r, var_aux_r);
			
			var_Aux_STD := To_StdLogicVector(var_aux_r);
			Atb <= var_Aux_STD;	
			
			wait for 1*clk_period;
			
			var_aux_w := to_bitvector(Ytb);
			
			write(line_pointer_w, var_aux_w);
			writeline(file_pointer_w, line_pointer_w);
			
		end loop;
			
      wait;
		
   end process;

END;
