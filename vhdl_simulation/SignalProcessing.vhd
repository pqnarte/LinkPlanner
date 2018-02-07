library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;


------------------------------------------
---------- PACKAGE DECLARATIONS ----------
------------------------------------------
package SignalProcessing is
	
	procedure computation (signalIn:in std_logic_vector; signalOut:out std_logic_vector);
	
end SignalProcessing;

------------------------------------------
------------- PACKAGE BODY ---------------
------------------------------------------
package body SignalProcessing is
	
	-- Processes each byte of the signal
	procedure computation (signalIn:in std_logic_vector; signalOut:out std_logic_vector) is
	begin
		-- Implementation
		signalOut := std_logic_vector(unsigned(signalIn) + 1); --remove later
		
	end computation;
	
end SignalProcessing;