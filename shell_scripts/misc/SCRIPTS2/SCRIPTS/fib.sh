begin
n=10
f1=1
f2=1
no=1
echo  $f1, $f2

while [$no -le n]
  begin
    sum = expr $f1  + $f2
    echo $sum
    $f1 = $f2 
    $f2 = $sum   
  end
end
