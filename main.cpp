#include <iostream>
#include <string>
#include <map>
#include "Room.h"
#include "GameWorld.h"

using namespace std;

int main()
{
	GameWorld *world;
	world = new GameWorld();

	bool isPlaying;

	cin.get();
	do
	{

		isPlaying = world->interact();

	} while (isPlaying);

	return 0;
}