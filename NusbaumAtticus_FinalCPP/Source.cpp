#include "Player.h"

using namespace std;


void MainGame() {
	Map GameMap;
	char com;
	Player Wigginator;
	Player* Wigg = new Player();

	Wigginator.pLoc->pRoomName();
	Wigginator.pLoc->pRoomDesc();

	while (1) {
		Wigginator.Travel(Wigg);
	}
}

void gamePrologue() {
	cout << "\nWelcome to Castle!\n";

	cout << "Our story begins with a young rogue sleeping on the back on a wagon. Upon waking, the rogue notices the wagon is filled with precious items. Managing to swipe a few, he runs off into the woods. Eventually he is well and lost, but luckily, fortune smiles upon him and he finds a castle!\n";
}

void Controls() {
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

int main()
{
	cout << "\n--------------------------------------------\n-------------Welcome to Castle!-------------\n--------------------------------------------\n";

	while (1) {


		int choice;

		cout << "---------------\n---Main Menu---\n---------------\n";

		cout << "1. New Game\n2. Prologue\n3. Controls\n4. Quit\n";

		cin >> choice;

		if (cin.fail()) {
			cout << "\nInvalid entry!\n";
			cin.clear();
			cin.ignore(256, '\n');
		}

		else {
			switch (choice) {
			case 1: MainGame(); break;
			case 2: gamePrologue();  break;
			case 3: Controls(); break;
			case 4: return 0;
			default: cout << "Invalid entry!"; break;
			}
		}

	}
}


