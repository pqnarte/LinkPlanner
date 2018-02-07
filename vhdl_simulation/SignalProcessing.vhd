library IEEE;
use IEEE.STD_LOGIC_1164.all;


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
		signalOut := signalIn; --remove later
		
	end computation;
	
end SignalProcessing;