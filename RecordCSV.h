#pragma once

#include <string.h>
#include <direct.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <winerror.h>

using namespace std;

/*
This class reads an input and tries to open a file with an input name/directory 
*/

class RecordCSV
{

private:
	ofstream datafile;

public:
	RecordCSV();
	RecordCSV(char* FileName);
	~RecordCSV();
	// File writting 
	void InitCSVOutputLog(char* FileName);
	void WriteToCSV(string input);
	void CloseCSV();
};


class FolderHandler
{
public:
	static bool CreateFolder(const char* folderName);
	static bool CheckFileExistence(const char* name);
};
