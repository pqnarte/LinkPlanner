LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

entity SelectROMadrr is
	Generic (
		Data_widthIn		: integer := 2;
		Data_widthOut		: integer := 2;
		indexWitdh		: integer := 1;
		Nsig			: integer := 2
	);
	Port ( 
		DataIn	 		: in  std_logic_vector (Data_widthIn-1 DOWNTO 0);
		MinDist 		: in  std_logic_vector (indexWitdh-1 DOWNTO 0);
		Clk 			: in  STD_LOGIC;
		Clk_en 			: in  STD_LOGIC;
		DataOut			: out std_logic_vector (Data_widthOut-1 DOWNTO 0)
	);
end SelectROMadrr;

architecture Behavioral of SelectROMadrr is
	--signal temp : std_logic_vector(Data_widthOut-1 Downto 0) := (others =>'0');
begin

	-- Read process
	process (Clk)
			variable temp : std_logic_vector(Data_widthOut-1 Downto 0) := (others =>'0');
	begin
		if rising_edge(Clk) then			
			if Clk_en = '1' then							
					temp := DataIn((to_integer(unsigned(MinDist))+1)*(Data_widthOut)-1 DOWNTO (to_integer(unsigned(MinDist)))*(Data_widthOut));
			end if;
		end if;
		DataOut <= temp;
	end process;
	--DataOut <= temp;
end Behavioral;