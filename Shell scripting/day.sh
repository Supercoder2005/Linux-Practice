#!/bin/bash
read -p "Enter any integer between 1 to 7:" n
case $n in 
    1) echo -e "Monday";;
    2) echo -e "Tuesday";;
    3) echo -e "Wednesday";;
    4) echo -e "Thursday";;
    5) echo -e "Friday";;
    6) echo -e "Saturday";;
    7) echo -e "Sunday";;
    *) echo -e "Invalid integer"
esac 
