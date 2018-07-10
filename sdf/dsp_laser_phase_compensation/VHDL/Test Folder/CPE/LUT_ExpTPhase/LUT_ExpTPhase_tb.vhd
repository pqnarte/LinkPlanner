LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
use ieee.math_real.all;


 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY CExpLUT_tb IS
GENERIC( 
			Data_width   : integer := 8;
			Addr_width   : integer := 2;
			NTphase      : integer := 4
  );
END CExpLUT_tb;
 
ARCHITECTURE behavior OF CExpLUT_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT TPhaseExpLut_File
    PORT(
         clk    : in std_logic;
			clk_en : in std_logic;
			--Addr   : in std_logic_vector (Addr_width-1 DOWNTO 0);      
			Cos_out  : out std_logic_vector (NTphase*Data_width-1 DOWNTO 0);       
			Sin_out 	: out std_logic_vector (NTphase*Data_width-1 DOWNTO 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal clk_en : std_logic := '1';

	signal addr_tb : std_logic_vector(Addr_width-1 downto 0) := (others => '0');
	
 	--Outputs
   signal Data_out1  : std_logic_vector(NTphase * Data_width-1 downto 0);
	signal Data_out2  : std_logic_vector(NTphase * Data_width-1 downto 0);

   -- Clock period definitions
   constant Clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: TPhaseExpLut_File PORT MAP (
          clk => clk,
          clk_en => clk_en,
			 --Addr    => Addr_tb,
          Cos_out => Data_out1,
			 Sin_out => Data_out2   
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
      wait for 60 ns;	
--
--      wait for clk_i_period*10;

      addr_tb <= "00";

      -- insert stimulus here 

      wait;
   end process;

END;