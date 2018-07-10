
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_unsigned.all;
--USE ieee.std_logic_signed.all;
USE ieee.numeric_std.all;
use ieee.math_real.all;

library work;
--USE work.out2Darray_pkg.all;
USE work.constDef_pkg.all;
---------------------------------------------------------

ENTITY CpeBPS IS
   GENERIC( 
		Input_int   		: integer := 2;
		Input_frac  		: integer := 6;
		Dist_int   			: integer := 2;
		Dist_frac  			: integer := 14;
		Output_int  		: integer := 2;
		Output_frac 		: integer := 12;
		data_lut_width		: integer := 8;
		--AdrrWidth  			: integer := 4;
		Nsig  				: integer := 1;
		NTphase				: integer := 2;
		Ntap				 	: integer := 1
   );
   PORT( 
      Input_re    		: IN     std_logic_vector (Nsig*(Input_int+Input_frac)-1 DOWNTO 0);	  
	   Input_im	    		: IN     std_logic_vector (Nsig*(Input_int+Input_frac)-1 DOWNTO 0);
      clk              	: IN     std_logic;
      clk_en          	: IN     std_logic;      		
      Output_re    	   : OUT    std_logic_vector (Nsig*(Output_int+Output_frac)-1 DOWNTO 0);
	   Output_im   	   : OUT    std_logic_vector (Nsig*(Output_int+Output_frac)-1 DOWNTO 0)
   );
END CpeBPS ;


ARCHITECTURE Struct OF CpeBPS IS
   
	constant nBitIQmap : integer := 2;
	constant romDeep : integer := 2**2;
   constant indexWitdh : integer := (integer(ceil(log2(real(NTphase)))));
	
   SIGNAL Input_re_dl		    : std_logic_vector (Nsig*(Input_int+Input_frac)-1 DOWNTO 0) := (others =>'0');
   SIGNAL Input_im_dl		    : std_logic_vector (Nsig*(Input_int+Input_frac)-1 DOWNTO 0) := (others =>'0');
   SIGNAL Lut_Out_re 		: std_logic_vector (NTphase*(Input_int+Input_frac)-1 DOWNTO 0); --:= "0100000000101101";
   SIGNAL Lut_Out_im 		: std_logic_vector (NTphase*(Input_int+Input_frac)-1 DOWNTO 0); --:= "0000000011010011";
   SIGNAL Out_DS    			: std_logic_vector (NTphase*(Dist_int+Dist_frac)-1 DOWNTO 0) := (others =>'0');
	SIGNAL Out_adrr_temp     : std_logic_vector (NTphase*(nBitIQmap)-1 DOWNTO 0) := (others =>'0');
   SIGNAL AdrrMTP          : std_logic_vector (Nsig*(nBitIQmap)-1 DOWNTO 0) := (others =>'0');
	SIGNAL AdrrMTP_dl          : std_logic_vector (Nsig*(nBitIQmap)-1 DOWNTO 0) := (others =>'0');
   SIGNAL Out_MinDist    	: std_logic_vector (Nsig*indexWitdh-1 DOWNTO 0) := (others =>'0');
	SIGNAL Out_MinDist2    	: std_logic_vector (Nsig*indexWitdh-1 DOWNTO 0) := (others =>'0');
   SIGNAL Out_rom_re    	   : std_logic_vector (romDeep*(Output_int+Output_frac)-1 DOWNTO 0) := (others =>'0');
	SIGNAL Out_rom_im   	   : std_logic_vector (romDeep*(Output_int+Output_frac)-1 DOWNTO 0) := (others =>'0');
	SIGNAL Out_vet_aux          : std_logic_vector (1*(nBitIQmap)-1 DOWNTO 0) := (others =>'0');	
	SIGNAL EstPhase_re		    : std_logic_vector (Nsig*(Input_int+Input_frac)-1 DOWNTO 0) := (others =>'0');
	SIGNAL EstPhase_im		    : std_logic_vector (Nsig*(Input_int+Input_frac)-1 DOWNTO 0) := (others =>'0');
  
	 
	signal Out_DS_memIn 			: ArrayIn1;
	signal Out_DS_memOut 		: ArrayOut;
	signal Out_adrr_memIn 		: ArrayIn2;
	signal Out_adrr_memIn_dl 	: ArrayIn2;
	signal Out_adrr_memOut 	   : ArrayOut2;
	signal Out_adrr_memOut_dl  : ArrayOut2;
	
	
   COMPONENT ErrorTPhase 
   GENERIC( 
		Input_int   	: integer := 2;
		Input_frac  	: integer := 6;
		Dist_int   		: integer := 2;
		Dist_frac  		: integer := 14;
		AdrrWidth  		: integer := 4;
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
	  Out_AvgDist   : OUT    std_logic_vector ((Nsample)*(Dist_int+Dist_frac)-1 DOWNTO 0);
	  Output_adrr   : OUT    std_logic_vector (Nsample*AdrrWidth-1 DOWNTO 0)
   );
	END COMPONENT ;
   
   COMPONENT TPhaseExpLut_File 
	GENERIC( 
			 Data_width   : integer := 8;
			 Addr_width   : integer := 2;
			 NTphase      : integer := 4
	  );
	port (
			clk    	: in std_logic;
			clk_en 	: in std_logic;
			--Addr   	: in std_logic_vector  (Addr_width-1 DOWNTO 0);      
			Cos_out  : out std_logic_vector (NTphase*Data_width-1 DOWNTO 0);       
			Sin_out 	: out std_logic_vector (NTphase*Data_width-1 DOWNTO 0) 
		);		
	end COMPONENT;
   
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
   
   COMPONENT MinArray
	GENERIC(
		  DataWidth_in		: integer := 7;
		  IndexWidth		: integer := 7;
		  Nsig 		: integer := 2
	);
	PORT( 
		  clk 		: IN  std_logic;
        clk_en 	: IN  std_logic;
		  A : IN     std_logic_vector ((DataWidth_in)*Nsig-1 DOWNTO 0);
		  Y : OUT    std_logic_vector ((IndexWidth)-1 downto 0)
	);		
	END COMPONENT;
	
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
	
	COMPONENT ROM_IQmap
	 GENERIC( 
       Data_width  : integer := 8;
	    Addr_width  : integer := 4;
		 Nsample     : integer := 4
	 );
	 port (
		clk     : in std_logic;
		clk_en  : in std_logic;  
		--Addr    : in std_logic_vector (Addr_width-1 DOWNTO 0);  
		Data1   : out std_logic_vector (Nsample * Data_width-1 DOWNTO 0);        
		Data2   : out std_logic_vector (Nsample * Data_width-1 DOWNTO 0)      
	 );	
	end COMPONENT;
	
	COMPONENT Array2Array 
	Generic (
			Data_width		: integer := 2;
			--Adrr_width		: integer := 1;
			NsigIn			: integer := 2;
			NsigOut			: integer := 4
		);
		Port ( 
			DataIn 		: in  ArrayIn1;
			--Adrr			: in  STD_LOGIC_VECTOR (Adrr_width - 1 downto 0);
			Clk 			: in  STD_LOGIC;
			Clk_en 		: in  STD_LOGIC;
			DataOut		: out ArrayOut
		);
	end COMPONENT;
	
	COMPONENT Array2Array2 
	Generic (
			Data_width		: integer := 2;
			--Adrr_width		: integer := 1;
			NsigIn			: integer := 2;
			NsigOut			: integer := 4
		);
		Port ( 
			DataIn 		: in  ArrayIn2;
			--Adrr			: in  STD_LOGIC_VECTOR (Adrr_width - 1 downto 0);
			Clk 			: in  STD_LOGIC;
			Clk_en 		: in  STD_LOGIC;
			DataOut		: out ArrayOut2
		);
	end COMPONENT;
	
	COMPONENT FindROMIndex 
	Generic (
		Data_width		: integer := 2;
		indexWitdh		: integer := 1;
		NsigIn			: integer := 2;
		NsigOut			: integer := 4
	);
	Port ( 
		DataIn 		: in  ArrayIn2;
		Out_MinDist 	: in  std_logic_vector (NsigIn * indexWitdh-1 DOWNTO 0);
		Clk 			: in  STD_LOGIC;
		Clk_en 			: in  STD_LOGIC;
		DataOut			: out std_logic_vector (NsigIn * Data_width-1 DOWNTO 0)
	);
	end COMPONENT;
	
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
	
	COMPONENT SelectROMadrr 
	Generic (
		Data_widthIn		: integer := 2;
		Data_widthOut		: integer := 2;
		indexWitdh		: integer := 1;
		Nsig				: integer := 2
	);
	Port ( 
		DataIn	 		: in  std_logic_vector (Data_widthIn-1 DOWNTO 0);
		MinDist 		: in  std_logic_vector (indexWitdh-1 DOWNTO 0);
		Clk 			: in  STD_LOGIC;
		Clk_en 			: in  STD_LOGIC;
		DataOut			: out std_logic_vector (Data_widthOut-1 DOWNTO 0)
	);
	end COMPONENT;
	
	COMPONENT ArrayColRead 
	Generic (
		Data_width		: integer := 2;
		Adrr_width		: integer := 1;
		NsigIn			: integer := 2;
		NsigOut			: integer := 4
	);
	Port ( 
		DataIn 		: in  ArrayIn1;
		AdrrCol		: in  STD_LOGIC_VECTOR (Adrr_width - 1 downto 0);
		Clk 			: in  STD_LOGIC;
		Clk_en 		: in  STD_LOGIC;
		DataOut		: out std_logic_vector( NsigOut * Data_width - 1 downto 0)
	);
	end COMPONENT;

BEGIN
    
	-------------------------------	X Polarization ----------------------------------
	---------------------------------------------------------------------------------

	D_0 : Delay_IT
	 GENERIC MAP (
		 depth 		 => 1,
		 Datawidth	 => Nsig*(Input_int+Input_frac)
		 )
	 PORT MAP(	
		 clk 			=> clk,
		 clk_en 	 	=> clk_en,
		 Din		 	=> Input_re,
		 Dout 		=> Input_re_dl
	 );	

	D_1 : Delay_IT
	 GENERIC MAP (
		 depth 		 => 1,
		 Datawidth	 => Nsig*(Input_int+Input_frac)
		 )
	 PORT MAP(	
		 clk 			=> clk,
		 clk_en 	 	=> clk_en,
		 Din		 	=> Input_im,
		 Dout 		=> Input_im_dl
	);
		
	---------------------------------------------------------------
-------------- LUT Read ---------------------------------------
	
	 U_L0 : TPhaseExpLut_File 
	   GENERIC MAP (
			 Addr_width   => indexWitdh,
			 Data_width   => data_lut_width,
			 NTphase      => NTphase
       )
	 PORT MAP (
			 clk 		=> clk,
			 clk_en 	=> clk_en,
			 Cos_out 	=> Lut_Out_re,
			 Sin_out 	=> Lut_Out_im   
	   );
	
	U_EPF : for I in 0 to NTphase-1 generate		
	   U_EP : ErrorTPhase
		GENERIC MAP ( 
					Input_int   	=> Input_int,
					Input_frac   	=> Input_frac,
					Dist_int   		=> Dist_int,
					Dist_frac  		=> Dist_frac,
					AdrrWidth  		=> nBitIQmap,
					Nsample  		=> Nsig,
					NtapCPE			=> Ntap
		)
		PORT MAP ( 
				  Input_re   	=> Input_re_dl,
				  Input_im  	=> Input_im_dl,
				  Tphase_re   	=> Lut_Out_re((I+1)*(data_lut_width) -1 DOWNTO I*(data_lut_width)),
				  Tphase_im  	=> Lut_Out_im((I+1)*(data_lut_width) -1 DOWNTO I*(data_lut_width)),
				  clk          => clk,
				  clk_en       => clk_en,     
				  Out_AvgDist  => Out_DS_memIn(I),
				  Output_adrr  => Out_adrr_memIn(I)
		);				
	end generate;
	
	U_RAM0 : Array2Array 
		GENERIC MAP (
			Data_width		=> Dist_int+Dist_frac,
			--Adrr_width		=>	indexWitdh,
			NsigIn			=> Nsig,
			NsigOut			=> NTphase
		)
		PORT MAP ( 
			DataIn 		 => Out_DS_memIn,
			--Adrr			 => Out_DS_mem,
			Clk          => clk,
			Clk_en       => clk_en,    
			DataOut		 => Out_DS_memOut
		);
	
	U_RAM1 : Array2Array2 
		GENERIC MAP (
			Data_width		=> nBitIQmap,
			--Adrr_width		=>	indexWitdh,
			NsigIn			=> Nsig,
			NsigOut			=> NTphase
		)
		PORT MAP ( 
			DataIn 		 => Out_adrr_memIn,
			--Adrr			 => Out_DS_mem,
			Clk          => clk,
			Clk_en       => clk_en,    
			DataOut		 => Out_adrr_memOut
		);
	
	U_DLF : for I in 0 to Nsig-1 generate		
	   D_1 : Delay_IT
       GENERIC MAP (
          depth 		 => integer((Ntap-1)/2),
			 Datawidth	 => (NTphase*nBitIQmap)
			 )
		 PORT MAP(	
			 clk 			=> clk,
			 clk_en 	 	=> clk_en,
			 Din		 	=> Out_adrr_memOut(I),
			 Dout 		=> Out_adrr_memOut_dl(I)
       );				
	end generate;
	
	U_MAF : for I in 0 to Nsig-1 generate
		U_MA : MinArray
		 GENERIC MAP(
			  DataWidth_in	=> Dist_int+Dist_frac,
			  IndexWidth	=>	indexWitdh,
			  Nsig 			=> NTphase
		 )
		 PORT MAP( 
			  clk          => clk,
			  clk_en       => clk_en, 
			  A 				=> Out_DS_memOut(I),
			  Y 				=> Out_MinDist((I+1)*(indexWitdh) -1 DOWNTO I*(indexWitdh))
		 );

	 U_FRI : SelectROMadrr 
			GENERIC MAP (
				Data_widthIn	=> NTphase*nBitIQmap,
				Data_widthOut	=>	nBitIQmap,
				indexWitdh		=>	indexWitdh,
				Nsig				=> NTphase
			)
			PORT MAP ( 
				DataIn 		 => Out_adrr_memOut_dl(I),
				MinDist  	 => Out_MinDist((I+1)*(indexWitdh) -1 DOWNTO I*(indexWitdh)),
				Clk          => clk,
				Clk_en       => clk_en,    
				DataOut		 => AdrrMTP((I+1)*(nBitIQmap) -1 DOWNTO I*(nBitIQmap))
			);
	end generate; 

	U_AdrrF : for I in 0 to Nsig-1 generate
		U_ROM : ROM_IQmap_Sel 
		  GENERIC MAP( 
				Data_width  => Output_int+Output_frac,
				Addr_width  => nBitIQmap
		  )
		  PORT MAP(
			 clk 		=> clk,
			 clk_en 	=> clk_en, 
			 Addr    => AdrrMTP((I+1)*(nBitIQmap) -1 DOWNTO I*(nBitIQmap)),
			 Data1   => Output_re((I+1)*(Output_int+Output_frac)-1 DOWNTO I*(Output_int+Output_frac)),
			 Data2 	=> Output_im((I+1)*(Output_int+Output_frac)-1 DOWNTO I*(Output_int+Output_frac))     
		  );
	end generate; 
		
END Struct;