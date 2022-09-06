PROGRAM HelloWorld;
var i : Integer;
BEGIN
    i := 1;
    REPEAT
        writeln('Hello, world!');
         i := i + 1;
    UNTIL i = 10;
END.