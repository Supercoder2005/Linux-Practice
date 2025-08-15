# String Replacement
str="Hello World !"
echo $str
echo ${str/World/Universe} # replace only the 1st occurance 

str1="Srinjinee is a very good girl . Srinjinee is the topper of her class."
echo $str1 
echo ${str1//Srinjinee/She} # replace all occurances