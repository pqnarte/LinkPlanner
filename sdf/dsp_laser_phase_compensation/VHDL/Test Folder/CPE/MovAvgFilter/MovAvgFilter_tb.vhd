--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:47:20 04/10/2018
-- Design Name:   
-- Module Name:   C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/MovAvgFilter/MovAvgFilter_tb.vhd
-- Project Name:  MovAvgFilter
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: MovAvgFilter
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
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY MovAvgFilter_tb IS
GENERIC(
	  DataWidth_in		: integer := 8;
	  DataWidth_out	: integer := 8;
      N_Signals 		: integer := 3
   );
END MovAvgFilter_tb;
 
ARCHITECTURE behavior OF MovAvgFilter_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT MovAvgFilter
    PORT(
         A : IN  std_logic_vector((DataWidth_in)*N_Signals-1 downto 0);
         Y : OUT  std_logic_vector(DataWidth_out-1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector((DataWidth_in)*N_Signals-1 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(DataWidth_out-1 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   constant Clk_period : time := 10 ns;
   --Inputs
   signal clk : std_logic := '0';
   signal clk_en : std_logic := '1';

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: MovAvgFilter PORT MAP (
          A => A,
          Y => Y
        );

   -- Clock process definitions
   Clk_process :process
   begin
		Clk <= '0';
		wait for Clk_period/2;
		Clk <= '1';
		wait for Clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 60 ns;	
		
		A <= "11101000000100000011000000100000";

      -- insert stimulus here 

      wait;
   end process;

END;
