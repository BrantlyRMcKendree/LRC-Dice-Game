#include <iostream>
#include <fstream>
#include <string>
#include "pch.h"

using namespace std;

// A class created to display the rules of the game and keep code clean
class Rules
{
	void displayRules()
	{
		string myText;
		ifstream LCR_Rules("LCR_Rules.txt");

		while (getline(LCR_Rules, myText))
		{
			cout << myText << endl;
		}
	}
};

