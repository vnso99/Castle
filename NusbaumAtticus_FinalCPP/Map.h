#include<iostream>
#include<string>
#include<vector>
#include "Room.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();

	Room* mStart;
	Room* mSecretTunnel;
	Room* mDungeon;
	Room* mMasterBedroom;
	Room* mLibrary;
	Room* mFamilyRecords;
	Room* mSummoningRoom;
};
