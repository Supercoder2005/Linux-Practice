# write a for loop script to print the multiplication table of a given number 
read -p "Enter a number :" num
for i in {1..10}
do 
    table=$((num*i))
    echo "$num x $i = $table"
done