#!/bin/bash 
echo "Enter the array elements(space seperated):" 
read -a arr
smallest=${arr[0]}
largest=${arr[0]}
for num in ${arr[@]}; do 
    if(( num<smallest )); then 
        smallest=$num 
    fi
    if(( num>largest )); then 
        largest=$num 
    fi 
done 
echo -e "Smallest number in the array : $smallest"
echo -e "Largest number in the array : $largest"