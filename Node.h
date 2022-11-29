#pragma once
#include <iostream>
#include "Patient.h"

using namespace std;

class Node {
	Patient data;
	Node* next;
	Node* previous;
public:
	Patient getData() const {
		return data;
	}

	void setData(Patient newData) {
		data = newData;
	}

	Node* getNext() const {
		return next;
	}

	void setNext(Node* newNext) {
		next = newNext;
	}

	Node* getPrevious() const {
		return previous;
	}

	void setPrevious(Node* newPrevious) {
		previous = newPrevious;
	}

	static Node* createNode(Patient data) {
		Node* newNode = new Node;
		newNode->setData(data);
		newNode->setNext(nullptr);
		newNode->setPrevious(nullptr);
		return newNode;
	}

	
};

