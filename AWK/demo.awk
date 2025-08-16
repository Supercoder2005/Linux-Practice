#{ print } #used to print the entire line

# print only the name and salary of each recod 
#{ print $2, $4 }

# print only the name of the employees
#{ print $2}

# print all of those employees who are in IT dept.
$3 == "IT" { print $0}

# print the salary of diana
$2 == "Diana" {print $4}