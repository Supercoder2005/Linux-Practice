# write a while loop script to display a countdown from 10 to 1
i=10
while [ $i -ge 1 ]; do
    echo $i 
    i=$((i-1))
done 
