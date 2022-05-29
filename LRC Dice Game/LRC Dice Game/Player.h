#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player
{
private:
	string m_name; // Allows the player to have a name
	int m_chips = 3; // Player starts with 3 chips

public:
	// Constructor
	Player()
	{

	}

	//Destructor
	~Player()
	{

	}


	// Accessors and Mutators are listed below. 
	void setName(string name)
	{
		m_name = name;
	}

	string getName()
	{
		return m_name;
	}

	void setChips(int chips)
	{
		m_chips = chips;
	}

	int getChips()
	{
		return m_chips;
	}



};

