#include "stdafx.h"
#include "ReadCSV.h"


ReadCSV::ReadCSV()
{
}


ReadCSV::ReadCSV(char * name)
{
	InitCSVInputLog(name);
}

ReadCSV::~ReadCSV()
{
}

/*Try to open the file*/
void ReadCSV::InitCSVInputLog(char* FileName) {

	char * FolderName;
	char directory[1000];
	char * postfix = ".csv";
	FolderName = "./Input/";


	/*
	strcpy_s(directory, FolderName);  // ./Output/
	strcat_s(directory, FileName);	// ./Output/FileName
	strcat_s(directory, postfix);
	*/

	strcpy_s(directory, FileName);

	/*
	if (_mkdir(directory) ||
	ERROR_ALREADY_EXISTS == GetLastError())
	*/

	datafile = ifstream(FileName);


	cout << "Opened file " << FileName << endl;
}



/* Extract the content from the .CSV file*/
string ReadCSV::GetFormula() {

	char prov[5000];
	string  line;
	if (std::getline(datafile, line))
	{
		//cout << line << endl;
		std::stringstream   linestream(line);
		std::string         data;

		//strcpy(prov, line.c_str());

	}

	return line;
	//cout << input << endl;
}


/*Close the opened file*/
void ReadCSV::CloseCSV() {
	datafile.close();

}