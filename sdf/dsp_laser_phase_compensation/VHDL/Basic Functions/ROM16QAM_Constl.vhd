library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;
use ieee.math_real.all;

-- library work;
-- USE work.coef_type_pkg.all;

entity LutExpTPhase is
GENERIC( 
		Data_width  : integer := 6;
	    Addr_width  : integer :=6;
		Nsig   		: integer :=4
  );
port (
		clk    : in std_logic;
		clk_en : in std_logic;
		--Addr   : in std_logic_vector (Addr_width-1 DOWNTO 0);      
		out_re  : out std_logic_vector (Nsig * Data_width-1 DOWNTO 0);       
		out_im 	: out std_logic_vector (Nsig * Data_width-1 DOWNTO 0) 
	);	
end LutExpTPhase;


architecture BEHAVIOR of LutExpTPhase is

	constant n_words: integer := 2**Addr_width;
	
	subtype memoryData is std_logic_vector(Data_width-1 DOWNTO 0);
	type tmemory is array (0 to n_words-1) of memoryData;
	--type tmemory is array (0 to n_words-1) of signed(Data_width-1 downto 0);
	
	function init_mem_cos return tmemory is
		constant SCALE : real := 2**(real(DATA_WIDTH-2));
		constant phaseTest  : real := 1.0/real(n_words)-(1.0/2.0);
		variable temp_mem : tmemory := ((others=> (others=>'0')));
	begin
		for i in 0 to n_words-1 loop
			temp_mem(i) := STD_LOGIC_VECTOR(to_signed(INTEGER(cos(2.0*MATH_PI*real(i)*phaseTest)*SCALE),Data_width));
			--temp_mem(i) := (to_signed(integer(sin(2.0*MATH_PI*real(i)*phaseTest)*SCALE), Data_width)); 
		end loop;
		return temp_mem;
	end;
	function init_mem_sin return tmemory is
		constant SCALE : real := 2**(real(Data_width-2));
		constant phaseTest  : real := 1.0/real(n_words)-(1.0/2.0);
		variable temp_mem : tmemory := ((others=> (others=>'0')));
	begin
		for i in 0 to n_words-1 loop
			temp_mem(i) := STD_LOGIC_VECTOR(to_signed(INTEGER(sin(2.0*MATH_PI*real(i)*phaseTest)*SCALE),Data_width));
		end loop;
		return temp_mem;
	end;
	
	constant s_tmemory1 : tmemory := init_mem_cos;
	constant s_tmemory2 : tmemory := init_mem_sin;
		
	begin -- BEHAVIOR
		process (Clk)
			variable Cos_out_aux,Sin_out_aux : std_logic_vector(Data_width-1 DOWNTO 0):= (others => '0');
			begin -- process
			if(rising_edge(clk)) then
				if(clk_en = '1') then
					for i in 0 to Ntap_half-1 loop
					Data1((Ntap_half-i)*Data_width-1 downto (Ntap_half-i-1)*Data_width) <= s_tmemory1(i);
					Data2((i+1)*Data_width-1 downto i*Data_width) <= s_tmemory2(i);
					--aux := aux+1;
					end loop;
					out_re ((Nsig-i)*Data_width-1 downto (Nsig-i-1)*Data_width) <= s_tmemory1(i);
					out_im ((Nsig-i)*Data_width-1 downto (Nsig-i-1)*Data_width) <= s_tmemory1(i);
				end if;
			end if;
			--out_re <= Cos_out_aux;
			--out_im <= Sin_out_aux;
		end process;
	
end BEHAVIOR;