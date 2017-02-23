#include "stdafx.h"
#include "MathNode.h"


MathNode::MathNode()
{
	prev = NULL;
	next = NULL;
}


MathNode::MathNode(string tcontent, MathNode* tprev, MathNode* tnext) {

	content = tcontent;
	prev = tprev;
	next = tnext;
}


/*Set the pointer to the next Node */
void MathNode::SetNext(MathNode* tnext) {
	next = tnext;
}

/*Set the pointer to the prev Node */
void MathNode::SetPrev(MathNode* tprev) {
	prev = tprev;
}

/*Set the value of the content String */
void MathNode::SetContent(string cont) {
	content = cont;
}

/*Set the value of the Symbol Boolean */
void MathNode::SetSymbol(bool symb) {
	isSymbol = symb;
}


/*Clear the access to the reference pointers*/
void MathNode::clearPointers() {
	next = NULL;
	prev = NULL;
}


/*Get the pointer to the next Node */
MathNode* MathNode::GetPrev() {
	return prev;
}

/*Get the pointer to the previous Node */
MathNode* MathNode::GetNext() {
	return next;
}


/* Get last node in the linked list */
MathNode* MathNode::GetLast() {
	MathNode *pointer = this;
	while (pointer->GetNext()!=NULL) {
		pointer = pointer->GetNext();
	}
	return pointer;
}

/* Add node to the last position in the list*/
void MathNode::AddNode(MathNode* theNewNode) {
	/*
	if (this == NULL)
		this->content = theNewNode->content;
		this->isSymbol =
	else {
	*/
		theNewNode->prev = this->GetLast();
		this->GetLast()->next = theNewNode;
		theNewNode->SetNext(NULL);
	}



/*Get the value of the content String */
string MathNode::GetContent() {
	return content;
}
/*Get the value of the Symbol bool */
bool MathNode::getIsSymbol() {
	return isSymbol;
}






/*Call to destructor*/
MathNode::~MathNode()
{
}


