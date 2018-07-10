----------------------------------------------------------
-- Authors: Pedro Costa @ 2013 @ PT Inovação e Sistemas --
----------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE IEEE.STD_LOGIC_SIGNED.ALL;
use ieee.math_real.all;
---------------------------------------------------------

ENTITY Average_Ncycle IS
   GENERIC(
	  NBits		: integer := 16;
     NSamples	: integer := 3;
	  Index		: integer := 2
   );
   PORT( 
	  clk 		: in std_logic;
	  clk_en 	: in std_logic;
      A 		: IN     std_logic_vector (NBits*NSamples-1 DOWNTO 0);
      Y 		: OUT    std_logic_vector (NBits-1 downto 0)
   );
	
END Average_Ncycle;

ARCHITECTURE Behavioral OF Average_Ncycle IS

		signal Bx : std_logic_vector(NBits-1 downto 0);
		
BEGIN				
	process(clk)
		variable B, aux : std_logic_vector(NBits+integer(ceil(log2(real(NSamples))))-1 Downto 0);
	begin
		if rising_edge(clk) then
			if (clk_en = '1') then
				B := (others => '0');
				for i in 0 to NSamples-1 loop
					aux(NBits-1 downto 0) := A((i+1)*NBits-1 downto i*NBits);
					for j in NBits to (NBits+integer(ceil(log2(real(NSamples)))))-1 loop
						aux(j) := A((i+1)*NBits-1);
					end loop;
					B := B + aux;
				end loop;  
				Bx <= B(NBits-1+integer(ceil(log2(real(NSamples))))-Index downto integer(ceil(log2(real(NSamples))))-Index);
			end if;
		end if;
	end process;
	Y <= Bx;
END ARCHITECTURE Behavioral;