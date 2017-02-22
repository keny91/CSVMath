// CSVMath.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "MathOperations.h"
#include "Operations.h"
#include "RecordCSV.h"
#include "ReadCSV.h"


void InitFolders();


int main()
{

	// (31+6*36/3)
	char* input = "2893271372";
	//MathOperations* MathObject = new MathOperations(input);

	char* OutFileName = "test";
	char* InFileName = "Sample";

	InitFolders();

	RecordCSV theOutputFile(OutFileName);
	theOutputFile.WriteToCSV(input);
	theOutputFile.CloseCSV();
	



	string formulaline;
	ReadCSV theInputFile(InFileName);
	formulaline = theInputFile.GetFormula();
	theInputFile.CloseCSV();
	cout << formulaline<<"      char format" << endl;
	//char f = formulaline[12];
	cout <<  sizeof(formulaline) << "    aaaaaaaa" << endl;
	MathOperations Maths = MathOperations(formulaline);
	cout << Maths.formula << endl;

	Maths.CheckValidFormula();


	// check that formulaline is read per separators

		//Determine if operator or number

		// is it what we expected

	while (1) {

	}


	/*
		switch (op)
		{
		case '+':
			res = x + y;
			break;
		case '-':
			res = x - y;
			break;
		case '*':
			res = x * y;
			break;
		case '/'
			res = x / y;
			break;
		}
		*/


	/* Read and compute*/

		// Get arg 1
		// Search and read file.csv
		// Check valid string
		// 1st priority operations  (*,/)
		// 2nd...
		// Get result


	// Get arg 2
		// Create file
		// Write result in file


    return 0;
}

void InitFolders() {
	FolderHandler::CreateFolder("./Output");
	FolderHandler::CreateFolder("./Input");
}