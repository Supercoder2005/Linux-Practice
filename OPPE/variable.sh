var=5
var2=10
echo $var
echo $var2

echo $(( var+var2 ))
echo $(( var/var2 )) 
echo $(( var-var2 )) 
echo $(( var*var2 )) 

expr $var / $var2
expr $var - $var2

res="$var / $var2"
echo $res
