--		U_ARead : ArrayColRead 
--		GENERIC MAP (
--			Data_width		=> Dist_int+Dist_frac,
--			Adrr_width		=>	1,
--			Nline			=> Nsig,
--			Ncol			=> NTphase
--		)
--		PORT MAP ( 
--			DataIn 		 => Out_DS_memIn,
--			AdrrCol		 => std_logic_vector(to_unsigned(i, 1)),
--			Clk          => clk,
--			Clk_en       => clk_en,    
--			DataOut		 => Out_DS
--		);




--	 U_R0 : Register_IT
--		GENERIC MAP (
--			DataWidth 	=> indexWitdh
--		)
--		PORT MAP (
--			clk      	=> clk,
--			clk_en   	=> clk_en,
--			data_in  	=> Out_MinDist,
--			data_out 	=> Out_MinDist2
--		);
--	--Out_MinDist2 <= Out_MinDist;


--	
----	U_AdrrF : for I in 0 to Nsig-1 generate
----		Out_adrr_temp <= Out_adrr_memOut(I);
----		AdrrMTP((I+1)*(nBitIQmap) -1 DOWNTO I*(nBitIQmap)) <= Out_adrr_temp((to_integer(unsigned(Out_MinDist((I+1)*(indexWitdh) -1 DOWNTO I*(indexWitdh))))+1)*(nBitIQmap)-1 DOWNTO (to_integer(unsigned(Out_MinDist((I+1)*(indexWitdh) -1 DOWNTO I*(indexWitdh)))))*(nBitIQmap));
----	end generate; 
--




----	U_FRI : FindROMIndex 
----		GENERIC MAP (
----			Data_width		=> nBitIQmap,
----			indexWitdh		=>	indexWitdh,
----			NsigIn			=> Nsig,
----			NsigOut			=> NTphase
----		)
----		PORT MAP ( 
----			DataIn 		 => Out_adrr_memIn,
----			Out_MinDist  => Out_MinDist,
----			Clk          => clk,
----			Clk_en       => clk_en,    
----			DataOut		 => AdrrMTP
----		);
--		
--	--Out_vet2 <= AdrrMTP;
--	
----	U_ROMF : for I in 0 to Nsig-1 generate
----		U_ROM : ROM_IQmap_Sel 
----		  GENERIC MAP( 
----				Data_width  => Input_int+Input_frac + 6,
----				Addr_width  => 4
----		  )
----		  PORT MAP(
----			 clk 	=> clk,
----			 clk_en 	=> clk_en, 
----			 Addr    => AdrrMTP((I+1)*(nBitIQmap)-1 DOWNTO I*(nBitIQmap)),
----			 Data1   => Output_re_aux((I+1)*(Output_int+Output_frac) -1 DOWNTO I*(Output_int+Output_frac)),
----			 Data2 	=> Output_im_aux((I+1)*(Output_int+Output_frac) -1 DOWNTO I*(Output_int+Output_frac))
----		 );
----		 Out_vet2((I+1)*(nBitIQmap) -1 DOWNTO I*(nBitIQmap)) <= AdrrMTP((I+1)*(nBitIQmap) -1 DOWNTO I*(nBitIQmap));
----	end generate; 	
-- 
--		D_3 : Delay_IT
--       GENERIC MAP (
--          depth 		 => 1,
--			 Datawidth	 => (Nsig*nBitIQmap)
--			 )
--		 PORT MAP(	
--			 clk 			=> clk,
--			 clk_en 	 	=> clk_en,
--			 Din		 	=> AdrrMTP,
--			 Dout 		=> AdrrMTP_dl
--       );				
--
--
--		U_ROM : ROM_IQmap 
--		  GENERIC MAP( 
--				Data_width  => Input_int+Input_frac + 6,
--				Addr_width  => nBitIQmap,
--				Nsample => romDeep 
--		  )
--		  PORT MAP(
--			 clk 		=> clk,
--			 clk_en 	=> clk_en, 
--			 Data1   => Out_rom_re,
--			 Data2 	=> Out_rom_im
--		 );
--