{ Recursion }
program Main1;
var v:integer;

  procedure Fun(n:integer);
  begin
    if n > 10 then begin
      v:=v+n;
      Fun(n-1);
    end;
  end;

begin
  Fun(5);
end.