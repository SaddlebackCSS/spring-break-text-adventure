#pragma once

#include <string>

class Room
{
public:
    // default constructor
    Room();

    // constructor with default values
    Room(std::string name, std::string desc, std::string north = "none",
         std::string east = "none", std::string south = "none",
         std::string west = "none");

    ~Room();

    std::string GetRoomDesc();
    std::string GetNorth();
    std::string GetEast();
    std::string GetWest();
    std::string GetSouth();
    std::string GetRoomName();

private:

    std::string northRoom;
    std::string eastRoom;
    std::string southRoom;
    std::string westRoom;
    std::string roomName;
    std::string roomDesc;

};

