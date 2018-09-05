LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE IEEE.STD_LOGIC_SIGNED.ALL;
---------------------------------------------------------

ENTITY MovAvgFilter IS
   GENERIC(
	  DataWidth_in		: integer := 4;
	  DataWidth_out	: integer := 6;
      N_Signals 		: integer := 5
   );
   PORT( 
      A : IN     std_logic_vector ((DataWidth_in)*N_Signals-1 DOWNTO 0);
      Y : OUT    std_logic_vector ((DataWidth_out)-1 downto 0)
   );
	
END MovAvgFilter ;


ARCHITECTURE Behavioral OF MovAvgFilter IS
  
BEGIN
  P1:if (DataWidth_in) = (DataWidth_out) generate
	  process (A)
		variable B: std_logic_vector((DataWidth_out)-1 Downto 0);
	  begin
		
		B := (others => '0');
		for i in 0 to N_Signals-1 loop
			B := A((i+1)*(DataWidth_in)-1 downto i*(DataWidth_in)) + B;
		end loop;  
		B := B / N_Signals;
		-- Output:
		Y<=B;
	  end process;
	end generate;
	
	P2:if (DataWidth_in) < (DataWidth_out) generate
	  process (A)
		variable B, aux : std_logic_vector((DataWidth_out)-1 Downto 0);
	  begin
		
		B := (others => '0');
		for i in 0 to N_Signals-1 loop
			aux((DataWidth_in)-1 downto 0) := A((i+1)*(DataWidth_in)-1 downto i*(DataWidth_in));
			for j in (DataWidth_in) to (DataWidth_out)-1 loop
				aux(j) := A((i+1)*(DataWidth_in)-1);
			end loop;
			B := B + aux;
		end loop;  
		B := B / N_Signals;
		-- Output:
		Y<=B;
	  end process;
	end generate;
	
	
END ARCHITECTURE Behavioral;