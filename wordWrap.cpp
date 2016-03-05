#include <iostream>
#include <string>


//	Word Wrap Function
//  INPUTS:
//		message: The message to be output
//		length: the number of characters to limit the output to

void wrapText(string message, int length)
{
	const int LENGTH_OF_SPACE = 1;
	int stringLength = message.length();

	do
	{
		if (stringLength > length)
		{
			if (message[length] == ' ')
			{
				// Output, remove the outputted words, and decrease the length
				cout << message.substr(0, length + LENGTH_OF_SPACE) << endl;
				message = message.substr(length + LENGTH_OF_SPACE, stringLength - length + LENGTH_OF_SPACE);
				stringLength -= length + LENGTH_OF_SPACE;
			}
			else
			{
				int letterIndex = length;

				// Loop and find the first instance of a space
				while (message[letterIndex] != ' ')
				{
					letterIndex--;
				}

				// increment so that the space doesnt end up on the next line
				letterIndex++;

				// Output, remove the outputted words, and decrease the length
				cout << message.substr(0, letterIndex) << endl;
				message = message.substr(letterIndex, stringLength - letterIndex);
				stringLength -= letterIndex;
			}
		}
		else
		{
			cout << message;
			stringLength -= message.length();
		}
	} while (stringLength != 0);
	cout << endl;
}
