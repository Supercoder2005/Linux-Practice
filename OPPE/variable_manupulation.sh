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

# Prefix removal (greedy, and not greedy)
var1=a/home/user/Documents/system-commands
echo $var1

# '.*' means -> Anything Any Number of times
# '.+' means -> Anything Amy Number of time but Atleast once

# non - greedy removal
echo ${var1#*/} # Removes the shortest match of /* from the beginning
echo ${var1#?*/} # Removes the shortest match of : remove any one letter followed by a /
# greedy removal
echo ${var1##*/} # Removes the longest match of /* from the beginning 


# Suffix removal
# non-greedy removal
echo ${var1%/*} # Remove / and then any character after the / shortest one 
# greedy removal
echo ${var1%%/*} # Remove / and then any character after the / but the longest one 