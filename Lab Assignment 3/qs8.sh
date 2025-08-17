# use a for loop to print the following pattern for n rows entered by user
read -p "Enter no of rows :" n
for ((i=1;i<=n;i++))
do 
    for ((j=1;j<=i;j++))
    do 
        echo -n "*"
    done
    echo 
    
done