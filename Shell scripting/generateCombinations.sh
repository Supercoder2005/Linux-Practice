#!/bin/bash 
read -p "Enter three numbers :" a b c
for i in $a $b $c ; do 
    for j in $a $b $c ; do 
        for k in $a $b $c ; do 
            echo -e "$i $j $k"
        done 
    done 
done