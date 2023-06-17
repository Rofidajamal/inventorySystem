#include "Item.h"
#include <vector>
#include <fstream>

class inventory
{
private:
	vector<Item> items;
public:
	inventory();

	size_t getSize();
	Item getItem(int itemCode);
	void addItem(Item item);
	void editItem(int itemCode, string name, string description, float price, int quantity, Supplier* supplier);
	void deleteItem(int itemCode);
	bool checkInventortylevels(int itemCode, int threshold);
	void print();
	void writeToFile(string path);

};
