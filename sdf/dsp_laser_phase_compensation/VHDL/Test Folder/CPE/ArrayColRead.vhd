LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

library work;
USE work.constDef_pkg.all;

entity ArrayColRead is
	Generic (
		Data_width		: integer := 2;
		Adrr_width		: integer := 1;
		NsigIn			: integer := 2;
		NsigOut			: integer := 4
	);
	Port ( 
		DataIn 		: in  ArrayIn1;
		AdrrCol		: in  STD_LOGIC_VECTOR (Adrr_width - 1 downto 0);
		Clk 		: in  STD_LOGIC;
		Clk_en 		: in  STD_LOGIC;
		DataOut		: out std_logic_vector( NsigOut * Data_width - 1 downto 0)
	);
end ArrayColRead;

architecture Behavioral of ArrayColRead is
	signal Aux_dataOut : std_logic_vector( NsigOut * Data_width - 1 downto 0):= (others => '0');
begin
		
	-- Read process
	process (Clk) 
		variable Aux_dataIn : std_logic_vector( NsigIn * Data_width - 1 downto 0):= (others => '0');
		
	begin
		if rising_edge(Clk) then			
			if Clk_en = '1' then
				for i in 0 to NsigOut-1 loop
					Aux_dataIn := DataIn(i);
					Aux_dataOut((i+1)*Data_width-1 downto i*Data_width) <= Aux_dataIn((to_integer(unsigned(AdrrCol))+1)*Data_width-1 downto (to_integer(unsigned(AdrrCol)))*Data_width);
				end loop;
			end if;
		end if;
	end process;
	DataOut <= Aux_dataOut;
end Behavioral;