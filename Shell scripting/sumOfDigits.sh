#!/bin/bash 
read -p "Enter a number:" num 
sum=0
original=$num
while (( num>0 ));do 
    rem=$(( num%10 ))
    sum=$(( sum+rem ))
    num=$(( num/10 ))
done
echo -e "Sum of all digits of $original is = $sum"