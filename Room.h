#ifndef SPRING_BREAK_TEXT_ADVENTURE_ROOM_H
#define SPRING_BREAK_TEXT_ADVENTURE_ROOM_H

#include <string>
#include <map>

class Room
{
public:
    Room();
    Room(std::string desc, std::string N, std::string S, std::string E, std::string W);
    ~Room();

    std::string GetDesc()const;

private:
    std::string description;
    std::map<std::string, std::string> linked;
    std::string north;
    std::string south;
    std::string east;
    std::string west;
};


#endif //SPRING_BREAK_TEXT_ADVENTURE_ROOM_H
