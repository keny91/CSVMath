#include "stdafx.h"
#include "MathOperations.h"



MathOperations::MathOperations(string input)
{
	formula = input;
	validOperators = "+-/*";
	validNumbers = "0123456789";
}


/* 
	Set the valid possible ASCII symbols that will act as operators.
	PARAMS:
		input: the chain of char symbols that will conform the mathematical operations
		NOTE: the operations have been hardcoded for now. New operators have no asociated functionality
*/
void MathOperations::SetMathOperators(string input) {
	validOperators = input;
}

void MathOperations::SetMathNumbers(string input){
	validNumbers = input;
}



MathOperations::~MathOperations()
{
}



