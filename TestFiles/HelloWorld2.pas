PROGRAM HelloWorld;

BEGIN
    i := 0;

    REPEAT
        i := i + 1;
        write('#'); write(i);
        writeln(': Hello, world!');
    UNTIL i = 5;
END.