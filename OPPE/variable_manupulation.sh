# Case Conversion in Bash
var=Banana
echo $var
echo ${var^}  # the first letter will be in upper case
echo ${var,} # the first letter will be in lower case
echo ${var^^} # the wholw word will be in upper 
echo ${var,,} # the wholw word will be in lower case