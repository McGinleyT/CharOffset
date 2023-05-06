//Thomas McGinley
//06 May, 2023
//CIS1202 N01

#include<iostream>
#include<cctype>

using namespace std;

char character(char start, int offset);

int main()
{
	bool loop = true;

	character('A', 1);
	cout << "\n\n";
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

	if (isupper(start))
	{
		upper = true;
		start = (char)tolower(int(start)); //converts start to lower, for bounds detection purposes
	}
	cout << start;
	cout << "\t" << offset << "\t";
	start = int(start) + offset;
	cout << start;




	return ' ';
}
