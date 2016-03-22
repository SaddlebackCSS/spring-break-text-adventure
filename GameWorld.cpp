#include "GameWorld.h"
#include <iostream>
#include <algorithm>

GameWorld::GameWorld(Room *initialRoom)
{
  currentRoom = initialRoom;
  validCommands.push_back("north");
  validCommands.push_back("south");
  validCommands.push_back("east");
  validCommands.push_back("west");
  validCommands.push_back("exit");
  validCommands.push_back("quit");
}

GameWorld::~GameWorld()
{ }

void GameWorld::addRoom(std::string key, Room &room)
{
  roomMap[key] = room;
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
      std::cout << std::endl << "That is not a valid command" << std::endl;
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


