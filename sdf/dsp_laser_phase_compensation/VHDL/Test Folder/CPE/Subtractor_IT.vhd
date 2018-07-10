
------------------------------------------------------
-- Authors: Ricardo M. Ferreira, Sofia Amado @ 2014 --
------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE IEEE.STD_LOGIC_SIGNED.ALL;
---------------------------------------------------------

ENTITY Subtractor_IT IS
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
END Subtractor_IT;


ARCHITECTURE Behavioral OF Subtractor_IT IS

	signal result1 : std_logic_vector(NBitsIn downto 0) := (others =>'0');
	
BEGIN

	result1 <= (input1(NBitsIn-1)&input1)-(input2(NBitsIn-1)&input2);
	
	ID1: if (NbitsOut = NbitsIn) generate
		result <= result1(NbitsIn-Index downto 1-Index);
	end generate;
	
	ID2: if (NbitsOut > NbitsIn) generate
		result <= result1;
	end generate;
	
END ARCHITECTURE Behavioral;

