// CSVMath.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "MathOperations.h"
#include "RecordCSV.h"
#include "ReadCSV.h"
//#include <cstdio>



void InitFolders();

int main(int argc, char *argv[])
{
	

	//char* OutFileName = "testbad";
	char* InFileName = new char();
	char* OutFileName = new char();
	if (argc == 1) {
		cout <<  endl << endl << "No Arguments detected: " << endl;
		cout << "Please enter the input Directory value: " << endl;
		cout << "Remember to include file extension \".csv\". " << endl;
		cin >> InFileName;
		//cout <<sizeof(InFileName) << endl << endl;

		cout << "Please enter the output Directory value: " << endl;
		cout << "Remember to include file extension \".csv\" at the end. " << endl;
		cin >> OutFileName;
		//cout << endl << OutFileName;
	}
	else if(argc == 3){  // If we receive two arguments 

		cout << "Detected 2 arguments." << endl;
		//ifstream infile;
		InFileName = argv[1];	
		OutFileName = argv[2];

		cout << "Input File Set to: "<< InFileName << endl;
		cout << "Output File Set to: "<< OutFileName << endl;

	}
	else {
		cout << "Invalid number of arguments, this application requires 0 or 2 arguments to properly run" << endl;
	}



	// Read the mathematical operation from a file
	string formulaLine;
	ReadCSV theInputFile(InFileName);
	// need read input check
	if (!theInputFile.datafile.is_open()) {
		cout << "Input file Not found; Are you sure you typed it properly? (Check that you are using \\\\ and not \\)" << endl << endl;
		cout << endl << endl << "Press ENTER key to exit."; // Wait for key to exit
		cin.get();
		return -1;
	}
	formulaLine = theInputFile.GetFormula();
	theInputFile.CloseCSV();

	cout << "Mathematical operation:     " <<formulaLine<<  endl;		// Debugg info

	// Create the linked list processor class.
	MathOperations Maths = MathOperations(formulaLine);
	cout << "   VALID NUMBERS:   " << Maths.validNumbers << endl;
	cout << "   VALID OPERATORS    "   <<  Maths.validOperators <<  endl ;
	cout << Maths.formula << endl << endl;


	// check that is a valid Formula and create a linked list
	bool valid = Maths.CheckValidFormula();
	string outputText;

	// Do mathematical  '*' & '/' operations first and '+' & '-' later; this is specified inside the DoOperation() method
	int highestPriority = 1;
	int lowestPriority = 2;

	if (valid) {  // check if the formula was valid, then start the operations
		for (int priority = 1; priority <= lowestPriority; priority++)
			Maths.DoOperationBasedOnPriority(priority);  

		outputText = Maths.NodeList->GetContent();

	}
	else {  // Case of invalid formula
		outputText = string ("Invalid mathematical sequence");
	}





	// Final step. Record the result in the output file.
	RecordCSV theOutputFile(OutFileName);
	theOutputFile.WriteToCSV(outputText);
	theOutputFile.CloseCSV();


	cout << endl << endl <<"DONE.  Press ENTER key to exit."; // Wait for key to exit
	cin.get();
	

	

    return 0;
}


/* OLD VERSION OF THE APP; created the folders where the input/output files were stored in previous versions*/
void InitFolders() {
	FolderHandler::CreateFolder("./Output");
	FolderHandler::CreateFolder("./Input");
}