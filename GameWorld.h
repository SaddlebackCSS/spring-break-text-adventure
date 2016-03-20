#pragma once

#include <map>
#include <vector>
#include "Room.h"

class GameWorld
{
public:
	std::map<const std::string, Room> roomMap;
	std::vector<std::string> validCommands;
	Room* currentRoom;
	void addARoom(std::string name, Room& room);
	void moveToRoom(std::string roomName);
	bool isValidCommand(std::string input);
	bool InteractWithRoom();
	GameWorld(Room* initialRoom);
	~GameWorld();
};

