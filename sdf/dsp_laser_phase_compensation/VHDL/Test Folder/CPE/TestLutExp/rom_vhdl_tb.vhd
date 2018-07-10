--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   17:09:31 04/05/2018
-- Design Name:   
-- Module Name:   C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/TestLutExp/rom_vhdl_tb.vhd
-- Project Name:  TestLutExp
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: rom_vhd
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
 
ENTITY rom_vhdl_tb IS
END rom_vhdl_tb;
 
ARCHITECTURE behavior OF rom_vhdl_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT rom_vhd
    PORT(
         clk_i : IN  std_logic;
         addr_i : IN  std_logic_vector(7 downto 0);
         data_o : OUT signed(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk_i : std_logic := '0';
   signal addr_i : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal data_o : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant clk_i_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: rom_vhd PORT MAP (
          clk_i => clk_i,
          addr_i => addr_i,
          data_o => data_o
        );

   -- Clock process definitions
   clk_i_process :process
   begin
		clk_i <= '0';
		wait for clk_i_period/2;
		clk_i <= '1';
		wait for clk_i_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_i_period*10;

      addr_i <= "00000001";

      wait;
   end process;

END;
