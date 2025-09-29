Start IntPointer Program



-Declare assignment function

 	1) build pointers for each input variable

 	2) display values for the input variables and the pointer variables

 	3) delete pointer variables



-Declare input validation function

 	1) declare local variables: *input,* *value*

 	2) start loop

 		1: display initial message

 		2: look for exit entry

 			exit

 		3: check to see if non-integer values have been entered

 			display error message and return to loop beginning if non-integer characters found

 			return value variable if only integer variables found

 		4: check to see if the integers are too many and may cause overflow errors

 			display error message and return to loop beginning

-Declare Main function

 	1) declare variables: *one, two, three*

 	2) display input request message

 	3) assign variables using input validation function

 	4) check to see if using variable in assignment function causes errors

 		1: if errors present, exit with failure code

 		2: if none, exit with success code

 

