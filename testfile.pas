program ParserTest;

var i,j,a,b,c: integer;

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
        case b of
            1: begin  
                c:= b;
                writeln('c = ', c);
            end;
            2: begin
                c:= b + 1;
                writeln('c = ', c);
            end;
            5: begin
                c:= b*5;
                writeln('c = ', c);
            end;
    end;
end;
end.