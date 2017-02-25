
#include "RecordCSV.h"
//#include "stdafx.h"


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

	
	char directory[1000];
	char * postfix = ".csv";
	//char * FolderName;
	//FolderName = "./Output/";


	
	strcpy_s(directory, FileName);  // ./Output/
	strcat_s(directory, postfix);
	

	datafile = ofstream(directory);
	cout << "Opened file " << directory << endl;
}


void RecordCSV::WriteToCSV(string input) {
	const char * prov = input.c_str();
	datafile << prov;
	cout << "Written to file value: " <<prov << endl;
}

void RecordCSV::CloseCSV() {
	datafile.close();

}
