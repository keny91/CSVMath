========================================================================
    ##CONSOLE APPLICATION: CSVMath 
========================================================================

This application requires either none or two parameters to run.


###CASE 1: 2 parameters
    - Param1: input file; just the name/ relative directory of the CSV file. (remember to include the .csv)
    - Param2: name of the output .CSV file (add .csv yourself)

###CASE 2: No params
 
    In this case we will be asked first for the input file/directory and then for the output.
    
    
In any case if the input is not properly opened (no such directory), the application triggers an error message.

Afterward the application will follow the following steps:
    1. Validate that the formula is valid and create an linked list for the terms split.
    2. If valid proceed with the operations. First '*' or '/' and then '-' and '+'
    3. We will store successful results in the output file directory provided.

