#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include "Player.h"

using namespace std;

Player::Player()
{
	pLoc = mStart;

	inventory.push_back("scroll");
	inventory.push_back("crest");
	inventory.push_back("book");
	inventory.push_back("sword");
}

void Player::getInventory()
{
	vector<string>::iterator iter;

	if (inventory.size() != 0)
	{
		cout << "\nInventory list:" << endl;
		for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
	else
		cout << "\nInventory is empty!" << endl;
}

int Quit() {

	char chk;
	cout << "Are you sure you want to quit? Y/N\n";
	cin >> chk;
	chk = toupper(chk);
	if (chk == 'Y') {
		exit(EXIT_SUCCESS);
	}
	else if (chk == 'N') {

	}
	else {
		cout << "Invalid entry";
	}
}

void Help() {
	cout << "\n+---List of Controls: ---+\n";
	cout << "Use 'W,A,S,D' to move your character\n";
	cout << "Use 'I' to check your inventory\n";
	cout << "Use 'G' to pick up the current room's items\n";
	cout << "Use 'L' to look around your surroundings for hidden clues\n";
	cout << "Use 'B' to activate your cleansing scroll... if you dare\n";
	cout << "Use 'H' to summon this menu\n";
	cout << "Use 'Q' to leave the game\n";
	cout << "+-------------------------+\n";
}

void Player::grabRoomItems(Player* Wigg)
{
	string item;
	cout << "What do you want to pick up?\n";
	cin >> item;

	if (find(Wigg->pLoc->roomInventory.begin(), Wigg->pLoc->roomInventory.end(), item) != Wigg->pLoc->roomInventory.end())
	{
		cout << "You got the " << item << "!\n" << endl;
		Wigg->inventory.push_back(item);
		Wigg->pLoc->roomInventory.pop_back();
	}
	else {
		cout << "That item cannot be found!\n";
	}
}

bool Player::keyCheck(Player* Wigg)
{
	if (pLoc->r == mDungeon) {
		vector<string>::iterator position = find(inventory.begin(), inventory.end(), "dungeonkey");
		if (position != inventory.end()) {
			cout << "\nYou unlocked the door!\n";
			pLoc->unLock(false);
			return true;
		}
	}
	else if (pLoc->r == mLibrary || pLoc->l == mLibrary) {
		vector<string>::iterator position = find(inventory.begin(), inventory.end(), "librarykey");
		if (position != inventory.end()) {
			cout << "\nYou unlocked the door!\n";
			pLoc->unLock(false);
			return true;
		}
	}
	else if (pLoc->r == mFamilyRecords || pLoc->l == mFamilyRecords) {
		vector<string>::iterator position = find(inventory.begin(), inventory.end(), "recordskey");
		if (position != inventory.end()) {
			cout << "\nYou unlocked the door!\n";
			pLoc->unLock(false);
			return true;
		}
	}
	else if (pLoc->l == mMasterBedroom || pLoc->r == mMasterBedroom) {
		vector<string>::iterator position = find(inventory.begin(), inventory.end(), "bedroomkey");
		if (position != inventory.end()) {
			cout << "\nYou unlocked the door!\n";
			pLoc->unLock(false);
			return true;
		}
	}
}

void Player::pLose() {
	cout << "You open the magic scroll and reciute the words found within!\n Immidietly upon finishing, the scroll catches on fire, and your body disolves into a pile of goo. You die knowing you didn't complete your quest.\n";
	cout << "\n You have failed your quest.\n";
	system("pause");
	exit(EXIT_SUCCESS);
}

void Player::pWin() {
	cout << "You open the magic scroll and reciute the words found within!\n Immidietly upon finishing, the scroll floats out of your hands and emits a blinding light! You hear a loud shreak and sounds of death. The scroll explodes in a burst of light. Suddenly, the room you are in feels safe and warm.\n";
	cout << "\n\nYou have vanquished the evil vampire and cleansed the castle!\n Congratulations Brave Hero!\n";
	cout << "\nYou beat the game!\n";
	system("pause");
	exit(EXIT_SUCCESS);
}

void Player::pBadWin() {
	cout << "You open the magic scroll, but suddenly, something evil overcomes you!\n You throw the scroll into the lit pyre and hear a tremedous scream! A strange voice screams, 'I am free once more!' You notice a shadow behind you, then, everything goes black...\n";
	cout << "\n\nYou have resurrected the evil vampire and plunged the world into 1000 years of darkness!\n Congratulations!\n";
	cout << "\nYou beat the game, and are now the thrall of a vampire!\n";
	system("pause");
	exit(EXIT_SUCCESS);
}

void Player::finalCheck(Player* Wigg)
{
	char inp;
	cout << "Are you sure you want to read the scroll? Y/N \n";
	cin >> inp;
	inp = toupper(inp);
	if (inp == 'Y') {
		vector<string>::iterator position = find(inventory.begin(), inventory.end(), "crest");
		if (position != inventory.end()) {
			vector<string>::iterator position2 = find(inventory.begin(), inventory.end(), "book");
			if (position2 != inventory.end()) {
				vector<string>::iterator position3 = find(inventory.begin(), inventory.end(), "sword");
				if (position3 != inventory.end()) {
					string choose;
					cout << "Do you want to be a hero... or a villan?";
					cin >> choose;
					if (choose == "hero" || "Hero") {
						pWin();
					}
					else {
						pBadWin();
					}
				}
			}
		}
		else {
			pLose();
		}
	}
	else if (inp == 'N') {

	}
	else {
		cout << "Invalid input";
	}

}

void Player::Travel(Player* Wigg) {
	cout << "What will you do?\n";

	char c;
	cin >> c;
	c = toupper(c);

	switch (c) {
	case 'W': nullCheck(Wigg, c); break;
	case 'S': nullCheck(Wigg, c); break;
	case 'D': nullCheck(Wigg, c); break;
	case 'A': nullCheck(Wigg, c); break;
	case 'I': Wigg->getInventory(); break;
	case 'G': grabRoomItems(Wigg); break;
	case 'H': Help(); break;
	case 'L': Wigg->pLoc->roomLook(); break;
	case 'B': finalCheck(Wigg); break;
	case 'Q': Quit(); break;
	default: cout << "Invalid command"; break;
	}
}


void Player::nullCheck(Player* Wigg, char inp) {

	bool key;

	if (inp == 'W') {
		// North Validation
		if (Wigg->pLoc->n == NULL) {
			cout << "\nYou walk into a wall\n";
		}
		else {
			if (Wigg->pLoc->n->needsKey() == false) {
				Wigg->pLoc = Wigg->pLoc->n; Wigg->pLoc->roomInfo();
			}
			else if (Wigg->keyCheck(Wigg) == true) {
				Wigg->pLoc = Wigg->pLoc->n; Wigg->pLoc->roomInfo();
			}
			else {
				cout << "\nYou need a key!\n";
			}
		}
	}

	else if (inp == 'S') {
		//South Validation
		if (Wigg->pLoc->s == NULL) {
			cout << "\nYou walk into a wall\n";
		}
		else {
			if (Wigg->pLoc->s->needsKey() == false) {
				Wigg->pLoc = Wigg->pLoc->s; Wigg->pLoc->roomInfo();
			}
			else if (Wigg->keyCheck(Wigg) == true) {
				Wigg->pLoc = Wigg->pLoc->s; Wigg->pLoc->roomInfo();
			}
			else {
				cout << "\nYou need a key!\n";
			}
		}
	}

	else if (inp == 'D') {
		//East Validation
		if (Wigg->pLoc->r == NULL) {
			cout << "\nYou walk into a wall\n";
		}

		else {
			if (Wigg->pLoc->r->needsKey() == false) {
				Wigg->pLoc = Wigg->pLoc->r; Wigg->pLoc->roomInfo();
			}
			else if (Wigg->keyCheck(Wigg) == true) {
				Wigg->pLoc = Wigg->pLoc->r; Wigg->pLoc->roomInfo();
			}
			else {
				cout << "\nYou need a key!\n";
			}
		}
	}

	else if (inp == 'A') {
		//West Validation
		if (Wigg->pLoc->l == NULL) {
			cout << "\nYou walk into a wall\n";
		}
		else {
			if (Wigg->pLoc->l->needsKey() == false) {
				Wigg->pLoc = Wigg->pLoc->l; Wigg->pLoc->roomInfo();
			}
			else if (Wigg->keyCheck(Wigg) == true) {
				Wigg->pLoc = Wigg->pLoc->l; Wigg->pLoc->roomInfo();
			}
			else {
				cout << "\nYou need a key!\n";
			}
		}
	}

	else {
		cout << "Error";
	}

}