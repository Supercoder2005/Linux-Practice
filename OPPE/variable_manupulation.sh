# Case Conversion in Bash
var=AbCd123
echo $var
echo ${var^}  # the first letter will be in upper case
echo ${var,} # the first letter will be in lower case
echo ${var^^} # the whole word will be in upper case
echo ${var,,} # the whole word will be in lower case

# String length
echo ${#var}

# Substring extraction
# the first parameter is for the starting index, the second is for the length
echo ${var:0:4} # Extracts the first 3 characters
echo ${var:4:3} # Extracts 3 characters starting from index 4