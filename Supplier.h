#pragma once
#include<string>
#include <iostream>
using namespace std;

class Supplier
{
private:
	string name;
	string email;
	int phoneNumber;
	string address;
public:
	Supplier();
	Supplier(string name, string email, int phoneNumber, string address);

	void setName(string name);
	string getName();

	void setEmail(string email);
	string getEmail();

	void setPhoneNmber(int phoneNumber);
	int getPhoneNumber();

	void setAddress(string address);
	string getAddress();

	void printInfo();


};