-----------------------------------------------------
-- Authors: Ricardo M.Ferreira, Sofia Amado @ 2014 --
-----------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
---------------------------------------------------------

--entity
ENTITY Buffer_BPS IS
  generic (
			NBits 		: integer := 8;
			NSamplesIn	: integer := 16;
         NSamplesOut	: integer := 28
		); 
  port (
			clk 			: in std_logic;
			clk_en 		: in std_logic;
			Data_in		: in std_logic_vector(NSamplesIn*NBits-1 downto 0);
			Data_out		: out std_logic_vector(NSamplesOut*NBits-1 downto 0)
		);
END Buffer_BPS;


ARCHITECTURE Behavioral OF Buffer_BPS IS

  -- Signal declaration
  signal Buffer_Data 	: std_logic_vector(NSamplesOut*NBits-1 downto 0) := (others =>'0');

BEGIN

	-- Shift register
	process(clk)
	begin
		if(rising_edge(clk)) then
			if(clk_en='1') then
				--Buffer_Data((NSamplesOut-NSamplesIn)*NBits-1 downto 0) <= Buffer_Data(NSamplesOut*NBits-1 downto NSamplesIn*NBits);
				Buffer_Data((NSamplesOut-1)*NBits-1 downto 1*NBits) <= Data_in;
			end if;
		end if;
	end process;

	Data_out <= Buffer_Data;

end Behavioral;
