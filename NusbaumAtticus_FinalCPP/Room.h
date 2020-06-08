#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Room
{
public:
	Room(string n, string desc, string look, bool key);
	void pRoomName();
	void pRoomDesc();
	void getRoomItems();
	void grabRoomItems(vector<string> &inv);
	void setRoomItems(string items);
	void roomInfo();
	void roomLook();
	bool needsKey();
	void unLock(bool lock);

	Room* r;
	Room* l;
	Room* n;
	Room* s;


	vector<string> roomInventory;

private:
	string rName;
	string rDesc;
	string rLook;
	bool rKey;
	bool rPick;
	bool rFinal;
};
