
------------------------------------------------------
-- Authors: Ricardo M. Ferreira, Sofia Amado @ 2014 --
------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
USE ieee.std_logic_arith.all;
---------------------------------------------------------

entity Sqrt_IT is
	generic ( 
			NBits		: positive:= 8 	-- NBitsIn = NBitsOut*2
	);
   PORT( 
			Input    : IN     std_logic_vector (NBits*2-1 DOWNTO 0);
			Output 	: OUT    std_logic_vector (NBits-1 DOWNTO 0)
   );
end Sqrt_IT;

architecture RTL of Sqrt_IT is
	
	signal In1	: unsigned (NBits*2-1 DOWNTO 0) := (others=>'0');
	signal Out1	: unsigned (NBits-1 DOWNTO 0) := (others=>'0');
	
	---------------------------------------------------------------------------------
	function  sqrt  ( d : UNSIGNED ) return UNSIGNED is
		variable a : unsigned(NBits*2-1 downto 0):=d;  --original input.
      variable q : unsigned(NBits-1 downto 0):=(others => '0');  --result.
      variable left,right,r : unsigned(NBits-1+2 downto 0):=(others => '0');  --input to adder/sub.r-remainder.
      variable i : integer:=0;
   begin      
		for i in 0 to NBits-1 loop         
			right(0):='1';
         right(1):=r(NBits-1+2);
         right(NBits-1+2 downto 2):=q;
         left(1 downto 0):=a(NBits*2-1 downto NBits*2-1-1);
         left(NBits-1+2 downto 2):=r(NBits-1 downto 0);
       
         a(NBits*2-1 downto 2):=a(NBits*2-1-2 downto 0);  --shifting by 2 bit.
                               
         if ( r(NBits-1+2) = '1') then
				r := left + right;
         else
            r := left - right;
         end if;
                       
         q(NBits-1 downto 1) := q(NBits-1-1 downto 0);
         q(0) := not r(NBits-1+2);
      end loop;
		
		return q;
    end sqrt;
	 
begin

	In1 <= conv_unsigned(conv_integer(Input), NBits*2);
	Out1 <= sqrt(In1);
	Output <= conv_std_logic_vector(Out1, NBits);

end RTL;
