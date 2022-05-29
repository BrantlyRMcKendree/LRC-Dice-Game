#pragma once
#include <iostream>
#include <fstream>
#include "pch.h"


using namespace std;

// Creates a class game to encapsulate data and keep main method clean
class Game
{

//Protects data and methods listed below except the RunGame Method which will initiate the game. 
private:
	void displayRules();
	void numberOfPlayers();
	void getPlayers();
	void rollDie();
	void determineDiceRoll();
	void printVector();
	int checkForWinner();
	void playGame();

public:
	// Initiates the game. 
	void runGame();

};




