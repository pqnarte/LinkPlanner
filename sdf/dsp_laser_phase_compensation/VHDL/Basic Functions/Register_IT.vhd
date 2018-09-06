
-------------------------------------------------------------------
-- Authors: Pedro Costa, Ricardo M. Ferreira, Sofia Amado @ 2014 --
-------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY Register_IT IS
  generic(
				DataWidth 	: integer := 8
			);
  port(
				clk 			: in std_logic;
				clk_en 		: in std_logic;
				data_in     : in std_logic_vector(DataWidth-1 downto 0);
				data_out    : out std_logic_vector(DataWidth-1 downto 0)
		 );
END Register_IT;

--Define ROM and initialize entries
ARCHITECTURE Behavioral OF Register_IT IS

	-- Signals
	signal stored 		: std_logic_vector(DataWidth-1 downto 0) := (others => '0');
	
BEGIN

	process(clk, clk_en)
	begin
		if(rising_edge(clk)) then
			if clk_en = '1' then
				stored <= data_in;
			end if;
		end if;
	end process;
  
	data_out <= stored;
  
END Behavioral;

