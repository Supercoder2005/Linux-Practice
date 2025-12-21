#!/bin/bash 
read -p "Enter first number:" a
read -p "Enter second number:" b
read -p "Enter operator(+-*/):" op 
case $op in
    '+') echo "Result = $((a+b))";;
    '-') echo "Result = $((a-b))";;
    '*') echo "Result = $((a*b))";;
    '/') echo "Result = $((a/b))";;
    *) echo "Invalid operator";;
esac