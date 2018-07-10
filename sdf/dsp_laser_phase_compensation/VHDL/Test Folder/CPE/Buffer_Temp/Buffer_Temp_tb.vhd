--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:28:47 04/10/2018
-- Design Name:   
-- Module Name:   C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/Buffer_Temp/Buffer_Temp_tb.vhd
-- Project Name:  Buffer_Temp
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Buffer_Temp
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
 
ENTITY Buffer_Temp_tb IS
generic (
				DataWidth 	: integer := 4;
				Nsig 		: integer := 4
		); 
END Buffer_Temp_tb;
 
ARCHITECTURE behavior OF Buffer_Temp_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Buffer_Temp
    PORT(
         clk : IN  std_logic;
         clk_en : IN  std_logic;
         Data_in : IN  std_logic_vector(DataWidth-1 downto 0);
         Data_out : OUT  std_logic_vector(Nsig*DataWidth-1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal clk_en : std_logic := '1';
   signal Data_in : std_logic_vector(DataWidth-1 downto 0) := (others => '0');

 	--Outputs
   signal Data_out : std_logic_vector(Nsig*DataWidth-1 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
   constant clk_en_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Buffer_Temp PORT MAP (
          clk => clk,
          clk_en => clk_en,
          Data_in => Data_in,
          Data_out => Data_out
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
      wait for 20 ns;	

      Data_in <= "1011";
      wait;
   end process;

END;
