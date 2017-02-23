// CSVMath.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "MathOperations.h"
#include "RecordCSV.h"
#include "ReadCSV.h"


void InitFolders();


int main()
{


	//Sample inputs
	// (31+6*36/3)
	char* input = "2893271372";
	char* OutFileName = "test";
	char* InFileName = "Sample";

	// Initialize input and output folders
	InitFolders();


	


	// Read the mathematical operation from a file
	string formulaLine;
	ReadCSV theInputFile(InFileName);
	formulaLine = theInputFile.GetFormula();
	theInputFile.CloseCSV();



	cout << "Mathematical operation:     " <<formulaLine<<  endl;		// Debugg info




	MathOperations Maths = MathOperations(formulaLine);
	cout << Maths.validNumbers << "   VALID NUMS" << endl;
	cout << Maths.validOperators << "   VALID OPERATORS" << endl;
	cout << Maths.formula << endl;




	// check that is a valid Formula and create a linked list
	Maths.CheckValidFormula();

	// Do mathematical  '*' & '/' operations first
	bool highpriority = true;
	Maths.DoOperationBasedOnPriority(1);
	cout << Maths.NodeList->GetNext()->GetContent() << endl;

	while (1) {

	}





	/* Read and compute*/

		// Get arg 1
		// Search and read file.csv
		// Check valid string
		// 1st priority operations  (*,/)
		// 2nd...
		// Get result


	// Get arg 2



		// Create the log with the result
	RecordCSV theOutputFile(OutFileName);
	theOutputFile.WriteToCSV(input);
	theOutputFile.CloseCSV();


    return 0;
}

void InitFolders() {
	FolderHandler::CreateFolder("./Output");
	FolderHandler::CreateFolder("./Input");
}