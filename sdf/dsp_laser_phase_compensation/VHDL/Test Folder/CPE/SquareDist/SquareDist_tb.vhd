-- TestBench Template 

  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE ieee.numeric_std.ALL;
	use std.textio.all;
	use ieee.std_logic_unsigned.all;
	use ieee.math_real.all;
  ENTITY SquareDist_tb IS
  GENERIC( 
      Input_int   		: integer := 2;
		Input_frac  	   : integer := 6;
		Dist_int   	: integer := 2;
		Dist_frac  	: integer := 14;
		AdrrWidth  		: integer := 2
   );
  END SquareDist_tb;

  ARCHITECTURE behavior OF SquareDist_tb IS 

  -- Component Declaration
          COMPONENT SquareDist
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
			  END COMPONENT ;

          --Inputs
		signal clk : std_logic := '0';
		signal clk_en : std_logic := '1';
		signal Input_I_tb : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
		signal Input_R_tb : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
		signal Tphase_re_tb : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
		signal Tphase_im_tb : std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
		

		--Outputs
		signal Output_dist_tb : std_logic_vector(Dist_int+Dist_frac-1 downto 0);
		signal Output_adrr_tb : std_logic_vector(AdrrWidth-1 downto 0);
		signal Output_adrr2_tb : std_logic_vector(2-1 downto 0);
		--signal Output_dc_im_tb : std_logic_vector(Output_int+Output_frac-1 downto 0);
          
		constant clk_period : time := 10 ns;
		
  BEGIN

  -- Component Instantiation
          uut: SquareDist PORT MAP (
				 clk => clk,
				 clk_en => clk_en,
				 Input_re => Input_R_tb,
				 Input_im => Input_I_tb,
				 Tphase_re => Tphase_re_tb,
				 Tphase_im => Tphase_im_tb,
				 Output_dist => Output_dist_tb,
				 --Output_adrr2 => Output_adrr2_tb,
				 Output_adrr => Output_adrr_tb
        );
		
		-- Clock process definitions
		clk_process :process
		begin
			clk <= '0';
			wait for clk_period/2;
			clk <= '1';
			wait for clk_period/2;
		end process;
	 
	 

		-- Stimulus process
		stim_proc: process
		--begin		
			-- hold reset state for 100 ns.
--			wait for 60 ns;	
--
--			Input_R_tb <= "00001010";
--			Input_I_tb <= "11011010";
--			Tphase_re_tb <= "00110111";
--			Tphase_im_tb <= "11011111";
--
----			Input_R_tb <= "00001100";
----			Input_I_tb <= "11010111";
----			Tphase_re_tb <= "00110111";
----			Tphase_im_tb <= "11011111";
--			
--			wait;
			file file_pointer_Input_re, file_pointer_Input_img, file_pointer_Output_re, file_pointer_Output_img, file_pointer_Output_re_bit : text; 
			
		--ponteiros de linha
		variable line_pointer_Input_re, line_pointer_Input_img: line;
		variable line_pointer_Output_re, line_pointer_Output_img: line;	
		variable line_pointer_Output_re_bit: line;
		--informa��o retirada da linha
		variable var_input_re, var_input_img : integer := 0;

		
		--vari�veis
		variable var_Inputs_Real, var_Inputs_Imag	: std_logic_vector((Input_int+Input_frac)-1 downto 0) := (others => '0');
		variable var_Outputs_Real, var_Outputs_Imag	: integer := 0;
		variable var_Outputs_Real_bit  :	bit_vector((1)*(4)-1 downto 0);
		
		Variable Count : Integer := 0;		
		constant file_length : real := 6.0;
		--variable loop_cout : integer := integer(ceil((file_length/real(Nsample))))+1;
	begin
	
	-- hold reset state for 100 ns.
		--wait for 60 ns;	
		
		--abrir vectores com as componentes dos sinais X e Y canais para leitura
		file_open(file_pointer_Input_re, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Input_R.txt"), READ_MODE);
		file_open(file_pointer_Input_img, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Input_I.txt"), READ_MODE);
						
		--abrir vectores de escrita
		file_open(file_pointer_Output_re, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_R.txt"), WRITE_MODE);
		--file_open(file_pointer_Output_img, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_I.txt"), WRITE_MODE);
		
		file_open(file_pointer_Output_re_bit, string'("C:\Users\csmartins\Dropbox\_PhD\MyWorks\VHDL\Matlab_Functions\Output_re_bitSQ.txt"), WRITE_MODE);
				
		--fazer o loop e gravar a informa��o agora
		for i in 0 to 8-1 loop		
		
			for counter in 0 to 1-1 loop	
			
				--if(not endfile(file_pointer_Input_re)) then
					
					readline(file_pointer_Input_re,line_pointer_Input_re);
					readline(file_pointer_Input_img,line_pointer_Input_img);
					read(line_pointer_Input_re, var_input_re);
					read(line_pointer_Input_img, var_input_img);
															
					var_Inputs_Real((counter+1) * (Input_int+Input_frac)-1 downto counter * (Input_int+Input_frac)) := std_logic_vector(to_signed(var_input_re, (Input_int+Input_frac)));
					var_Inputs_Imag((counter+1) * (Input_int+Input_frac)-1 downto counter * (Input_int+Input_frac)) := std_logic_vector(to_signed(var_input_img, (Input_int+Input_frac)));
												
				 --end if;
			  end loop;			
				--wait for 1*clk_period;
			--atribuir as entradas
				Input_R_tb <= var_Inputs_Real;
				Input_I_tb <= var_Inputs_Imag;
				Tphase_re_tb <= "00101101";
				Tphase_im_tb <= "11010011";
--				Tphase_re_tb <= "00110111";
--				Tphase_im_tb <= "11011111";
				-- esperar por 1 per�odo de clock
				wait for 1*clk_period;
				
			for counter in 0 to 1-1 loop

				--if Count >= (((Ntap-1)/NSig)+2)+1+2 then
				
					--retirar as sa�das e armazenar num ficheiro
				
				var_Outputs_Real := conv_integer(Output_dist_tb((counter+1) * (Dist_int+Dist_frac)-1 downto counter * (Dist_int+Dist_frac)));
				--var_Outputs_Real := conv_integer(var_Inputs_Real((counter+1) * (Input_int+Input_frac)-1 downto counter * (Input_int+Input_frac)));
				write(line_pointer_Output_re, var_Outputs_Real);
				writeline(file_pointer_Output_re, line_pointer_Output_re);
										
				--end if;	
			END LOOP;
			
			var_Outputs_Real_bit := to_bitvector(Output_adrr_tb);
			
			write(line_pointer_Output_re_bit, var_Outputs_Real_bit);
			writeline(file_pointer_Output_re_bit, line_pointer_Output_re_bit);
			
			 --Count := Count + 1;
			
		 end loop;
		
		wait;
		end process;

  END;
