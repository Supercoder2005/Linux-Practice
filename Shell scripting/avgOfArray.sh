#!/bin/bash
echo "Enter elements of array(space seperated):" 
read -a arr 
n=${#arr[@]} # used to calculate length of array
sum=0
for num in ${arr[@]}; do 
    sum=$((sum+num))
done 
avg=$((sum/n))
echo -e "Average of elements = $avg" 