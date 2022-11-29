#pragma once
#include <iostream>
#include "Patient.h"

//we name the elements of our vector "Nodes"
//Node has a data plus a pointer that points to the next element in our linked list, it also has a pointer to the previous one but it won't come to use that much


using namespace std;

class Node {
	Patient data;
	Node* next;
	Node* previous;
public:
	//implementing setter & getter functions for our Node
	Patient getData() const;
	void setData(Patient newData);
	Node* getNext() const;
	void setNext(Node* newNext);
	Node* getPrevious() const;
	void setPrevious(Node* newPrevious);
	static Node* createNode(Patient data);

	
};

