#pragma once

#include <map>
#include <vector>
#include "Room.h"

class GameWorld
{
public:
    GameWorld(Room *initialRoom);

    ~GameWorld();

    void addRoom(std::string key, Room &room);

    void moveToRoom(std::string roomName);

    bool isValidCommand(std::string input);

    bool interact();

private:

    std::map<std::string, Room> roomMap;
    std::vector<std::string> validCommands;
    Room *currentRoom;
};

