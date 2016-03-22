//
// Created by ozyx on 3/4/16.
//

#include <iostream>
#include "Mansion.h"

Mansion::Mansion()
{
  currentLocation = "start";
  readRooms();
}

Mansion::~Mansion()
{

}

void Mansion::readRooms()
{
  Room *newRoom;
  std::string roomKey;
  std::string description;
  std::string northKey;
  std::string southKey;
  std::string eastKey;
  std::string westKey;

  std::ifstream inFile;
  inFile.open("rooms.txt");
  while(inFile)
  {
    getline(inFile, roomKey);
    getline(inFile, description);
    getline(inFile, northKey);
    getline(inFile, southKey);
    getline(inFile, eastKey);
    getline(inFile, westKey);
    std::cerr << roomKey;
    newRoom = new Room(description, northKey, southKey, eastKey, westKey);
    mansion[roomKey] = *newRoom;
    numRooms++;
  }
  inFile.close();
}

Room Mansion::GetRoom(std::string key)
{
  return mansion[key];
}



