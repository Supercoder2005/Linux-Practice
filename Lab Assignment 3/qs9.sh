# create a script that takes two numbers and an operation(+,-,*,/) from theuser and uses a case statement to perform the calculation(Menu driven).
read -p "Enter first number :" a
read -p "Enter second number:" b
read -p "Enter operator (+ - * /):" op

case $op in 
    +) echo "Result = $((a+b))" ;;
    -) echo "Result = $((a-b))" ;;
    *) echo "Result = $((a*b))" ;;
    /) echo "Result = $((a/b))" ;;
esac