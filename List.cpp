#pragma once
#include<iostream>
#include <string>
#include "Patient.h"
#include "Node.h"
#include "List.h"

using namespace std;

List::List()
{
	//making epty head node for our list and set element_count to 0
	Node* P = new Node();
	head = P;
	head->setNext(NULL);
	this->elementCount = 0;
}

List::~List()
{

}

int List::getElementCount() const
{
	return elementCount;
}

//using this function to set capacity to check when we insert
void List::set_capacity(int a)
{
	this->capacity = a;
}

//insert in order from high to low
bool List::insert(const Patient& newElement)
{
	//check capacity
	if (this->elementCount < this->capacity)
	{
		Node* NewPatient = new Node();
		NewPatient->setData(newElement);
		//check if our list is empty
		if (this->head->getNext() == NULL)
		{
			head->setNext(NewPatient);
			elementCount++;
		}
		//check if our patient has higher number than our first member
		else if (head->getNext()->getData()<newElement)
		{
			NewPatient->setNext(head->getNext());
			head->setNext(NewPatient);
			elementCount++;
		}
		else
		{
			Node* temp = new Node();
			temp = head->getNext();
			if (temp->getNext() == NULL)
			{
				NewPatient->setNext(temp->getNext());
				temp->setNext(NewPatient);
				elementCount++;
				return 1;
			}
			// check the place to put patient
			while (temp->getNext() != NULL || temp->getNext()->getData() > newElement)
			{
				if (temp->getNext()->getData() == newElement)
				{
					cout << "Error Same Id";
					return 0;
				}
				else
				{
					NewPatient->setNext(temp->getNext());
					temp->setNext(NewPatient);
					elementCount++;
					return 1;
				}
				if (temp->getNext() == NULL)
				{
					break;
				}
				temp = temp->getNext();
				
			}
			
		}
	}
	else
	{
		cout << "hospital is full";
	}
}

bool List::remove(const Patient& toBeRemoved)
{
	if (head->getNext() == NULL)
	{
		cout << "There is no Patient with this information";
		return 0;
	}
	else
	{
		Node* temp = new Node();
		Node* deleted_Patient = new Node();
		temp = head->getNext();
		while (temp->getNext()!=NULL)
		{
			if (temp->getNext()->getData() == toBeRemoved)
			{
				deleted_Patient = temp->getNext();
				temp->setNext(temp->getNext()->getNext());
				delete deleted_Patient;
				elementCount--;
				return 1;
			}
			temp = temp->getNext();
		}
		cout << "There is no Patient with this information";
		return 0;
	}
}

void List::removeAll()
{
	if (head != NULL)
	{
		Node* Temp1 = new Node();
		Node* Temp2 = new Node();
		Temp1 = (head);
		Temp2 = (head->getNext());
		while (Temp2)
		{
			Temp1 = NULL;
			delete Temp1;
			Temp1 = Temp2;
			Temp2 = (Temp2->getNext());
		}
		Temp1 = NULL;
		delete Temp1;
		elementCount = 0;
	}
	
}


Patient* List::search(const Patient& target)
{
	Node* Temp = new Node();
	
	Temp = head;
	while (Temp->getNext())
	{
		if (Temp->getData() == target)
		{
			auto temp = Temp->getData();
			return &temp;
		}
		Temp = Temp->getNext();
	}
	delete Temp;
	return NULL;
}

void List::printList()
{
	Node* Temp = new Node();
	Temp = head->getNext();
	while (Temp)
	{
		cout << Temp->getData() << "\n";
		Temp = Temp->getNext();
	}
	delete Temp;
}



