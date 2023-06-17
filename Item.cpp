#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

Item::Item()
{
	itemCode = 0;
	itemName = " ";
	description = " ";
	price = 0.0;
	quantity = 0;
	supplierInfo = NULL;



}

Item::Item(int itemCode, string itemName, string description, float price, int quantity, Supplier* supplierInfo)
{
	this->itemCode = itemCode;
	this->itemName = itemName;
	this->description = description;
	this->price = price;
	this->quantity = quantity;
	this->supplierInfo = supplierInfo;
}

void Item::setItemCode(int itemCode)
{
	this->itemCode = itemCode;
}

void Item::setItemName(string itemName)
{
	this->itemName = itemName;
}

void Item::setDescription(string description)
{
	this->description = description;
}

void Item::setPrice(float price)
{
	this->price = price;
}

void Item::setQuantity(int quantity)
{
	this->quantity = quantity;
}

void Item::setSupplierInfo(Supplier* supplierInfo)
{
	this->supplierInfo = supplierInfo;
}

int Item::getItemCode() const
{
	return itemCode;
}

string Item::getItemName()
{
	return itemName;
}

string Item::getDescription()
{
	return description;
}

Supplier* Item::getSuppInfo()
{
	return this->supplierInfo;
}

float Item::getPrice()
{
	return price;
}

int Item::getQuaintity()
{
	return quantity;
}

void Item::printItemInfo()
{
	cout << "item Code: " << getItemCode() << endl;
	cout << "item Name: " << getItemName() << endl;
	cout << "descreiption:  " << getDescription() << endl;
	cout << "price of item: " << getPrice() << endl;
	cout << "Quantity: " << getQuaintity() << endl;
	cout << "Supplier info: \n";
	this->supplierInfo->printInfo();
	cout << endl;
}

