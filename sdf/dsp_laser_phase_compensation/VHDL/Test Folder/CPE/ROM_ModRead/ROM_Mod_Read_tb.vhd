-- TestBench Template 
  
  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE ieee.numeric_std.ALL;
	
  library work;
	USE work.out2Darray_pkg.all;
  
  ENTITY testbench IS
		Generic (
		Data_width		: integer := 2;
		Adrr_width		: integer := 1;
		NsigIn			: integer := 2;
		NsigOut			: integer := 4
	);
  END testbench;

  ARCHITECTURE behavior OF testbench IS 

  -- Component Declaration
          COMPONENT Array2Array 
				Port ( 
					DataIn 		: in  ArrayIn;
					Adrr			: in  STD_LOGIC_VECTOR (Adrr_width - 1 downto 0);
					Clk 			: in  STD_LOGIC;
					Clk_en 		: in  STD_LOGIC;
					DataOut		: out  ArrayOut
				);
			end COMPONENT;

         signal Clk   		: std_logic := '0';
			--signal DataIn	 	: std_logic_vector(NsigIn*Data_width-1 downto 0) := (others => '0');
			signal Adrr	 		: std_logic_vector(Adrr_width-1 downto 0) := (others => '0');
			signal Clk_en    	: std_logic := '1';
					 
			signal DataOut  	: ArrayOut;
			
			signal DataIn: ArrayIn := (  "0010",
                         "0111",
                         "1000",
                         "1110");
								 
			constant CLK_period : time := 10 ns;
			
  BEGIN

  -- Component Instantiation
          uut: Array2Array 
				Port map( 
					DataIn 		=> DataIn,
					Adrr			=> Adrr,
					Clk 			=> Clk,
					Clk_en 		=> Clk_en,
					DataOut		=> DataOut
				);

	 -- Clock process definitions
   CLK_process : process
   begin
		Clk <= '0';
		wait for CLK_period/2;
		Clk <= '1';
		wait for CLK_period/2;
   end process;
 

  --  Test Bench Statements
     tb : PROCESS
     BEGIN

        wait for 100 ns; -- wait until global set/reset completes

        --Adrr <= "0";

        wait; -- will wait forever
     END PROCESS tb;
  --  End Test Bench 

  END;
