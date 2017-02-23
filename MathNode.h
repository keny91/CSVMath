#pragma once

#include <string.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

class MathNode
{

private:
	MathNode * prev;  // Ref to prev
	MathNode * next;	// Ref to next
	string content;		// Content as a string can be a symbol or a float
	bool isSymbol;		// Define the type of content contained here

public:

	int NodeID; // Exist for debugging purpose at the moment

	void SetNext(MathNode* next);
	void SetPrev(MathNode* next);
	void SetContent(string cont);
	void SetSymbol(bool symb);


	MathNode* GetPrev();
	MathNode* GetNext();
	MathNode* GetLast();
	void AddNode(MathNode* theNewNode);

	string GetContent();
	bool getIsSymbol();

	void clearPointers();

	MathNode();
	MathNode(string content, MathNode* prev, MathNode* next);

	~MathNode();
};

