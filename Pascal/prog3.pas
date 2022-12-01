{ function calls }
program Main1;
var i,j:integer;

  function Fun(a,b:integer):integer;
  begin
    if a then result:=b
      else result:=0;
  end;

begin 
  j:=2;
  i:=Fun(1,j);
end.