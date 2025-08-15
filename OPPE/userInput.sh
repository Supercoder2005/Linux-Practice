echo "What is your name?"
# read the entire line of the input and store in to a variable 
read name 
echo "Hello! $name, Welcome to the script!"


# tokenization 
# IFS (Internal Field Separator) is used to split the input into tokens

echo "Enter a sentence containing two words:" # Srinjinee Mitra
read first second # first = Srinjinee , second = Mitra 
echo "First token: $first"
echo "Second token: $second"

# Storing a particular word from a sentence
echo "Enter a sentence:"
read a b c variable d  # by default splitting by space 
echo "variable : $variable"


# Custom IFS - Splitting by a different character rather than space 
echo "Enter a comma seperated input:"
IFS=',' read first second third
echo "First: $first"
echo "Second: $second"
echo "Third: $third" 



# reading multiple lines of input
echo "Enter multiple lines of input (Press Ctrl+D to finish):"
while read line; do 
    echo "You entered: $line"
done 