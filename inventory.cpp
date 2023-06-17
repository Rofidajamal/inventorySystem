#include "inventory.h"
#include "Item.h"
#include <iostream>
#include <fstream>
using namespace std;


inventory::inventory()
{

}

size_t inventory::getSize()
{
	return items.size();
}

Item inventory::getItem(int itemCode)
{
	if (itemCode < 0 || itemCode > items.size()) {
		throw("invalid item code");
	}
	for (int i = 0; i < items.size(); i++) {
		if (items[i].getItemCode() == itemCode) {
			return items[i];
			break;

		}
	}

}

void inventory::addItem(Item item)
{
	items.push_back(item);
}

void inventory::editItem(int itemCode, string name, string description, float price, int quantity, Supplier* supplier)
{
	if (itemCode < 0 || itemCode > items.size()) {
		throw("invalid item code");
	}

	for (int i = 0; i < items.size(); i++) {
		if (items[i].getItemCode() == itemCode) {
			items[i].setItemName(name);
			items[i].setDescription(description);
			items[i].setPrice(price);
			items[i].setQuantity(quantity);
			items[i].setSupplierInfo(supplier);
		}
	}

}

void inventory::deleteItem(int itemCode) {
	if (itemCode <0 || itemCode > items.size()) {
		throw("Invalid item code");
		cout << endl;
	}
	for (int i = 0; i < items.size(); i++) {
		if (items[i].getItemCode() == itemCode) {
			items.erase(items.begin() + i);
			break;
		}
	}
}

bool inventory::checkInventortylevels(int itemCode, int threshold)
{
	for (int i = 0; i < items.size(); i++) {
		if (items[i].getItemCode() == itemCode) {
			if (items[i].getQuaintity() < threshold) {
				cout << "Alert: Item " << items[i].getItemName() << " is running low on inventory." << endl;
				return true;
			}
			break;
		}
	}
	return false;
}

void inventory::print()
{
	for (int i = 0; i < items.size(); i++) {
		cout << "item code: " << items[i].getItemCode() << endl;
		cout << "item name: " << items[i].getItemName() << endl;
		cout << "item Discription: " << items[i].getDescription() << endl;
		cout << "item quantity : " << items[i].getQuaintity() << endl;
		cout << "item price : " << items[i].getPrice() << endl;
		Supplier* sup = items[i].getSuppInfo();
		cout << "supplier info: \n" << sup->getName() << " " << sup->getEmail() << " " << sup->getAddress() << " " << sup->getPhoneNumber();
		cout << "\n===========================================\n";
	}

}

void inventory::writeToFile(string path)
{
	ofstream f;
	f.open(path);

	if (!f.is_open()) {
		runtime_error("ERROR you don't have a permission to open it");

	}

	for (int i = 0; i < this->getSize(); i++) {
		f << "item code: " << items[i].getItemCode()<<"\n";
		f << "item name: " << items[i].getItemName() << "  " << "item discription: " << items[i].getDescription()<<"\n";
		f << "item Quantity: " << items[i].getQuaintity() << " " << "item price: " << items[i].getPrice() << "\n";
		Supplier* sup = items[i].getSuppInfo();
		f << "supplier info: \n"<<sup->getName()<<" "<<sup->getEmail()<<" "<<sup->getAddress()<<" "<<sup->getPhoneNumber();
		f << "\n==============================================================\n";
	}
	f.close();
}




