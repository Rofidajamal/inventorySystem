#include "Supplier.h"
#include <string>
#include <iostream>
using namespace std;

Supplier::Supplier()
{
	name = " ";
	email = " ";
	phoneNumber = 0;
	address = " ";
}

Supplier::Supplier(string name, string email, int phoneNumber, string address) {
	this->name = name;
	this->email = email;
	this->phoneNumber = phoneNumber;
	this->address = address;
}

void Supplier::setName(string name)
{
	this->name = name;
}

string Supplier::getName()
{
	return name;
}

void Supplier::setEmail(string email)
{
	this->email = email;
}

string Supplier::getEmail()
{
	return email;
}

void Supplier::setPhoneNmber(int phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

int Supplier::getPhoneNumber()
{
	return phoneNumber;
}

void Supplier::setAddress(string address)
{
	this->address = address;
}

string Supplier::getAddress()
{
	return address;
}

void Supplier::printInfo()
{
	cout << "name: " << this->getName() << "\n" << "email: " << this->getEmail() << "\n";
	cout << "phone: " << this->getPhoneNumber() << "\n" << "address: " << this->getAddress() << "\n";
}

