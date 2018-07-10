-----------------------------------------
-- Authors: 
-----------------------------------------

-- Atraso =  clocks

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_signed.all;
use ieee.math_real.all;
---------------------------------------------------------

ENTITY SymbolDecision IS
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
END SymbolDecision;

ARCHITECTURE Struct OF SymbolDecision IS
	
	SIGNAL Out_I_sb    	: std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0) := (others => '0');
    SIGNAL Out_R_sb    	: std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0) := (others => '0');
    SIGNAL mult1 		: std_logic_vector(2*(Input_int+Input_frac )-1 DOWNTO 0) := (others => '0');
    SIGNAL mult2 		: std_logic_vector(2*(Input_int+Input_frac)-1 DOWNTO 0) := (others => '0');
	SIGNAL Out_adder    : std_logic_vector(2*(Input_int+Input_frac)-1 DOWNTO 0) := (others => '0');
	SIGNAL Out_sqrt    	: std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0) := (others => '0');
	
	
	COMPONENT Adder_IT IS
     GENERIC( 
      NBitsIn 	: integer := 8;
		NBitsOut : integer := 8;		-- (NBitsIn=NBitsOut) or (NBitsIn+1=NBitsOut)
		Index 	: integer := 1			-- Used if NBitsIn=NBitsOut >> 1-return the LSB of the sum, 0-return the MSB of the sum 
     );
     PORT( 
      input1  : IN     std_logic_vector (NBitsIn-1 Downto 0);
      input2  : IN     std_logic_vector (NBitsIn-1 Downto 0);
      result  : OUT    std_logic_vector (NBitsOut-1 Downto 0)
     );
	
	 END COMPONENT;
	 
	COMPONENT Multiplier_IT IS
	 generic (
				NbitsIn 	: integer := 8;
				NbitsOut : integer := 8;		-- (NBitsIn=NBitsOut) or (NBitsIn*2=NBitsOut)
				Index 	: integer := 2			-- Used if NBitsIn=NBitsOut
	 );
	 port (
				clk 		: in std_logic;
				clk_en 	: in std_logic;
				input1   : in std_logic_vector(NbitsIn-1 downto 0);
				input2   : in std_logic_vector(NbitsIn-1 downto 0);
				result   : out std_logic_vector(NbitsOut-1 downto 0)
	 );
	 END COMPONENT;
	
	COMPONENT Register_IT IS
	 generic(
				DataWidth 	: integer := 8
			);
	 port(
				clk 			: in std_logic;
				clk_en 		: in std_logic;
				data_in     : in std_logic_vector(DataWidth-1 downto 0);
				data_out    : out std_logic_vector(DataWidth-1 downto 0)
		 );
	 END COMPONENT;
   
   COMPONENT Subtractor_IT IS
	GENERIC( 
      NBitsIn 	: integer := 8;
		NBitsOut : integer := 8;		-- (NBitsIn=NBitsOut) or (NBitsIn+1=NBitsOut)
		Index 	: integer := 1			-- Used if NBitsIn=NBitsOut >> 1-return the LSB of the sum, 0-return the MSB of the sum 
	);
	PORT( 
      input1  : IN     std_logic_vector (NBitsIn-1 Downto 0);
      input2  : IN     std_logic_vector (NBitsIn-1 Downto 0);
      result  : OUT    std_logic_vector (NBitsOut-1 Downto 0)
	);
	END COMPONENT;
   
   COMPONENT Sqrt_IT is
	generic ( 
			NBits		: positive:= 8 	-- NBitsIn = NBitsOut*2
	);
    PORT( 
			Input    : IN     std_logic_vector (NBits*2-1 DOWNTO 0);
			Output 	: OUT    std_logic_vector (NBits-1 DOWNTO 0)
    );
    end COMPONENT;

BEGIN
	
		U_S0 : Subtractor_IT
		  GENERIC MAP (
			 NBitsIn  => Input_int + Input_frac,
			 NBitsOut => Input_int + Input_frac,
			 Index    => 1
		  )
		  PORT MAP (
			 input1 => Input_I,
			 input2 => Input_I_Ref,
			 result => Out_I_sb
		  );
		
		U_S1 : Subtractor_IT
		  GENERIC MAP (
			 NBitsIn  => Input_int + Input_frac,
			 NBitsOut => Input_int + Input_frac,
			 Index    => 1
		  )
		  PORT MAP (
			 input1 => Input_R,
			 input2 => Input_R_Ref,
			 result => Out_R_sb
		  );
	
	
	  U_M0 : Multiplier_IT
		GENERIC MAP (
			NbitsIn 	=> (Input_int+Input_frac),
			NbitsOut => (Input_int+Input_frac)*2,
			Index 	=> 1
		)
		PORT MAP (
			clk    => clk,
			clk_en => clk_en,
			input1 => Out_I_sb,
			input2 => Out_I_sb,
			result => mult1
		);
	
	U_M1 : Multiplier_IT
		GENERIC MAP (
			NbitsIn 	=> (Input_int+Input_frac),
			NbitsOut => (Input_int+Input_frac)*2,
			Index 	=> 1
		)
		PORT MAP (
			clk    => clk,
			clk_en => clk_en,
			input1 => Out_R_sb,
			input2 => Out_R_sb,
			result => mult2
		);
	
	U_A0 : Adder_IT
		GENERIC MAP (
			NbitsIn 	=> (Input_int+Input_frac)*2,
			NbitsOut    => (Input_int+Input_frac)*2,
			Index 	    => 1
		)
		PORT MAP (
			input1 => mult1,
			input2 => mult2,
			result => Out_adder
		);
	  		
	U_SR0: Sqrt_IT
		GENERIC MAP( 
			NBits		=> (Input_int+Input_frac)
		)
		PORT MAP( 
			Input		=> Out_adder,
			Output 	=> Out_sqrt
		);
		
   U_R0 : Register_IT
		GENERIC MAP (
			DataWidth 	=> (Input_int+Input_frac)
		)
		PORT MAP (
			clk      	=> clk,
			clk_en   	=> clk_en,
			data_in  	=> Out_sqrt,
			data_out 	=> Output
		);
	
END Struct;