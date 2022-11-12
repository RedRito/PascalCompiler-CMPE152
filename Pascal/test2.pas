program ParserTest;
var
    i, k : integer;
    j : real;
    a : integer;
    n: Array [char] of array [integer] of array [integer] of char;
function max(num1, num2: integer): integer;
var
   result, pp, a: integer;
begin
   if (num1 > num2) then
      result := num1
   else result := num2;
   max := result;
        function min(num1, num2: integer): real;
            var
            result2, result5: integer;
            p: Array [char] of array [integer] of integer;
            begin
            if (num1 > num2) then
                result := num1
            else result := num2;
            max := result;
            end;
end;
procedure findMin(x, y, z: integer; var m: real); 
begin
   if x < y then
      m := x
   else
      m := y;
   
   if z <m then
      m := z;
end;
begin 
    i:= a + k + 5.5 * 4;
    while i <= 10 do 
    begin 
        writeln('i = ', i);
        i := i-1;
    end;
end.