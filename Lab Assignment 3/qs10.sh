# write a script that takes a number (1-7) from the user and prints the corresponding day of the week using a case statement 
read -p "Enter a number between 1 to 7:" n
case $n in 
    1) echo "Monday" ;;
    2) echo "Tuesday" ;;
    3) echo "Wednesday" ;;
    4) echo "Thursday" ;;
    5) echo "Friday" ;;
    6) echo "Saturday" ;;
    7) echo "Sunday" ;;
    *) echo "Invalid input" ;;
esac