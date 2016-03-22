
#ifndef SPRING_BREAK_TEXT_ADVENTURE_MANSION_H
#define SPRING_BREAK_TEXT_ADVENTURE_MANSION_H

#include <fstream>
#include <vector>
#include <map>
#include "Room.h"

class Mansion
{
public:
    Mansion();
    ~Mansion();

    Room GetRoom(std::string key);

private:

    void readRooms();

    std::string currentLocation;
    std::map<std::string, Room> mansion;
    int numRooms;
};


#endif //SPRING_BREAK_TEXT_ADVENTURE_MANSION_H
