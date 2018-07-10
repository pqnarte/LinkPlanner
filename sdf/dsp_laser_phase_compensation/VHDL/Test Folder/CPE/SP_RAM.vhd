library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE ieee.numeric_std.ALL;

-- A 128x8 single-port RAM in VHDL
entity SP_RAM is
	 Data_width  : integer := 6;
	 Addr_width  : integer :=6;
	 Nsample   	 : integer :=4
port(
	 clk    		: in std_logic;
	 clk_en 		: in std_logic;
	 we				: in std_logic; -- Write enable 
	 RAM_ADDR		: in std_logic_vector(Addr_width downto 0); -- Address to write/read RAM
	 RAM_DATA_IN	: in std_logic_vector(Data_width downto 0); -- Data to write into RAM
	 RAM_DATA_OUT	: out std_logic_vector(Data_width downto 0) -- Data output of RAM
	);
end SP_RAM;

architecture Behavioral of SP_RAM is
-- define the new type for the 128x8 RAM 
type RAM_ARRAY is array (0 to 2**Addr_width ) of std_logic_vector (Data_width downto 0);
-- initial values in the RAM

begin
process(clk,we)
begin
	 if(rising_edge(clk)) then
		 if(we='1') then -- when write enable = 1, 
			 -- write input data into RAM at the provided address
			 RAM(to_integer(unsigned(RAM_ADDR))) <= RAM_DATA_IN;
			 -- The index of the RAM array type needs to be integer so
			 -- converts RAM_ADDR from std_logic_vector -> Unsigned -> Interger using numeric_std library
		 end if;
	 end if;
end process;
 -- Data to be read out 
 RAM_DATA_OUT <= RAM(to_integer(unsigned(RAM_ADDR)));
end Behavioral;