#pragma once
#include <string>

class Room
{
public:
	std::string northRoom;
	std::string eastRoom;
	std::string southRoom;
	std::string westRoom;
	std::string roomName;
	std::string roomDesc;
	Room(std::string name, std::string desc, std::string north = "none", std::string east = "none", std::string south = "none", std::string west = "none");
	Room();
	~Room();
};

