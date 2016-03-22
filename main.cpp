#include <iostream>
#include <string>
#include <map>
#include "Room.h"
#include "GameWorld.h"

using namespace std;

int main()
{
	const string ROOM_1_NAME = "First Room";
	const string ROOM_2_NAME = "Second Room";
	Room room1(ROOM_1_NAME, "The first room in the house ", ROOM_2_NAME);
	Room room2(ROOM_2_NAME, "The second room in the house ", "none", "none", ROOM_1_NAME, "none");

	GameWorld world(&room1);
	world.addARoom(ROOM_1_NAME, room1);
	world.addARoom(ROOM_2_NAME, room2);

	bool isPlaying;

	/*world.moveToRoom(ROOM_2_NAME);

	world.InteractWithRoom();*/

	do
	{

		isPlaying = world.interact();

	} while (isPlaying);

	return 0;
}