
---------------------------------------------------------
-- Authors: Pedro Costa, Ricardo Ferreira, Sofia Amado --
---------------------------------------------------------

----------------------------------------
--	Introdução de um número fixo de atrasos
--	Depth no sinal com DataWidth bits
-----------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
---------------------------------------------------------

entity DelayN is
	generic (depth		: integer :=1;
			Datawidth	: integer := 8
		);
	port(	clk 		: in std_logic;
			clk_en 	: in std_logic;
			Din		: in std_logic_vector (Datawidth-1 downto 0);
			Dout 		: out std_logic_vector(Datawidth-1 downto 0)
		);
			
end DelayN;


architecture Behavioral of DelayN is

	subtype reg is std_logic_Vector(datawidth -1 downto 0);
	type delay_line is array (0 to depth) of reg;
	signal D_Line : delay_line := (others => (others => '0'));
	
begin

	D_Line(0) <= Din;
	dline : for i in 1 to depth generate
	
		process(clk)
		begin
			if(rising_edge(clk)) then
				if(clk_en='1') then
					D_Line(i)<=D_Line(i-1);
				end if;
			end if;
		end process;
		
	end generate;
	
	Dout <= D_Line(depth);
	
end Behavioral;

