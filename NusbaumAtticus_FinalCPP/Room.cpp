#include<iostream>
#include<vector>
#include<string>
#include "Room.h"

using namespace std;

Room::Room(string n, string desc, string look, bool key)
{
	rName = n;
	rDesc = desc;
	rLook = look;
	rKey = key;
}

void Room::setRoomItems(string items)
{
	roomInventory.push_back(items);
}

void Room::pRoomName()
{
	cout << rName << endl;

}

void Room::pRoomDesc()
{
	cout << rDesc << endl;

}

void Room::roomLook()
{
	cout << "\n" << rLook << "\n" << endl;

	getRoomItems();
}

void Room::roomInfo() {
	pRoomName();
	pRoomDesc();
}

bool Room::needsKey() {
	if (rKey == true) {
		return true;
	}
	else {
		return false;
	}
}

void Room::getRoomItems()
{

	vector<string>::iterator iter;


	if (roomInventory.size() != 0)
	{
		cout << "\nThe rooms item(s):" << endl;
		for (iter = roomInventory.begin(); iter != roomInventory.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
	else
		cout << "\nThere are no items in this room!" << endl;
}

void Room::unLock(bool unlock) {
	if (unlock == true) {
		rKey = unlock;
	}
}