#!/bin/bash 
read -p "Enter start:" start
read -p "Enter end:" end 
echo -e "Prime numbers between $start and $end are:"

for(( num=start;num<=end;num++ )); do 
    if (( num<2 )); then
        continue
    fi 
    count=0
    for(( i=2;i<num;i++ )); do 
        if(( num%i==0 )); then 
            count=1
            break
        fi
    done 
    if(( count==0 )); then 
        echo "$num"
    fi 
done