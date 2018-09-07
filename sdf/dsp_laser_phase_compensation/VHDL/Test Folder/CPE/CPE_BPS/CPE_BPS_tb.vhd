-- TestBench Template 

  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  use std.textio.all;
  use ieee.numeric_std.all;
  use ieee.std_logic_unsigned.all;
  use ieee.math_real.all;
  
  
  
  ENTITY CpeBPS_tb IS
  GENERIC( 
		Input_int   		: integer := 2;
		Input_frac  		: integer := 6;
		Dist_int   			: integer := 2;
		Dist_frac  			: integer := 14;
		Output_int  		: integer := 2;
		Output_frac 		: integer := 6;
		data_lut_width		: integer := 8;
		--AdrrWidthMP 		: integer := 2;
		Nsig  				: integer := 1;
		NTphase				: integer := 2;
		Ntap				 	: integer := 1
   );
  END CpeBPS_tb;

  ARCHITECTURE behavior OF CpeBPS_tb IS 

  -- Component Declaration
          COMPONENT CpeBPS
				PORT( 
				   Input_re    		: IN     std_logic_vector (Nsig*(Input_int+Input_frac)-1 DOWNTO 0);	  
					Input_im	    		: IN     std_logic_vector (Nsig*(Input_int+Input_frac)-1 DOWNTO 0);
					clk              	: IN     std_logic;
					clk_en          	: IN     std_logic;      
					--Out_vet0    	   : OUT    std_logic_vector (Nsig*NTphase*(Dist_int+Dist_frac)-1 DOWNTO 0);
					--Out_vet    	   	: OUT    std_logic_vector (Nsig*2-1 DOWNTO 0);
					--Out_vet1    	   	: OUT    std_logic_vector (Nsig*NTphase*4-1 DOWNTO 0);
				   --Out_vet2    	   	: OUT    std_logic_vector (Nsig*4-1 DOWNTO 0);
					Output_re    	   : OUT    std_logic_vector (Nsig*(Output_int+Output_frac)-1 DOWNTO 0);
					Output_im   	   : OUT    std_logic_vector (Nsig*(Output_int+Output_frac)-1 DOWNTO 0)
				);
			  END COMPONENT ;

          --Inputs
		signal Clk_tb 				   : std_logic := '0';
		signal Clk_en_tb 			   : std_logic := '1';
		signal Input_I_tb : std_logic_vector(Nsig*(Input_int+Input_frac)-1 downto 0) := (others => '0');
		signal Input_R_tb : std_logic_vector(Nsig*(Input_int+Input_frac)-1 downto 0) := (others => '0');
		
		--Outputs
		signal Out_adrr	:    std_logic_vector (Nsig*4-1 DOWNTO 0);
		--signal Output_dist_tb : std_logic_vector((Nsig)*(Dist_int+Dist_frac)-1 downto 0);
		signal Out_MinDist1_tb : std_logic_vector(Nsig*NTphase*(4)-1 downto 0);
		signal Out_MinDist2_tb : std_logic_vector(Nsig*(4)-1 downto 0);
		signal Out_MinDist0_tb : std_logic_vector(Nsig*NTphase*(Dist_int+Dist_frac)-1 downto 0);
		signal Out_MinDist_tb  : std_logic_vector (Nsig*2-1 DOWNTO 0);
		signal Output_re_tb : std_logic_vector(Nsig*(Output_int+Output_frac)-1 downto 0);
		signal Output_im_tb : std_logic_vector(Nsig*(Output_int+Output_frac)-1 downto 0);
          
		constant clk_period : time := 10 ns;
		
  BEGIN

  -- Component Instantiation
          uut: CpeBPS PORT MAP (
				 
				 Input_re => Input_R_tb,
				 Input_im => Input_I_tb,
				 clk => clk_tb,
				 clk_en => clk_en_tb,
				 --Out_vet0 => Out_MinDist0_tb,
				 --Out_vet => Out_MinDist_tb,
				 --Out_vet1 => Out_MinDist1_tb,
				 --Out_vet2 => Out_MinDist2_tb,
				 Output_re => Output_re_tb,
				 Output_im => Output_im_tb		
				 
        );
		
		-- Clock process definitions
		clk_process :process
		begin
			Clk_tb <= '0';
			wait for clk_period/2;
			Clk_tb <= '1';
			wait for clk_period/2;
		end process;

	 
	 

		-- Stimulus process
	process
		--ficheiros com as componentes
		file file_pointer_Input_re, file_pointer_Input_img, file_pointer_Output_re, file_pointer_Output_img, file_pointer_Output_re_bit, file_pointer_Output_re_bit0,file_pointer_Output_re_bit1,file_pointer_Output_re_bit2,file_pointer_Output_re_bit3,file_pointer_Output_re_bit4 : text; 
			
		--ponteiros de linha
		variable line_pointer_Input_re, line_pointer_Input_img: line;
		variable line_pointer_Output_re, line_pointer_Output_img: line;	
		variable line_pointer_Output_re_bit, line_pointer_Output_re_bit0, line_pointer_Output_re_bit1, line_pointer_Output_re_bit2,line_pointer_Output_re_bit3,line_pointer_Output_re_bit4: line;
		--informação retirada da linha
		variable var_input_re, var_input_img : integer := 0;

		
		--variáveis
		variable var_Inputs_Real, var_Inputs_Imag	: std_logic_vector(Nsig*(Input_int+Input_frac)-1 downto 0) := (others => '0');
		variable var_Outputs_Real, var_Outputs_Imag	: integer := 0;
		--variable var_Outputs_Real_bit  :	bit_vector((Nsig+Ntap-1)*(Dist_int+Dist_frac)-1 downto 0);
		variable var_Outputs_Real_bit  :	bit_vector((Nsig*NTphase)*(Dist_int+Dist_frac)-1 downto 0);
		variable var_Outputs_Real_bit0  :	bit_vector((Nsig)*(2)-1 downto 0);
		variable var_Outputs_Real_bit1  :	bit_vector((Nsig*NTphase)*(2)-1 downto 0);
		variable var_Outputs_Real_bit2  :	bit_vector((Nsig)*(4)-1 downto 0);
		variable var_Outputs_Real_bit3  :	bit_vector((Nsig)*(Output_int+Output_frac)-1 downto 0);
		variable var_Outputs_Real_bit4  :	bit_vector((Nsig)*(Output_int+Output_frac)-1 downto 0);
		Variable Count : Integer := 0;		
		constant file_length : real := 8.0+7.0;
		variable loop_cout : integer := integer(ceil((file_length/real(Nsig))))+3;
	begin
	
--	-- hold reset state for 100 ns.
--		wait for 60 ns;	
----		
--		Input_R_tb <= "00011101000100000011011000100000";
--		Input_I_tb <= "11110000001111011111000000010000";
----		Input_R_tb <= "0011011000100000";
----		Input_I_tb <= "1111000000010000";
--				
--		wait;
	
		--abrir vectores com as componentes dos sinais X e Y canais para leitura
		file_open(file_pointer_Input_re, string'("C:\netxpto\Celestino\sdf\dsp_laser_phase_compensation\VHDL\Matlab_Functions\Input_R.txt"), READ_MODE);
		file_open(file_pointer_Input_img, string'("C:\netxpto\Celestino\sdf\dsp_laser_phase_compensation\VHDL\Matlab_Functions\Input_I.txt"), READ_MODE);
						
		--abrir vectores de escrita
		file_open(file_pointer_Output_re, string'("C:\netxpto\Celestino\sdf\dsp_laser_phase_compensation\VHDL\Matlab_Functions\Output_R0.txt"), WRITE_MODE);
		file_open(file_pointer_Output_img, string'("C:\netxpto\Celestino\sdf\dsp_laser_phase_compensation\VHDL\Matlab_Functions\Output_I0.txt"), WRITE_MODE);
		
		file_open(file_pointer_Output_re_bit, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_re_bit.txt"), WRITE_MODE);
		file_open(file_pointer_Output_re_bit0, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_re0_bit.txt"), WRITE_MODE);
		file_open(file_pointer_Output_re_bit1, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_re1_bit.txt"), WRITE_MODE);
		file_open(file_pointer_Output_re_bit2, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_re2_bit.txt"), WRITE_MODE);
		
		file_open(file_pointer_Output_re_bit3, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_re3_bit.txt"), WRITE_MODE);
		file_open(file_pointer_Output_re_bit4, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_re4_bit.txt"), WRITE_MODE);
		--fazer o loop e gravar a informação agora
		for i in 0 to loop_cout+1 loop		
		
			for counter in 0 to Nsig-1 loop	
			
				--if(not endfile(file_pointer_Input_re)) then
					
					readline(file_pointer_Input_re,line_pointer_Input_re);
					readline(file_pointer_Input_img,line_pointer_Input_img);
					read(line_pointer_Input_re, var_input_re);
					read(line_pointer_Input_img, var_input_img);
															
					var_Inputs_Real((counter+1) * (Input_int+Input_frac)-1 downto counter * (Input_int+Input_frac)) := std_logic_vector(to_signed(var_input_re, (Input_int+Input_frac)));
					var_Inputs_Imag((counter+1) * (Input_int+Input_frac)-1 downto counter * (Input_int+Input_frac)) := std_logic_vector(to_signed(var_input_img, (Input_int+Input_frac)));
												
				 --end if;
			  end loop;			
			
			--atribuir as entradas
--			Input_R_tb <= "00011101000100000011011000100000";
--			Input_I_tb <= "11110000001111011111000000010000";
			Input_R_tb <= var_Inputs_Real;
			Input_I_tb <= var_Inputs_Imag;
			
		-- esperar por 1 período de clock
			wait for 1*clk_period;
			
			for counter in 0 to Nsig-1 loop

				--if Count >= (((Ntap-1)/NSig)+2)+1+2 then
				
					--retirar as saídas e armazenar num ficheiro
				var_Outputs_Real := conv_integer(Out_MinDist0_tb((counter+1) * (Dist_int+Dist_frac)-1 downto counter * (Dist_int+Dist_frac)));
				var_Outputs_Imag := conv_integer(Output_im_tb((counter+1) * (Output_int+Output_frac)-1 downto counter * (Output_int+Output_frac)));
				
				var_Outputs_Real := conv_integer(Output_re_tb((counter+1) * (Output_int+Output_frac)-1 downto counter * (Output_int+Output_frac)));
				var_Outputs_Imag := conv_integer(Output_im_tb((counter+1) * (Output_int+Output_frac)-1 downto counter * (Output_int+Output_frac)));
				
				write(line_pointer_Output_re, var_Outputs_Real);
				writeline(file_pointer_Output_re, line_pointer_Output_re);
				
				write(line_pointer_Output_img, var_Outputs_Imag);
				writeline(file_pointer_Output_img, line_pointer_Output_img);
										
				--end if;	
			END LOOP;
			
			var_Outputs_Real_bit := to_bitvector(Out_MinDist0_tb);
			var_Outputs_Real_bit0 := to_bitvector(Out_MinDist_tb);
			var_Outputs_Real_bit1 := to_bitvector(Out_MinDist1_tb);
			var_Outputs_Real_bit2 := to_bitvector(Out_MinDist2_tb);
			var_Outputs_Real_bit3 := to_bitvector(Output_re_tb);
			var_Outputs_Real_bit4 := to_bitvector(Output_im_tb);
			
			write(line_pointer_Output_re_bit, var_Outputs_Real_bit);
			writeline(file_pointer_Output_re_bit, line_pointer_Output_re_bit);
			write(line_pointer_Output_re_bit0, var_Outputs_Real_bit0);
			writeline(file_pointer_Output_re_bit0, line_pointer_Output_re_bit0);
			write(line_pointer_Output_re_bit1, var_Outputs_Real_bit1);
			writeline(file_pointer_Output_re_bit1, line_pointer_Output_re_bit1);
			write(line_pointer_Output_re_bit2, var_Outputs_Real_bit2);
			writeline(file_pointer_Output_re_bit2, line_pointer_Output_re_bit2);
			
			write(line_pointer_Output_re_bit3, var_Outputs_Real_bit3);
			writeline(file_pointer_Output_re_bit3, line_pointer_Output_re_bit3);
			write(line_pointer_Output_re_bit4, var_Outputs_Real_bit4);
			writeline(file_pointer_Output_re_bit4, line_pointer_Output_re_bit4);
			
			 --Count := Count + 1;
			
		 end loop;
		
		wait;
		
	end process;

  END;