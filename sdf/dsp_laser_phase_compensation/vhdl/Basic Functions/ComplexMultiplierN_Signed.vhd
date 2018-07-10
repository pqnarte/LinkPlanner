---------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
--USE ieee.std_logic_arith.all;
USE ieee.std_logic_signed.all;
USE ieee.numeric_std.all;
---------------------------------------------------------

ENTITY ComplexMultiplierN_Signed IS
   GENERIC( 
      Input_fracCM  : integer := 6;
      Input_intCM    : integer := 2;
      Output_fracCM  : integer := 6;
      Output_intCM   : integer := 2
   );
   PORT( 
       clk         : IN     std_logic;
       clk_en      : IN     std_logic;
	   Input_re1   : IN     std_logic_vector ((Input_intCM+Input_fracCM)-1 DOWNTO 0);
       Input_img1  : IN     std_logic_vector ((Input_intCM+Input_fracCM)-1 DOWNTO 0);
	   Input_re2   : IN     std_logic_vector ((Input_intCM+Input_fracCM)-1 DOWNTO 0);
       Input_img2  : IN     std_logic_vector ((Input_intCM+Input_fracCM)-1 DOWNTO 0);
       result_re   : OUT    std_logic_vector ((Output_intCM+Output_fracCM)-1 DOWNTO 0);
	   result_img  : OUT    std_logic_vector ((Output_intCM+Output_fracCM)-1 DOWNTO 0)
   );

END ComplexMultiplierN_Signed ;


ARCHITECTURE Struct OF ComplexMultiplierN_Signed IS


   SIGNAL Out_adder0 : std_logic_vector(1+(Input_intCM+Input_fracCM)-1 DOWNTO 0) := (others => '0');
   SIGNAL Out_adder1 : std_logic_vector(1+(Input_intCM+Input_fracCM)-1 DOWNTO 0) := (others => '0');
   SIGNAL result_re_aux1 : std_logic_vector(1+2*(Input_intCM+Input_fracCM+1)-1 DOWNTO 0) := (others => '0');
  --SIGNAL result_re_aux2 : std_logic_vector((Output_intCM+Output_fracCM)-1 DOWNTO 0);
   SIGNAL Out_subtrator0 : std_logic_vector(1+(Input_intCM+Input_fracCM)-1 DOWNTO 0) := (others => '0');
   SIGNAL result_img_aux1 : std_logic_vector(1+2*(Input_intCM+Input_fracCM+1)-1 DOWNTO 0) := (others => '0');
   SIGNAL result_img_aux2 : std_logic_vector((Output_intCM+Output_fracCM)-1 DOWNTO 0) := (others => '0');
   SIGNAL Values_mult1 : std_logic_vector(2*(Input_intCM+Input_fracCM + 1)-1 DOWNTO 0) := (others => '0');
   SIGNAL Values_mult2 : std_logic_vector(2*(Input_intCM+Input_fracCM + 1)-1 DOWNTO 0) := (others => '0');
   SIGNAL Values_mult3 : std_logic_vector(2*(Input_intCM+Input_fracCM + 1)-1 DOWNTO 0) := (others => '0');
   SIGNAL Input_re1_exp : std_logic_vector((Input_intCM+Input_fracCM + 1)-1 DOWNTO 0) := (others => '0');
   SIGNAL Input_re2_exp : std_logic_vector((Input_intCM+Input_fracCM + 1)-1 DOWNTO 0) := (others => '0');
   SIGNAL Input_img1_exp : std_logic_vector((Input_intCM+Input_fracCM + 1)-1 DOWNTO 0) := (others => '0');
	
	
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
   
   COMPONENT SubtractorN_Signed
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
	
   COMPONENT MultiplierN_Signed
   GENERIC (
      int_in   : integer := 2;
      frac_in  : integer := 3;
      int_out  : integer := 3;
      frac_out : integer := 4
   );
   PORT (
      clk    : IN     std_logic;
      clk_en : IN     std_logic;
      input1 : IN     std_logic_vector (int_in+frac_in-1 DOWNTO 0);
      input2 : IN     std_logic_vector (int_in+frac_in-1 DOWNTO 0);
      result : OUT    std_logic_vector (int_out+frac_out-1 DOWNTO 0)
   );
   END COMPONENT;
	
   -- COMPONENT Register_M
   -- GENERIC (
      -- DataWidth : integer := 5
   -- );
   -- PORT (
      -- clk      : IN     std_logic;
      -- clk_en   : IN     std_logic;
      -- data_in  : IN     std_logic_vector (DataWidth-1 DOWNTO 0);
      -- data_out : OUT    std_logic_vector (DataWidth-1 DOWNTO 0)
   -- );
   -- END COMPONENT;
      
BEGIN


   -- Instance port mappings.
   -- Adder B+A
   U_0 : AdderN_Signed
      GENERIC MAP (
         DataWidth_in  => Input_intCM + Input_fracCM,
         DataWidth_out => Input_intCM + Input_fracCM + 1
      )
      PORT MAP (
         DinA => Input_img1,
		   DinB => Input_re1,
         Dout => Out_adder0
      );
	  
	-- Adder C+D	
   U_1 : AdderN_Signed
      GENERIC MAP (
         DataWidth_in  => Input_intCM + Input_fracCM,
         DataWidth_out => Input_intCM + Input_fracCM + 1
      )
      PORT MAP (
         DinA => Input_re2,
		   DinB => Input_img2,
         Dout => Out_adder1
      );
	
	-- Adder C*(B+A) + A*(D-C)
	U_2 : AdderN_Signed
      GENERIC MAP (
         DataWidth_in  => (Input_intCM + Input_fracCM + 1)*2,
         DataWidth_out => (Input_intCM + Input_fracCM + 1)*2 + 1
      )
      PORT MAP (
         DinA => Values_mult1,
		   DinB => Values_mult3,
         Dout => result_img_aux1
      );
	
	-- Subtractor (D-C)
    U_3 : SubtractorN_Signed
      GENERIC MAP (
         DataWidth_in  => Input_intCM + Input_fracCM,
         DataWidth_out => Input_intCM + Input_fracCM + 1
      )
      PORT MAP (
         DinA => Input_img2,
         DinB => Input_re2,
         Dout => Out_subtrator0
      );
	
	-- Subtractor C*(B+A) - B*(C+D)
    U_4 : SubtractorN_Signed
      GENERIC MAP (
         DataWidth_in  => (Input_intCM + Input_fracCM + 1)*2,
         DataWidth_out => (Input_intCM + Input_fracCM + 1)*2 + 1
      )
      PORT MAP (
         DinA => Values_mult1,
         DinB => Values_mult2,
         Dout => result_re_aux1
      );

	-- Multiplier C*(B+A)
   U_5 : MultiplierN_Signed
      GENERIC MAP (
         int_in   => Input_intCM+1,
         frac_in  => Input_fracCM,
         int_out  => (Input_intCM+1)*2,
         frac_out => (Input_fracCM)*2
      )
      PORT MAP (
         clk    => clk,
         clk_en => clk_en,
         input1 => Input_re2_exp, -- C
         input2 => Out_adder0, -- B+A
         result => Values_mult1
      );
	
	-- Multiplier B*(C+D)
   U_6 : MultiplierN_Signed
      GENERIC MAP (
         int_in   => Input_intCM+1,
         frac_in  => Input_fracCM,
         int_out  => (Input_intCM+1)*2,
         frac_out => (Input_fracCM)*2
      )
      PORT MAP (
         clk    => clk,
         clk_en => clk_en,
         input1 => Input_img1_exp, -- B
         input2 => Out_adder1,
         result => Values_mult2
      );
	
	-- Multiplier A*(D-C)
   U_7 : MultiplierN_Signed
      GENERIC MAP (
         int_in   => Input_intCM+1,
         frac_in  => Input_fracCM,
         int_out  => (Input_intCM+1)*2,
         frac_out => Input_fracCM*2
      )
      PORT MAP (
         clk    => clk,
         clk_en => clk_en,
         input1 => Input_re1_exp, -- A
         input2 => Out_subtrator0,
         result => Values_mult3
      );
	
	-- Expander -- Expander C*(B+A) - B*(C+D)
	U_8 : Expander_NSigned
      GENERIC MAP (
         Inputs_int   => (Input_intCM+1)*2+1,
         Inputs_frac  => Input_fracCM*2,
         Outputs_int  => Output_intCM,
         Outputs_frac => Output_fracCM
      )
      PORT MAP (
         Din  => result_re_aux1,
         Dout => result_re
      );
	  
	  -- Expander C*(B+A) + B*(D-C).
	U_9 : Expander_NSigned
      GENERIC MAP (
         Inputs_int   => (Input_intCM+1)*2+1,
         Inputs_frac  => Input_fracCM*2,
         Outputs_int  => Output_intCM,
         Outputs_frac => Output_fracCM
      )
      PORT MAP (
         Din  => result_img_aux1,
         Dout => result_img
      );
	
	-- Registers -- A entrada corresponde à saída do expander
   -- U_10 : Register_M
      -- GENERIC MAP (
         -- DataWidth => (Output_intCM+Output_fracCM)
      -- )
      -- PORT MAP (
         -- clk      => clk,
         -- clk_en   => clk_en,
         -- data_in  => result_re_aux2,
         -- data_out => result_re
      -- );	
	
	-- U_11 : Register_M
      -- GENERIC MAP (
         -- DataWidth => (Output_intCM+Output_fracCM)
      -- )
      -- PORT MAP (
         -- clk      => clk,
         -- clk_en   => clk_en,
         -- data_in  => result_img_aux2,
         -- data_out => result_img
      -- );
	
	U_12 : Expander_NSigned
      GENERIC MAP (
         Inputs_int   => Input_intCM,
         Inputs_frac  => Input_fracCM,
         Outputs_int  => Input_intCM+1,
         Outputs_frac => Input_fracCM
      )
      PORT MAP (
         Din  => Input_re1,
         Dout => Input_re1_exp
      );
	
	U_13 : Expander_NSigned
      GENERIC MAP (
         Inputs_int   => Input_intCM,
         Inputs_frac  => Input_fracCM,
         Outputs_int  => Input_intCM+1,
         Outputs_frac => Input_fracCM
      )
      PORT MAP (
         Din  => Input_img1,
         Dout => Input_img1_exp
      );
	
	U_14 : Expander_NSigned
      GENERIC MAP (
         Inputs_int   => Input_intCM,
         Inputs_frac  => Input_fracCM,
         Outputs_int  => Input_intCM+1,
         Outputs_frac => Input_fracCM
      )
      PORT MAP (
         Din  => Input_re2,
         Dout => Input_re2_exp
      );

END Struct;