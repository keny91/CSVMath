#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include "MathNode.h"

using namespace std;


/*
Class dedicated to process a linked list and gather a result.
Previous to any calculation, the validity of the string input checked.
*/


class MathOperations
{

public:
	string formula;  // Storage of the 
	char* validOperators; //
	char* validNumbers; // Also valid as char[] / *
	char separator;

	MathNode* NodeList; //Pointer to the first node in the list
	
	MathNode* DoNodeOperations(MathNode* firstNode, int highPriority);
	float DoOperation(float a, float b, char c);

	int N_symbols;

	MathOperations(string input);
	void SetMathOperators(char* input);
	void SetMathNumbers(char input);
	void DoOperationBasedOnPriority(int priority);

	bool CheckValidFormula();
	bool IsOperator(string i);
	bool IsNumber(string i);


	~MathOperations();
};

struct PrioritySymbols;



