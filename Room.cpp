#include "Room.h"

Room::Room()
{
	roomName = "default";
	roomDesc = "You're in the first room. Wow.";
	northRoom = "none";
	eastRoom  = "none";
	westRoom  = "start";
	eastRoom  = "none";
}

Room::Room(std::string name, std::string desc, std::string north,
					 std::string east, std::string south, std::string west)
{
	roomName = name;
	roomDesc = desc;
	northRoom = north;
	eastRoom = east;
	southRoom = south;
	westRoom = west;
}

Room::~Room() {}

// Return the description of the room.
std::string Room::GetRoomDesc()
{
	return roomDesc;
}

// Return the key of the room to the North.
std::string Room::GetNorth()
{
	return northRoom;
}

// Return the key of the room to the East.
std::string Room::GetEast()
{
	return eastRoom;
}

// Return the key of the room to the West.
std::string Room::GetWest()
{
	return westRoom;
}

// Return the key of the room to the South.
std::string Room::GetSouth()
{
	return southRoom;
}

// Return the key of the current room.
std::string Room::GetRoomName()
{
	return roomName;
}












