--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:37:24 04/18/2018
-- Design Name:   
-- Module Name:   C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/AbsCValue2/AbsCValue2_tb.vhd
-- Project Name:  AbsCValue2
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: AbsCValue2
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
 
ENTITY AbsCValue2_tb IS
GENERIC( 
     Input_int   	: integer := 2;
	  Input_frac  	   : integer := 6;
	  Output_int  	   : integer := 2;
	  Output_frac 	   : integer := 6
   );
END AbsCValue2_tb;
 
ARCHITECTURE behavior OF AbsCValue2_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT AbsCValue2
    PORT(
         clk : IN  std_logic;
         clk_en : IN  std_logic;
         Input_re : IN  std_logic_vector((Input_int+Input_frac)-1 downto 0);
         Input_im : IN  std_logic_vector((Input_int+Input_frac)-1 downto 0);
         result : OUT  std_logic_vector(Output_int+Output_frac-1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal clk_en : std_logic := '1';
   signal Input_re : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
   signal Input_im : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');

 	--Outputs
   signal result : std_logic_vector(Output_int+Output_frac-1 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: AbsCValue2 PORT MAP (
          clk => clk,
          clk_en => clk_en,
          Input_re => Input_re,
          Input_im => Input_im,
          result => result
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

      Input_re <= "00100111";
		Input_im <= "11101101";
		
      wait;
   end process;

END;
