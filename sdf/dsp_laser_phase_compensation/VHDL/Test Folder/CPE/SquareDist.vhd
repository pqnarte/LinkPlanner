LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_signed.all;
USE ieee.numeric_std.all;
use ieee.math_real.all;

---------------------------------------------------------

ENTITY SquareDist IS
   GENERIC( 
		Input_int   		: integer := 2;
		Input_frac  	   : integer := 6;
		Dist_int   	: integer := 2;
		Dist_frac  	: integer := 14;
		AdrrWidth  		: integer := 2
   );
   PORT( 
     Input_re    	: IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);	  
	  Input_im	    : IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
	  Tphase_re     : IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);	  
	  Tphase_im	    : IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
	  clk           : IN     std_logic;
	  clk_en        : IN     std_logic;
	  Output_dist   : OUT    std_logic_vector ((Dist_int+Dist_frac)-1 DOWNTO 0);
	  --Output_adrr2   : OUT    std_logic_vector (2-1 DOWNTO 0);
	  Output_adrr   : OUT    std_logic_vector (AdrrWidth-1 DOWNTO 0)
   );
END SquareDist ;


ARCHITECTURE Struct OF SquareDist IS
   
   constant plusBit : integer := 6;
	
	SIGNAL Input_re_rg     : std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
   SIGNAL Input_im_rg     : std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
   SIGNAL Out_re_cm     : std_logic_vector ((Input_int+Input_frac+plusBit)-1 DOWNTO 0);
   SIGNAL Out_im_cm     : std_logic_vector ((Input_int+Input_frac+plusBit)-1 DOWNTO 0);
   SIGNAL Out_re_dc     : std_logic_vector ((Input_int+Input_frac+plusBit)-1 DOWNTO 0);
   SIGNAL Out_im_dc     : std_logic_vector ((Input_int+Input_frac+plusBit)-1 DOWNTO 0);
   SIGNAL Out_re_cm_dl  : std_logic_vector ((Input_int+Input_frac+plusBit)-1 DOWNTO 0);
   SIGNAL Out_im_cm_dl  : std_logic_vector ((Input_int+Input_frac+plusBit)-1 DOWNTO 0);
   SIGNAL Out_re_sb    	: std_logic_vector ((Input_int+Input_frac+plusBit)-1 DOWNTO 0);
   SIGNAL Out_im_sb    	: std_logic_vector ((Input_int+Input_frac+plusBit)-1 DOWNTO 0);
   SIGNAL Out_abs     	: std_logic_vector ((Dist_int+Dist_frac)-1 DOWNTO 0);
   signal SymAdrr 		: std_logic_vector(AdrrWidth-1 downto 0) := (others=>'0');
	signal SymAdrr_dl 	: std_logic_vector(AdrrWidth-1 downto 0) := (others=>'0');
   signal QuadNumber_fd : std_logic_vector(1 downto 0) := (others=>'0');

	
	
   COMPONENT ComplexMultiplierN_Signed
   GENERIC (
      Input_fracCM   : integer := 0;
      Input_intCM    : integer := 8;
      Output_fracCM  : integer := 0;
      Output_intCM   : integer := 8
   );
   PORT( 
      clk         : IN     std_logic;
      clk_en      : IN     std_logic;
	   Input_re1   : IN     std_logic_vector ((Input_intCM + Input_fracCM)-1 DOWNTO 0);
      Input_img1  : IN     std_logic_vector ((Input_intCM + Input_fracCM)-1 DOWNTO 0);
	   Input_re2   : IN     std_logic_vector ((Input_intCM + Input_fracCM)-1 DOWNTO 0);
      Input_img2  : IN     std_logic_vector ((Input_intCM + Input_fracCM)-1 DOWNTO 0);
      result_re   : OUT    std_logic_vector ((Output_intCM + Output_fracCM)-1 DOWNTO 0);
	   result_img  : OUT    std_logic_vector ((Output_intCM + Output_fracCM)-1 DOWNTO 0)
   );
   END COMPONENT;
	
   COMPONENT AbsCValue2 
    GENERIC( 
		  Input_int   : integer := 2;
		  Input_frac  : integer := 6;
		  Output_int  : integer := 2;
		  Output_frac : integer := 6
    );
    PORT( 
		   clk         	: IN     std_logic;
		   clk_en      	: IN     std_logic;
		   Input_re   	: IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
		   Input_im  	: IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
		   Result  		: OUT    std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0)
    );		
	END COMPONENT ;
   
   COMPONENT DecisionCircuit16QAM 
	GENERIC( 
      Input_int   	: integer := 2;
	  Input_frac  	: integer := 6;
	  AdrrWidth 	: integer := 6
	);
	PORT( 
      clk         	: IN  std_logic;
      clk_en      	: IN  std_logic;
	  Input_R 		: IN  std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
      Input_I 		: IN  std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
	  DecodeSymAdrr : OUT std_logic_vector (AdrrWidth-1 DOWNTO 0)
      --Output_R    	: OUT std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0);
      --Output_I    	: OUT std_logic_vector ((Output_int+Output_frac)-1 DOWNTO 0)
   );
	END COMPONENT;      
	
	COMPONENT DecisionCircuit4QAM 
	GENERIC( 
      Input_int   	: integer := 2;
	  Input_frac  	: integer := 6;
	  AdrrWidth 	: integer := 6
	);
	PORT( 
      clk         	: IN  std_logic;
      clk_en      	: IN  std_logic;
	  Input_R 		: IN  std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
      Input_I 		: IN  std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
	  DecodeSymAdrr : OUT std_logic_vector (AdrrWidth-1 DOWNTO 0)
   );
	END COMPONENT;
	
   COMPONENT Register_IT 
	 generic(
				DataWidth 	: integer := 8
			);
	 port(
				clk 			: in std_logic;
				clk_en 		: in std_logic;
				data_in     : in std_logic_vector(DataWidth-1 downto 0);
				data_out    : out std_logic_vector(DataWidth-1 downto 0)
		 );
	 END COMPONENT;
   
   COMPONENT Subtractor_IT 
	GENERIC( 
      NBitsIn 	: integer := 8;
		NBitsOut : integer := 8;		-- (NBitsIn=NBitsOut) or (NBitsIn+1=NBitsOut)
		Index 	: integer := 1			-- Used if NBitsIn=NBitsOut >> 1-return the LSB of the sum, 0-return the MSB of the sum 
	);
	PORT( 
      input1  : IN     std_logic_vector (NBitsIn-1 Downto 0);
      input2  : IN     std_logic_vector (NBitsIn-1 Downto 0);
      result  : OUT    std_logic_vector (NBitsOut-1 Downto 0)
	);
	END COMPONENT;
	
   COMPONENT Delay_IT
	generic (
	depth		: integer :=1;
			Datawidth	: integer :=8
		);
	port(	clk 		: in std_logic;
			clk_en 	: in std_logic;
			Din		: in std_logic_vector (Datawidth-1 downto 0);
			Dout 		: out std_logic_vector(Datawidth-1 downto 0)
		);			
	end COMPONENT;
	
	COMPONENT ROM_IQmap_Sel
	 GENERIC( 
        Data_width  : integer := 8;
	    Addr_width  : integer := 4
	 );
	 port (
		clk     : in std_logic;
		clk_en  : in std_logic;  
		Addr    : in std_logic_vector (Addr_width-1 DOWNTO 0);  
		Data1   : out std_logic_vector (Data_width-1 DOWNTO 0);        
		Data2 	: out std_logic_vector (Data_width-1 DOWNTO 0)      
	 );	
	end COMPONENT;
	
BEGIN
   
--	Input_re_rg <= Input_re;
--	Input_im_rg <= Input_im;
	
	U_CM : ComplexMultiplierN_Signed
	  GENERIC MAP (
		 Input_fracCM   => Input_frac,
		 Input_intCM    => Input_int,
		 Output_fracCM  => Input_frac+plusBit,
		 Output_intCM   => Input_int
	  )
	  PORT MAP (
		 clk    => clk,
		 clk_en => clk_en,
		 input_re1 => Input_re,
		 input_img1 => Input_im,
		 input_re2 => Tphase_re,
		 input_img2 => Tphase_im,
		 result_re => Out_re_cm,
		 result_img => Out_im_cm
	   );	
	
	-- delay of 1 clock cycle
	U_DC0 : DecisionCircuit4QAM
	   GENERIC MAP (
		  Input_frac   => Input_frac+plusBit,
		  Input_int    => Input_int,
		  AdrrWidth    => AdrrWidth
	   )
	   PORT MAP (
		  clk    	=> clk,
		  clk_en 	=> clk_en,
		  Input_R   => Out_re_cm,
		  Input_I 	=> Out_im_cm,
		  DecodeSymAdrr	=> SymAdrr
	   );
		
	-- delay of 1 clock cycle
--	U_DC0 : DecisionCircuit16QAM
--	   GENERIC MAP (
--		  Input_frac   => Input_frac+plusBit,
--		  Input_int    => Input_int,
--		  AdrrWidth    => AdrrWidth
--	   )
--	   PORT MAP (
--		  clk    	=> clk,
--		  clk_en 	=> clk_en,
--		  Input_R   => Out_re_cm,
--		  Input_I 	=> Out_im_cm,
--		  DecodeSymAdrr	=> SymAdrr
--	   );
	 
--	 U_R0 : Register_IT
--		GENERIC MAP (
--			DataWidth 	=> 4
--		)
--		PORT MAP (
--			clk      	=> clk,
--			clk_en   	=> clk_en,
--			data_in  	=> SymAdrr,
--			data_out 	=> SymAdrr_rg
--		);
	 D_2 : Delay_IT
       GENERIC MAP (
          depth 		 => 2,
			 Datawidth	 => (AdrrWidth)
			 )
		 PORT MAP(	
			 clk 		=> clk,
			 clk_en 	 	=> clk_en,
			 Din		 	=>  SymAdrr,
			 Dout 		=> SymAdrr_dl
       );
		 
	 U_ROM : ROM_IQmap_Sel 
	  GENERIC MAP( 
         Data_width  => Input_int+Input_frac + plusBit,
	      Addr_width  => AdrrWidth
	  )
	  PORT MAP(
		 clk 		=> clk,
	    clk_en 	=> clk_en, 
		 Addr    => SymAdrr,
		 Data1   => Out_re_dc,
		 Data2 	=> Out_im_dc     
	  );	
	  
		--Output_dist <= Out_re_dc;
		
	 D_0 : Delay_IT
       GENERIC MAP (
          depth 		 => 1,
			 Datawidth	 => (Input_int + Input_frac + plusBit)
			 )
		 PORT MAP(	
			 clk 		=> clk,
			 clk_en 	 	=> clk_en,
			 Din		 	=> Out_re_cm,
			 Dout 		=> Out_re_cm_dl
       );
		
	 D_1 : Delay_IT
       GENERIC MAP (
          depth 		 => 1,
			 Datawidth	 => (Input_int + Input_frac + plusBit)
			 )
		 PORT MAP(	
			 clk 		=> clk,
			 clk_en 	 	=> clk_en,
			 Din		 	=>  Out_im_cm,
			 Dout 		=> Out_im_cm_dl
       );
	
	U_S0 : Subtractor_IT
	  GENERIC MAP (
		 NBitsIn  => Input_int + Input_frac + plusBit,
		 NBitsOut => Input_int + Input_frac + plusBit,
		 Index    => 1
	  )
	  PORT MAP (
		 input1 => Out_re_cm_dl,
		 input2 => Out_re_dc,
		 result => Out_re_sb
	  );
		  
	U_S1 : Subtractor_IT
	  GENERIC MAP (
		 NBitsIn  => Input_int + Input_frac + plusBit,
		 NBitsOut => Input_int + Input_frac + plusBit,
		 Index    => 1
	  )
	  PORT MAP (
		 input1 => Out_im_cm_dl,
		 input2 => Out_im_dc,
		 result => Out_im_sb
	  );	  
	  
	  --Output_dist <= Out_re_sb;
	  
	U_Abs0 : AbsCValue2 
    GENERIC MAP ( 
      Input_int   => Input_int,
	  Input_frac   => Input_frac + plusBit,
      Output_int  => Dist_int,
	  Output_frac  => Dist_frac
    )
    PORT MAP ( 
       clk         	=> clk,
       clk_en      	=> clk_en,
	    Input_re   	=> Out_re_sb,
       Input_im  	=> Out_im_sb,
	    Result  	=> Output_dist
    );
    
--	U_R1 : Register_IT
--		GENERIC MAP (
--			DataWidth 	=> (Dist_int+Dist_frac)
--		)
--		PORT MAP (
--			clk      	=> clk,
--			clk_en   	=> clk_en,
--			data_in  	=> Out_abs,
--			data_out 	=> Output_dist
--		);
--	
	 --Output_adrr2 <= QuadNumber_fd;
	  Output_adrr <= SymAdrr_dl;
	 
END Struct;