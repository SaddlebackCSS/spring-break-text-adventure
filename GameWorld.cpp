#include "GameWorld.h"
#include <iostream>
#include <algorithm>

using namespace std;

GameWorld::GameWorld(Room* initialRoom)
{
	currentRoom = initialRoom;
}

GameWorld::~GameWorld(){}

void GameWorld::addARoom(string name, Room& room)
{
	roomMap[name] = room;
}

void GameWorld::moveToRoom(std::string roomName)
{
	if (roomName != "none")
	{
		currentRoom = &roomMap[roomName];
	}
	else
	{
		cout << "There is nowhere to go in that direction." << endl;
	}
}

bool GameWorld::isValidCommand(string input)
{
	bool isValid = false;

	if (input == "north")
	{
		isValid = true;
	}

	if (input == "east")
	{
		isValid = true;
	}

	if (input == "south")
	{
		isValid = true;
	}

	if (input == "west")
	{
		isValid = true;
	}

	if (input == "exit")
	{
		isValid = true;
	}

	if (input == "quit")
	{
		isValid = true;
	}

	return isValid;
}

bool GameWorld::InteractWithRoom()
{
	std::string input;
	bool isStillPlaying = true;

	do
	{
		cout << currentRoom->roomDesc;

		getline(std::cin, input);
		transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (!isValidCommand(input))
		{
			std::cout << std::endl << "That is not a valid command" << std::endl;
		}

	} while (!isValidCommand(input));

	if (input == "north")
	{
		moveToRoom(currentRoom->northRoom);
	}

	if (input == "east")
	{
		moveToRoom(currentRoom->eastRoom);
	}

	if (input == "south")
	{
		moveToRoom(currentRoom->southRoom);
	}

	if (input == "west")
	{
		moveToRoom(currentRoom->westRoom);
	}

	if (input == "quit")
	{
		isStillPlaying = false;
	}

	if (input == "exit")
	{
		isStillPlaying = false;
	}

	return isStillPlaying;
}


