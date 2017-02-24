#include "stdafx.h"
#include "MathOperations.h"

/*NUMBER,SYMBOL,NUMBER,SYMBOL,...*/
/*NOTE: Start and End in NUMBER*/
/*OPERATIONS ARE  NUMBER+SYMBOL+NUMBER*/
/*N_NUMBERS n+1  || N_Symbols: n  */


MathOperations::MathOperations(string input)
{
	formula = input;
	//strcpy(formula,input);
	
	//char validOperatorsprov[] = "+-/*";
	validOperators = new char(sizeof("+-/*"));
	validNumbers = new char(sizeof("0123456789."));
	validOperators = "+-/*";
	validNumbers = "0123456789.";
	NodeList = NULL;

	separator = ',';
}


/* 
	Set the valid possible ASCII symbols that will act as operators.
	PARAMS:
		input: the chain of char symbols that will conform the mathematical operations
		NOTE: the operations have been hardcoded for now. New operators have no asociated functionality
*/





/* Check if the formula provided is valid given the parameters */
bool MathOperations::CheckValidFormula(){
	
	bool expectNumber = true;
	bool expectSymbol = false;
	bool result = false;
	std::stringstream  linestream(formula);
	

	string data;
	int count = 0;
	while (std::getline(linestream, data, separator)) {
		//cout << data << endl;
		count++;
		if (expectNumber) { // The next input will be a number?
			result = IsNumber(data);
		}
		else if (expectSymbol) {  // The next input will be a symbol?
			result = IsOperator(data);
		}
		
		
		
		if (!result){  // Trigger Exit
			cout << "interrupt triggered: count "<< count  <<endl;  //DEBUG MSG
				return false;  // Failed
		}
		else {  //Store the info in the list

			if(NodeList == NULL) { // First node   // CHANGE THIS LATER TO BE MORE DYNAMIC--- look AddNode()
				NodeList = new MathNode();
				NodeList->SetContent(data);
				NodeList->SetSymbol(expectSymbol);
				NodeList->NodeID = count;
		}
			else {
				MathNode* newNode = new MathNode();
				newNode->SetContent(data);
				NodeList->SetSymbol(expectSymbol);
				NodeList->NodeID = count;
				NodeList->AddNode(newNode);


			}
				
		}


		// Expect the next 
		expectNumber = !expectNumber;
		expectSymbol = !expectSymbol;

				
	}

	N_symbols = (count - 1) / 2;	// Get the number of operations 
	cout << "Valid Formula; there are "<< N_symbols << "  operations "<<endl;
	return true;
	
}


/* Check if the input string is considered a valid operator*/
bool MathOperations::IsOperator(string str) {

	const char * prov = str.c_str();

	if (strlen(prov) == (unsigned int)1)  // Operators will only be a single char
	{
		for (int i = 0; i < sizeof(validOperators)/ sizeof(char); i++)
			if (validOperators[i] == prov[0])
				return true;
	}

	cout << "Invalid Operator: "<< str << endl;
	return false;

}

/*Depending on the priority stage we will be looking to do a different set of operations*/
void MathOperations::DoOperationBasedOnPriority(int priority) 
{

	MathNode * presentNode = NodeList;  // Start from the beggining
	bool done = false;
	MathNode* n;

	cout << "Operations with priority: " << priority << endl << endl;
	while (presentNode->GetNext() != NULL && presentNode->GetNext()->GetNext() != NULL) // check that we have enough nodes to operate with
	{
		n  = DoNodeOperations(presentNode, priority);  //

		if (n!=NULL) { // Susccess try again with this node - We delete the following 2 nodes in case of success.
			presentNode = n;
		}
		else { // no success -> try two nodes ahead
			presentNode = presentNode->GetNext()->GetNext();
		}
	}

	cout << endl;

}


/* Check if the input string is a number*/
/* Any number combination that can incluying a single '.'  -> having 2 dots will trigger an error*/

bool MathOperations::IsNumber(string str) {


	const char * prov = str.c_str();

	//strcpy(prov, str.c_str());
	bool found;

	/*   OLD LESS EFFICIENT IMPLEMENTATION
	for (int j = 0; j < strlen(prov); j++) {
		found = false;
		for (int i = 0; i < strlen(validNumbers) / sizeof(char); i++) {
		 
			if (validNumbers[i] == prov[j]) { // found the number in the list
				found = true;

				break;
			}						
		}
		if (!found) {
			cout << "Invalid Number:" << str << endl;
			return false;
		}
			
	}
	*/


	if (stof(str) != NULL) {  // Check if the number is convertible to float format
		return true;
	}
	else {
		cout << "Invalid Number:" << str << endl;
		return false;
	}
	
	return true;  // return false in any other case

}






/* Get the initial node in the list  */
MathNode* MathOperations::DoNodeOperations(MathNode* firstNode, int priority){

	//MathNode* firstNode;
	MathNode* SymbolNode = firstNode->GetNext();
	MathNode* SecondNode = SymbolNode->GetNext();
	char Symbol = SymbolNode->GetContent()[0];
	float param1;
	float param2;
	float result;
	bool done = false;


	if ((Symbol == '/' || Symbol == '*') && priority == 1)   // Design more dynamic systems -- revamp symbols available
	{
		param1 = stof(firstNode->GetContent());
		param2 = stof(SecondNode->GetContent());
		result = DoOperation(param1 , param2, Symbol);
		
		done = true;

	}
	else if((Symbol == '+' || Symbol == '-') && priority == 2)
	{
		param1 = stof(firstNode->GetContent());
		param2 = stof(SecondNode->GetContent());
		result = DoOperation(param1, param2, Symbol);
		//cout << "Performing \'" << Symbol << "\'." << endl;
		done = true;
	}
	else
		return NULL;

	cout << "Performing: " << param1 << "   " << Symbol << "   " << param2 << "  =  " << result <<endl;

	MathNode * newNode = new MathNode();
	// Set new values
	ostringstream ss;
	ss << result;
	string s(ss.str());
	newNode->SetContent(s);
	newNode->SetSymbol(false);


	// Create new links
	if(firstNode->GetPrev() != NULL)
		firstNode->GetPrev()->SetNext(newNode);

	if (SecondNode->GetNext() != NULL)
		SecondNode->GetNext()->SetPrev(newNode);
	
	// To other nodes
	if (SecondNode->GetNext() == NULL)	// Not sure if necessary but just in case
		newNode->SetNext(NULL);
	else
		newNode->SetNext(SecondNode->GetNext()); // From the new node
	
	if (firstNode->GetPrev() == NULL) // In case that the first node is the one changed
		NodeList = newNode;
	else
		newNode->SetPrev(firstNode->GetPrev());

	return newNode;
	

	//Delete the used 3 nodes to prevent leaks
	delete firstNode;
	delete SymbolNode;
	delete SecondNode;


}


float MathOperations::DoOperation(float a, float b, char c) {

	float result;

	switch (c)
	{
	case '+':
		result = a+b;
		break;
	case '-':
		result = a-b;
		break;
	case '*':
		result = a*b;
		break;
	case '/':
		result = a/b;
		break;
	}
	return result;
}

MathOperations::~MathOperations()
{

}


struct PrioritySymbols {
	int priority;
	char symbol;

	PrioritySymbols(int prio, char sym) {
		priority = priority;
		symbol = sym;
	}
};

