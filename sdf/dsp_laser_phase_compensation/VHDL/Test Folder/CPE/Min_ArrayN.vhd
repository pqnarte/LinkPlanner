LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE IEEE.STD_LOGIC_SIGNED.ALL;
use IEEE.NUMERIC_STD.all;
---------------------------------------------------------

ENTITY Min_ArrayN IS
   GENERIC(
	  DataWidth_in		: integer := 4;
	  AdrrWidth			: integer := 4;
	  NsigIn			: integer := 4;
	  NsigOut			: integer := 4
   );
   PORT( 
      A1 : in  ArrayIn1;
	  A2 : in  ArrayIn2;
      Y : OUT    std_logic_vector (Nsig*(AdrrWidth)-1 downto 0)
   );
	
END Min_ArrayN ;


ARCHITECTURE Behavioral OF Min_ArrayN IS
  
BEGIN
	  process (A)
		variable B: std_logic_vector((DataWidth_in)-1 Downto 0);
		variable C: std_logic_vector((IndexWidth)-1 Downto 0) := (others =>'0');
	  begin
		
			B := A(DataWidth_in-1 downto 0);
			for i in 1 to Nsig-1 loop
				if(B > A((i+1)*(DataWidth_in)-1 downto i*(DataWidth_in))) then
					B := A((i+1)*(DataWidth_in)-1 downto i*(DataWidth_in));
					C := std_logic_vector(to_unsigned(i, IndexWidth));
				end if;
			end loop;  
			-- Output:
			Y <= C;
			C := (others =>'0');
	  end process;
	-- Read process
	process (Clk)
		variable Aux_dataIn : std_logic_vector( NsigIn * Data_width - 1 downto 0):= (others => '0');
		variable Aux_dataOut : std_logic_vector( NsigOut * Data_width - 1 downto 0):= (others => '0');
	begin
		if rising_edge(Clk) then			
			if Clk_en = '1' then
				for k in 0 to NsigIn-1 loop
					for i in 0 to NsigOut-1 loop
						Aux_dataIn := DataIn(i);
						Aux_dataOut((i+1)*Data_width-1 downto i*Data_width) := Aux_dataIn((k+1)*Data_width-1 downto k*Data_width);
					end loop;
					DataOut(k) <= Aux_dataOut;
				end loop;
			end if;
		end if;
	end process;
	
END ARCHITECTURE Behavioral;