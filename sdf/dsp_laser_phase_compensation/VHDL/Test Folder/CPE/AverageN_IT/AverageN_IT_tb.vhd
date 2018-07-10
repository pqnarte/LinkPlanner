--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   16:04:40 04/10/2018
-- Design Name:   
-- Module Name:   C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/AverageN_IT/AverageN_IT_tb.vhd
-- Project Name:  AverageN_IT
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: AverageN_IT
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
 
ENTITY AverageN_IT_tb IS
GENERIC( 
		NBits		: integer := 16;
		NSamples : integer := 3;
		NCycles 	: integer := 2;
		Index		: integer := 2
   );
END AverageN_IT_tb;
 
ARCHITECTURE behavior OF AverageN_IT_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Average_Ncycle
    PORT(
         clk : IN  std_logic;
         clk_en : IN  std_logic;
         A : IN  std_logic_vector(NSamples*NBits-1 downto 0);
         Y : OUT  std_logic_vector(NBits-1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal clk_en : std_logic := '1';
   signal A : std_logic_vector(NSamples*NBits-1 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(NBits-1 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
   constant clk_en_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Average_Ncycle PORT MAP (
          clk => clk,
          clk_en => clk_en,
          A => A,
          Y => Y
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
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      A <= "000000110000111000000011110010000000011100011010";

      wait;
   end process;

END;
