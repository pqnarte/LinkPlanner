-----------------------------------------
-- Authors: 
-----------------------------------------

-- Atraso = 3 clocks

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_signed.all;
use ieee.math_real.all;
---------------------------------------------------------

ENTITY DecisionCircuit16QAM IS
   GENERIC( 
      Input_int   	: integer := 2;
	  Input_frac  	: integer := 16;
	  Output_int  	: integer := 3;
	  Output_frac 	: integer := 18;
   );
   PORT( 
      clk         	: IN  std_logic;
      clk_en      	: IN  std_logic;
      Input_I 		: IN  std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
      Input_R 		: IN  std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
      Output_I    	: OUT std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0);
      Output_R    	: OUT std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0)
   );
END DecisionCircuit16QAM;

ARCHITECTURE Struct OF DecisionCircuit16QAM IS
	
	signal Output_dc		 : std_logic_vector(16*(Input_int+Input_frac)-1 downto 0) := (others=>'0');
	signal Out_MinDist 					 : std_logic_vector(3 downto 0) := (others=>'0');
	signal Input_R_Ref, Input_I_Ref		 : std_logic_vector(16*(Input_int+Input_frac)-1 downto 0) := (others=>'0');
	
	COMPONENT SymbolDecision IS
     GENERIC( 
      Input_int   	: integer := 4;
	  Input_frac  	: integer := 4;
	  Output_int  	: integer := 4;
	  Output_frac 	: integer := 4
     );
     PORT( 
      clk         	: IN  std_logic;
      clk_en      	: IN  std_logic;
      Input_I 		: IN  std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
      Input_R 		: IN  std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
	  Input_I_Ref 	: IN  std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
      Input_R_Ref 	: IN  std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
      Output    	: OUT std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0)
     );
     END COMPONENT;
	 
	COMPONENT ROM_IQmap is
	 GENERIC( 
        Data_width  : integer := 8;
	    Addr_width  : integer := 4;
	    Ntap_half   : integer :=11
	 );
	 port (
		clk     : in std_logic;
		clk_en  : in std_logic;  
		Data1   : out std_logic_vector (Data_width-1 DOWNTO 0);        
		Data2 	: out std_logic_vector (Data_width-1 DOWNTO 0)      
	 );	
	end COMPONENT;
	
	
BEGIN

	U_R0 : ROM_IQmap 
	 GENERIC MAP( 
        Data_width  => Input_int+Input_frac,
	    Addr_width  => 4
	 );
	 port (
		clk 	=> clk,
	    clk_en 	=> clk_en,     
		Data1   => Input_R_Ref,
		Data2 	=> Input_I_Ref     
	 );	
	 
	U_DC : for I in 0 to 15 generate
		U_0 : SymbolDecision
		  GENERIC MAP (
			   Input_int   		=> Input_int,
			   Input_frac   	=> Input_frac,
			   Output_int   	=> Output_int,
			   Output_frac  	=> Output_frac,
		  )
		  PORT MAP (
			  clk 			=> clk,
			  clk_en 		=> clk_en,
			  Input_I 		=> Input_I,
			  Input_R 		=> Input_R,
			  Input_I_Ref 	=> Input_I_Ref((I+1)*(Input_int+Input_frac)-1 DOWNTO (I)*(Input_int+Input_frac)),
			  Input_R_Ref 	=> Input_R_Ref((I+1)*(Input_int+Input_frac)-1 DOWNTO (I)*(Input_int+Input_frac)),
			  Output 		=> Output_dc((I+1)*(Output_int + Output_frac) -1 DOWNTO I*(Output_int + Output_frac))
		  );
	end generate;
	
	U_MA0 : MinArray
	 GENERIC MAP(
			DataWidth_in	=> Input_frac + Input_int,
			IndexWidth	=>	4,
			Nsig 			=> 16
     );
	 PORT MAP( 
			A 			=> Output_dc,
			Y 			=> Out_MinDist
	 );		
	 END COMPONENT;
		
    Output_I <= Input_I_Ref((to_integer(unsigned(Out_MinDist))+1)*(Output_int+Output_frac)-1 DOWNTO (to_integer(unsigned(Out_MinDist)))*(Output_int+Output_frac));
	Output_R <= Input_R_Ref((to_integer(unsigned(Out_MinDist))+1)*(Output_int+Output_frac)-1 DOWNTO (to_integer(unsigned(Out_MinDist)))*(Output_int+Output_frac));

END Struct;