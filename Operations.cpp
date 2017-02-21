#include "stdafx.h"
#include "Operations.h"


Operations::Operations(char theSymbol, int Priority)
{

}



/*
Implement the operation of each class.
*/

float Multiplication::DoOperation(float param1, float param2)
{
	return param1*param2;
}


float Division::DoOperation(float param1, float param2)
{
	return param1/param2;
}


float Sum::DoOperation(float param1, float param2)
{
	return param1+param2;
}


float Sustraction::DoOperation(float param1, float param2)
{
	return param1-param2;
}
