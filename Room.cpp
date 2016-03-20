#include "Room.h"



Room::Room(std::string name, std::string desc, std::string north, std::string east, std::string south, std::string west)
{
	roomName = name;
	roomDesc = desc;
	northRoom = north;
	eastRoom = east;
	southRoom = south;
	westRoom = west;
}

Room::Room() {}

Room::~Room() {}
