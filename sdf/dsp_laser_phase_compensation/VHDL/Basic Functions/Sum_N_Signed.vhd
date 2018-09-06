
---------------------------------------------------------
-- Authors: Pedro Costa, Ricardo Ferreira, Sofia Amado --
---------------------------------------------------------

----------------------------------------------
--	Efectua o somatório de um array contendo
--	vários (N) sinais signed em vírgula fixa 
--	(array com os sinais todos armazenados 
--	sequencialmente). Caso se deseje, para 
--	evitar overflow, deve ser definido o 
--	tamanho dos dados de saída acima dos dados
--	de entrada, o que aumenta o número de bits
--	utilizados para representar a parte inteira
--	do resultado. A resolução necessária fica ao
-- critério do utilizador (Sinal de saída é suposto
-- ter o mesmo número de bits fraccionários que 
-- sinal de entrada; apenas se controla a parte
-- inteira).
--	Inputs : a.b
--	Output : c.b com 
--	c-a=DataWidth_out-DataWidth_in
--	Não introduz atraso
----------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE IEEE.STD_LOGIC_SIGNED.ALL;
---------------------------------------------------------

ENTITY Sum_N_Signed IS
   GENERIC(
	  DataWidth_in		: integer := 7;
	  DataWidth_out	: integer := 8;
     N_Signals 		: integer := 2
   );
   PORT( 
      A : IN     std_logic_vector ((DataWidth_in)*N_Signals-1 DOWNTO 0);
      Y : OUT    std_logic_vector ((DataWidth_out)-1 downto 0)
   );
	
END Sum_N_Signed ;


ARCHITECTURE Behavioral OF Sum_N_Signed IS
  
BEGIN
  P1:if (DataWidth_in) = (DataWidth_out) generate
	  process (A)
		variable B: std_logic_vector((DataWidth_out)-1 Downto 0);
	  begin
		
		B := (others => '0');
		for i in 0 to N_Signals-1 loop
			B := A((i+1)*(DataWidth_in)-1 downto i*(DataWidth_in)) + B;
		end loop;  
		
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
		-- Output:
		Y<=B;
	  end process;
	end generate;
	
	P3:if (DataWidth_in) > (DataWidth_out) generate
	  process (A)
		variable B, aux : std_logic_vector((DataWidth_in)-1 Downto 0);
	  begin
		
		B := (others => '0');
		for i in 0 to N_Signals-1 loop
			aux := A((i+1)*(DataWidth_in)-1 downto i*(DataWidth_in));
			B := B + aux;
		end loop;  
		-- Output:
		Y<=B(DataWidth_out-1 downto 0);
	  end process;
	end generate;
	
END ARCHITECTURE Behavioral;

