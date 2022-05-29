#include "GameLoop.h"
#include <iostream>
#include <time.h>
#include "Player.h"
#include <vector>

using namespace std;

// Global varibles used in multiple methods
int amountOfPlayers; 
int winner;
int playerTurn = 0;

// Creates a vector and initializes player class
vector<Player> playerVector;
Player player;

// This method displays the rules to the user from the text file "LCR_Rules.txt"
void Game::displayRules()
{
	string myText;
	ifstream LCR_Rules("LCR_Rules.txt");

	while (getline(LCR_Rules, myText))
	{
		cout << myText << endl;
	}
	cout << endl << endl;
}

// This method accepts a number of players no less than 3
void Game::numberOfPlayers()
{
	char verifyNumberOfPlayers = 'a';

	// While loop to determine if the player entered the correct value
	while (verifyNumberOfPlayers != 'y')
	{
		cout << "Please enter the number of players, any less three cannot be played and will ask for more players: " << endl;
		cin >> amountOfPlayers;

		while (amountOfPlayers < 3)
		{
			cout << "This is not a valid number of players please enter more players" << endl;
			cin >> amountOfPlayers;
		}

		cout << "Is " << amountOfPlayers << " correct?(Y/N)" << endl;
		cin >> verifyNumberOfPlayers; 
		cout << endl;

	}
}

// This method collects player information including name 
void Game::getPlayers()
{
	for (int i = 1; i < (amountOfPlayers + 1) ; i++)
	{
		string playerName;
		char verifyPlayerName = 'a';	
		Player player;

		// While loop to determine if they entered the correct player name
		while (verifyPlayerName != 'y' && verifyPlayerName != 'Y')
		{
			cout << "Enter player " << i << "'s name: " << endl;
			cin >> playerName;
			

			cout << "Is " << playerName << " correct? (Y/N)" << endl;
			cin >> verifyPlayerName;
			cout << endl;
		}
		
		player.setName(playerName);
		playerVector.push_back(player);
	}
}

// This method is used to print the playerVector to display who is playing and how many chips they have. 
void Game::printVector()
{
	unsigned int size = playerVector.size();

	for (unsigned int i = 0; i < size; i++)
	{
		cout << "Player " << i + 1 << "'s name: " << playerVector[i].getName() << endl;
		cout << playerVector[i].getName() << "'s chips: " << playerVector[i].getChips() << endl << endl;
	}
}

// This method is used to roll dice and pass chips according to the dice. 
void Game::rollDie()
{
	// These lines initialize variables for function rollDice for the dice display.
	int dieNumber;
	char dieDisplay = 'a';

	// This line determines the roll of the die. 
	
	dieNumber = (rand() % 5) + 1;
	
	// This switch statement determines what the player does according to their roll. 
	switch (dieNumber)
	{
	//Case 1: L means the player pass to the left or down a number in the playerVector location.
	case 1:
		dieDisplay = 'L';
		cout << dieDisplay << endl;
		
		// This if statement makes sure the vector doesn't throw a trouble when location 0 pass to the left or -1. 
		if (playerTurn == 0)
		{

			playerVector[playerTurn].setChips((playerVector[playerTurn].getChips() - 1));
			playerVector[playerVector.size() - 1].setChips((playerVector[playerVector.size() - 1].getChips() + 1));

		}

		else
		{
			playerVector[playerTurn].setChips((playerVector[playerTurn].getChips() - 1));
			playerVector[playerTurn - 1].setChips((playerVector[playerTurn - 1].getChips() + 1));
		}

		//Prints remaining chips to help keep track of whats going on during gameplay. 
		cout << playerVector[playerTurn].getName() << "'s chips remaining: " << playerVector[playerTurn].getChips() << endl << endl;

		break;

	// Case 2: R is passing a chip to the right or +1 position in the vector 
	case 2:
		dieDisplay = 'R';
		cout << dieDisplay << endl << endl;

		//This branch allows the last player to pass back to the first player without causing vector issues. 
		if (playerTurn == (playerVector.size() -1))
		{
			playerVector[playerTurn].setChips((playerVector[playerTurn].getChips() - 1));
			playerVector[0].setChips(playerVector[0].getChips() + 1);
		}

		else

		{
			playerVector[playerTurn].setChips((playerVector[playerTurn].getChips() - 1));
			playerVector[playerTurn + 1].setChips((playerVector[playerTurn + 1].getChips() + 1));
		}

		//Again printing the remaining chips to keep track of the chips remaining. 
		cout << playerVector[playerTurn].getName() << "'s chips remaining: " << playerVector[playerTurn].getChips() << endl << endl;

		break;

	// Case 3: C is passing a chip to the center or removing it from play. 
	case 3:
		dieDisplay = 'C';
		cout << dieDisplay << endl << endl;

		playerVector[playerTurn].setChips((playerVector[playerTurn].getChips() - 1));

		// And again, printing the remaining chips to keep track. 
		cout << playerVector[playerTurn].getName() << "'s chips remaining: " << playerVector[playerTurn].getChips() << endl << endl;
		break;
	
	// Default: this case means the player doesn't pass a chip anywhere. 
	default:
		dieDisplay = '*';
		cout << dieDisplay << endl << endl;

		// Finally, displaying the chips for this case also to keep track of chips.
		cout << playerVector[playerTurn].getName() << "'s chips remaining: " << playerVector[playerTurn].getChips() << endl << endl;

		break;
	}	
}

// This method determines how many chips a player has and how many dice they can roll
void Game::determineDiceRoll()
{
	// Creates a variable to use in the switch expression
	int chips = playerVector[playerTurn].getChips();

	switch (chips)
	{
	case 0:
		break;

		case 1:
		rollDie();
			break;

		case 2:
			rollDie();
			rollDie();
			break;
		default:
			rollDie();
			rollDie();
			rollDie();
			break;
	}
}

// This method determines a winner and is used in the playGame method
int Game::checkForWinner()
{
	int winningGame = 0;
	int winningPlayer;
	int size = playerVector.size();
	char exitGame = 'a';

	for (int i = 0; i < size; i++)
	{
		if (playerVector[i].getChips() > 0)
		{
			winningPlayer = i;
			winningGame++;
		}
	}

	if (winningGame > 1)
	{
		return -1;
	}

	else
	{

		cout << "The winner is " << playerVector[winningPlayer].getName() << "! Congratulations!" << endl << endl;

		while (exitGame = 'a') {
			cout << "Please exit the game with any key." << endl;
			cin >> exitGame;
		}
		return 1;
	}
	
}

// This is the method that actually initiates gameplay after players are entered
void Game::playGame()
{
	do
	{
		// Adds a stop to allow the player to roll their dice instead of just running through the code without input
		char playerRoll = 'a';

		while (playerRoll != 'r')
		{	
			// Asks the player to roll the dice 
			cout << playerVector[playerTurn].getName() << "'s roll. " << playerVector[playerTurn].getChips() << " Chips remaining. Press R to roll." << endl << endl;
			cin >> playerRoll;
		}

		// Calls method to roll dice and determine where chips are passed
		determineDiceRoll();

		//Calls method that checks for winner. 
		winner = checkForWinner();
		
		// Iterates through player turns and comes back around to first player
		if ((playerTurn + 1) == playerVector.size())
		{
			playerTurn = 0;
		}

		else
		{
			playerTurn++;
		}

	} while (winner != 1);
	
}

// Creates the RunGame method which is used in the LRC Dice Game.cpp to create encapsulation and protect data
void Game::runGame()
{
	srand((unsigned int)time(NULL));
	displayRules();
	numberOfPlayers();
	getPlayers();
	printVector();
	playGame();
}