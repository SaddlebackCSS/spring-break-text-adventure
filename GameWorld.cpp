#include "GameWorld.h"
#include <iostream>
#include <algorithm>

GameWorld::GameWorld(Room* initialRoom)
{
	currentRoom = initialRoom;
}

GameWorld::~GameWorld(){}

void GameWorld::addARoom(std::string key, Room& room)
{
	roomMap[key] = room;
}

void GameWorld::moveToRoom(std::string roomName)
{
	if (roomName != "none")
	{
		currentRoom = &roomMap[roomName];
	}
	else
	{
		std::cout << "There is nowhere to go in that direction." << std::endl;
	}
}

bool GameWorld::isValidCommand(std::string input)
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

bool GameWorld::interact()
{
	std::string input;
	bool isStillPlaying = true;

	std::cout << currentRoom->GetRoomDesc() << std::endl;
	do
	{
		std::cout << "Enter a command: ";

		getline(std::cin, input);
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (!isValidCommand(input))
		{
			std::cout << std::endl << "That is not a valid command" << std::endl;
		}

	} while (!isValidCommand(input));

	if (input == "north")
	{
		moveToRoom(currentRoom->GetNorth());
	}

	if (input == "east")
	{
		moveToRoom(currentRoom->GetEast());
	}

	if (input == "south")
	{
		moveToRoom(currentRoom->GetSouth());
	}

	if (input == "west")
	{
		moveToRoom(currentRoom->GetWest());
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


