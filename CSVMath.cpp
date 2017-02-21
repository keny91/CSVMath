// CSVMath.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "MathOperations.h"
#include "Operations.h"

int main()
{

	// (31+6*36/3)
	string input = string("3+1");
	MathOperations* MathObject = new MathOperations(input);

	void*OperationList[4]; // At this moment we have 4 different operators "*/+-"
	OperationList[0] = new Multiplication();
	OperationList[1] = new Division();
	OperationList[2] = new Sum();
	OperationList[3] = new Sustraction();

	OperationList[1]->
	/* Read and compute*/

		// Get arg 1
		// Search and read file.csv
		// Check valid string
		// 1st priority operations
		// 2nd...
		// Get result


	// Get arg 2
		// Create file
		// Write result in file


    return 0;
}

