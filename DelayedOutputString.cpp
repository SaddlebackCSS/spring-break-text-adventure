#include "DelayedOutputString.h"

DelayedOutputString::DelayedOutputString(std::string message, int delayInMilliseconds, bool endOfLine)
{
	internalString = message;
	delay = delayInMilliseconds;
	endsLine = endOfLine;
}

DelayedOutputString::~DelayedOutputString() {}

std::ostream& operator << (std::ostream& os, const DelayedOutputString message)
{
	for (int i = 0; i < message.internalString.length(); i++)
	{
		os << message.internalString[i];
		std::this_thread::sleep_for(std::chrono::milliseconds(message.delay));
	}

	if (message.endsLine)
	{
		os << std::endl;
	}

	return os;
}