library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;

entity RAM_Adrr is
	Generic (
		Data_width		: integer := 2;
		AdrrWr_width	: integer := 2;
		AdrrRe_width	: integer := 1;
		NsigIn			: integer := 2;
		NsigOut			: integer := 4
	);
	Port ( 
		DataIn 		: in  STD_LOGIC_VECTOR (NsigIn*Data_width - 1 downto 0);
		AddrWr		: in  STD_LOGIC_VECTOR (AdrrWr_width - 1 downto 0);
		AddrRe		: in  STD_LOGIC_VECTOR (AdrrRe_width - 1 downto 0);
		Clk 		: in  STD_LOGIC;
		Clk_en 		: in std_logic;
		We			: in  STD_LOGIC;
		DataOut 	: out STD_LOGIC_VECTOR (NsigOut*Data_width - 1 downto 0)
	);
end RAM_Adrr;

architecture Behavioral of RAM_Adrr is
	type memory_Array is array (NsigIn - 1 downto 0) of STD_LOGIC_VECTOR (NsigOut * Data_width - 1 downto 0);
	signal memory0 : memory_Array;
begin
	
	-- Write process
	process (Clk)
		variable Aux_data : std_logic_vector(Data_width - 1 downto 0):= (others => '0');
	begin
		if rising_edge(Clk) then			
			if Clk_en = '1' then
				if We = '1' then
					for I in 0 to NsigIn-1 loop
						Aux_data := DataIn((I+1)*Data_width-1 downto I*Data_width);
						memory0(I)((to_integer(unsigned(AddrWr))+1)*Data_width-1 downto to_integer(unsigned(AddrWr))*Data_width) <= Aux_data;
					end loop;
				end if;
			end if;
		end if;
	end process;
	
	DataOut <= memory0(to_integer(unsigned(AddrRe)));

end Behavioral;