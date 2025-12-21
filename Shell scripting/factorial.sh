#!/bin/bash
read -p "Enter an integer number:" num
if (( num==0 || num==1 ));then 
    echo -e "Factorial = 1"
fi 
fact=1
while(( num>0 ));do 
    fact=$(( fact*num ))
    num=$(( num-1 ))
done 
echo -e "Factorial = $fact"

