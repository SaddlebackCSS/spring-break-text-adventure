#pragma once

#include <fstream>
#include <map>
#include <vector>
#include "Room.h"

class GameWorld
{
public:
    GameWorld();

    GameWorld(Room *initialRoom);

    ~GameWorld();

    void moveToRoom(std::string roomName);

    bool isValidCommand(std::string input);

    bool interact();

private:
    void initializeRooms();
    void initializeCommands();
    void addRoom(std::string key, Room newRoom);

    std::map<std::string, Room> roomMap;
    std::vector<std::string> validCommands;
    Room *currentRoom;
    int numRooms;
};

