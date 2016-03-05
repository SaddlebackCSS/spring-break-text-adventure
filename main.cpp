
#include <iostream>
#include "Mansion.h"
#include "Room.h"

using namespace std;

int main()
{
  Mansion newHouse;

  std::cout << newHouse.GetRoom("start").GetDesc();


  return 0;
}