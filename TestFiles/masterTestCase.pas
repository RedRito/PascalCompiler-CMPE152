program master;

begin
	i := 1;
	while not i<5 do
	begin
		write('i = ');
		writeln(i);
		i:=i+1;
	end;
	writeln;
	i := 1;
	while i<=5 do
	begin
		j := 10;
		while j <= 30 do
		begin
			write('i = ');
			write(i);
			write(', j = ');
			writeln(j);
			j := j + 10;
		end;
	i:=i + 1
	end
end.