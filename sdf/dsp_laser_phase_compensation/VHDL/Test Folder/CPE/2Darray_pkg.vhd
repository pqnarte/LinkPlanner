LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.numeric_std.all;

PACKAGE out2Darray_pkg IS
	constant Data_width 	: integer := 16;  
	constant Adrr_width 	: integer := 2;
	constant NTphase    	: integer := 1; 
	constant Nsig    		: integer := 1; 
    type ArrayIn1  is array (NTphase - 1 downto 0) of std_logic_vector(Nsig * Data_width - 1 downto 0);
	type ArrayOut  is array (Nsig - 1 downto 0) of std_logic_vector(NTphase * Data_width - 1 downto 0);
	type ArrayIn2  is array (NTphase - 1 downto 0) of std_logic_vector(Nsig * Adrr_width - 1 downto 0);
	type ArrayOut2 is array (Nsig - 1 downto 0) of std_logic_vector(NTphase * Adrr_width - 1 downto 0);
END; 
