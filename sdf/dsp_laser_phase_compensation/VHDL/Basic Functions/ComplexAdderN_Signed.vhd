LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_signed.all;
USE ieee.numeric_std.all;
---------------------------------------------------------

ENTITY ComplexAdderN_Signed IS
   GENERIC( 
	   DataWidth_in_c		: integer := 8;
	   DataWidth_out_c	: integer := 9
   );
   PORT(      
	   InputAdder_re1   : IN     std_logic_vector ((DataWidth_in_c)-1 DOWNTO 0);
       InputAdder_img1  : IN     std_logic_vector ((DataWidth_in_c)-1 DOWNTO 0);
	   InputAdder_re2   : IN     std_logic_vector ((DataWidth_in_c)-1 DOWNTO 0);
       InputAdder_img2  : IN     std_logic_vector ((DataWidth_in_c)-1 DOWNTO 0);
       resultAdder_re   : OUT    std_logic_vector ((DataWidth_out_c)-1 DOWNTO 0);
	   resultAdder_img  : OUT    std_logic_vector ((DataWidth_out_c)-1 DOWNTO 0)
   );

END ComplexAdderN_Signed ;

ARCHITECTURE Struct OF ComplexAdderN_Signed IS
   
	--SIGNAL resultAdder_img1  :  std_logic_vector ((DataWidth_out_c)-1 DOWNTO 0);
    --SIGNAL resultAdder_re1   :  std_logic_vector ((DataWidth_out_c)-1 DOWNTO 0);
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
   END COMPONENT;
   
   COMPONENT Expander_NSigned
   GENERIC (
      Inputs_int   : integer := 2;
      Inputs_frac  : integer := 3;
      Outputs_int  : integer := 3;
      Outputs_frac : integer := 4
   );
   PORT (
      Din  : IN     std_logic_vector (Inputs_int+Inputs_frac-1 Downto 0);
      Dout : OUT    std_logic_vector (Outputs_int+Outputs_frac-1 Downto 0)
   );
   END COMPONENT;
   
BEGIN


   -- Instance port mappings.
   -- Adder B+A
   U_0 : AdderN_Signed
      GENERIC MAP (
         DataWidth_in  => DataWidth_in_c,
         DataWidth_out => DataWidth_out_c
      )
      PORT MAP (
		     DinA => InputAdder_re1,
		     DinB => InputAdder_re2,
           Dout => resultAdder_re(DataWidth_out_c-1 Downto 0)
      );
	  
	-- Adder C+D	
   U_1 : AdderN_Signed
      GENERIC MAP (
         DataWidth_in  => DataWidth_in_c,
         DataWidth_out => DataWidth_out_c
      )
      PORT MAP (
           DinA => InputAdder_img1,
		   DinB => InputAdder_img2,
           Dout => resultAdder_img(DataWidth_out_c-1 Downto 0)
      );
	
--	U_2 : Expander_NSigned
--      GENERIC MAP (
--         Inputs_int   => Input_intAM+1,
--         Inputs_frac  => Input_fracAM,
--         Outputs_int  => Input_intAM+1,
--         Outputs_frac => Input_fracAM
--      )
--      PORT MAP (
--         Din  => resultAdder_re1,
--         Dout => resultAdder_re(DataWidth_out_c-1 Downto 0)
--      );
--	  
--	  U_3 : Expander_NSigned
--      GENERIC MAP (
--         Inputs_int   => Input_intAM+1,
--         Inputs_frac  => Input_fracAM,
--         Outputs_int  => Input_intAM+1,
--         Outputs_frac => Input_fracAM
--      )
--      PORT MAP (
--         Din  => resultAdder_img1,
--         Dout => resultAdder_img(DataWidth_out_c-1 Downto 0)
--      );
		
END Struct;