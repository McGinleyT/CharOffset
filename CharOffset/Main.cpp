//Thomas McGinley
//06 May, 2023
//CIS1202 N01

#include<iostream>

using namespace std;

char character(char start, int offset);

int main()
{
	char startChar = 'A';
	int offsetNum = 1;

	for (int i = 0; i < 6; i++)
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
				cout << "End letter out of bounds\n\n";
		}
	}


	system("pause");
	return 0;
}

char character(char start, int offset)
{
	int invalidCharacterSelection = 1;
	int invalidRangeException = 2;
	bool upper = false;
	const int ASCII_LOW = 97, //a
		ASCII_HIGH = 122; //z

	if (!isalpha(start))
	{
		throw invalidCharacterSelection;
	}

	if (isupper(start))	//converts start to lower, for bounds detection purposes
	{
		upper = true;
		start = (char)tolower(int(start));
	}

	char end = int(start) + offset; //offset movement

	if (int(end) < ASCII_LOW || int(end) > ASCII_HIGH) //bounds detection
	{
		throw invalidRangeException;
	}

	if (upper)	//return char to upper
	{
		end = (char)toupper(int(end));
	}

	return end;
}
