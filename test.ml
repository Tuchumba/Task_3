program 
var a: int, b: bool, c: record x: int, y: bool;; 
begin 
	{a := 6;}
	read(a);
	c.x := 1;
	while a > 0 do begin write(c.x); a := a - 1; c.x := c.x + 1 end;
	
	write(a);
	write(c.x + a)
end
@