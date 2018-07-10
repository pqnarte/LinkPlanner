LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.numeric_std.all;
use std.textio.all;

package constDef_pkg is
--
	-- constant dcI1 : STD_LOGIC_VECTOR(to_signed(INTEGER(0.4714),10));
	-- constant dcR1 : STD_LOGIC_VECTOR(to_signed(INTEGER(0.4714),10));
	-- constant dcI2 : STD_LOGIC_VECTOR(to_signed(INTEGER(-0.4714),10));
 	-- constant dcR2 : STD_LOGIC_VECTOR(to_signed(INTEGER(-0.4714),10));
   
	-- constant dcI1 : STD_LOGIC_VECTOR(7 downto 0) := "00011110";
	-- constant dcR1 : STD_LOGIC_VECTOR(7 downto 0) := "00011110";
	-- constant dcI2 : STD_LOGIC_VECTOR(7 downto 0) := "11100010";
 	-- constant dcR2 : STD_LOGIC_VECTOR(7 downto 0) := "11100010";
	
	constant Data_width 	: integer := 16;  
	constant Adrr_width 	: integer := 2;
	constant NTphase    	: integer := 2; 
	constant Nsig    		: integer := 1; 
    type ArrayIn1  is array (NTphase - 1 downto 0) of std_logic_vector(Nsig * Data_width - 1 downto 0);
	type ArrayOut  is array (Nsig - 1 downto 0) of std_logic_vector(NTphase * Data_width - 1 downto 0);
	type ArrayIn2  is array (NTphase - 1 downto 0) of std_logic_vector(Nsig * Adrr_width - 1 downto 0);
	type ArrayOut2 is array (Nsig - 1 downto 0) of std_logic_vector(NTphase * Adrr_width - 1 downto 0);
	
	constant nBit : integer := 14;
		
	-- (8,10)
	-- constant dcI1 : STD_LOGIC_VECTOR(nBit-1 downto 0) := "0001111001";
	-- constant dcR1 : STD_LOGIC_VECTOR(nBit-1 downto 0) := "0001111001";
	-- constant dcI2 : STD_LOGIC_VECTOR(nBit-1 downto 0) := "1110000111";
 	-- constant dcR2 : STD_LOGIC_VECTOR(nBit-1 downto 0) := "1110000111";
	
	-- (12,14)
	constant dcI1 : STD_LOGIC_VECTOR(nBit-1 downto 0) := "00011110001011";
	constant dcR1 : STD_LOGIC_VECTOR(nBit-1 downto 0) := "00011110001011";
	constant dcI2 : STD_LOGIC_VECTOR(nBit-1 downto 0) := "11100001110101";
 	constant dcR2 : STD_LOGIC_VECTOR(nBit-1 downto 0) := "11100001110101";
	
	-- constant Nsample : integer := 2**Adrr_width;
	-- subtype memoryData is std_logic_vector(nBit-1 DOWNTO 0);
	-- type tmemory is array (0 to Nsample-1) of memoryData;
	-- function init_mem (mif_file_name : in string) return tmemory;
	
	--constant s_tmemory1 : tmemory := init_mem("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\IQMap_re.txt");
	--constant s_tmemory2 : tmemory := init_mem("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\IQMap_im.txt");
	
	-- constant s_tmemory1 : tmemory := init_mem("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\IQMapQPSK_re.txt");
	-- constant s_tmemory2 : tmemory := init_mem("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\IQMapQPSK_im.txt");
	
end constDef_pkg;

-- package body constDef_pkg is
	
	-- function init_mem(mif_file_name : in string) return tmemory is
		-- file mif_file : text open read_mode is mif_file_name;
		-- variable mif_line : line;
		-- variable temp_int_v : integer := 0;
		-- variable temp_mem : tmemory;
	-- begin
		-- for i in 0 to Nsample-1 loop
			-- readline(mif_file, mif_line);
	
			-- read(mif_line, temp_int_v);
			-- temp_mem(i) := std_logic_vector(to_signed(temp_int_v, nBit));
			
		-- end loop;
		-- return temp_mem;
	-- end function;
	
-- end constDef_pkg;
