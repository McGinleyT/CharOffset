//Thomas McGinley
//06 May, 2023
//CIS1202 N01

#include<iostream>

using namespace std;

char character(char start, int offset);

//MAIN------------------------------------------------------------------------------------------
/*	Driver for character() allowing 5 test cases before ending. */
int main()
{
	char startChar = 'a';
	int offsetNum = 1;

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter a starting character: ";
		cin >> startChar;
		cout << "Enter offset amount: ";
		cin >> offsetNum;

		try
		{
			cout << "End letter: " << character(startChar, offsetNum) << "\n\n";

		}
		catch (int error)
		{
			cout << "Error no. " << error << ": ";
			if (error == 1)
				cout << startChar << " is not a letter.\n\n";
			if (error == 2)
				cout << "Endpoint out of bounds\n\n";
		}
	}

	system("pause");
	return 0;
}

//CHARACTER-------------------------------------------------------------------------------------
/*	Uses ASCII values to offset characters. Converts all letters to lower case first for bounds
*	detection, then offsets the character. Reverts to upper case if applicable and returns endpoint.
*	Throws different exceptions for bad start character and bad endpoint characters.*/
char character(char start, int offset)
{
	const int INVALID_CHARACTER_SELECTION = 1;
	int INVALID_RANGE_EXCEPTION = 2;
	bool upper = false;

	if (!isalpha(start))
	{
		throw INVALID_CHARACTER_SELECTION;
	}

	if (isupper(start))	//converts start to lower, for bounds detection purposes
	{
		upper = true;
		start = (char)tolower(int(start));
	}

	char end = int(start) + offset; //transition to endpoint

	/*	Bounds detection: If not letter, out of bounds. Must also be lower case letter because
	*	the letter was converted to lower case and upper-lower transitions not allowed. On ASCII
	*	table, you can offset low enough to put endpoint in range of the upper case letters, so
	*	if it's not lower it's out of bounds. ie. a-10 != W
	*/
	if (!isalpha(end) || !islower(end))
	{
		throw INVALID_RANGE_EXCEPTION;
	}

	if (upper)	//return char to upper
	{
		end = (char)toupper(int(end));
	}

	return end;
}
