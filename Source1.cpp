#include<iostream>
#include <string>
#include "Patient.h"
#include "Node.h"
#include "List.h"

using namespace std;

int main()
{
	List mylist;
	mylist.set_capacity(10);
	Patient P1("1234567890", "Nima Zamani", "nima.1.1.1", "arazande", "0910121314");
	Patient P2("0134567890", "azi", "azi11", "aadjkfazande", "091017891");
	Patient P3("0234567890", "azi", "azi11", "aadjkfazande", "091017891");
	Patient P4("0674567890", "azi", "azi11", "aadjkfazande", "091017891");
	mylist.insert(P1);
	mylist.insert(P2);
	mylist.insert(P3);
	mylist.insert(P4);
	mylist.printList();
	cout << mylist.getElementCount();
	mylist.remove(P1);
	mylist.printList();
}