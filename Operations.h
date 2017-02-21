#pragma once

#include <string.h>
#include <iostream>

using namespace std;




/* 
	The present design is made so it could be scalable to new symbols and operations in the future.
*/
class Operations
{
public:
	Operations();
	char symbol;
	int priority;
//protected:
	Operations(char theSymbol, int Priority);

	float DoOperation(float param1, float param2) { cout << "Called virtual parent function; Not what you expected."; };
	~Operations();
};


/**********************************s
	Operator functions.
************************************/


class Multiplication:Operations
{
public:
	Multiplication() {};
	float DoOperation(float param1, float param2) ;
	char symbol = '*';
	int priority = 1;

};


class Division : public Operations
{
public:
	Division() {};
	float DoOperation(float param1, float param2);
	char symbol = '/';
	int priority = 1;
};

class Sum :Operations
{
public:
	Sum() {};
	float DoOperation(float param1, float param2);
	char symbol = '+';
	int priority = 5;
};

class Sustraction :Operations
{
public:
	Sustraction() {};
	float DoOperation(float param1, float param2);
	char symbol = '-';
	int priority = 5;
};