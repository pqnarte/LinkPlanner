LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY DecisionCircuit16QAM_tb IS
GENERIC( 
      Input_int   	: integer := 2;
	  Input_frac  	: integer := 6;
	  AdrrWidth 	: integer := 4
   );
END DecisionCircuit16QAM_tb;
 
ARCHITECTURE behavior OF DecisionCircuit16QAM_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT DecisionCircuit16QAM
    PORT(
         clk : IN  std_logic;
         clk_en : IN  std_logic;
         Input_I : IN  std_logic_vector((Input_int+Input_frac)-1 downto 0);
         Input_R : IN  std_logic_vector((Input_int+Input_frac)-1 downto 0);
			DecodeSymAdrr : OUT std_logic_vector (AdrrWidth-1 DOWNTO 0)
         --Output_I    	: OUT std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0);
			--Output_R    	: OUT std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal clk_en : std_logic := '1';
   signal Input_I_tb : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
   signal Input_R_tb : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');

 	--Outputs
   signal Output_I_tb : std_logic_vector(AdrrWidth-1 downto 0);
	--signal Output_R_tb : std_logic_vector(Output_int+Output_frac-1 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
   --constant clk_en_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: DecisionCircuit16QAM PORT MAP (
          clk => clk,
          clk_en => clk_en,
          Input_I => Input_I_tb,
          Input_R => Input_R_tb,
          DecodeSymAdrr => Output_I_tb
          --Output_R => Output_R_tb
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
      wait for 60 ns;	

      Input_I_tb <= "11010111";
		Input_R_tb <= "00001000";
		
      wait;
   end process;

END;
