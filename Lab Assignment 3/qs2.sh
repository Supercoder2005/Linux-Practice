# write a while loop to calculate out the sum of all integers from 1 to a user entered number.

read -p "Enter a number :" num
i=1
sum=0
while [ $i -le $num ]; do
    sum=$((sum+i))
    i=$((i+1))
done 
echo "Sum : $sum"