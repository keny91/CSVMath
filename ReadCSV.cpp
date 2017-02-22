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


void ReadCSV::InitCSVInputLog(char* FileName) {

	char * FolderName;
	char directory[200];
	char * postfix = ".csv";
	FolderName = "./Input/";



	strcpy_s(directory, FolderName);  // ./Output/
	strcat_s(directory, FileName);	// ./Output/FileName
	strcat_s(directory, postfix);


	/*
	if (_mkdir(directory) ||
	ERROR_ALREADY_EXISTS == GetLastError())
	*/

	datafile = ifstream(directory);
	cout << "Opened file " << directory << endl;
}


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

void ReadCSV::CloseCSV() {
	datafile.close();

}