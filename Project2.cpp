// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Supplier.h"
#include "Item.h"
#include "inventory.h"
using namespace std;

void getPurchaseOrder(inventory* inv)
{
	int chos;
	cout << "1- you will add new item \n2- add more quantity of an existing item\n";
	cin >> chos;
	if (chos == 1) {
		string name, email, address, disc;
		int phone, itemCode, quantity;
		float price;
		cout << "enter the information of supplier name, email, address, phone \n";
		cin >> name >> email >> address >> phone;
		Supplier sup(name, email, phone, address);
		cout << "enter the name of the item and the item code\n";
		cin >> name >> itemCode;
		cout << "enter the price , quantity and discription \n";
		cin >> price >> quantity >> disc;
		Item it(itemCode, name, disc, price, quantity, &sup);
		inv->addItem(it);
		//inv->print();

	}
	else if (chos == 2) {
		int itemCode, q;
		cout << "enter the item code please \n";
		cin >> itemCode;
		Item it = inv->getItem(itemCode);
		it.printItemInfo();
		cout << "enter the new quantity \n";
		cin >> q;
		inv->editItem(itemCode, it.getItemName(), it.getDescription(), it.getPrice(), q, it.getSuppInfo());
		//inv->print();
	}
}



void readFromFile(string path) {
	string line;
	ifstream f(path);

	if (!f.is_open()) {
		runtime_error("ERROR file not exist or you don't have a permission to open it");
	}


	while (getline(f, line)) {
		cout << line << endl;

	}
}

int main()
{
	cout << "welcome to our system \n\n";
	int c = 2;
	inventory inv;
	while (true) {
		if (c == 1) {
			int num;
			cout << "You should add items first\n";
			cout << "how much items you want to add \n";
			cin >> num;
			for (int i = 0; i < num; i++) {
				int code, q, phone;
				float price;
				string name, desc, supName, address, email;
				cout << "enter the item information item code, name, description , quantity, and price\n";
				cin >> code >> name >> desc >> q >> price;
				cout << "Enter the information of the supplier name address email and phone number \n";
				cin >> supName >> address >> email >> phone;

				Supplier sup(supName, email, phone, address);
				Item item(code, name, desc, price, q, &sup);
				inv.addItem(item);

			}
			c++;

		}
		else {
			int choice;
			cout << "\n====================================================\n";
			cout << "1-add new item\n2-delete item\n3-edit an item\n4-purchase order\n5-write to file\n6-load file\n7-Exit\n ";
			cin >> choice;
			if (choice == 1) {
				int code, q, phone;
				float price;
				string name, desc, supName, address, email;
				cout << "enter the item information item code, name, description , quantity, and price\n";
				cin >> code >> name >> desc >> q >> price;
				cout << "Enter the information of the supplier name address email and phone number \n";
				cin >> supName >> address >> email >> phone;

				Supplier sup(supName, email, phone, address);
				Item item(code, name, desc, price, q, &sup);
				inv.addItem(item);

			}
			else if (choice == 2) {
				int code;
				cout << "enter the item code you want to delete it \n";
				cin >> code;
				inv.deleteItem(code);
				cout << "item has been Removed \n";
			}
			else if (choice == 3) {
				int code, q, phone;
				float price;
				string name, desc, supName, address, email;
				cout << "enter the item information item code, name, description , quantity, and price\n";
				cin >> code >> name >> desc >> q >> price;
				cout << "Enter the information of the supplier name address email and phone number \n";
				cin >> supName >> address >> email >> phone;
				Supplier sup(supName, email, phone, address);
				inv.editItem(code, name, desc, price, q, &sup);
				cout << "DONE!" << endl << endl;

			}
			else if (choice == 4) {
				getPurchaseOrder(&inv);
				cout << "DONE!" << endl << endl;
			}
			else if (choice == 5) {
				string path;
				cout << "enter the path of the file\n";
				inv.writeToFile(path);
				cout << "DONE!" << endl << endl;
			}
			else if (choice == 6) {
				string path;
				cout << "enter the path of the file\n";
				readFromFile(path);
				cout << "\n===============================================\nDONE!\n";
			}
			else
				break;
		}

	}
		return 0;
}
