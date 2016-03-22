#include "GameWorld.h"
#include <iostream>
#include <algorithm>

GameWorld::GameWorld()
{
  numRooms = 1;
  Room *firstRoom = new Room();
  currentRoom = firstRoom;
  //initialize rooms
  initializeRooms();
  //initialize valid commands
  initializeCommands();
}

GameWorld::GameWorld(Room *initialRoom)
{
  numRooms = 1;
  currentRoom = initialRoom;
  initializeCommands();
}

GameWorld::~GameWorld()
{ }

void GameWorld::addRoom(std::string key, Room newRoom)
{
  roomMap[key] = newRoom;
}

void GameWorld::moveToRoom(std::string roomName)
{
  if (roomName != "none")
  {
    currentRoom = &roomMap[roomName];
  }
  else
  {
    std::cout << "There is nowhere to go in that direction." << std::endl;
  }
}

bool GameWorld::isValidCommand(std::string input)
{
  bool isValid = false;

  //initialize iterator to beginning of validCommands vector
  std::vector<std::string>::iterator it = validCommands.begin();
  while (it != validCommands.end() && !isValid)
  {
    if (input == *it)
    {
      isValid = true;
    }
    else
    {
      it++;
    }
  }

  return isValid;
}

bool GameWorld::interact()
{
  std::string input;
  bool isStillPlaying = true;

  std::cout << currentRoom->GetRoomDesc() << std::endl;
  do
  {
    std::cout << "Enter a command: ";

    getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (!isValidCommand(input))
    {
      std::cout << "That is not a valid command" << std::endl;
    }

  } while (!isValidCommand(input));

  if (input == "north")
  {
    moveToRoom(currentRoom->GetNorth());
  }

  if (input == "east")
  {
    moveToRoom(currentRoom->GetEast());
  }

  if (input == "south")
  {
    moveToRoom(currentRoom->GetSouth());
  }

  if (input == "west")
  {
    moveToRoom(currentRoom->GetWest());
  }

  if (input == "quit")
  {
    isStillPlaying = false;
  }

  if (input == "exit")
  {
    isStillPlaying = false;
  }

  return isStillPlaying;
}

void GameWorld::initializeRooms()
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
  while (inFile)
  {
    getline(inFile, roomKey);
    getline(inFile, description);
    getline(inFile, northKey);
    getline(inFile, southKey);
    getline(inFile, eastKey);
    getline(inFile, westKey);

    newRoom = new Room(roomKey, description, northKey, southKey, eastKey, westKey);
    addRoom(roomKey, *newRoom);
    numRooms++;
    inFile.ignore('\n');
  }
  inFile.close();
}

void GameWorld::initializeCommands()
{
  validCommands.push_back("north");
  validCommands.push_back("south");
  validCommands.push_back("east");
  validCommands.push_back("west");
  validCommands.push_back("exit");
  validCommands.push_back("quit");
}








