
---------------------------------------------------------
-- Authors: Pedro Costa, Ricardo Ferreira, Sofia Amado --
---------------------------------------------------------

----------------------------------------------
--	Efectua a extensão de um sinal signed de 
--	entrada	(em termos de inteiros e/ou 
--	fraccionarios) para a saída. Utilizado para
-- efetuar a interface entre blocos com saídas
--	/entradas com formatos diferentes.
-- Não é feito controlo de overflow da entrada 
-- para a saída, por isso deve-se ter cuidado
-- na escolha das resoluções.
--	Inputs : Inputs_int.Inputs_frac
--	Output : Outputs_int.Outputs_frac 
--	Não introduz atraso
----------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE IEEE.STD_LOGIC_SIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
---------------------------------------------------------

ENTITY Expander_NSigned IS
   GENERIC( 
			Inputs_int 		: integer := 2;
			Inputs_frac 	: integer := 3;
			Outputs_int 	: integer := 3;
			Outputs_frac 	: integer := 4
   );
   PORT( 
			Din  	: IN     std_logic_vector (Inputs_int+Inputs_frac-1 Downto 0);
			Dout  : OUT    std_logic_vector (Outputs_int+Outputs_frac-1 Downto 0)
   );
END Expander_NSigned;


ARCHITECTURE Behavioral OF Expander_NSigned IS

	signal temp_int_out : std_logic_vector( Outputs_int-1 downto 0);
	signal temp_frac_out : std_logic_vector( Outputs_frac-1 downto 0);
	
BEGIN

  P1: if(Outputs_int > (Inputs_int)) generate
		process(Din)
			variable aux : std_logic_vector(Outputs_int -1 downto 0);
		begin
			aux(Inputs_int -1 downto 0) := Din(Inputs_int+Inputs_frac-1 downto Inputs_frac);
			for i in Inputs_int to Outputs_int -1 loop
				aux(i) := Din(Inputs_int+Inputs_frac-1);
			end loop;
			temp_int_out <= aux;
		end process;
	end generate;
	
	P2: if(Inputs_int >= Outputs_int) generate
		temp_int_out <= Din(Outputs_int+Inputs_frac-1 downto Inputs_frac);
	end generate;
	
	P3: if(Outputs_frac > (Inputs_frac)) generate
		process(Din)
			variable aux : std_logic_vector(Outputs_frac -1 downto 0);
		begin
			aux := (others => '0');
			aux(Outputs_frac -1 downto Outputs_frac-Inputs_frac) := Din(Inputs_frac-1 downto 0);
			temp_frac_out <= aux;
		end process;
	end generate;
	
	P4: if(Inputs_frac >= Outputs_frac) generate
		temp_frac_out <= Din(Inputs_frac-1 downto Inputs_frac-Outputs_frac);
	end generate;
	Dout <= temp_int_out&temp_frac_out;
	
END ARCHITECTURE Behavioral;

