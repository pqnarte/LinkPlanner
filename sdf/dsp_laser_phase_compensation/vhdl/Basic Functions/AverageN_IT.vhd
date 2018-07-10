
----------------------------------------------------------
-- Authors: Pedro Costa @ 2013 @ PT Inovação e Sistemas --
----------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE IEEE.STD_LOGIC_SIGNED.ALL;
use ieee.math_real.all;
---------------------------------------------------------

ENTITY AverageN_IT IS
   GENERIC( 
		NBits		: integer := 16;
		NSamples : integer := 3;
		NCycles 	: integer := 2
   );
   PORT( 
		clk 		: in std_logic;
		clk_en 	: in std_logic;
		A 			: in std_logic_vector(NSamples*NBits-1 DOWNTO 0);
      Y 			: out std_logic_vector(NBits-1 downto 0)
   );
END AverageN_IT;

ARCHITECTURE Behavioral OF AverageN_IT IS

	signal Y1, intermedio_output	: std_logic_vector(NBits-1 Downto 0) := (others => '0');
	signal counter 					: integer := 0;
	
BEGIN

	process(A)
		variable B, aux : std_logic_vector(NBits+integer(ceil(log2(real(NSamples))))-1 Downto 0);
	begin		
		B := (others => '0');
		for i in 0 to NSamples-1 loop
			aux(NBits-1 downto 0) := A((i+1)*NBits-1 downto i*NBits);
			for j in NBits to (NBits+integer(ceil(log2(real(NSamples)))))-1 loop
				aux(j) := A((i+1)*NBits-1);
			end loop;
			B := B + aux;
		end loop;  
		Y1 <= B(NBits-1+integer(ceil(log2(real(NSamples)))) downto integer(ceil(log2(real(NSamples)))));
	end process;
	
	process(clk)
		variable sum_NCycles, aux1 : std_logic_vector(NBits+integer(ceil(log2(real(NCycles))))-1 Downto 0);
	begin
		if rising_edge(clk) then
			if (clk_en = '1') then
			
				aux1(NBits-1 downto 0) := Y1;
				for j in NBits to (NBits+integer(ceil(log2(real(NCycles)))))-1 loop
					aux1(j) := Y1(NBits-1);
				end loop;
				
				if (counter = 0) then
					sum_NCycles := aux1;
				else
					sum_NCycles := sum_NCycles + aux1;
				end if;
				
				if (counter = NCycles-1) then
					counter <= 0;
					intermedio_output <= sum_NCycles(NBits-1+integer(ceil(log2(real(NCycles)))) downto integer(ceil(log2(real(NCycles)))));
				else
					counter <= counter + 1;
				end if;
			end if;
		end if;
	end process;
	
	Y <= intermedio_output;
	
END ARCHITECTURE Behavioral;

