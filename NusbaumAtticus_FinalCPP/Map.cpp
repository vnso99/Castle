#include<vector>
#include<iostream>
#include<string>
#include "Map.h"

using namespace std;

Map::Map()
{
	Room* start = new Room("Castle Entrance", "You stand outside the castle. The castle’s rough stone walls are enveloped in moss. You look up seeing the castle’s towers stretch into the clouds. A giant, wrought iron portcullis stands at the ready, guarding the castle’s dark entrance. You find yourself lost in its mystery when suddenly, the sky flashes, and rain begins to pour down. You should hurry inside!", "Large briar bushes surround you and the large tree is blocking the path behind you. Maybe you should seek shelter in the castle? Returning your gaze to the portcullis, you notice it gives the castle’s entrance an inviting look. You feel drawn towards the darkness... ", false);
	mStart = start;

	Room* airlock = new Room("Portcullis House", "Crack* As you run inside the gate, a large bolt of lightning strikes where you stood only moments ago! *Crash* The portcullis has closed behind you, sealing you in!  You feel your only way out is through the castle.", "On the floor lays a skeleton; clutching a pickaxe in his bony hands. A lone wooden door stands before you. Dare you enter?", false);

	Room* entrancehall = new Room("Entrance Hall", "Passing through the small wooden door, you enter a grand Entrance Hall. Tapestry covered walls and vaulted marble ceilings stretch as far as your eyes can see. The whole room is well lit, yet nary a candle nor torch can be found", "To your right, a humble wooden door stands. Surrounded by marbled walls on all sides, it looks out of place. To your front and to your left, archways inscribed with a strange language grace the ceiling, leading to other sections of the massive hall.", false);

	Room* lounge = new Room("Lounge", "You pass through the small, wooden door and enter a belabouredly decorated Lounge. Visions of wealthy aristocrats enjoying cigars and relaxing in the plush surroundings flood your mind. There are several cob-web covered chairs and loveseats stricken across the lounge. Bookshelves filled to the brim with ancient texts dot the wall.", "To your South lies a silver lined door.", false);

	Room* gbedroom = new Room("Guest Bedroom", "As you enter the Guest Bedroom, a feeling of immense exhaustion overtakes you. You see a large, plush bed in the middle of the room surrounded by night tables and a large changing area. Strangely enough, the bed is free from all spiderwebs and dust.", "To your right, there is a bathroom.", false);
	gbedroom->setRoomItems("bedroomkey");

	Room* gbathroom = new Room("Guest Bathroom", "You enter the Guest Bathroom. The floor is composed of white and blue ceramic tiles. A large bathtub stretched along the wall, with intricate designs running along its side. Next to it stands a rusted sink. Clearly, no one has used it in years.", "You investigate the sink. The bowl is filled with murky brown water.  At the bottom you of the sink is a key. You wonder what it opens.", false);
	gbathroom->setRoomItems("librarykey");

	Room* kitchens = new Room("Kitchens", "You enter the Kitchens of the castle. Countertops, stoves, sinks, and ovens stretch as far as the eye can see.", "To your South lies a flimsy wooden door. ", false);

	Room* foodstore = new Room("Food Store", "You enter the Food Storage. Large sacks of grain line the walls, while meat and vegetables sit perfectly preserved on the shelves. How have they stayed fresh this long?", "You see a small hole in the wall. As you lean down to get a closer look a rat runs right past your nose.", false);

	Room* wquarters = new Room("Worker's Quarters", "Cots and bedpans spread as far as the eye can see. This was not a pleaent place to live...", "You see holes in the walls where shackles once hung. Hopefully they escaped. ", false);
	wquarters->setRoomItems("dungeonkey");

	Room* phall = new Room("Painting Hall", "You enter the Painting Hall. The entirety of each wall is covered in paintings. Various gold and silver frames dance off your torchlight. As you walk down the hall, the eyes of the paintings seem to follow you... ", "As you are walking down the hall, you hear a sudden sound. You turn around to see a broken painting and chunks of stone on the floor. Where the painting once stood is a small hole. Maybe you can make a larger one?", false);

	Room* bathes = new Room("Bathes", "You enter the Bathes. A giant pool adorned with fountains, diving boards and pillars spread out before you.", "To your left stands a small metal door, painted to match the walls.", false);

	Room* boiler = new Room("Boiler Room", "You enter the Boiler Room. Rusted pipes, water heaters, dials, and valves wrap around each other in an intricate maze. The once marvelous system is quiet now, expect for the occasional drop of water.", "A drop of rust filled water falls in your eye. At least you got your daily amount of iron. ", false);

	Room* stunnel = new Room("Secret Tunnel", "Exhausted, you stop to catch your breath, leaning on a section of the wall. Suddenly, it gives way, revealing a secret tunnel! While only the entrance is lit, you can see the tunnel was carved from solid layers of stone. It looks to have been by hand. How many years of work did this take?", "Unable to see, you walk slowly down the tunnel, feeling your way along its length until you walk face first into a metal door.", false);
	mSecretTunnel = stunnel;

	Room* dungeon = new Room("Dungeon", "You enter the Dungeon. Shackles and torture devices line the walls. A caged skeleton is hanging from the ceiling. The air is heavy with feelings of malice and suffering. In the center of the room sits a blood-soaked pedestal.", "You enter the Dungeon. Shackles and torture devices line the walls. A caged skeleton is hanging from the ceiling. The air is heavy with feelings of malice and suffering. In the center of the room sits a blood-soaked pedestal.", true);
	dungeon->setRoomItems("recordskey");
	mDungeon = dungeon;

	Room* parea = new Room("Private Area", "You walk into a gated area with a broken lock. This must be the castle lord's private quarters!", "To your right is a grand wooden door with the word 'Library' carved into. To your left lies a gigantic door laden with diamonds and other precious gems...", false);

	Room* mbedroom = new Room("Master Bedroom", "You enter the Master Bedroom. A luxurious bed, covered in the most expensive silks, surrounded by an Ebony Wood frame stands before you. It demands your attention and respect.", "You lean in closer to examine the bed. Carvings depicting dragons, knights, and vampires cover the bed’s frame. The bed’s cover is stitched in the pattern of a family crest.", true);
	mbedroom->setRoomItems("crest");
	mMasterBedroom = mbedroom;

	Room* mbathroom = new Room("Master Bathroom", "You enter the Master Bathroom.  Walls and a floor composed of marble and gold dance before your eyes. A bath the size of an Olympic swimming pool stretches out before you. Its edge is paved with diamonds.", "", false);

	Room* library = new Room("Library", "You enter the library. Thousands of books, filling every shelf meet your gaze.", "You look over the titles of the books, and almost all of them are about vampires. You open one at random and are shocked to see an illistration of the vary castle you are in. In the right end of the library lies a gated off section. What could be in there?", true);
	mLibrary = library;

	Room* records = new Room("Family Records", "Opening the gate, you enter the family records section. A large leather bound book sits before you. Upon opening it, you see a family tree... with only three members. As you go to turn the page, a fang falls out of the book, and you jump back. Could the lord of this castle be a vampire?", "To your right you see a book sticking out of the shelf and notice a wire attached to it. Maybe you should investiage?", true);
	records->setRoomItems("book");
	mFamilyRecords = records;

	Room* crypt = new Room("Family Crypt", "You grab the wire, and a book case swings open. Looking at the newly revelead room, you see three tombs hidden inside a cave. The lid on one is adjacent!", "Looking around, you see intricate paintings on the walls of the cave. Battles depicting vampires fighting hundreds of men. In the corner of the room you notice a diamond-entrusted sword next to a small tunnel entrance.", false);
	crypt->setRoomItems("sword");

	Room* t1 = new Room("Tunnel", "You crawl into the tunnel. Dark and damp it is.", "You cannot see anything but the tunnel heads north.", false);

	Room* t2 = new Room("Tunnel", "In the distance, you can see a light!", "There is no way but north!", false);

	Room* sroom = new Room("Summoning Room", "Crawling out of the tunnel, you find yourself in a strange, evil room. A large pyre sits in the middle of it. Lit candles line the room's wall, and give it an eeire glow. The scroll in your pocket is starting to emit bolts of light!", "The only way out of this room is the tunnel behind you. You know what you must you do.", false);
	mSummoningRoom = sroom;

	start->n = airlock;
	start->s = NULL;
	start->r = NULL;
	start->l = NULL;

	airlock->n = entrancehall;
	airlock->s = start;
	airlock->r = NULL;
	airlock->l = NULL;

	entrancehall->n = phall;
	entrancehall->s = airlock;
	entrancehall->r = lounge;
	entrancehall->l = kitchens;

	lounge->n = NULL;
	lounge->s = gbedroom;
	lounge->r = NULL;
	lounge->l = entrancehall;

	gbedroom->n = lounge;
	gbedroom->s = NULL;
	gbedroom->r = gbathroom;
	gbedroom->l = NULL;

	gbathroom->n = NULL;
	gbathroom->s = NULL;
	gbathroom->r = NULL;
	gbathroom->l = gbedroom;

	kitchens->n = NULL;
	kitchens->s = wquarters;
	kitchens->r = entrancehall;
	kitchens->l = foodstore;

	wquarters->n = kitchens;
	wquarters->s = NULL;
	wquarters->r = NULL;
	wquarters->l = NULL;

	foodstore->n = NULL;
	foodstore->s = NULL;
	foodstore->r = kitchens;
	foodstore->l = NULL;

	phall->n = parea;
	phall->s = entrancehall;
	phall->r = stunnel;
	phall->l = bathes;

	stunnel->n = NULL;
	stunnel->s = NULL;
	stunnel->r = dungeon;
	stunnel->l = phall;

	dungeon->n = NULL;
	dungeon->s = NULL;
	dungeon->r = NULL;
	dungeon->l = stunnel;

	bathes->n = NULL;
	bathes->s = NULL;
	bathes->r = phall;
	bathes->l = boiler;

	boiler->n = NULL;
	boiler->s = NULL;
	boiler->r = bathes;
	boiler->l = NULL;

	parea->n = NULL;
	parea->s = phall;
	parea->r = library;
	parea->l = mbedroom;

	mbedroom->n = NULL;
	mbedroom->s = NULL;
	mbedroom->r = parea;
	mbedroom->l = mbathroom;

	mbathroom->n = NULL;
	mbathroom->s = NULL;
	mbathroom->r = mbedroom;
	mbathroom->l = NULL;

	library->n = NULL;
	library->s = NULL;
	library->r = records;
	library->l = parea;

	records->n = NULL;
	records->s = NULL;
	records->r = crypt;
	records->l = library;

	crypt->n = t1;
	crypt->s = NULL;
	crypt->r = NULL;
	crypt->l = records;

	t1->n = t2;
	t1->s = crypt;
	t1->r = NULL;
	t1->l = NULL;

	t2->n = sroom;
	t2->s = t1;
	t2->r = NULL;
	t2->l = NULL;

	sroom->n = NULL;
	sroom->s = t2;
	sroom->r = NULL;
	sroom->l = NULL;
};

Map::~Map()
{
	delete mStart->n;
	delete mStart->r;
	delete mStart->s;
	delete mStart->l;
}