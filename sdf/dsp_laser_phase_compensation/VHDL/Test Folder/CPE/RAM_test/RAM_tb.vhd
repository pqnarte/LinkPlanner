LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
 
ENTITY TB_RAM IS
	GENERIC (
			Data_width		: integer := 2;
			AdrrWr_width	: integer := 2;
			AdrrRe_width	: integer := 1;
			NsigIn			: integer := 2;
			NsigOut			: integer := 4
		  );
END TB_RAM;
	
ARCHITECTURE behavior OF TB_RAM IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT RAM_Adrr      PORT(
         DataIn 	: in  STD_LOGIC_VECTOR (NsigIn*Data_width - 1 downto 0);
			AddrWr	: in  STD_LOGIC_VECTOR (AdrrWr_width - 1 downto 0);
			AddrRe	: in  STD_LOGIC_VECTOR (AdrrRe_width - 1 downto 0);
			Clk 		: in  STD_LOGIC;
			We			: in  STD_LOGIC;
			Clk_en		 	: in  STD_LOGIC;
			DataOut 	: out STD_LOGIC_VECTOR (NsigOut*Data_width - 1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal CLK   : std_logic := '0';
   signal Din	 : std_logic_vector(NsigIn*Data_width-1 downto 0) := (others => '0');
   signal AddrWr	 : std_logic_vector(AdrrWr_width-1 downto 0) := (others => '0');
	signal AddrRe	 : std_logic_vector(AdrrRe_width-1 downto 0) := (others => '0');
   signal Wr_En : std_logic := '0';
   signal En    : std_logic := '1';

 	--Outputs
   signal DOut  : std_logic_vector(NsigOut*Data_width-1 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
	uut : RAM_Adrr
		PORT MAP (
			DataIn => Din,
			AddrWr => AddrWr,
			AddrRe => AddrRe,
			Clk => CLK,
			We => Wr_En,
			Clk_en => En,
			DataOut => DOut
		);

   -- Clock process definitions
   CLK_process : process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 
 
   -- Stimulate Write process
   stim_write : process
   begin		
      wait for CLK_period * 10;	
		
      for i in 0 to 3 loop
			Wr_En <= '1';
			
			Din  <= "0010" + i;
			AddrWr <= "00" + i;
			
			wait for CLK_period * 1;
--			
--			Wr_En <= '0';
--			
--			wait for clk_period * 2;
		end loop;

      wait;
   end process;
	
	-- Stimulate Read process
	stim_read : process
   begin		
      wait for CLK_period * 20;	
			
			--Wr_En <= '0';
			
			AddrRe <= "0";
			
			wait for clk_period * 1;

      wait;
   end process;

end;