//************************  intSLList.h  **************************
//           singly-linked list class to store integers
#include <string>

#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST


using namespace std;

class IntSLLNode {
public:
	IntSLLNode() {
		next = 0;
	}
	IntSLLNode(string el, IntSLLNode* ptr = 0) {
		info = el; next = ptr;
	}
	string info = "";
	IntSLLNode* next = NULL;
};

class IntSLList {
public:
	IntSLList() {
		head = tail = 0;
	}
	~IntSLList();
	bool isEmpty() {
		return head == 0;
	}
	void addToHead(string);
	void addToTail(string);
	void deleteAll();
	string findNodeElementText(int);
	string deleteFromHead(); // delete the head and return its info;
	string deleteFromTail();
	string deleteNode(int);
	void moveNode(int, int);
	string replaceNode(int, string);
	void insertNode(int, string);
	void printAll(int, int, int, int);
	void save(string) const;

private:
	IntSLLNode* head, * tail;
};

#endif

