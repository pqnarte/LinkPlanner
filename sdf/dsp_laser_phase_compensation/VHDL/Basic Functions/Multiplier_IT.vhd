
------------------------------------------------------
-- Authors: Ricardo M. Ferreira, Sofia Amado @ 2014 --
------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
use ieee.std_logic_signed.all;
---------------------------------------------------------

ENTITY Multiplier_IT IS
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
END Multiplier_IT;

ARCHITECTURE Behavioral of Multiplier_IT is

	signal result1	: std_logic_vector(2*NbitsIn-1 downto 0) := (others =>'0');

BEGIN

	process(clk)
	begin
		if(rising_edge(clk)) then
			if(clk_en='1') then
				result1 <= input1 * input2;
			end if;
		end if;
	end process;

	ID1: if (NbitsOut = NbitsIn) generate
		result <= result1(2*NbitsIn-1-Index downto NbitsIn-Index);
	end generate;
	
	ID2: if (NbitsOut > NbitsIn) generate
		result <= result1;
	end generate;
	
END Behavioral;
