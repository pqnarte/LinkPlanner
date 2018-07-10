LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

library work;
USE work.out2Darray_pkg.all;

entity RAM_ModRead is
	Generic (
		Data_width		: integer := 2;
		Adrr_width		: integer := 1;
		NsigIn			: integer := 2;
		NsigOut			: integer := 4
	);
	Port ( 
		DataIn 		: in  Array2Dout;
		Adrr			: in  STD_LOGIC_VECTOR (Adrr_width - 1 downto 0);
		Clk 			: in  STD_LOGIC;
		Clk_en 		: in  STD_LOGIC;
		DataOut		: out STD_LOGIC_VECTOR (NsigOut*Data_width - 1 downto 0)
	);
end RAM_ModRead;

architecture Behavioral of RAM_ModRead is
	
begin

	-- Read process
	process (Clk)
		variable Aux_data : std_logic_vector( NsigIn * Data_width - 1 downto 0):= (others => '0');
	begin
		if rising_edge(Clk) then			
			if Clk_en = '1' then
				for i in 0 to NsigOut-1 loop
					Aux_data := DataIn(i);
					DataOut((i+1)*Data_width-1 downto i*Data_width) <= Aux_data((to_integer(unsigned(Adrr))+1)*Data_width-1 downto to_integer(unsigned(Adrr))*Data_width);
				end loop;
			end if;
		end if;
	end process;

end Behavioral;