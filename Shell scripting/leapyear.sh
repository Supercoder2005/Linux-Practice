#!/bin/bash 
read -p "Enter your year :" year 
if (( year%4 == 0 ));then 
    echo -e "$year is Leap Year"
elif (( year%400 == 0 ));then
    echo -e "$year is Leap Year"
elif (( year%100 == 0 ));then 
    echo -e "$year is not a Leap Year"
else
    echo -e "$year is not a Leap Year"
fi
