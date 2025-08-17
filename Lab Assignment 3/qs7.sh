# write a script that uses a for loop to display all even numbers between 1 and 50 
for i in {1..50}
do 
    if (( $i % 2 == 0 ))
    then 
        echo $i 
    fi 
done