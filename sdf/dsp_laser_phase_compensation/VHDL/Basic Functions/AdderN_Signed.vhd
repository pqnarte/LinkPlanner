
---------------------------------------------------------
-- Authors: Pedro Costa, Ricardo Ferreira, Sofia Amado --
---------------------------------------------------------

----------------------------------------------
--	Efectua a soma de dois números com vírgula
--	fixa. Caso se deseje, para evitar overflow,
--	pode ser definido o tamanho dos dados de 
--	saída acima dos dados de entrada, o que
--	aumenta o número de bits utilizados para
--	representar a parte inteira do resultado
-- (atenção: bloco supõe que a saída tem o 
-- mesmo número de bits fraccionários que a 
-- entrada; diferença de bits só na parte
-- inteira).
--	Inputs : a.b
--	Output : c.b com 
--	c-a=DataWidth_out-DataWidth_in
--	Não introduz atraso
----------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE IEEE.STD_LOGIC_SIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;
---------------------------------------------------------

ENTITY AdderN_Signed IS
   GENERIC( 
      DataWidth_in : integer := 8;
	  DataWidth_out : integer := 9
   );
   PORT( 
      DinA  : IN     std_logic_vector (DataWidth_in-1 Downto 0);
      DinB  : IN     std_logic_vector (DataWidth_in-1 Downto 0);
      Dout  : OUT    std_logic_vector (DataWidth_out-1 Downto 0)
   );	
END AdderN_Signed ;


ARCHITECTURE Behavioral OF AdderN_Signed IS

	signal aux : std_logic_vector ( DataWidth_in downto 0) := (others => '0');
	signal temp_out : std_logic_vector( DataWidth_out-1 downto 0) := (others => '0');
	
BEGIN

  aux <= (DinA(DataWidth_in-1)&DinA)+(DinB(DataWidth_in-1)&DinB);
  
  P1: if(DataWidth_out > (DataWidth_in+1)) generate
		process(aux)
			variable temp_loot : std_logic_vector(DataWidth_out-1 downto 0);
		begin
			temp_loot(DataWidth_in downto 0) := aux;
			for i in DataWidth_in+1 to DataWidth_out -1 loop
				temp_loot(i) := aux(DataWidth_in);
			end loop;
			temp_out <= temp_loot;
		end process;
	end generate;
	
	P2: if((DataWidth_in +1) = DataWidth_out) generate
		temp_out <= aux(DataWidth_out-1 downto 0);
	end generate;
	
	-- Protecçao contra overflows
	P3: if((DataWidth_in +1) > DataWidth_out) generate
		process(aux)
			variable overf: std_logic;
			variable sig_and: std_logic;
			variable sig_or: std_logic;
		begin
			sig_and := '1';
			sig_or := '0';
			for i in DataWidth_out to DataWidth_in+1 loop
				sig_and := sig_and and aux(i-1);
				sig_or := sig_or or aux(i-1);
			end loop;
			overf :=sig_and xor sig_or;
			if(((overf='1') and (aux(DataWidth_in)='1'))) then
				temp_out(DataWidth_out-1) <= '1';
				temp_out(DataWidth_out-2 downto 0) <= (others => '0');
			elsif(((overf='1') and (aux(DataWidth_in)='0'))) then
				temp_out(DataWidth_out-1) <= '0';
				temp_out(DataWidth_out-2 downto 0) <= (others => '1');
			else
				temp_out <= aux(DataWidth_out-1 downto 0);
			end if;
		end process;
	end generate;
	
	Dout <= temp_out;
	
END ARCHITECTURE Behavioral;
