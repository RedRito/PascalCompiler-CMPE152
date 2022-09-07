Program ScannerTest;

var
    a,b: integer;
    
begin
    a:=10;
    b:=15;
    
    if (a < b) then 
        writeln('a = ', a, ' is less than b = ', b)
    else if (a = b) then
        writeln('a = ', a, ' is equal to b =  ', b)
    else
        writeln('a = ', a, ' is greater than b = ', b);
    
end.