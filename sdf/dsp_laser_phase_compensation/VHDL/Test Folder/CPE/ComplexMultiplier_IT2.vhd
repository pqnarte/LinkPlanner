------------------------------------------------------
-- Authors: Ricardo M. Ferreira, Sofia Amado @ 2014 --
------------------------------------------------------

-- Atraso = 2

LIBRARY ieee;
USE ieee.std_logic_1164.all;
---------------------------------------------------------

ENTITY ComplexMultiplier_IT IS
   GENERIC( 
		NBits		: integer := 8;
		Index		: integer := 0;
		IndexM	: integer := 2
   );
   PORT(
      clk      : IN     std_logic;
      clk_en   : IN     std_logic;
      Input_Rx : IN     std_logic_vector (NBits-1 DOWNTO 0);
      Input_Ix : IN     std_logic_vector (NBits-1 DOWNTO 0);
      Input_Ry : IN     std_logic_vector (NBits-1 DOWNTO 0);
      Input_Iy : IN     std_logic_vector (NBits-1 DOWNTO 0);
      Output_R : OUT    std_logic_vector (NBits-1 DOWNTO 0);
      Output_I : OUT    std_logic_vector (NBits-1 DOWNTO 0)
   );
	
END ComplexMultiplier_IT;


ARCHITECTURE Struct OF ComplexMultiplier_IT IS

   SIGNAL input1, input2, input3, DinA, DinB, DinB1 	: std_logic_vector(NBits DOWNTO 0);
   SIGNAL mult_I, mult_R 										: std_logic_vector(NBits+1 DOWNTO 0);
   
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
	
BEGIN

	-- a+b
   U_1 : Adder_IT
      GENERIC MAP (
			NbitsIn 	=> NBits,
			NbitsOut => NBits+1,
			Index 	=> 0
      )
      PORT MAP (
         input1 => Input_Rx,
         input2 => Input_Ix,
         result => input1
      );
		
	-- c+d
   U_2 : Adder_IT
      GENERIC MAP (
			NbitsIn 	=> NBits,
			NbitsOut => NBits+1,
			Index 	=> 0
      )
      PORT MAP (
         input1 => Input_Ry,
         input2 => Input_Iy,
         result => input2
      );
		
	-- b-a
   U_3 : Subtractor_IT
      GENERIC MAP (
			NbitsIn 	=> NBits,
			NbitsOut => NBits+1,
			Index 	=> 0
      )
      PORT MAP (
         input1 => Input_Ix,
         input2 => Input_Rx,
         result => input3
      );
		
	-- (b-a)*c
   U_4 : Multiplier_IT
		GENERIC MAP (
			NbitsIn 	=> NBits+1,
			NbitsOut => NBits+1,
			Index 	=> IndexM
			)
      PORT MAP (
         clk    => clk,
         clk_en => clk_en,
         input1 => input3,
         input2 => Input_Ry(NBits-1) & Input_Ry,
         result => DinB1
      );
		
	-- (c+d)*a
   U_5 : Multiplier_IT
		GENERIC MAP (
			NbitsIn 	=> NBits+1,
			NbitsOut => NBits+1,
			Index 	=> IndexM
			)
      PORT MAP (
         clk    => clk,
         clk_en => clk_en,
         input1 => Input_Rx(NBits-1) & Input_Rx,
         input2 => input2,
         result => DinA
      );
		
	-- (a+b)*d
   U_6 : Multiplier_IT
		GENERIC MAP (
			NbitsIn 	=> NBits+1,
			NbitsOut => NBits+1,
			Index 	=> IndexM
			)
      PORT MAP (
         clk    => clk,
         clk_en => clk_en,
         input1 => input1,
         input2 => Input_Iy(NBits-1) & Input_Iy,
         result => DinB
      );
		
	-- (c+d)*a - (a+b)*d
   U_7 : Subtractor_IT
      GENERIC MAP (
			NbitsIn 	=> NBits+1,
			NbitsOut => NBits+2,
			Index 	=> 0
      )
      PORT MAP (
         input1 => DinA,
         input2 => DinB,
         result => mult_R
      );
		
	-- (c+d)*a + (b-a)*c
   U_8 : Adder_IT
      GENERIC MAP (
			NbitsIn 	=> NBits+1,
			NbitsOut => NBits+2,
			Index 	=> 0
      )
      PORT MAP (
         input1 => DinA,
         input2 => DinB1,
         result => mult_I
      );

   U_9 : Register_IT
      GENERIC MAP (
         DataWidth => NBits
      )
      PORT MAP (
         clk      => clk,
         clk_en   => clk_en,
         data_in  => mult_R(Nbits+1-Index downto 2-Index),
         data_out => Output_R
      );
   
	U_10 : Register_IT
      GENERIC MAP (
         DataWidth => NBits
      )
      PORT MAP (
         clk      => clk,
         clk_en   => clk_en,
         data_in  => mult_I(Nbits+1-Index downto 2-Index),
         data_out => Output_I
      );
	  
END Struct;
