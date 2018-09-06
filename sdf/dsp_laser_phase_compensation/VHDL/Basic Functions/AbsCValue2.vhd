LIBRARY ieee;
USE ieee.std_logic_1164.all;
--USE ieee.std_logic_arith.all;
USE ieee.std_logic_signed.all;
USE ieee.numeric_std.all;
---------------------------------------------------------

ENTITY AbsCValue2 IS
   GENERIC( 
      Input_int   : integer := 2;
	  Input_frac  : integer := 6;
      Output_int  : integer := 2;
	  Output_frac : integer := 6
   );
   PORT( 
       clk         	: IN     std_logic;
       clk_en      	: IN     std_logic;
	   Input_re   	: IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
       Input_im  	: IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
	   result  		: OUT    std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0)
   );

END AbsCValue2 ;


ARCHITECTURE Struct OF AbsCValue2 IS

   SIGNAL Out_adder   		: std_logic_vector(1+2*(Input_int+Input_frac)-1 DOWNTO 0) := (others => '0');
   SIGNAL mult1 			: std_logic_vector(2*(Input_int+Input_frac )-1 DOWNTO 0) := (others => '0');
   SIGNAL mult2 			: std_logic_vector(2*(Input_int+Input_frac)-1 DOWNTO 0) := (others => '0');
    --SIGNAL Out_adder_expd    : std_logic_vector(1+(Input_int+Input_frac)-1 DOWNTO 0) := (others => '0');
	
   -- Component Declarations
   COMPONENT Adder_IT IS
     GENERIC( 
        NBitsIn 	: integer := 8;
		NBitsOut    : integer := 8;		-- (NBitsIn=NBitsOut) or (NBitsIn+1=NBitsOut)
		Index 	    : integer := 1			-- Used if NBitsIn=NBitsOut >> 1-return the LSB of the sum, 0-return the MSB of the sum 
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
				NbitsOut    : integer := 8;		    -- (NBitsIn=NBitsOut) or (NBitsIn*2=NBitsOut)
				Index 	    : integer := 2			-- Used if NBitsIn=NBitsOut
	 );
	 port (
				clk 	 : in std_logic;
				clk_en 	 : in std_logic;
				input1   : in std_logic_vector(NbitsIn-1 downto 0);
				input2   : in std_logic_vector(NbitsIn-1 downto 0);
				result   : out std_logic_vector(NbitsOut-1 downto 0)
	 );
	 END COMPONENT;
    
	COMPONENT Expander_NSigned
	GENERIC (
      Inputs_int   : integer := 2;
      Inputs_frac  : integer := 3;
      Outputs_int  : integer := 3;
      Outputs_frac : integer := 4
	);
	PORT (
      Din  : IN     std_logic_vector (Inputs_int+Inputs_frac-1 Downto 0);
      Dout : OUT    std_logic_vector (Outputs_int+Outputs_frac-1 Downto 0)
	);
	END COMPONENT;
	
BEGIN


   -- Instance port mappings.
   U_M0 : Multiplier_IT
		GENERIC MAP (
			NbitsIn 	=> (Input_int+Input_frac),
			NbitsOut => (Input_int+Input_frac)*2,
			Index 	=> 1
			)
      PORT MAP (
         clk    => clk,
         clk_en => clk_en,
         input1 => Input_re,
         input2 => Input_re,
         result => mult1
      );
	-- Multiplier A^2
   U_M1 : Multiplier_IT
		GENERIC MAP (
			NbitsIn 	=> (Input_int+Input_frac),
			NbitsOut => (Input_int+Input_frac)*2,
			Index 	=> 1
			)
      PORT MAP (
         clk    => clk,
         clk_en => clk_en,
         input1 => Input_im,
         input2 => Input_im,
         result => mult2
      );
	
	U_1 : Adder_IT
      GENERIC MAP (
			NbitsIn 	=> (Input_int+Input_frac)*2,
			NbitsOut => (Input_int+Input_frac)*2+1,
			Index 	=> 0
      )
      PORT MAP (
         input1 => mult1,
         input2 => mult2,
         result => Out_adder
      );	  
	
	U_E3 : Expander_NSigned
	 GENERIC MAP (
		  Inputs_int   => Input_int*2+1,
		  Inputs_frac  => Input_frac*2,
		  Outputs_int  => Output_int,
		  Outputs_frac => Output_frac
	 )
	 PORT MAP (
		  Din  => Out_adder,
		  Dout => result
	 );
END Struct;