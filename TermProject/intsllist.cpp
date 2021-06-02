//************************  intSLList.cpp  **************************

#include <fstream>
#include <iostream>
#include "intSLList.h"

using namespace std;

IntSLList::~IntSLList() {
	for (IntSLLNode* p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}

void IntSLList::addToHead(string el) {
	if (head == NULL || tail == NULL)
		head = tail = 0;

	head = new IntSLLNode(el, head);
	if (tail == 0)
		tail = head;
}

void IntSLList::addToTail(string el) {
	if (head == NULL || tail == NULL)
		head = tail = 0;

	if (tail != 0) {      // if list not empty;
		tail->next = new IntSLLNode(el);
		tail = tail->next;
	}
	else head = tail = new IntSLLNode(el);
}

string IntSLList::deleteFromHead() {
	string deletedText = head->info;
	head = head->next;
	return deletedText;
}

string IntSLList::deleteFromTail() {
	if (head == NULL)
		return " ";

	if (head->next == NULL)
		return deleteFromHead();

	IntSLLNode* second_last = head;
	while (second_last->next->next != NULL)
		second_last = second_last->next;	// Find the second last node 

	delete (second_last->next);	// Delete last node 


	second_last->next = NULL;	// Change next of second last 

	return " ";
}

void IntSLList::deleteAll() {
	if (head != NULL)
	{
		IntSLLNode* current = head;
		IntSLLNode* next;

		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}

		head = NULL;
	}
}

void IntSLList::moveNode(int currentPos, int targetPos)
{
	if (currentPos != targetPos)
	{
		IntSLLNode* tmp = head;

		string nodeTxt = findNodeElementText(currentPos);
		deleteNode(currentPos);
		insertNode(targetPos, nodeTxt);
	}
}

string IntSLList::findNodeElementText(int pos)
{
	IntSLLNode* tmp = head;
	string nodeTxt = "";

	// itterate over a node until the pos value reached
	for (int i = 0; tmp != NULL && i < pos; i++)
	{
		if ((pos - 1) == i)
			nodeTxt = tmp->info;

		tmp = tmp->next;
	}
	return nodeTxt;
}

string IntSLList::deleteNode(int pos)
{
	string deletedText = " ";

	if (head != NULL)
	{
		IntSLLNode* previousNodeOFTheNodeToBeDeleted = head;

		if (pos == 1) //if head needs to be removed
			return deleteFromHead();

		for (int i = 1; head != NULL && i < pos - 1; i++)	// Find previous node of the node to be deleted 
			previousNodeOFTheNodeToBeDeleted = previousNodeOFTheNodeToBeDeleted->next;

		deletedText = previousNodeOFTheNodeToBeDeleted->next->info; // can not be null as we expect filled txt file
		IntSLLNode* next = previousNodeOFTheNodeToBeDeleted->next->next;	// Store pointer to the next of node to be deleted   
		delete(previousNodeOFTheNodeToBeDeleted->next);	// Delete the node from linked list
		previousNodeOFTheNodeToBeDeleted->next = next;	// link next to new node 
	}

	return deletedText;
}

string IntSLList::replaceNode(int pos, string newText)
{
	string replacedText = "";
	if (head == NULL)
		return replacedText;

	IntSLLNode* tmp = head;

	for (int i = 0; tmp != NULL && i < pos; i++)
	{
		replacedText = tmp->info;
		if ((pos - 1) == i)
			tmp->info = newText;

		tmp = tmp->next;
	}
	return replacedText;
}

void IntSLList::insertNode(int pos, string newText)
{

	if (pos == 1)
	{
		addToHead(newText);
	}
	else
	{
		if (head != NULL)
		{
			IntSLLNode* tmp = head;
			IntSLLNode* newNode = new IntSLLNode(newText);

			for (int i = 1; head != NULL && i < pos; i++)
			{
				if ((pos - 1) == i)
					newNode->next = tmp->next;
				else
					tmp = tmp->next;
			}

			tmp->next = newNode;
		}
	}

}

void IntSLList::printAll(int page, int size, int totalPageCount, int totalLineCount) {
	int i = 0;
	int lineCounter = 0;

	cout << endl;

	for (IntSLLNode* tmp = head; tmp != 0; tmp = tmp->next)
	{
		i++;
		if (((page - 1) * size) < i)
		{
			if (lineCounter < size)
			{
				lineCounter++;
				cout << lineCounter + ((page - 1) * size) << " - " << tmp->info << " " << endl;
			}

			if (lineCounter == size)
				break;
		}
	}
	cout << endl << "Current Page Number : " << page << " of " << totalPageCount << " --> ( " << totalLineCount << " lines )" << endl;
}

void IntSLList::save(string userFileName) const {
	ofstream MyFile(userFileName);
	if (MyFile.is_open())
	{
		for (IntSLLNode* tmp = head; tmp != 0; tmp = tmp->next)
			MyFile << tmp->info << " " << endl;
		MyFile.close();
	}
}

