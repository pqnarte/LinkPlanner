---------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_signed.all;
USE ieee.numeric_std.all;
---------------------------------------------------------

ENTITY DiffQuad_Encoder IS
   GENERIC( 
      Input_frac   : integer := 6;
      Input_int    : integer := 2;
      Output_frac  : integer := 12;
      Output_int   : integer := 7;
	  nBps      	 : integer := 4
   );
   PORT( 
       clk         : IN     std_logic;
       clk_en      : IN     std_logic;
	   bits_in     : IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
       result_re   : OUT    std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0);
	   result_img  : OUT    std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0)
   );

END DiffQuad_Encoder ;

ARCHITECTURE Struct OF DiffQuad_Encoder IS


 -- Internal signal declarations

 -- Component Declarations
   COMPONENT AdderN_Signed
   GENERIC (
      DataWidth_in  : integer := 5;
      DataWidth_out : integer := 6
   );
   PORT (
      DinA : IN     std_logic_vector (DataWidth_in-1 Downto 0);
      DinB : IN     std_logic_vector (DataWidth_in-1 Downto 0);
      Dout : OUT    std_logic_vector (DataWidth_out-1 Downto 0)
   );
   
   COMPONENT Register_M
	GENERIC (
	  DataWidth : integer := 5
	);
	PORT (
	  clk      : IN     std_logic;
	  clk_en   : IN     std_logic;
	  data_in  : IN     std_logic_vector (DataWidth-1 DOWNTO 0);
	  data_out : OUT    std_logic_vector (DataWidth-1 DOWNTO 0)
	);
	END COMPONENT;