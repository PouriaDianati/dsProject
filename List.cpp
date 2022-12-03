#pragma once
#include<iostream>
#include <string>
#include "Patient.h"
#include "Node.h"
#include "List.h"

using namespace std;

List::List()
{
	this->head = NULL;
	this->elementCount = 0;
}

List::~List()
{

}

int List::getElementCount() const
{
	return elementCount;
}

void List::set_capacity(int a)
{
	this->capacity = a;
}

bool List::insert(const Patient& newElement)
{
	if (this->elementCount < this->capacity)
	{
		Node* NewPatient = new Node();
		NewPatient->setData(newElement);
		if (this->head == NULL)
		{
			head = NewPatient;
			elementCount++;
		}
		else if (head->getData()<newElement)
		{
			NewPatient->setNext(head);
			head = NewPatient;
			elementCount++;
		}
		else
		{
			Node* temp = new Node();
			temp = head;
			while (temp->getNext()->getData() > newElement || temp->getNext() == NULL)
			{
				temp = temp->getNext();
			}
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
	if (head == NULL)
	{
		cout << "There is no Patient with this information";
		return 0;
	}
	else
	{
		Node* temp = new Node();
		Node* deleted_Patient = new Node();
		temp = head;
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
	Temp = head;
	while (Temp->getNext())
	{
		cout << Temp->getData() << "\n";
		Temp = Temp->getNext();
	}
	delete Temp;
}



