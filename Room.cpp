//
// Created by ozyx on 3/4/16.
//

#include "Room.h"

Room::Room()
{
  description = "You see a room full of defaults.";
  north = "none";
  south = "none";
  east  = "none";
  west  = "none";
}

Room::Room(std::string desc, std::string N, std::string S, std::string E,
           std::string W)
{
  description = desc;
  north = N;
  south = S;
  east  = E;
  west  = W;
}

Room::~Room()
{

}

std::string Room::GetDesc() const
{
  return description;
}
