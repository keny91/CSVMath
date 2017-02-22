
#include "RecordCSV.h"



RecordCSV::RecordCSV()
{
}

RecordCSV::RecordCSV(char* FileName) {
	InitCSVOutputLog(FileName);
}

RecordCSV::~RecordCSV()
{
}



/*
Recording Datafile Operations
*/

void RecordCSV::InitCSVOutputLog(char* FileName) {

	char * FolderName;
	char directory[200];
	char * postfix = ".csv";
	FolderName = "./Output/";



	strcpy_s(directory, FolderName);  // ./Output/
	strcat_s(directory, FileName);	// ./Output/FileName
	strcat_s(directory, postfix);


	/*
	if (_mkdir(directory) ||
	ERROR_ALREADY_EXISTS == GetLastError())
	*/

	datafile = ofstream(directory);
	cout << "Opened file " << directory << endl;
}


void RecordCSV::WriteToCSV( char*input) {

	datafile << input;
	cout << input << endl;
}

void RecordCSV::CloseCSV() {
	datafile.close();

}
