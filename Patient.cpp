/*
 * Patient.cpp
 *
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified.
 *
 * Author: (For you to fill)
 * Date: (For you to fill)
 */			

 // You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"

//defenition for getter functions

string Patient::getName() const {
	return this->name;
}

string Patient::getAddress() const {
	return this->address;
}

string Patient::getEmail() const {
	return this->email;
}

string Patient::getCareCard() const {
	return this->cardNum;
}

string Patient::getPhone() const {
	return this->phone;
}

void Patient::setName(const string aName) {
	this->name = aName;
}

void Patient::setAddress(const string anAddress) {
	this->address = anAddress;
}

void Patient::setPhone(const string aPhone) {
	this->phone = aPhone;
}

void Patient::setEmail(const string anEmail) {
	this->email = anEmail;
}

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient() {

	// You need to complete this method.
	this->cardNum = "0000000000";
	this->address = "To be entered";
	this->email = "To be entered";
	this->name = "To be entered";
	this->phone = "To be entered";

}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {

	// You need to complete this method.
	if (aCareCard.length() == 10) {
		this->cardNum = aCareCard;
	}
	else {
		this->cardNum = "0000000000";
	}
	this->address = "To be entered";
	this->email = "To be entered";
	this->name = "To be entered";
	this->phone = "To be entered";
}

Patient::Patient(string aCareCard, string aName) {
	if (aCareCard.length() == 10) {
		this->cardNum = aCareCard;
	}
	else {
		this->cardNum = "0000000000";
	}
	this->address = "To be entered";
	this->email = "To be entered";
	this->name = aName;
	this->phone = "To be entered";
}

Patient::Patient(string aCareCard, string aName, string anEmail) {
	if (aCareCard.length() == 10) {
		this->cardNum = aCareCard;
	}
	else {
		this->cardNum = "0000000000";
	}
	this->address = "To be entered";
	this->email = anEmail;
	this->name = aName;
	this->phone = "To be entered";
}

Patient::Patient(string aCareCard, string aName, string anEmail, string aPhone) {
	if (aCareCard.length() == 10) {
		this->cardNum = aCareCard;
	}
	else {
		this->cardNum = "0000000000";
	}
	this->address = "To be entered";
	this->email = anEmail;
	this->name = aName;
	this->phone = aPhone;
}

Patient::Patient(string aCareCard, string aName, string anEmail, string anAddress, string aPhone) {
	if (aCareCard.length() == 10) {
		this->cardNum = aCareCard;
	}
	else {
		this->cardNum = "0000000000";
	}
	this->address = anAddress;
	this->email = anEmail;
	this->name = aName;
	this->phone = aPhone;
}

// All other parameterized constructors -> You need to implement these methods.

// Getters and setters -> You need to implement these methods.

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient& rhs) {

	// Compare both Patient objects
	return this->cardNum == rhs.getCareCard();

} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient& rhs) {

	// Compare both Patient objects
	return this->cardNum > rhs.getCareCard();

} // end of operator >

// Description: Less than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is < the care card 
//              number of "rhs" Patient object.
bool Patient::operator < (const Patient& rhs) {

	// Compare both Patient objects
	return this->cardNum < rhs.getCareCard();

} // end of operator <

// For testing purposes!
// Description: Prints the content of "this".
ostream& operator<<(ostream& os, const Patient& p) {

	os << p.cardNum << " - Patient: " << p.name << ", "
		<< p.address << ", " << p.phone << ", " << p.email << endl;

	return os;

} // end of operator<<

// end of Patient.cpp