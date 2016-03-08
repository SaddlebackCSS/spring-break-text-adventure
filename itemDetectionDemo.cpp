#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Item
{
	Item(string name);
	~Item();
	string name;
	void Interact();
};

Item::Item(string Name)
{
	name = Name;
}

Item::~Item(){}

void Item::Interact()
{
	cout << "You interact with the " << name << endl;
}

int main()
{
	Item item1("banana");
	Item item2("apple");
	Item item3("clock");
	Item item4("computer");
	Item item5("cup");

	vector<Item> itemList;
	itemList.push_back(item1);
	itemList.push_back(item2);
	itemList.push_back(item3);
	itemList.push_back(item4);
	itemList.push_back(item5);

	string input;

	cout << "You are in a room with a banana, an apple, a clock, a computer, and a cup: ";
	getline(cin, input);

	for (vector<Item>::iterator it = itemList.begin(); it != itemList.end(); it++)
	{
		if (input.find(it->name) != string::npos)
		{
			it->Interact();
			break;
		}
	}

	return 0;
}