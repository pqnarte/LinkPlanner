
---------------------------------------------------------
-- Authors: Pedro Costa, Ricardo Ferreira, Sofia Amado --
---------------------------------------------------------

---------------------------------------------
--	Multiplica dois sinais com vírgula fixa
--	utilizando o megawizard. Pode ser implementado
--	tanto em lógica como unidades DSP. Também 
--	pode ser aplicado a inteiros (colocar 0 bits
--	frac)
--	Faz arredondamento para cima do último bit
--	(sem esta feature circuito não funciona 
--	corretamente, devido aos erros de quantização)
-- Inputs int_in.frac_in bits
-- Outputs int_out.frac_out bits
--	Este bloco introduz atraso de um período de clock
---------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.math_real.all;
use ieee.std_logic_signed.all;
USE ieee.numeric_std.all;
LIBRARY lpm;
USE lpm.all;
---------------------------------------------------------

ENTITY MultiplierN_Signed IS
  generic (int_in : integer := 1;
           frac_in : integer := 7;
           int_out : integer := 1;
           frac_out : integer := 7);
  port (clk : in std_logic;
        clk_en : in std_logic;
        input1     : in std_logic_vector(int_in+frac_in-1 downto 0);
        input2     : in std_logic_vector(int_in+frac_in-1 downto 0);
        result    : out std_logic_vector(int_out+frac_out-1 downto 0));
END MultiplierN_Signed;


ARCHITECTURE Behavioral OF MultiplierN_Signed IS

	SIGNAL sub_wire0	: STD_LOGIC_VECTOR (2*(int_in+frac_in)-1 DOWNTO 0) := (others => '0');
	SIGNAL sub_wire0_1: STD_LOGIC_VECTOR ((2*int_in+frac_out)-1 DOWNTO 0) := (others => '0');

	signal result1 : std_logic_vector(int_out+frac_out-1 downto 0) := (others => '0');
	signal sig_and, sig_or, sig_ovfl : std_logic;
	

BEGIN
	process(clk)
	begin
		if(rising_edge(clk)) then
			if(clk_en='1') then
				sub_wire0<=input1*input2;
			end if;
		end if;
	end process;
	
	-- Arredondamento do último bit caso seja necessário
	U0: if(2*frac_in > frac_out) generate --neste caso pode ocorrer arredondamento
		sub_wire0_1 <= sub_wire0(2*int_in+2*frac_in-1 DOWNTO 2*frac_in-frac_out)+ sub_wire0(2*frac_in-frac_out-1);--CUIDADO
	end generate;
	
	U1: if(2*frac_in= frac_out) generate --sem arredondamento possível
		sub_wire0_1 <= sub_wire0;
	end generate;
	
	-- Monitorizar overflows (procurar mudança de bits) caso seja necessário
	U2: if(2*int_in>int_out) generate --neste caso pode ocorrer overflow
		process(sub_wire0_1)
		variable and_aux, or_aux : std_logic;
		begin
			and_aux := '1';
			or_aux := '0';
			for i in 0 to 2*int_in-int_out loop
				and_aux := and_aux and sub_wire0_1(int_out+i+frac_out-1);
				or_aux := or_aux or sub_wire0_1(int_out+i+frac_out-1);
			end loop;
			sig_and <= and_aux;
			sig_or <= or_aux;
		end process;
		sig_ovfl <= sig_and xor sig_or;
		process(sub_wire0_1, sig_ovfl)
		begin
			if((sub_wire0_1(2*int_in+frac_out-1) = '1') and (sig_ovfl='1')) then
					result1(int_out+frac_out-2 downto 0) <= (others => '0');
					result1(int_out+frac_out-1) <= '1';

			elsif((sub_wire0_1(2*int_in+frac_out-1) = '0') and (sig_ovfl='1')) then
					result1(int_out+frac_out-2 downto 0) <= (others => '1');
					result1(int_out+frac_out-1) <= '0';
			else
				result1    <= sub_wire0_1(int_out+frac_out-1 DOWNTO 0);
			end if;
		end process;
	end generate;
	
	U3: if(2*int_in = int_out) generate	--neste caso não é possível ocorrer overflow
		result1 <= sub_wire0_1;
	end generate;
	
	result <= result1;
	
END Behavioral;
