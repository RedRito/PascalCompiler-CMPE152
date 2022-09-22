program ParserTest;
begin 
    i:=5;
    j:=10;
    a:= 15;

    while i <= 10 do 
    begin 
        writeln('i = ', i);
        i := i+1;
    end;

    if i = j then
        writeln('a = ', a)
    else 
        a:= 20;
        writeln('a = ', a);

    for b:=5 downto 1 do 
    begin
        writeln('b = ', b);
    end;

    for b:= 1 to 5 do 
    begin
        writeln('Value of b is: ', b);
    end;
end.