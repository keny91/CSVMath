#include "stdafx.h"
#include "MathOperations.h"



MathOperations::MathOperations(string input)
{
	formula = input;
	//strcpy(formula,input);
	
	char validOperatorsprov[] = "+-/*";
	char validNumbersprov [] = "0123456789";
	validOperators = validOperatorsprov;
	validNumbers = validNumbersprov;
	separator = ',';
}


/* 
	Set the valid possible ASCII symbols that will act as operators.
	PARAMS:
		input: the chain of char symbols that will conform the mathematical operations
		NOTE: the operations have been hardcoded for now. New operators have no asociated functionality
*/


/*NUMBER,SYMBOL,NUMBER,SYMBOL,...*/
/*NOTE: Start and End in NUMBER*/
/*OPERATIONS ARE  NUMBER+SYMBOL+NUMBER*/
/*N_NUMBERS n+1  || N_Symbols: n  */

bool MathOperations::CheckValidFormula(){
	
	bool expectNumber = true;
	bool expectSymbol = false;
	bool result = false;
	std::stringstream  linestream(formula);
	cout << formula << endl;

	string data;
	int count = 0;
	while (std::getline(linestream, data, separator)) {
		cout << data << endl;
		count++;
		if (expectNumber) {
			result = IsNumber(data);
		}
		else if (expectSymbol) {
			result = IsOperator(data);
		}
		else {
			cout << count <<endl;  //DEBUG MSG
				return false;  // Failed
		}

		// Expect the next 
		expectNumber != expectNumber;
		expectSymbol != expectSymbol;

				
	}

	N_symbols = (count - 1) / 2;	
	cout << "Valid Formula; there are "<< N_symbols << endl;
	return true;
	
}

bool MathOperations::IsOperator(string str) {
	char prov [200];
	strcpy(prov, str.c_str());
	//str = string(*str);
	if (strlen(prov) == (unsigned int)1)  // Operators will only be a single char
	{
		for (int i = 0; i < sizeof(validOperators)/ sizeof(char); i++)
			if (validOperators[i] == prov[0])
				return true;
	}

	cout << "Invalid Operator" << endl;
	return false;

}

bool MathOperations::IsNumber(string str) {
	char prov[200];
	strcpy(prov, str.c_str());

	for (int i = 0; i < sizeof(validNumbers) / sizeof(char); i++) {
		for (int j = 0; j < strlen(prov); j++) {
			if (validNumbers[i] == prov[j])   // found the 
				return true;
		}
	}
	cout << "Invalid Number" << endl;
	return false;  // return false in any other case

}




MathOperations::~MathOperations()
{
}



