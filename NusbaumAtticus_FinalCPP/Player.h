#include <iostream>
#include <vector>
#include <string>
#include "Map.h"

using namespace std;

class Player : public Map
{
	char input;

public:
	Player();
	Room* pLoc;

	vector<string> inventory;

	void nullCheck(Player* Wigg, char inp);
	void getInventory();
	void grabRoomItems(Player* Wigg);
	bool keyCheck(Player* Wigg);
	bool pickCheck(Player* Wigg);
	void finalCheck(Player* Wigg);
	void Travel(Player* Wigg);
	void pWin();
	void pLose();
	void pBadWin();

	friend class Map;
};