# write a shell program to find out the maximum of three numbers 

# a=89
# b=32
# c=99
# if [ $a -gt $b ] && [ $a -gt $c ]; then
#     echo -e "Maximum is : $a"
# elif [ $b -gt $a ] && [ $b -gt $c ]; then
#     echo -e "Maximum is : $b" 
# else 
#     echo -e "Maximum is : $c"
# fi 



# bash style 

#!/bin/bash
a=89
b=99
c=23
if (( a>b && a>c )); then 
    echo -e "Maximum is : $a"
elif (( b>a && b>c )); then 
    echo -e "Maximum is : $b"
else 
    echo -e "Maximum is : $c"
fi 