#include "Node.h"

Patient Node::getData() const {
	return this->data;
}

void Node::setData(Patient newData) {
	this->data = newData;
}

Node* Node::getNext() const {
	return this->next;
}

void Node::setNext(Node* newNext) {
	this->next = newNext;
}

Node* Node::getPrevious() const {
	return this->previous;
}

void Node::setPrevious(Node* newPrevious) {
	this->previous = newPrevious;
}

Node* Node::createNode(Patient data) {
	Node* newNode = new Node;
	newNode->setData(data);
	newNode->setNext(nullptr);
	newNode->setPrevious(nullptr);
	return newNode;
}
