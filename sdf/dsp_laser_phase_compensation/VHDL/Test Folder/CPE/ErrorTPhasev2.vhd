library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_unsigned.all;
USE ieee.numeric_std.all;
use ieee.math_real.all;

---------------------------------------------------------

ENTITY ErrorTPhase IS
   GENERIC( 
		Input_int   	: integer := 2;
		Input_frac  	: integer := 6;
		Dist_int   		: integer := 2;
		Dist_frac  		: integer := 14;
		AdrrWidth  		: integer := 2;
		Nsample  		: integer := 1;
		NtapCPE			: integer := 1
   );
   PORT( 
      Input_re     : IN     std_logic_vector (Nsample*(Input_int+Input_frac)-1 DOWNTO 0);	  
	  Input_im	    : IN     std_logic_vector (Nsample*(Input_int+Input_frac)-1 DOWNTO 0);
	  Tphase_re     : IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);	  
	  Tphase_im	    : IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
	  clk           : IN     std_logic;
	  clk_en        : IN     std_logic;
	  --Out2_AvgDist   : OUT    std_logic_vector ((NtapCPE)*(Dist_int+Dist_frac)-1 DOWNTO 0);
	  Out_AvgDist   : OUT    std_logic_vector ((Nsample)*(Dist_int+Dist_frac)-1 DOWNTO 0);
	  Output_adrr   : OUT    std_logic_vector (Nsample*AdrrWidth-1 DOWNTO 0)
   );
END ErrorTPhase ;


ARCHITECTURE Struct OF ErrorTPhase IS
   
   
   SIGNAL Out_distSquare    : std_logic_vector (Nsample*(Dist_int+Dist_frac)-1 DOWNTO 0);
   SIGNAL Out_adrr          : std_logic_vector (Nsample*AdrrWidth-1 DOWNTO 0);
	SIGNAL Out_adrr_dl       : std_logic_vector (Nsample*AdrrWidth-1 DOWNTO 0);
   SIGNAL Out_buffer    	 : std_logic_vector ((Nsample+NtapCPE-1)*(Dist_int+Dist_frac)-1 DOWNTO 0);
   SIGNAL Out_AvgDist_rg    : std_logic_vector (Nsample*(Dist_int+Dist_frac)-1 DOWNTO 0);
   
   
   COMPONENT SquareDist 
    GENERIC( 
		Input_int   		: integer := 2;
		Input_frac  	   : integer := 6;
		Dist_int   	: integer := 2;
		Dist_frac  	: integer := 12;
		AdrrWidth  		: integer := 4
    );
    PORT( 
       Input_re    	: IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);	  
	   Input_im	    : IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
	   Tphase_re     : IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);	  
	   Tphase_im	    : IN     std_logic_vector ((Input_int+Input_frac)-1 DOWNTO 0);
	   clk           : IN     std_logic;
	   clk_en        : IN     std_logic;
	   Output_dist   : OUT    std_logic_vector ((Dist_int+Dist_frac)-1 DOWNTO 0);
	   Output_adrr   : OUT    std_logic_vector (AdrrWidth-1 DOWNTO 0)
    );
    END COMPONENT ;

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
	
   COMPONENT Buffer_IT IS
	generic (
			NBits 		: integer := 8;
			NSamplesIn	: integer := 16;
			NSamplesOut	: integer := 28
		); 
	port (
			clk 			: in std_logic;
			clk_en 		: in std_logic;
			Data_in		: in std_logic_vector(NSamplesIn*NBits-1 downto 0);
			Data_out		: out std_logic_vector(NSamplesOut*NBits-1 downto 0)
		);
	END COMPONENT;
    
	COMPONENT Average_IT IS
    GENERIC( 
		NBits		: integer := 4;
		NSamples 	: integer := 4;
		Index 	: integer := 1
    );
    PORT( 
		A 			: in std_logic_vector(NSamples*NBits-1 DOWNTO 0);
		Y 			: out std_logic_vector(NBits-1 downto 0)
    );
    END COMPONENT;
	 
	 COMPONENT Average_Ncycle IS
    GENERIC( 
		NBits		: integer := 4;
		NSamples 	: integer := 4;
		Index 	: integer := 1
    );
    PORT( 
	   clk 		: in std_logic;
		clk_en 	: in std_logic;
		A 			: in std_logic_vector(NSamples*NBits-1 DOWNTO 0);
		Y 			: out std_logic_vector(NBits-1 downto 0)
    );
    END COMPONENT;
	 
	 COMPONENT AverageN_IT IS
    GENERIC( 
		NBits		: integer := 4;
		NSamples 	: integer := 4;
		NCycles 	: integer := 1
    );
    PORT( 
		clk 		: in std_logic;
		clk_en 	: in std_logic;
		A 			: in std_logic_vector(NSamples*NBits-1 DOWNTO 0);
		Y 			: out std_logic_vector(NBits-1 downto 0)
    );
    END COMPONENT;
	 
	 COMPONENT Sum_N_Signed
		GENERIC(
		  DataWidth_in		: integer := 7;
		  DataWidth_out	: integer := 8;
		  N_Signals 		: integer := 2
		);
		PORT( 
			A : IN     std_logic_vector ((DataWidth_in)*N_Signals-1 DOWNTO 0);
			Y : OUT    std_logic_vector ((DataWidth_out)-1 downto 0)
		);	
	 END COMPONENT ;
	 
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
	
BEGIN
    
	U_SDist : for I in 0 to Nsample-1 generate
	   U_SD : SquareDist
		GENERIC MAP ( 
					Input_int   	=> Input_int,
					Input_frac   	=> Input_frac,
					Dist_int       => Dist_int,
					Dist_frac      => Dist_frac,
					AdrrWidth      => AdrrWidth
		)
		PORT MAP ( 
				  Input_re   	=> Input_re((I+1)*(Input_int+Input_frac)-1 DOWNTO (I)*(Input_int+Input_frac)),
				  Input_im  	=> Input_im((I+1)*(Input_int+Input_frac)-1 DOWNTO (I)*(Input_int+Input_frac)),
				  Tphase_re   	=> Tphase_re,
				  Tphase_im  	=> Tphase_im,
				  clk           => clk,
				  clk_en        => clk_en,     
				  Output_dist   => Out_distSquare((I+1)*(Dist_int+Dist_frac)-1 DOWNTO (I)*(Dist_int+Dist_frac)),
				  Output_adrr   => Out_adrr((I+1)*AdrrWidth-1 DOWNTO (I)*AdrrWidth)
		);
	end generate;

	D_0 : Delay_IT
       GENERIC MAP (
          depth 		 => 2,
			 Datawidth	 => Nsample*AdrrWidth
			 )
		 PORT MAP(	
			 clk 		=> clk,
			 clk_en 	 	=> clk_en,
			 Din		 	=>  Out_adrr,
			 Dout 		=> Out_adrr_dl
       );
		 
	U_B : Buffer_IT
      GENERIC MAP (
					NBits 			=> Dist_int+Dist_frac,
					NSamplesIn  	=> Nsample,
					NSamplesOut 	=> NtapCPE + Nsample - 1
			)
	  PORT MAP (
					clk    		=> clk,
					clk_en 		=> clk_en,
					Data_in		=> Out_distSquare,
					Data_out		=> Out_buffer
					--Data_out => Out_AvgDist
	  );
	  
	U_AVG : for I in 0 to Nsample-1 generate
		U_AV : Average_IT
		 GENERIC MAP (
			NBits  =>  Dist_int+Dist_frac,
			NSamples =>  NtapCPE,
			Index =>  integer(ceil(log2(real(NtapCPE))))
		 )
		 PORT MAP (
		  A  				=> Out_buffer((I+NtapCPE)*(Dist_int+Dist_frac) -1 DOWNTO I*(Dist_int+Dist_frac)),
		  Y 				=> Out_AvgDist((I+1)*(Dist_int+Dist_frac) -1 DOWNTO I*(Dist_int+Dist_frac))
		);		
	 end generate;  
		 
	Output_adrr <= Out_adrr_dl;
	 
END Struct;