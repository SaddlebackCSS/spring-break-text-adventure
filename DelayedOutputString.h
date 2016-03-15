#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

class DelayedOutputString
{
public:
	DelayedOutputString(std::string, int delayInMilliseconds, bool endOfLine);
	~DelayedOutputString();
	friend std::ostream& operator<<(std::ostream& os, const DelayedOutputString);
private:
	std::string internalString;
	int delay = 45;
	bool endsLine;
};

