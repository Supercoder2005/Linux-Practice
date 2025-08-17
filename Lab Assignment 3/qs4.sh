# Create a script that takes a number as input and uses a while loop to find its factorial
read -p "Enter an integer :" n
fact=1
while [ $n -gt 0 ]; do
    fact=$((fact*n))
    n=$((n-1))
done 
echo $fact
