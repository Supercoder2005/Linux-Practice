#!/bin/bash
read -p "Enter a number:" num
count=0
if (( num<2 )); then
    echo -e "$num is not prime"
fi 
for (( i=2;i<num;i++ )); do 
    if(( num%i==0 ));then 
        count=1 
        break 
    fi 
done 
if (( count==0 )); then 
    echo -e "$num is Prime"
else 
    echo -e "$num is not Prime" 
fi
