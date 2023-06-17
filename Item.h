#pragma once
#include <string>
#include "Supplier.h"
using namespace std;
class Item
{

private:
	int itemCode;
	string itemName;
	string description;
	float price;
	int quantity;
	Supplier* supplierInfo;
public:
	Item();
	Item(int itemCode, string itemName, string description, float price, int quantity, Supplier* supplierInfo);
	void setItemCode(int itemCode);
	void setItemName(string itemName);
	void setDescription(string description);
	void setPrice(float price);
	void setQuantity(int quantity);
	void setSupplierInfo(Supplier* supplierInfo);

	int getItemCode() const;
	string getItemName();
	string getDescription();
	Supplier* getSuppInfo();
	float getPrice();
	int getQuaintity();
	void printItemInfo();
	



};

