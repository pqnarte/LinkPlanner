LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE IEEE.STD_LOGIC_SIGNED.ALL;
use IEEE.NUMERIC_STD.all;
---------------------------------------------------------

ENTITY MinArray IS
   GENERIC(
			DataWidth_in		: integer := 16;
		   IndexWidth		: integer := 1;
			Nsig 		: integer := 2
   );
   PORT( 
		clk 		: IN  std_logic;
      clk_en 	: IN  std_logic;
      A 			: IN     std_logic_vector ((DataWidth_in)*Nsig-1 DOWNTO 0);
      Y 			: OUT    std_logic_vector ((IndexWidth)-1 downto 0)
   );
	
END MinArray ;


ARCHITECTURE Behavioral OF MinArray IS
		--signal C: std_logic_vector((IndexWidth)-1 Downto 0) := (others =>'0');
BEGIN
	  process (clk)
		variable B: std_logic_vector((DataWidth_in)-1 Downto 0):= (others =>'0');
		variable C: std_logic_vector((IndexWidth)-1 Downto 0) := (others =>'0');
		variable D: std_logic_vector((DataWidth_in)-1 Downto 0) := (others =>'0');
	  begin		
			--B := A(DataWidth_in-1 downto 0);			
			if rising_edge(clk) then			
				if clk_en = '1' then
					B := A(DataWidth_in-1 downto 0);
					C := (others =>'0');
					for i in 1 to Nsig-1 loop
						D := A((i+1)*(DataWidth_in)-1 downto i*(DataWidth_in));
						if(B > D) then
							B := A((i+1)*(DataWidth_in)-1 downto i*(DataWidth_in));
							C := std_logic_vector(to_unsigned(i, IndexWidth));
						end if;
					end loop;  
					-- Output:
					Y <= C;
					B := (others =>'0');
					--C := (others =>'0');
					D := (others =>'0');
				end if;
			end if;
	  end process;
	  --Y <= C;
END ARCHITECTURE Behavioral;