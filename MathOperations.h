#pragma once

#include <string.h>
#include <iostream>

using namespace std;

class MathOperations
{
public:
	string formula;  // Storage of the 
	string validOperators; //
	string validNumbers; // Also valid as char[] / *

	MathOperations(string input);
	void SetMathOperators(string input);
	void SetMathNumbers(string input);

	bool CheckValidFormula(); 
	bool IsOperator(char i);
	bool IsNumber(char i);


	~MathOperations();
};

struct Operation {
protected:
	Operation(char theSymbol, int Priority);
	char symbol;
	int priority;
	virtual void DoOperation(int param1, int param2);
};


