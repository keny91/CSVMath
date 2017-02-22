#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

class MathOperations
{
public:
	string formula;  // Storage of the 
	char* validOperators; //
	char* validNumbers; // Also valid as char[] / *
	char separator;

	int N_symbols;

	MathOperations(string input);
	void SetMathOperators(char* input);
	void SetMathNumbers(char input);

	bool CheckValidFormula();
	bool IsOperator(string i);
	bool IsNumber(string i);


	~MathOperations();
};



