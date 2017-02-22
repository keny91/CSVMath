#pragma once

#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>


using namespace std;


class ReadCSV
{
private:
	ifstream datafile;
public:
	ReadCSV();
	ReadCSV(char * name);
	~ReadCSV();


	void InitCSVInputLog(char* FileName);
	string GetFormula();
	void CloseCSV();
	

};

